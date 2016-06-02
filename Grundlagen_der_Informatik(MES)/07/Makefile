CC=gcc
CFLAGS=-Wall

RM=/bin/rm -f

all: ggt

ggt.o: ggt.c
	 ${CC} ${CFLAGS} -c ggt.c

main: ggt.o
	${CC} ${CFLAGS} -o ggt ggt.o

#Enable DEBUG for GDB
debug: CFLAGS += -g
debug: ggt
	
#Clean up the folder
clean:
	${RM} *.o ggt
