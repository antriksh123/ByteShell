# ByteShell

ByteShell is a simple Linux shell implementation written in C++. It provides a command-line interface where users can execute commands, navigate the file system, and perform basic shell operations.

## Description

ByteShell is designed to simulate a basic Linux shell environment. It supports various shell commands such as `cd` (change directory), `echo` (display text), `pwd` (print working directory), and `exit` commands. The shell also handles basic error handling and provides a prompt for user input.

## How to run the project

1. Clone the repository to your local machine.
2. Open a terminal and navigate to the project directory.
3. Compile the code using the command: `g++ -o shell shell.cpp`
4. Run the shell executable: `./shell`
5. The ByteShell prompt will appear, and you can start entering commands.

## Supported Commands

ByteShell supports the following commands:

- `cd ~`: Change to the user's home directory.
- `cd /`: Change to the root directory.
- `cd`: Change to the default directory (C:\Users\Antriksh in your implementation).
- `cd .`: Stay in the current directory.
- `cd ..`: Move up one directory.
- `cd ar`: Change to the directory named "ar" if it exists.
- `cd arg1/arg2`: Change to the subdirectory "arg2" within the directory "arg1".

- `echo abc`: Display "abc" on the shell.
- `echo -n abc`: Display "abc" on the shell without a trailing newline.
- `echo “abc”`: Display "abc" on the shell.
- `echo -E ab\c`: Display "ab\c" on the shell without interpreting backslashes.

- `pwd`: Print the current working directory.

- `exit`: Terminate the shell.

## Tech Stack Used

- C++
- Standard Library
- Linux Shell

## The working

ByteShell operates in the following manner:

- Change directory (`cd`) command: Allows users to navigate the file system.
- Echo (`echo`) command: Displays text on the shell.
- Print working directory (`pwd`) command: Prints the current working directory.
- Basic error handling: Displays appropriate error messages for invalid commands or file/directory not found.
- Command prompt: Provides a user-friendly prompt for entering commands.

## Key Takeaways

ByteShell provides a starting point for understanding how a basic shell works. It demonstrates concepts such as parsing user input, executing commands, and interacting with the file system. The project can be extended to include more advanced shell features and functionalities.

## References

- [Hackernoon - Let's Build a Linux Shell (Part I)](https://hackernoon.com/lets-build-a-linux-shell-part-i-bz3n3vg1)
- [GeeksforGeeks - Introduction to Linux Shell and Shell Scripting](https://www.geeksforgeeks.org/introduction-linux-shell-shell-scripting/)
- [CodeWithHarry - YouTube Channel](https://www.youtube.com/@CodeWithHarry)
- [GNU Bash Manual - Bourne Shell Builtins](https://www.gnu.org/software/bash/manual/html_node/Bourne-Shell-Builtins.html)
