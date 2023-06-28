# ByteShell

ByteShell is a simple Linux shell implementation written in C++. It provides a command-line interface where users can execute commands, navigate the file system, and perform basic shell operations.

## Description

A Linux shell is a command-line interface that allows users to interact with the operating system by executing commands. It acts as an intermediary between the user and the operating system, interpreting user input and executing the corresponding actions.

ByteShell aims to replicate the functionality of a basic Linux shell. It provides a set of commands that users can enter to perform tasks such as navigating the file system, displaying information, and terminating the shell. The `cd` command allows users to change directories, `echo` displays text on the shell, `pwd` prints the current working directory, and exit terminates the shell.

The shell also includes basic error handling to notify users if a command is not recognized or if a file or directory does not exist. Additionally, ByteShell provides a prompt to indicate that it is ready to accept user input.

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
