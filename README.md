# push_swap
### Score 112/100
##### Mandatory
100/100
##### Bonus
19/25
***
### Challenge
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you'll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.
  
***
### The aim
I chose non-recursive quick-sort algorithm to sort one stack by use of another stack.

The aim of push_swap is to sort a stack of numbers using another stack in the least commands possible. The educational aim of the project was to introduce students to advanced sorting algorithms and the concept of complexity. This project earned maximum available marks for the algortihm's efficacy.

#### Commands explanation
The stacks can be rotated, have their top two elements swapped, or be pushed onto each other, the full command list is as follows:

##### Rotating commands:
```
RA - rotate stack A (send top number on stack to bottom)
RB - rotate stack B (send top number on stack to bottom)
RR - rotate both stack A and B at the same time
RRA - counter-rotate stack A (send bottom number of stack to top)
RRB - counter-rotate stack B (send bottom number of stack to top)
RRR - counter-rotate stack A and stack B at the same time
```
##### Swapping commands:
```
SA - swap top two numbers at top of stack A
SB - swap top two numbers at top of stack B
```
##### Pushing commands:
```
PA - push top element from stack A onto stack B
PB - push stack B
```
###  How to run
```console
git clone https://github.com/Severno/push_swap
cd push_swap
make

If you want run push_swap:
Arg=`Ruby -E "Puts (0..100).To_a.Shuffle.Join(' ')"`; ./Push_swap $Arg;

If you want run checker:
Arg=`Ruby -E "Puts (0..100).To_a.Shuffle.Join(' ')"`; ./Push_swap $Arg | ./checker $ARG
```
### The algortihm

While the aim of the project was to introduce students to complexity, the project did not actually favour algorithms with lowest complexity. Given that highest marks were achieved by using the least amount of commands, slower algorithms that read the data more times could be more precise than algortihms optimised for speed or least passes over the numbers. For this reason, computationally slower processes like **finding the true median for each split in quick sort achieved better results**.

In my implementation, I repeatedy split stack A around the true median, putting the lower numbers onto stack B, and maintaining the higher numbers in stack A. Partitions were recorded in stack B each time this process occurred as so:

##### Start
```
Stack A:
1
7 (median = 7)
25
4
9
3
2
11
10
Stack B:
```
##### First split:
```
Stack A: 
11(median = 11)
10
25
9
Stack B: 
2
3
4
7
1
```
Here is the moment. If there are 4 or 5 elements left in our **Stack A**, we move only the smallest ones until we have 3 elements left in **Stack A**
##### Second split:
```
Stack A:
11
10
25
Stack B:
9
2
3
4
7
1
```
Here we have 2 partition:
```
9
```
and
```
2
3
4
7
1
```
Once **Stack A** was reduced to three or less numbers, it was sorted. **Stack B** would then find the median of the numbers up until the last partition in **Stack B**(search until element - **2**), and push the higher values onto** Stack A **until it reached the next partition in **Stack B**.

If three or less numbers were pushed back on to **Stack A**, these numbers would be sorted using the swap and rotate commands, and a partition would be marked at the end of stack A too, signalling that stack A is sorted until this point. **Stack B** would then push onto **A**again as above.

If more than three numbers were pushed from **B** to **A**, **Stack A** would then repeat the process at beginning, repeatedly splitting around a median of all the numbers after the last partition in A, maintaining the higher values and pushing the lower values onto B.

The whole above process would be repeated until **Stack A** was sorted.

While many projects implemented a similar algortihm recursively, I employed a faster and less computationally expensive method by computing the problem iteratively. Two additional stacks kept a record of the position of the partitions, and allowed the algorithm to know when to stop pushing onto stack B or stack A, and from which point to calculate the medians. I based this implementation on an idea I read about here.

### Learnings
I used doubly linked lists and got a solid knowledge of adding, deleting, inserting, and sorting lists.

I learnt about complexity and (O)n notation.

I studied all major sorting algorithms in order to pick the one I felt best fit the task. It was very interesting to get my head around how they working recursively, and particularly enjoyable to then try and figure out how one could dissect the algorithm to perform it iteratively.

Thats it.
### HAVE FUN :))
