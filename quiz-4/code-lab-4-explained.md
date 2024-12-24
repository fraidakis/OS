[comment]: # (Open the file with Visual Studio Code and press Ctrl + Shift + V)


# Lab 04 - Operating Systems Signal Handling and Process Management

## Compile and run code

Compile all source files using the following command: 
```bash
    make all
```

Run a program using the following command eg for example1.c: 

```bash
    ./example1
```

## Example1

This program demonstrates process creation and execution of a new program in the child process.

### Example Usage and Output


#### Usage 

```bash
    ./example1
```


#### Example Output

```bash
Parent Process: PID = 3260116, Created Child PID = 3260117
Child Process: PID = 3260117, Parent PID = 3260116
total 128
-rwxrwxr-x 1 fraidaki fraidaki 19896 Dec 24 20:03 example1
-rw-rw-r-- 1 fraidaki fraidaki   855 Dec 24 17:49 example1.c
-rwxrwxr-x 1 fraidaki fraidaki 19568 Dec 24 20:03 example2
-rw-rw-r-- 1 fraidaki fraidaki   347 Dec 24 17:49 example2.c
-rwxrwxr-x 1 fraidaki fraidaki 19912 Dec 24 20:03 example3
-rw-rw-r-- 1 fraidaki fraidaki   643 Dec 24 18:59 example3.c
-rwxrwxr-x 1 fraidaki fraidaki 19912 Dec 24 20:03 example4
-rw-rw-r-- 1 fraidaki fraidaki   670 Dec 24 17:49 example4.c
-rwxrwxr-x 1 fraidaki fraidaki 20240 Dec 24 20:03 example5
-rw-rw-r-- 1 fraidaki fraidaki  1622 Dec 24 17:49 example5.c
-rw-rw-r-- 1 fraidaki fraidaki  1583 Dec 24 17:49 lab04.tar.gz
-rw-rw-r-- 1 fraidaki fraidaki   564 Dec 24 17:49 Makefile
Parent Process: Child has terminated.
```


### Explanation of the Code

fork(): Creates a new process (if not successful return 1)

Then follow a path according to pid : 
pid == 0 -> Child process path.
pid > 0 -> Parent process path.

execlp(...): Executes the "ls -l" bash command and if successful, the child will display current directory contents

wait(NULL): Parent process waits for the child to finish before returning.


## Example 2

This program is useful for understanding process hierarchies and how parent-child relationships work in Unix-like operating systems.

### Example Usage and Output


#### Usage 

```bash
    ./example2
```


#### Example Output

```bash
Current Process ID (PID): 3261000
Parent Process ID (PPID): 3256320
```

### Explanation of the Code

getpid(): Returns the process ID of the program running. 

getppid(): Returns the process ID of the parent of the current program.


## Example 3

This program demonstrates basic signal handling in C, allowing processes to handle interrupts in a controlled way.

### Example Usage and Output


#### Usage 

```bash
    ./example3
```


#### Example Output

```bash
Process ID: 3261436
Press Ctrl+C to trigger SIGINT.
Running... Press Ctrl+C to exit.
Running... Press Ctrl+C to exit.
^C
Caught signal 2 (SIGINT). Exiting gracefully...
```

### Explanation of the Code

signal(SIGINT, sigint_handler): Register the SIGINT handler which will intercept SIGINT signals.

sigint_handler: Prints the number of the signal and exits gracefully using exit(0).

while (1) loop: Terminates only if user presses Ctrl+C.


## Example 4

This program demonstrates how to intercept and ignore signals, such as SIGINT, effectively disabling Ctrl+C termination.

### Example Usage and Output


#### Usage 

```bash
    ./example4
```

#### Example Output

```bash
Process ID: 3261761
Press Ctrl+C to attempt to send SIGINT.
Running... Try pressing Ctrl+C.
Running... Try pressing Ctrl+C.
^C
Received SIGINT (signal 2), but ignoring it.
Running... Try pressing Ctrl+C.
^C
Running... Try pressing Ctrl+C.
^Z
[1]+  Stopped                 ./example4
```

### Explanation of the Code

signal(SIGINT, sigint_handler): Register the SIGINT handler which will catch SIGINT signals.

sigint_handler: Prints the number of the signal received and ignores it.

while(1) loop: No termination condition.

sleep(2): Print a message that program is still running every 2 seconds


## Example 5

This program demonstrates signal communication between parent and child processes, a fundamental concept in inter-process communication.

### Example Usage and Output


#### Usage 

```bash
    ./example5
```


#### Example Output

```bash
Parent process ID: 3262266. Child PID: 3262267
Child process ID: 3262267. Waiting for SIGUSR1...
Parent sending SIGUSR1 to child.
Child received SIGUSR1 (signal 10).
Parent sending SIGTERM to child.
Child process terminated.
```

### Explanation of the Code

#### Parent Process

Creates a child process using fork().

Waits 3 seconds and then sends SIGUSR1 to the child process using kill().

Waits 1 second and then sends SIGTERM to terminate the child process.

Waits for the child process to terminate using wait(NULL) and then return.

#### Child Process

Registers a signal handler (sigusr1_handler) which will catch SIGUSR1 signals.

Enters an infinite loop using pause() to wait for signals.

Display a message when receiving SIGUSR1

Terminates upon receiving SIGTERM.

