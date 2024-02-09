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
This function returns a double

This function takes an integer as a parameter

It creates a struct of a timeval object then gets the time of day and returns it

# Output screenshots
<put your screenshots here>

# References

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
I used this link to make a makefile for my project
