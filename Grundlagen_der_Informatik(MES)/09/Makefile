CC=gcc
CFLAGS=
RM=/bin/rm -f

all: pipe fifowriter fiforeader semaphore

pipe: pipe.c
	${CC} ${CFLAGS} pipe.c -o pipe

fifowriter: fifowriter.c
	${CC} ${CFLAGS} fifowriter.c -o fifowriter

fiforeader: fiforeader.c
	${CC} ${CFLAGS} fiforeader.c -o fiforeader

semaphore: semaphore.c
	${CC} ${CFLAGS} semaphore.c -o semaphore

clean:
	${RM} *.o pipe fiforeader fifowriter semaphore
