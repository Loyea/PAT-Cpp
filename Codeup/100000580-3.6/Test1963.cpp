#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    while (getline(cin, str1)) {
        getline(cin, str2);
        int len2 = str2.length();
        while (len2 != 0 && str1.find(str2) != string::npos) {
            int index = str1.find(str2);
            str1.erase(index, len2);
        }
        puts(str1.c_str());
    }

    return 0;
}