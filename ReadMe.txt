About:
A program that simulates some aspects of operating systems. There is no real system programming involved. The whole simulation is based on text inputs that the program receives from user.

Scheduling: There are 5 priority levels numbered from 0 to 4. 0 is the lowest priority and 4 is the highest. There are 5 levels in the ready-queue, one for each priority level. Within each level of the ready-queue the FCFS algorithm is used. A process from some level of the ready-queue can be scheduled only if all higher levels are empty. The scheduling is preemptive: When a higher priority process becomes available for execution the lower priority process is preemptied and sent to the end of its level of the ready queue.

Memory: simulates contiguous memory allocation with “First-Fit” approach.

Usage:

At the start, program asks the user three questions:
	How much RAM memory is there on the simulated computer? (in bytes up to 4 billions).
	How many hard disks the simulated computer has? (up to 10).
	How many printers the simulated computer has? (up to 10).

After these questions are answered, the simulation begins. The program constantly listens for the user inputs. The user inputs signal some system events. The program simulates the corresponding system behavior. 

The possible inputs are:
A priority size ‘A’ input means that a new process has been created. This process has the priority priority and needs size bytes of RAM memory. For example, the input A 2 2000000 means that a new process has arrived. This process has the priority of 2 and needs 2000000 bytes to operate.
When a new process arrives, your program should create its PCB and allocate memory for it. If there is no memory for this process your program should print an error message and refuse to create the new process.
Also, when a new process is created your program should send it to the ready-queue or allow it to use the CPU right away.
When choosing PID for a new process start from 1 and go up. Do NOT reuse PIDs of the terminated processes.
 
t   The process that currently uses the CPU terminates. It leaves the system immediately. Make sure you release the memory used by this process. If the process was positioned in RAM next to a hole, make sure its RAM is merged with the hole. In other words, make sure there are no adjacent holes.
 
d number    The process that currently uses the CPU requests the hard disk #number.
 
p number    The process that currently uses the CPU requests the printer #number.
 
D number   The hard disk #number has finished the work for one process.
 
P number    The printer #number has finished the work for one process.
 
S r     Shows what process is currently using the CPU and what processes are waiting to use the CPU on each level of the ready-queue. Processes on the same level of the ready-queue should be listed in the order in which they are positioned in the queue.
 
S i      Shows what processes are currently using the I/O devices and what processes are waiting to use them. For each busy device show the process that uses it and show its I/O-queue.
 
S m    Shows the state of memory. Display the range of addresses occupied by each process in the system.



Running the program:

To compile, run:
  $make

To run the program:
  $./os

To exit the program:
 Type “exit” or just kill it.

To remove executable:
  $make clean
