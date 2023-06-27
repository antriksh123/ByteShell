#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include "shell.h"
using namespace std;

char *read_cmd(void)
{
    const int bufferSize = 1024;
    char buf[bufferSize];
    char* ptr = nullptr;
    int ptrlen = 0;

    while (fgets(buf, bufferSize, stdin))
    {
        int buflen = strlen(buf);

        if (!ptr)
        {
            ptr = new char[buflen + 1];
        }
        else
        {
            char* ptr2 = new char[ptrlen + buflen + 1];
            memcpy(ptr2, ptr, ptrlen);
            delete[] ptr;

            ptr = ptr2;
        }

        if (!ptr)
        {
            cerr << "error: failed to allocate buffer\n";
            return nullptr;
        }

        strcpy(ptr + ptrlen, buf);

        if (buf[buflen - 1] == '\n')
        {
            if (buflen == 1 || buf[buflen - 2] != '\\')
            {
                return ptr;
            }

            ptr[ptrlen + buflen - 2] = '\0';
            buflen -= 2;
            print_prompt2(); 
        }

        ptrlen += buflen;
    }

    return ptr;
}

int main(){
    string cmd;
    bool exitFlag = false;
    do
    {
        print_prompt1();

        char* input = read_cmd();
        if (!input)
        {
            continue;
        }

        cmd = input;

        delete[] input;

        if (cmd.empty())
        {
            continue;
        }

        if (cmd == "exit\n")
        {
            exitFlag = true;
        }
        if(!exitFlag)
            cout << cmd << endl;

    } while (!exitFlag);

    return 0;
}