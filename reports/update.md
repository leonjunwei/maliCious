## maliCious

#### Leon Lam and Sean Foley

We intend to create three C programs which, when run, do various horrific things to the computer they are running on. We would also like to explain the exploits. Finally, we'd like to explore countermeasures; that's our stretch goal.

From this, we hope to learn about the underlying architecture of the 
operating system and how programs interact with it. We also hope to 
instill (both in ourselves and whoever else sees this) a healthy 
suspicion of executable files whose contents are unknown.

We did some research and talked with a friend taking computer security at Wellesley. This led us to implement two exploits. The first simply overwhelms the virtual memory by repeatedly calling malloc, and the second executes arbitrary code by overwriting a buffer and pointing the return address of the stack frame toward a small shell script. We learned about the second exploit from a paper called "Smashing the Stack."

We currently have four outstanding tasks, which we're both working on in tandem:

- Better understanding our second exploit; we could always understand the code a little better, but we'll be satisfied with this task when we can explain it concisely to someone with general SoftSys knowledge who has not seen this particular exploit before.
- Researching and implementing a third exploit; we'll know this is done when our third exploit works.
- Considering countermeasures; we'll know this is done when we have at least one functioning countermeasure.
- Writing explanations for our exploits; we'll know this is done when we have a brief report on it.
  ​
