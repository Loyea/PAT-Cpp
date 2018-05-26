#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main() {

    string input, str1, str2;
    char in[110] = " ";
    char s[110] = " ";
    char s2[110] = " ";
    while (gets(in + 1)) {
        gets(s + 1);
        gets(s2 + 1);
        input = in;
        str1 = s;
        str2 = s2;
        int len1 = str1.length();
        while (input.find(str1) != string::npos) {
            int index = input.find(str1);
            input.replace(index, len1, str2);
        }
        char temp[110];
        strcpy(temp, input.c_str());
        puts(temp + 1);
    }

    return 0;
}