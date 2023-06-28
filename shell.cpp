#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>
#include <fcntl.h>
#include "path.cpp"
#include "prompt.cpp"
using namespace std;

#define DELIMITER " \n\t\r"
char st[1024][1024];
int idx;

void execute_cd(char **tokens)
{
    if (tokens[1] != nullptr && strcmp(tokens[1], "~") == 0)
    {
        chdir("C:\\Users\\Antriksh");
    }
    else if (tokens[1] != nullptr && strcmp(tokens[1], "/") == 0)
    {
        chdir("/");
    }
    else if (tokens[1] == nullptr)
    {
        chdir("C:\\Users\\Antriksh");
    }
    else if (strcmp(tokens[1], "..") == 0)
        chdir(tokens[1]);
    else
    {
        struct stat buf;
        stat(("%s/%s", path(), tokens[1]), &buf);

        if (chdir(tokens[1]) == 0)
            chdir(tokens[1]);
        else if (chdir(tokens[1]) == -1)
        {
            if (S_ISREG(buf.st_mode))
            {
                cout << tokens[1] << ": Not a directory" << endl;
            }
            else
            {
                cout << tokens[1] << ": No such file or directory present" << endl;
            }
        }
    }
}

void execute_exit()
{
    exit(1);
}

int helper_echo(char **tokens)
{
    int k;
    if (tokens[1] != nullptr && strcmp(tokens[1], "-n") == 0)
    {
        k = 2;
    }
    else
        k = 1;
    if (tokens[1] != nullptr && strcmp(tokens[1], "-E") == 0)
    {
        k = 2;
    }
    int count1 = 0;
    int idx1 = 0;
    if (idx != 0)
        k = 0;
    while (tokens[k] != nullptr)
    {
        idx1 = 0;
        for (int t = 0; t < strlen(tokens[k]); t++)
        {
            if (((tokens[k])[t]) != '"')
            {
                st[idx][idx1] = tokens[k][t];
                idx1++;
            }
            else
            {
                count1 += 1;
            }
        }
        st[idx][idx1] = '\0';

        idx++;
        k++;
    }

    return count1;
}

void execute_echo(char **tokens)
{
    idx = 0;
    int count = helper_echo(tokens);

    if (count % 2 != 0)
    {
        char inst[1024];

        while (count % 2 != 0)
        {
            cout << '>';
            cin.getline(inst, 1024);
            char *ptr;

            if ((ptr = strchr(inst, '\n')) != nullptr)
            {
                *ptr = '\0';
            }

            int m = 0;
            char **arr = new char *[1024];
            char *c = strtok(inst, DELIMITER);
            arr[m] = c;
            m++;

            while (c != nullptr)
            {
                c = strtok(nullptr, DELIMITER);
                arr[m] = c;
                m++;
            }

            arr[m] = nullptr;
            st[idx][0] = '\n';
            idx++;
            count += helper_echo(arr);
            delete[] arr;
        }
    }
    for (int y = 0; y < idx; y++)
    {
        if (st[y][0] != '\n')
        {
            cout << st[y] << ' ';
        }
        else
        {
            cout << st[y];
        }
        memset(st[y], '\0', strlen(st[y]));
    }

    if (strcmp(tokens[1], "-n") != 0)
    {
        cout << endl;
    }
}

void execute_pwd()
{
    char directory[1024];

    if (getcwd(directory, sizeof(directory)) == nullptr)
    {
        perror("Error ");
    }
    else
    {
        cout << directory << endl;
    }
}

int main(int argc, char const *argv[])
{
    char cmd[1024];
    int i;
    int flag = 0;
    cout << "****Welcome to Byteshell****" << endl;
    while (true)
    {
        print_prompt1();
        cin.getline(cmd, 1024);
        if (strcmp(cmd, "\n") == 0)
        {
            continue;
        }
        char *pointer;
        if ((pointer = strchr(cmd, '\n')) != nullptr)
        {
            *pointer = '\0';
        }

        int i = 0;
        char **tokens = new char *[1024];
        char *ch = strtok(cmd, DELIMITER);
        tokens[i] = ch;
        i++;

        while (ch != nullptr)
        {
            ch = strtok(nullptr, DELIMITER);
            tokens[i] = ch;
            i++;
        }

        tokens[i] = nullptr;

        if (strcmp(tokens[0], "cd") == 0)
        {
            execute_cd(tokens);
        }
        else if (strcmp(tokens[0], "exit") == 0)
        {
            execute_exit();
        }
        else if (strcmp(tokens[0], "echo") == 0)
        {
            execute_echo(tokens);
        }
        else if (strcmp(tokens[0], "pwd") == 0)
        {
            execute_pwd();
        }
        else
        {
            cout << tokens[0] << ": command not found" << endl;
            exit(1);
        }

        delete[] tokens;
    }

    return 0;
}
