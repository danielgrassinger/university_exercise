CC=gcc
CFLAGS=

RM=/bin/rm -f

#Make all
all: fibonacci p2 p3 p4

fibonacci: fibonacci.c
	 ${CC} ${CFLAGS} fibonacci.c -o fibonacci

p2: p2.c
	${CC} ${CFLAGS}  p2.c -o p2

p3: p3.c
	${CC} ${CFLAGS}  p3.c -o p3

p4: p4.c
	${CC} ${CFLAGS}  p4.c -o p4


#Clean up the folder
clean:
	${RM} *.o fibonacci p2 p3 p4
