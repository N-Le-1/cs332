<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions

gcc -O -Wall <executable name> -lpthread # this will compile the filename and return an executable with the executable name

gcc -O -Wall pthread_sum.c -lpthread # this will compile pthread_sum.c and output an executable called a.out
```

# My Files
## pthread_sum.c

### main()

This function calculates the amount of threads in an element created using number of threads and number of elements. The main function creates the thread structure using 2 arguments in the terminal (argv). Then will use the "compute" function to calculate the final answer.


### void *compute(void *arg)
This function returns a void, but will calculate the amount of threads created during the program.

This function takes a voided thread argument 

The function computes the final sum of all the threads together by using the thread information given in by the structure created at the beginning of the program.

# Output screenshots
![image](https://github.com/N-Le-1/cs332/assets/156348689/c162dddb-8619-4238-851c-ed1cb6d4b515)

# References

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
I used this link to make a makefile for my project

# Github Repo.
https://github.com/N-Le-1/cs332
