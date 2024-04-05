<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions

If you're a make file
```bash
make # this will compile all the files
```

If you're not using a make file
```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o hw4 hw4.c # this will compile hw4.c and output an executable called hw4
```

# My Files
## hw4.c

### main()

This function prompts the user to create jobs, show jobs, or exit the program using a while loop and helper functions. 

### void submit_jobs(char *command)
This function returns a void type 

This function takes a string pointer to the "command" variable.

This function creates jobs and submits them to the job list. The function will first check if the job list has reached the maximum number of jobs avaliable. If so, the function will send an error and if not, the function will fork and create a process to continue to add the job. The function continues and if the process is a child, then the program uses "sprintf" to store the values in the job and "freopen" to redirect the files. If the process is a parent, the program will change the status of the job to running and add it to the jobs list using strcpy to the global string variable "jobs" to later list out the jobs. Once the parent process is completed, the program send a message into the terminal to confirm that the job as been created and submitted.

### void show_jobs()

This function returns a void type

This function takes in no parameters

This function uses a for loop to iterate through the number of jobs that have been submitted and will show the user the jobs that are completed and the jobs that are waiting to be completed. The function uses if statements to check if a job is submitted or if it is waiting to be completed. Once the function iterates through one job, the function subtracts 1 from the number of jobs and i to iterate through the index of jobs and to prevent an infinite loop.


# Output screenshots
![image](https://github.com/N-Le-1/cs332/assets/156348689/d3e0447f-61b1-42dd-85a2-92efa7f95b16)

# References
I used the lecture slides and lab workbooks to understand processes and functions

I used the links below to help learn how to use some functions:

https://www.bing.com/search?q=execlp+function&qs=n&form=QBRE&sp=-1&ghc=1&lq=0&pq=execlp+function&sc=8-15&sk=&cvid=8145BE8B903B4B479790D24BFDB99E03&ghsh=0&ghacc=0&ghpl=

https://stackoverflow.com/questions/21648342/freopen-or-freopen-s-what-exactly-are-they-doing

https://www.geeksforgeeks.org/sprintf-in-c/

https://stackoverflow.com/questions/8657702/what-do-t-and-b-do  (used the table to learn character commands)

# Github Repo.

