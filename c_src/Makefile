# Makefile to compile all solutions in this dir
CFLAGS := -coverage -O0

target:
	gcc $(CFLAGS) problem001.c -o p1
	gcc $(CFLAGS) problem002.c -o p2
	bash ./test.sh

clean:
	rm p1 p2 *.gcno *.gcda *.gcov
