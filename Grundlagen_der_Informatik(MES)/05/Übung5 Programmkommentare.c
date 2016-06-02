#include <stdio.h>

int main(void) {
	int x = 5, y = 8;
	int z[] ={10, 20, 30 , 40, 50};
	int *ip;						// 1 ip ist ein pointer vom Typ int
	ip = &x;						// 2 ip enthält nun die Adresse von x
	y = *ip;						// 3 y hat den wert von x
	*ip = 0;						// in der Speicheradresse von x steht 0
	ip = &z[0];						// der Pointer ip enthällt den Wert des ersten Elements von z[]
	y = *(ip+2);					// y wird mit Inhalt des "dritten" Array-Elements (30) beschrieben
	*((char*)ip+4) = 99;			// *(++ip)=99; typ von ip wird auf char* gesetzt ip + 4 = ip + 4 * sizeof(char) (=1); das zweite Array Element wird auf 99 gesetzt   
	x = *(ip+4);					// x wird mit dem fünften Array Element (50) beschrieben
	y = *(ip+1);					// y wird mit dem zweiten Arrey Element (99) beschrieben
	return 0;
}