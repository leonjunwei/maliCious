/* This code is a test platform for stack-based buffer overflows.
It blindly takes in a string argument from the command line, and attempts
to copy that string into a buffer. If the string is longer than the (stack-allocated)
buffer, it will write past the end of the buffer.
This could be used to change data about the stack frame itself, such as the
return address.
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>	

void main(int argc, char **argv, char **envp) {
	char array[200];
	strcpy(array,argv[1]);
}