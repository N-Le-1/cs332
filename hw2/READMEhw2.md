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

This function calls on listFiles and depending on the condition selected, the program will output the files listed in differnt ways.

### void listFiles(char *basePath, const int root, int depth, int size, char *pattern, int v)
This function has a return void type. However, the function will print out the list of files in various ways or with certain constraints.

This function takes in 6 variables. First variable is a pointer of basePath which is simply the directory that is being opened in the program. The second variable is the constant integer root which represents the root directory level that can not be changed since it is the base of the directory. The next variable is the integer depth which can be changed in order for the program to iterate and move through the file hierarchy. This is also used in the "-s" parameter to find certain files in a specific depth. The next variable is size which is mainly manipulated for the "-L" parameter. The size variable allows the program to only print out files that have a size larger than the size variable. The next variable is a string pointer called pattern, which is mainly used for the "-s" parameter. This variable allows the program to only print out files with a certain file type like only printing out .txt files. The last variable is an integer v which is a flag for the program that if v = 1, then the program will print out specific information about every file.

It creates a struct of a timeval object then gets the time of day and returns it

# Output screenshots
<put your screenshots here>

# References

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
I used this link to make a makefile for my project
