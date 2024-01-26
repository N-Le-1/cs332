<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions

```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o lab3 lab3.c # this will compile lab3.c and output an executable called lab3
```

# My Files
## lab3.c

### main()

This function calls on 3 helper functions that will read the strings, use insertion sort to sort the strings, and display the sorted strings.

## lab3.h

### readString(char ***arr, int *size)
This function creates the array of strings used in the next two functions and the size of the array.

This function takes in a pointer for the array of strings and the pointer for the size of the array.

Using the scanf function, the program will ask the user how many elements will be in the string in order to generate the size of the array
to mallocate and save the memory. The program will then ask the users to enter their strings (with spaces between) and loop through the strings as many times as the size of the array. Using the strdup function, this will copy the string into the array due to the char* pointer being in said position.

### insertionSort(char **arr, int size)
This function alphabetically sorts out an array of strings 

This function takes in a string array and an integer which is the size of the same array.

The function uses both a for loop and while loop that iterates through the array and compares each index in the array to sort out alphabetically. Insertion sort uses a 2 pointer method that compares each string in the array with. The for loop allows the program to iterate through the whole array while the while loop is able to go through the array and compare the string associated with the iterator pointer to the rest of the strings in the array.

### displayString(char **arr, int size)
This function prints out the sorted array of strings

This function takes in a string array and an integer which is the size of the same array.

This function is a simple for loop that iterates through the sorted array and prints out every element in the array which will be an alphabetical sorted array.
# Output screenshots
![image](https://github.com/N-Le-1/cs332/assets/156348689/fc2653cd-4aee-4b41-aaba-d64a918c8d14)

# References

"Lab Assignment #3" on Canvas
I used the given function and examples in the assignment pdfs and given files like insertionSort.

# Git Repo
https://github.com/N-Le-1/cs332
