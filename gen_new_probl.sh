#!/usr/bin/env zsh

zparseopts -D -E \
    l:=lang -language:=lang \
    n:=num -number:=num \
    a:=author -author=author \
    h=help -help=help

print_help() {
    echo "Usage: ./gen_new_probl.sh -l [LANGUAGE] -n [NUMBER] \n"

    echo "Mandatory arguments:"
    printf "%-15s  %s \n" "-l --language" "Programming language to use: Currently supported are 'cpp' for C++, 'c' for C and 'py' for Python"
    printf "%-15s  %s \n" "-n --number" "Number of the problem you want to solve"
    echo "\nOptional arguments:"
    printf "%-15s  %s \n" "-a --author" "Author name, default is the output of 'git config user.name'"
    printf "%-15s  %s \n" "-h --help" "Print this message and exit"
}

if [[ -z $lang || -z $num || -n $help ]]; then
    echo "Missing mandatory arguments!\n"
    print_help
    exit 0
fi

# Add leading 0s to the problem number
num=$(printf "%03d" $num[2]) 

# Create the problem source file
case $lang[2] in
    "cpp" )
        template="cpp_src/template.cpp"
        outfile="cpp_src/problem${num}.cpp"
        ;;
    "c" )
        template="c_src/template.c"
        outfile="c_src/problem${num}.c"
        ;;
    "py" )
        template="py_src/template.py"
        outfile="py_src/problem${num}.py"
        ;;
esac
if [[ -e $outfile ]]; then
    read -q "REPLY?File $outfil already exists! Overwrite? (y/n)"
    echo ""
    [[ $REPLY = "n" ]] && exit 1
fi
cp $template $outfile

# Add problem number
sed -i "s/Problem X/Problem $num/g" $outfile 

# Add author
[[ -z $author ]] && author=$(git config user.name) || author=$author[2]
sed -i "s/<author_name>/$author/g" $outfile 

# Add date
sed -i "s/Date: .*$/$(date +'%Y\/%m\/%d')/g" $outfile 

# Remove the comment about the template
sed -i "/demonstrates/d" $outfile

echo "Successfully created source file $outfile!"
