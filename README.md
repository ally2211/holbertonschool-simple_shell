
# Write a C - Simple Shell

There will be two modes that this simple shell can be run: (1) interactive mode where a prompt is given for the user to enter single commands (2) non-interactive mode where the arguments are piped at run time.

The approach we took after taking time to understand the requirements and going over the section:  Everything you need to know to start coding your own shell was 4-fold.



## Table of Contents

- Section 1:  Flowcharting and README
- Section 2:  Process flow
- Section 3:  Tokenization and handling of Built-In Functions
- Section 4:  Handling of Environment PATH tokens


## Section 1:  Flowcharting

Flowcharting and writing this README.md file.

( not sure if there is a way to add a flowchart here)


## Section 2:  Process flow

Writing the Main.c to accomplish:
-  Determine if the shell is being run in interactive or non-interactive mode.  Utilize the isatty() function.

-  Have a loop that forks a child process and have the parent wait for the child to complete by using the pid and ppid process id's.
  
## Section 3:  Tokenization and handling of Built-In Functions

Regarldess of which mode it is being run, the child process will need to accomplish:
- if it is interactive mode, use execve to determine if the process can be run.
- otherwise tokenize with delimeters such as a space or \n.
-  create a structure with built-in functions such as exit, env.
- determine if any of the token are built-in and if so run it.

## Section 4:  Handling of Environment PATH tokens

The last part of theis flowchart, if the token is not a built-in function, then:  
- get the environment variable Path and tokenize it with delimeter of a colon ':'.  - Then try using each path option to and see if it is a valid path for the process to run by :
 - first concatenating a '/' at the end of each path
 - and taking the first token and adding it  to the end of each path to execve it.

![flowchart_1](https://github.com/ally2211/holbertonschool-simple_shell/assets/131308234/ecfeea50-e635-4231-977a-3dde73d1e288)
