# Build the UTest example.
CFLAGS := -O0 -std=c99
prog := array_example
utest := ../utest

.PHONY: all test clean

all: $(prog).o $(utest).o
	gcc $(CFLAGS) $(prog).o $(utest).o -o $(prog)

$(prog).o:
	gcc $(CFLAGS) $(prog).c -c -o $(prog).o

$(utest).o:
	gcc $(CFLAGS) $(utest).c -c -o $(utest).o

test: $(prog)
	./$(prog)

clean:
	rm -f prog $(prog).o $(utest).o $(prog)
