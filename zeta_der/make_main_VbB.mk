#SHELL = /bin/bash

CC = gcc

CFLAG = -g

STD = -std=c17

LIBGSLPATH = -L/usr/local/lib

INCLUDEGSLPATH = -I/usr/local/include

#INCLUDEPATH = -I ~/Dropbox/LSMq_T/C++_codes/LSMq_codes/zeta_der/include

HDRS = myheaders.h

WARNFLAGS = -Wall

OBJS = main_VbB.o VbB.o zeta_der_real.o \

LIBS = -lm -lgsl -lgslcblas

MAKEFILE = make_main_VbB.mk

COMMAND = main_VbB

#VPATH = src

vpath %.h include

$(COMMAND): $(OBJS) 
	$(CC) $(STDC) $(CFLAG) $(LIBGSLPATH) -o $(COMMAND) $(OBJS) $(LIBS)

main_VbB.o: src/main_VbB.c $(HDRS)
	$(CC) $(STDC) $(CFLAG) $(WARNFLAGS) -c src/main_VbB.c

VbB.o: src/VbB.c $(HDRS)
	$(CC) $(STDC) $(CFLAG) $(WARNFLAGS) $(INCLUDEGSLPATH) -c src/VbB.c

zeta_der_real.o: src/zeta_der_real.c
	$(CC) $(STDC) $(CFLAG) $(WARNFLAGS) $(INCLUDEGSLPATH) -c src/zeta_der_real.c

.PHONY: clean

clean:
	rm -f $(OBJS)

.PHONY: move

move:
	mv $(COMMAND) bin