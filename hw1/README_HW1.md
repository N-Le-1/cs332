<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions
If you're not using a make file
```bash
gcc -o <executable name> <filename> -lm # this will compile the filename and return an executable with the executable name

gcc -o hw1 hw1.c -lm # this will compile hw1.c and output an executable called hw1
```

# My Files
## hw1.c

### main()

This function calls on all 5 different functions in the homework. Only 1 out of the 5 questions ask for user input(Question 2).

## HW1 Functions:

### numberTransformer(int n)
This function prints out a different string depending on the different conditions of the number.

This function takes an integer as a parameter

This function uses the helps of 3 other functions that include:
  - a function checking if the int is prime or not.
  - a function that generates the closest prime number below the given int.
  - a function that adds the sum of the integers in a number. ex.(123 = (1+2+3 = 6).
The function will first check if the given int is a prime number and not 3 or 5. If this is true, then the program will output: "Go Blazers". If one of the conditions is false, the program will go to the next condition and check if the int is divisble by both 5 and 3. If so, the output will be "UAB CS 332&532". If this condition fails, the next condition will take the given int and use the help of one of the functions I created to generate the sum of the digitis in the given int and check if it is divisible by 3. If so, the program will output, "CS".

### UABNumber()
This function returns a double

This function takes an integer as a parameter

It creates a struct of a timeval object then gets the time of day and returns it

### reverseNum(int n3)
This function returns a double

This function takes an integer as a parameter

It creates a struct of a timeval object then gets the time of day and returns it

### smallerThanIndex()
This function returns a double

This function takes an integer as a parameter

It creates a struct of a timeval object then gets the time of day and returns it

### arrayDetails()
This function returns a double

This function takes an integer as a parameter

It creates a struct of a timeval object then gets the time of day and returns it

# Output screenshots
<put your screenshots here>

# References

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
I used this link to make a makefile for my project
