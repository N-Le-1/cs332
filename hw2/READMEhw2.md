<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions

If you're a make file
```bash
make # this will compile all the files
make run # this will run all the files
```

If you're not using a make file
```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o hw2 hw2.c # this will compile hw2.c and output an executable called hw2
```

# My Files
## hw2.c

### main()

This function initializes the varibles used in the listFiles function, calls on listFiles and depending on the condition selected, the program will output the files listed in differnt ways. The function will iterate through the argument variable "argv[]" which will check for all the different parameters and flags set for each variable to what the user selects before calling the listFiles function. This also allows the user to enter in multiple different flags. For example, they can call both "-L" and "-v" to filter out files with a certain size and give more information for the files that are outputted. If there are no variables or flags, then they will all be 0 or NULL so the listFiles function does not call a parameter that does not need to be called.

### void listFiles(char *basePath, const int root, int depth, int size, char *pattern, int v)
This function has a return void type. However, the function will print out the list of files in various ways or with certain constraints.

This function takes in 6 variables. First variable is a pointer of basePath which is simply the directory that is being opened in the program. The second variable is the constant integer root which represents the root directory level that can not be changed since it is the base of the directory. The next variable is the integer depth which can be changed in order for the program to iterate and move through the file hierarchy. This is also used in the "-s" parameter to find certain files in a specific depth. The next variable is size which is mainly manipulated for the "-L" parameter. The size variable allows the program to only print out files that have a size larger than the size variable. The next variable is a string pointer called pattern, which is mainly used for the "-s" parameter. This variable allows the program to only print out files with a certain file type like only printing out .txt files. The last variable is an integer v which is a flag for the program that if v = 1, then the program will print out specific information about every file.

This function is able to travel through the file hieracrhy, print out the files, and filter through files through given conditions described above. The function begins with opening the directry, creating a structure pointer, and initialzing the string variable "path" where all the information being collected will be stored. I first created a base case that checks, if there is no directory, then print out: "Directory not found :(" and end the program. If the directory is presenet, the program will move into the recursive function that will continue to print out files until the directory is empty. The program uses "strcpy" and "strcat" to copy the given information and concatinate the information to the "path" variable which will be printed out. Towards the end of the loop, the program will check for if the parameters are active (-v, -s, -L) and have the necessary information provided with them. For example, Line 42 represents the "-s" parameter which checks if the pattern variable is not empty and if both the directory name and the pattern variable has the same string characters using the strstr() function. Line 45 represents the "-L" option which compares the size variable to a files size using the stats.st_size. The final parameter is the "-v" function which just checks if the flag is active. If it is, then the program will output more details for the files. If any of these parameters fails the condition, the program will skip the conditions and just print out the files and folders in a hierachry form. Once the while loop and recursive function ends, the program will close the directory. 


# Output screenshots
<put your screenshots here>

# References

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
I used this link to make a makefile for my project
