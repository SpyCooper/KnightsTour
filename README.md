# Knight's Tour
This is my implementation of the knight's tour project from our class. The main point of this was to teach us backtracking in recursive functions.

This code will go through and print out all possible combinations of moves the knight can make for every possible board from each board without repeating a square.
It starts at whatever position is entered in the command line. Ex "./a.exe 3 3" will start the knight's first position at 3,3. 

The program will print out all the possible boards with each movement order as well as how many tours were found (tours meaning the different set of movements).

A sample input and sample outputs that were provided to us to use as a test have been included in the testcases folder.

## Knight's Tour Explaination
The knight's tour basic summary is that on a board, in this case it's a 5 x 5 board, you want a knight from chess to be move and touch every square on the board without touching a square more than once.

There are more than 1 set of move combinations that can achieve this, which is why the code prints out all the possible combinations of moves.

# To run the program
To compile the code, you need to run the makefile. To run the program, you need to "./a.exe 3 3" (or the command in the input1.dat in the testcases folder) to check it with the output of the test case.
