# Makefile to compile all solutions in this dir
CFLAGS := -coverage -O0 -std=c99
test_dir := utest
test := $(test_dir)/utest
problems.o := p1.o p2.o
problems_exe := p1 p2

.PHONY: all debug_utest clean_utest clean test

all: $(problems_exe)
	bash ./test.sh
	bash ./time.sh

$(problems_exe): $(test).o
	gcc $(CFLAGS) p1.o $(test).o -o p1
	gcc $(CFLAGS) p2.o $(test).o -o p2

$(test).o: $(problems.o)
	gcc $(CFLAGS) $(test).c -c -o $(test).o

$(problems.o):
	gcc $(CFLAGS) problem001.c -c -o p1.o
	gcc $(CFLAGS) problem002.c -c -o p2.o

test:
	bash ./test.sh

clean:
	rm -f *.o $(problems_exe) *.gcno *.gcda *.gcov
	rm -f $(test_dir)/*.o $(test_dir)/*.gcno $(test_dir)/*.gcda $(test_dir)/*.gcov
