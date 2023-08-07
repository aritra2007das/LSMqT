SHELL=/bin/sh

CC = gcc

CV = -std=gnu14

IDIR = /usr/lib/include

LDIR = /usr/local/lib

VPATH = src

CCFLAGS = -I$(IDIR)

LCFLAGS = -L$(LDIR)

WARNFLAGS = -Wall

CFLAG = -std=c17

#LIBFILE = lib/libzetareal.a

LDFLAGS= -lm -lgsl -lgslcblas

#HDRS = V_decl.h
MAKEFILE = make_main_V2

COMMAND = main_V2

OBJS = Pi_ff_B.o Pi_ff_ThM.o PipiB.o\
		PipiThM.o Pi_pi_neutral_Th.o JB.o \
		ITh.o JThM_copy_rr.o lambda_eff.o Pi_thermal.o \
		Pi_pi0.o Pi_pi0_Vertex.o \
		VffThM.o VbThM.o VbTh.o\
		zeta_der_real.o VfB.o VbB.o \
		Vb.o Vct.o v0_cl.o V_total.o find_vBmin.o\
		pi0_disp.o mass_pi0.o Delta_T.o main_V2.o \


all: $(COMMAND) clean

$(COMMAND): $(OBJS)
	$(CC) $(CV) $(CFLAG) $(LCFLAGS) $(OBJS) -o $(COMMAND) $(LDFLAGS) 


main_V2.o: main_V2.c include/V_decl.h include/Pi0.h
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c main_V2.c

Delta_T.o: Delta_T.c
	$(CC) $(CFLAG) $(WARNFLAGS) -c src/Delta_T.c

mass_pi0.o: mass_pi0.c include/Pi0.h
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/mass_pi0.c

pi0_disp.o: pi0_disp.c include/Pi0.h
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/pi0_disp.c

find_vBmin.o: find_vBmin.c include/V_decl.h
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/find_vBmin.c

V_total.o: V_total.c include/V_decl.h include/Pi0.h
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/V_total.c

v0_cl.o: v0_cl.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/v0_cl.c

Vct.o: Vct.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/Vct.c

Vb.o: Vb.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/Vb.c 

VbB.o: VbB.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/VbB.c

VfB.o: VfB.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/VfB.c

zeta_der_real.o: zeta_der_real.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/zeta_der_real.c

VbTh.o: VbTh.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/VbTh.c

VbThM.o: VbThM.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/VbThM.c

VffThM.o: VffThM.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/VffThM.c

Pi_pi0_Vertex.o: Pi_pi0_Vertex.c
	$(CC) $(CFLAG) $(WARNFLAGS) -c src/Pi_pi0_Vertex.c

Pi_pi0.o: Pi_pi0.c
	$(CC) $(CFLAG) $(WARNFLAGS) -c src/Pi_pi0.c

Pi_thermal.o: Pi_thermal.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/Pi_thermal.c

lambda_eff.o: lambda_eff.c
	$(CC) $(CFLAG) $(WARNFLAGS) -c src/lambda_eff.c

JThM_copy_rr.o: JThM_copy_rr.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/JThM_copy_rr.c

ITh.o: ITh.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/ITh.c

JB.o: JB.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/JB.c

Pi_pi_neutral_Th.o: Pi_pi_neutral_Th.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/Pi_pi_neutral_Th.c

PipiThM.o: PipiThM.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/PipiThM.c

PipiB.o: PipiB.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/PipiB.c

Pi_ff_ThM.o: Pi_ff_ThM.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/Pi_ff_ThM.c

Pi_ff_B.o: Pi_ff_B.c
	$(CC) $(CFLAG) $(WARNFLAGS) $(CCFLAGS) -c src/Pi_ff_B.c

.PHONY: clean
clean:
	rm -f $(OBJS)
