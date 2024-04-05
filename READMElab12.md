<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions
```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o lab12 lab12.c # this will compile lab12.c and output an executable called lab12
```

# My Files
## lab12.c

### main()

The program takes in UNIX commands and executes them using popen and pclose. The program will prompt the user to enter their desired commands into the terminal and when they are finished, the can type in "quit" and the program will end. The main function takes in no parameters and a return integer type which will end the program.

Using a while loop, the program constantly asks the user to enter a command and using fgets and strcmp, the program will read what the user wants to execute. The program will execute commands using pipes (popen and pclose) and loops to loop through the directory.


# Output screenshots
![image](https://github.com/N-Le-1/cs332/assets/156348689/6a3cedfd-c398-4c13-8fcd-aa3904e9ab12)


# References

I used the Lab12 workbook given in the Lab 12 assignment

Also used the following link to remove the new line charcter from fgets:

https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input

# Github Repo.

https://github.com/N-Le-1/cs332
