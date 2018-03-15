# maliCious: Exploring Exploits in C
### Leon Lam and Sean Foley

#### Project Goal

We planned to research and implement exploits written in C that would have negative effects when run.

####Learning Goals

We hoped to learn more about how (and why) different exploits work and also investigate countermeasures. At a deeper level, we wanted to learn more about the underpinnings of both C and Linux by exploring their weaknesses.

#### Relevant Resources

We searched through a number of papers and tutorials from the late nineties/early 2000’s about overflow vulnerabilities. An annotated bibliography of the most relevant:

- One, Aleph. “Smashing The Stack For Fun And Profit.” Phrack Magazine, no. 49, 1996, www-inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf. A thorough paper on stack-allocated buffer overflow exploits. Bitrot may explain why the code in this paper did not work for us.
- Zillion. Writing Shellcode. 4 Oct. 2002, www.safemode.org/files/zillion/shellcode/doc/Writing_shellcode.html. A tutorial we used to try and write/debug shell code for our exploits.
- Brouwer, Andries. “Smashing The Stack.” Hackers Hut, 1 Apr. 2003, www.win.tue.nl/~aeb/linux/hh/hh-10.html. A tutorial version of Smashing the Stack. It was much more approachable than the paper itself.
- Designer, Solar. “JPEG COM Marker Processing Vulnerability.” Openwall, 25 July 2000, www.openwall.com/articles/JPEG-COM-Marker-Vulnerability#exploit. Some exploration of buffer overflow exploits on the heap.

#### Results

We also attempted to use buffer overflows to execute arbitrary code. Many C programmers do not implement bounds checking when writing data. We used [vuln.c](https://github.com/leonjunwei/maliCious/blob/master/vuln.c) as a simplified example for testing:

```c
void main(int argc, char argv, char envp) {
    char array[200];
    strcpy(array,argv[1]);
}
```

vuln.c takes in a string and attempts to store it in a stack-allocated buffer. If you were to give it a string of 1000 “A”’s, it would simply write past the end of the stack frame, and very likely give a segmentation fault error:

![img](https://lh6.googleusercontent.com/zIhYfFN1AG0FA8ZIwDH_iuVZYgXNkC7LUq2i-x5xLO-WVD157IbR8EHcL_hG0uEehyXNJ2-idp2Ub8wyorsN7WupEp8fxZMsslirI4ZZIaOsXRzsP2LhvaWdi-IzspglmigxofL6)

Unfortunately, that’s not a very useful exploit; there are plenty of ways to crash a process. A more powerful exploit involves carefully choosing the input string. When a function is called, it’s given a pointer to the place in code where it was called from. This can be thought of as the return address of the function. By crafting a string that overwrites this return address with a different address, it is possible to hijack the program into running arbitrary code.

Our primary source, “Smashing the Stack for Fun and Profit,” illustrates one way to do this. The gist of the method is to include the assembly code you want to execute, in this case the command to spawn a shell, in the string you use to overflow the buffer. You then overwrite the return address of the stack frame with the address of the buffer itself. The entire elegant exploit is contained within the string. The article also explains ways to improve our chances of actually executing the code, such as padding the string with NOP commands.

We experimented a number of different exploit files, but they all work on the same concept: they create a shell script of a user-input length (padded with NOP commands) and save it to an environment variable called EGG. Theoretically, passing EGG as input to a vulnerable program will overflow a buffer. If EGG is the correct length, we then overwrite the return address of that stack frame and point back toward our shell script, which executes arbitrary code.

This principle did not work so cleanly when we went to implement it. 

#### Reflection

We actually hit a little bit lower than we were hoping for our minimum viable product. The exploits turned out to much less straightforward than we expected, and the time we would have spent on a third was sunk into attempting to understand our second. 

We did, however, satisfy our learning goals. We learned about a handful of specific exploits. We learned about precautions that our computer systems already have built in. And we certainly gained insight into both the structure of virtual memory and its interplay with assembly code.