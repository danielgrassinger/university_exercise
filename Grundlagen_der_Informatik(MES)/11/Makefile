CC=gcc
CFLAGS=

RM=/bin/rm -f

all: comb ringpuffer_array ringpuffer_list

comb: comb.c
	${CC} ${CFLAGS} comb.c -o comb

ringpuffer_array: ringpuffer_array.c
	${CC} ${CFLAGS} ringpuffer_array.c -o ringpuffer_array

ringpuffer_list: ringpuffer_list.c
	${CC} ${CFLAGS} ringpuffer_list.c -o ringpuffer_list

#Clean up the folder
clean:
	${RM} *.o comb ringpuffer_array ringpuffer_list
