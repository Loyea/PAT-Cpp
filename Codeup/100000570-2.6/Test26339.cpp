//
// Created by Roy Hsu on 2018/3/10.
//
#include <stdio.h>
#include <cstring>

void reverse(char a[]){
    int len = strlen(a);
    for (int i = 0; i < len / 2; i++) {
        char temp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = temp;
    }
}

int main() {
    char a[255];
    gets(a);
    reverse(a);
    puts(a);
    return 0;
}

