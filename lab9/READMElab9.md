<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions
```bash
gcc -Wall <filename> # this will compile the filename and return an executable with the executable name

gcc -Wall forkexecvp.c # this will compile forkexecvp.c and output an executable called a.out
```

# My Files
## forkexecvp.c

### main()

This function creates parent and child processes and will detect signals coming from the keyboard. Depending on the signals receieved, the program will do specific things.

### signalHandler (int signum)
This function has a void return type

This function takes an integer as a parameter which represenets the signal integer 

This function will take in the signal integers and depending what integer is taken in, the program will execute a certain signal. If the program recieves "Ctrl-C" the program will interupt the child process. If the program recieves "Ctrl-Z", the child process will be suspended. If the program recieves "Ctrl-\" the program will quit the parent process.

# Output screenshots
![image](https://github.com/N-Le-1/cs332/assets/156348689/89726051-581f-4549-995f-5fda4242be54)
![image](https://github.com/N-Le-1/cs332/assets/156348689/fd33b3ac-63ed-4f17-b227-0d25fc338c15)
![image](https://github.com/N-Le-1/cs332/assets/156348689/c0f15027-3cea-4f1c-8ff0-8e829e6a7323)


# References
https://www.geeksforgeeks.org/sleep-function-in-c/
I used this link to pause the program for me to execute my signals.

# GitHub Repo
https://github.com/N-Le-1/cs332
