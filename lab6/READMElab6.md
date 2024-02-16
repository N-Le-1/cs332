<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions

```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o lab6 lab6.c # this will compile lab6.c and output an executable called lab6
```

# My Files
## lab6.c

### main()

This function reads a .csv file called "listings" and will sort the listings by host name and price and will write the new sorted list in seperate files called: "sortedByHostName" and "sortedByPrice". 

### gettime(int x)
This function returns a double

This function takes an integer as a parameter

It creates a struct of a timeval object then gets the time of day and returns it

# Output screenshots
<put your screenshots here>

# References

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
I used this link to make a makefile for my project
