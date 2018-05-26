#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string toup(string s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

int main() {
    string str1, str2;
    cin >> str1;
    str1 = toup(str1);
    int len1 = str1.length();

    getchar();
    while (getline(cin, str2)) {
        string copy = str2;
        copy = toup(copy);

        while (copy.find(str1) != string::npos) {
            int index = copy.find(str1);
            str2.erase(index, len1);
            copy.erase(index, len1);
        }

        while (str2.find(" ") != string::npos) {
            str2.erase(str2.find(" "), 1);
        }
        puts(str2.c_str());
    }

    return 0;
}