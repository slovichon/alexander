/* $Id$ */

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
		ch = tolower(*s);
		switch (ch)
		{
			case 'a': case 'b': case 'c': case 'd':
			case 'e': case 'f': case 'g': case 'h':
			case 'i': case 'j': case 'k': case 'l':
			case 'm': case 'n': case 'o': case 'p':
			case 'q': case 'r': case 's': case 't':
			case 'u': case 'v': case 'w': case 'x':
			case 'y': case 'z':
				val = val*39 + (ch-'a'+1);
				break;

			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9':
				val = val*39 + (ch-'0'+26+1);
				break;

			case '_':
				val = val*39 + 26+10+1;
				break;

			case '-':
				val = val*39 + 26+10+1+1;
				break;
		}
	}

	return val;
}
