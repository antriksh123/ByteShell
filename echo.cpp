#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

void echoCommand(const vector<string> &tokens)
{
    char nline = 1, lcase = 0, esc = 1, num[4];
    int c, g;

    for (const auto &arg : tokens)
    {
        if (strcmp(arg.c_str(), "--help") == 0)
        {
            puts("\nusage: echo [options] [message] ...\n\n"
                 "--            echo a dash in the place this option is given\n"
                 "-e            enable escape codes (default)\n"
                 "-E            disable escape codes\n"
                 "-n            do not print a newline before exiting\n"
                 "--help        display this help message\n"
                 "--version     display version information\n");
            puts("message       any message (also see \"escape codes\" below)\n\n"
                 "Escape codes:\n\n"
                 "\t\\a\t\t sound an alert\n"
                 "\t\\b\t\t backspace\n"
                 "\t\\c\t\t do not print newline afterwards\n"
                 "\t\\f\t\t form feed\n"
                 "\t\\l\t\t until another \\l is given, print in lowercase\n"
                 "\t\\n\t\t newline\n"
                 "\t\\r\t\t carriage return\n"
                 "\t\\t\t\t tab\n"
                 "\t\\u\t\t until another \\u is given, print in uppercase\n"
                 "\t\\v\t\t vertical tab\n"
                 "\t\\\\\t\t literal backslash\n"
                 "\t\\xxx\t\t output ASCII char encoded xxx\n");
            exit(0);
        }
        else if (strcmp(arg.c_str(), "--version") == 0)
        {
            puts("\necho 1.0 " __DATE__ " " __TIME__);
            return;
        }

        for (size_t i = 0; i < arg.size(); i++)
        {
            switch (arg[i])
            {
            case '\\':
                if (!esc)
                {
                    putchar(arg[i]);
                    continue;
                }

                switch (arg[++i])
                {
                case 'a':
                    putchar('\a');
                    break;
                case 'b':
                    putchar('\b');
                    break;
                case 'c':
                    nline = 0;
                    break;
                case 'f':
                    putchar('\f');
                    break;
                case 'l':
                    if (lcase == 1)
                        lcase = 0;
                    else
                        lcase = 1;
                    break;
                case 'n':
                    putchar('\n');
                    break;
                case 'r':
                    putchar('\r');
                    break;
                case 't':
                    putchar('\t');
                    break;
                case 'u':
                    if (lcase == 2)
                        lcase = 0;
                    else
                        lcase = 2;
                    break;
                case 'v':
                    putchar('\v');
                    break;
                case '\\':
                    putchar('\\');
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    num[0] = '\\';
                    num[1] = arg[i];
                    num[2] = arg[++i];
                    num[3] = arg[++i];
                    printf("%s", num);
                    break;
                default:
                    printf("\necho: unknown escape code \"\\%c\"", arg[i]);
                    return;
                }
                break;
            case '-':
                switch (arg[++i])
                {
                case 'e':
                    esc = 1;
                    break;
                case 'E':
                    esc = 0;
                    break;
                case 'n':
                    nline = 0;
                    break;
                case '-':
                    putchar('-');
                    break;
                default:
                    printf("\necho: unknown option \"-%c\"", arg[i]);
                    return;
                }
                i += 2;
                break;
            default:
                if (!lcase)
                    putchar(arg[i]);
                else if (lcase)
                    putchar(tolower(arg[i]));
                else
                    putchar(toupper(arg[i]));
                break;
            }
        }
    }

    if (nline)
        putchar('\n');
}
