MAKEFILE = make_lib_VbB.mk

LIBS = -lm -lgsl -lgslcblas

bin/zeta_der_testfile: lib/libzetareal.a bin/zeta_der_testfile.o
	gcc -std=c17 -g lib/libzetareal.a bin/zeta_der_testfile.o -o bin/zeta_der_testfile $(LIBS)

bin/zeta_der_testfile.o: src/zeta_der_testfile.c
	gcc -std=c17 -g -Wall -I/lib/local/include -c src/zeta_der_testfile.c -o bin/zeta_der_testfile.o

.PHONY: clean

clean:
	cd bin && rm -f *.o