#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    long long sum = 0;
    
    string input;
    cin >> input;

    int len = input.length();
    for (int i = 0; i < len; i++) {
        int x = input[i] - '0';
        sum = sum + x;
    }

    string result = to_string(sum);
    int len1 = result.length();

    for (int i = 0; i < len1; i++) {
        int x = result[i] - '0';
        printf("%s", num[x]);
        if (i != len1 - 1) {
            printf(" ");
        }
    }
    
    return 0;
}