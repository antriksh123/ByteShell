#include <stdio.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void usage()
{
    cout << "\nusage: echo [options] [message] ...\n\n"
              << "--            echo a dash in the place this option is given\n"
              << "-e            enable escape codes (default)\n"
              << "-E            disable escape codes\n"
              << "-n            do not print a newline before exiting\n"
              << "--help        display this help message\n"
              << "--version     display version information\n" << endl;

    cout << "message       any message (also see \"escape codes\" below)\n\n"
              << "Escape codes:\n\n"
              << "\t\\a\t\t sound an alert\n"
              << "\t\\b\t\t backspace\n"
              << "\t\\c\t\t do not print newline afterwards\n"
              << "\t\\f\t\t form feed\n"
              << "\t\\l\t\t until another \\l is given, print in lowercase\n"
              << "\t\\n\t\t newline\n"
              << "\t\\r\t\t carriage return\n"
              << "\t\\t\t\t tab\n"
              << "\t\\u\t\t until another \\u is given, print in uppercase\n"
              << "\t\\v\t\t vertical tab\n"
              << "\t\\\\\t\t literal backslash\n"
              << "\t\\xxx\t\t output ASCII char encoded xxx\n" << endl;

    return;
}

bool compare(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    for(int i = 0; i<s1.size(); i++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

void echoCommand(const vector<string>& tokens) {
    if(tokens.size() < 1) {usage(); return;}
    for(int i = 0; i<tokens.size(); i++){
        if(compare(tokens[i], "--help")) {usage(); return;}
        else if(compare(tokens[i], "--version")){
            cout<<"\necho 1.0 " __DATE__ " " __TIME__;
            return;
        }
        else{
            for(int j = 0; j<tokens[i].length(); j++){
                cout<<tokens[i][j];
            }
        }
    }
}