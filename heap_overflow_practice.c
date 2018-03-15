/* This code is an attempt to manipulate the in-band data structures
used by malloc. According to the tutorial at https://www.win.tue.nl/~aeb/linux/hh/hh-11.html,
allocated data should be preceded by a 4-byte struct consisting of 
size and status information. The chunks are the right size, but 
what should be size appears to be all 0's. Perhaps a different version
of malloc is in use?
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
	int *p = malloc(sizeof(int));
	int *q = malloc(sizeof(int));
	*p = 2;
	*q = 4;
	printf("%lu\n", sizeof(*p));
	printf("%p\n", p);
	printf("%p\n", q);
	printf("%i\n", *p);
	printf("%i\n", *(q-4));
}