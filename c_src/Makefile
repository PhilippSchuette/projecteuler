# Makefile to compile all solutions in this dir
CFLAGS := -coverage -O0 -std=c99

target:
	gcc $(CFLAGS) test/utest.c -c -o test/utest.o
	gcc $(CFLAGS) problem001.c -c -o p1.o
	gcc $(CFLAGS) problem002.c -c -o p2.o
	gcc $(CFLAGS) p1.o test/utest.o -o p1
	gcc $(CFLAGS) p2.o test/utest.o -o p2
	bash ./test.sh

debug_utest:
	gcc -g utest.c -c -o test/utest.o
	gcc -g problem001.c -c -o p1.o
	gcc -g test/utest.o p1.o -o p1
	./p1

clean_utest:
	rm -f test/*.gcno test/*.gcda test/*.gcov

clean:
	rm -f *.o p1 p2 *.gcno *.gcda *.gcov
	rm -f test/*.o test/*.gcno test/*.gcda test/*.gcov
