<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions

```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o readdir readdir.c # this will compile readdir.c and output an executable called readdir
```

# My Files
## readdir.c

### main(int argc, char **argv)

This function calls on listFiles to recursively iterate through a directory and list the files and directories. The recursive function comes into play when the program finds a new directory. If the program finds a new directory, the program will call listFiles and list the files in the new directory before moving on to the next file/directory.


### listFiles(const char* basePath)
This function has a void return type, but will print out files and directories when given a base directory.

This function takes a constant string (the given directory) as a parameter which allows the program to use this function recursively.

This function recursively iterates through a directory and prints out the file name alongside a statement that declares if it is a file or a directory. When iterating through the first directory given, the program will print out the files. However, when printing out the files, if the program finds a new directory, the program will call listFiles again for the new directory found in order to print out the files in the new directory found.

# Output screenshots
![image](https://github.com/N-Le-1/cs332/assets/156348689/d592d972-590e-4e49-85ba-9d6de5647927)


# References

I used the given files and lab workbook in the Lab 5 assignment on Canvas. I also used some of the lecture slides to refer back to when using different libraries and functions.

# Github Repo.

https://github.com/N-Le-1/cs332
