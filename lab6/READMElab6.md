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

This function reads a .csv file called "listings" and will sort the listings by host name and price using the qsort function and will write the new sorted list in seperate files called: "sortedByHostName" and "sortedByPrice". 

### int compareHostName(const void *x, const void *y)
This function returns an integer 

This function takes in 2 constant pointers 

It will iterate and compare each host name in the listings.csv for the qsort function in "main" 

### int comparePrice(const void *x, const void *y)
This function returns an integer

This function takes in 2 constant pointers

It will iterate and compare the price in the listings.csv for the qsort function in "main"

# Output screenshots
## OUTPUTS 2 .CSV FILES:

### SORTED BY HOST NAME 
![image](https://github.com/N-Le-1/cs332/assets/156348689/fc19b486-27ac-416e-869c-3d1bab2ec855)


### SORTED BY PRICE
![image](https://github.com/N-Le-1/cs332/assets/156348689/15e147d4-fdf2-40e5-ba90-59dc7b750427)


# References

I used the given Lab Materials in the Lab 6 Assignment 

I also used the link below to learn and use the qsort function in C
https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm

#GitHub Repo
https://github.com/N-Le-1/cs332
