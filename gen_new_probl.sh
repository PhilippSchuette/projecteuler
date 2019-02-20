#!/usr/bin/env zsh

zparseopts -D -E \
    l:=lang -language:=lang \
    n:=num -number:=num \
    a:=author -author=author \
    f=force -force=force \
    h=help -help=help

print_help() {
    echo "Usage: ./gen_new_probl.sh -l [LANGUAGE] -n [NUMBER] \n"

    echo "Mandatory arguments:"
    printf "%-15s  %s \n" "-l --language" "Programming language to use: Currently supported are 'cpp' for C++, 'c' for C and 'py' for Python"
    printf "%-15s  %s \n" "-n --number" "Number of the problem you want to solve"
    echo "\nOptional arguments:"
    printf "%-15s  %s \n" "-f --force" "Always override if file already exists without prompting"
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
is_go=false
is_js=false
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
    "go" )
        is_go=true
        template1="go_src/templates/template.go"
        template2="go_src/templates/template_test.go"
        template3="go_src/templates/template_main.go"
        outfile1="go_src/solver${num}.go"
        outfile2="go_src/solver${num}_test.go"
        outfile3="go_src/main/problem${num}.go"
        ;;
    "js" )
        is_js=true
        template1="js_src/template_problem.js"
        template2="js_src/template_solver.js"
        outfile1="js_src/problem${num}.js"
        outfile2="js_src/solver${num}.js"
        ;;
esac

# if target language is Go, copy multiple files
if $is_go; then
    if [[ -z $force && (-e $outfile1 || -e $outfile2 || -e $outfile3) ]]; then
        read -q "REPLY?One of the output files already exists! Overwrite? (y/n)"
        echo ""
        [[ $REPLY = "n" ]] && exit 1
    fi
    cp $template1 $outfile1
    cp $template2 $outfile2
    cp $template3 $outfile3
elif $is_js; then
    if [[ -z $force && (-e $outfile1 || -e $outfile2) ]]; then
        read -q "REPLY?One of the output files already exists! Overwrite? (y/n)"
        echo ""
        [[ $REPLY = "n" ]] && exit 1
    fi
    cp $template1 $outfile1
    cp $template2 $outfile2
else
    if [[ -z $force && -e $outfile ]]; then
        read -q "REPLY?File $outfile already exists! Overwrite? (y/n)"
        echo ""
        [[ $REPLY = "n" ]] && exit 1
    fi
    cp $template $outfile
fi

# Add problem number, author and date (not for Go files)
if $is_go; then
    echo "Successfully created source files $outfile1, $outfile2 and $outfile3!"
    echo "Please add author name, date and solution number manually."
elif $is_js; then
    echo "Successfully created source files $outfile1 and $outfile2!"
    echo "Please add author name, date and solution number manually."
else
    # add problem number
    sed -i "s/Problem X/Problem $num/g" $outfile

    # add author information
    [[ -z $author ]] && author=$(git config user.name) || author=$author[2]
    sed -i "s/<author_name>/$author/g" $outfile

    # add date
    sed -i "s/Date: .*$/$(date +'%Y\/%m\/%d')/g" $outfile

    # remove template comment
    sed -i "/demonstrates/d" $outfile

    # try to get problem text from `projecteuler.net'
    url="https://projecteuler.net/problem={$num}"
    statement=$(curl -s $url | tr -d '\n' | grep -o -P '(?<=problem_content" role="problem"\>).*(?=\<\/p\>\<\/div\>\<br)' | sed -e 's/<p>//g' | sed -e 's/<\/p>//g')
    # TODO (bug fix): Formulas have multiple inline html tags (spans, etc.)
    # that need to be removed to make this work for some problems!
    
    # Remove hyperlinks to input files, e.g. in problem 22
    statement=$(echo $statement | sed 's/<a href=".*">//g' | sed 's/<\/a>//g')

    # replace template comment with problem statement
    statement=$(echo "Problem statement: $statement")
    # use @ instead of / here, otherwise sed will be confused if the problem statement contains /
    sed -i "s@Problem statement:@$statement@g" $outfile

    echo "Successfully created source file $outfile!"
fi
