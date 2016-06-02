CC=gcc
CFLAGS=

RM=/bin/rm -f

all: tannenbaum  p1-angabe p2-angabe

tannenbaum: tannenbaum.o
	${CC} ${CFLAGS} tannenbaum.c -o tannenbaum

p1-angabe: p1-angabe.o
	${CC} ${CFLAGS} p1-angabe.c -o p1-angabe

p2-angabe: p2-angabe.o
	${CC} ${CFLAGS} p2-angabe.c -o p2-angabe

#Clean up the folder
clean:
	${RM} *.o tannenbaum p1-angabe p2-angabe
