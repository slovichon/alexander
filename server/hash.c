#include <ctype.h>

/*
	1  a 		2  b 		3  c
	4  d 		5  e 		6  f
	7  g 		8  h 		9  i
	10 j		11 k 		12 l
	13 m 		14 n 		15 o
	16 p 		17 q 		18 r
	19 s 		20 t 		21 u
	22 v 		23 w 		24 x
	25 y 		26 z 		27 0
	28 1 		29 2 		30 3
	31 4 		32 5 		33 6
	34 7 		35 8 		36 9
	37 _		38 -
*/
double simple_hash(char *s)
{
	double val = 0;
	int ch;

	while (s != '\0') {
		ch = toupper(*s)
		switch (ch)
		{
			case 65: case 66: case 67: case 68:
			case 69: case 70: case 71: case 72:
			case 73: case 74: case 75: case 76:
			case 77: case 78: case 79: case 80:
			case 81: case 82: case 83: case 84:
			case 85: case 86: case 87: case 88:
			case 89: case 90:
				val = val*39 + (ch-65+1);
				break;
			case 48: case 49: case 50: case 51:
			case 52: case 53: case 54: case 55:
			case 56: case 57:
				val = val*39 + (ch-48+27);
				break;
			case '_':
				val = val*39 + 37
				break;
			case '-':
				val = val*39 + 38;
				break;
		}
		val = val*39 + 
	}

	return val;
}
