//
// Created by Roy Hsu on 2018/3/10.
//

#include <stdio.h>
#include <cstring>

int main() {
    char a[3][255];
    for (int i = 0; i < 3; i++) {
        gets(a[i]);
    }

    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            char temp[255];
            if (strcmp(a[j], a[j + 1]) > 0) {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }

    printf("%s", a[2]);
}