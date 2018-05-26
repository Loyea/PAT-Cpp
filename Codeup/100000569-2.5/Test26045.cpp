//
// Created by Roy Hsu on 2018/3/9.
//

#include <stdio.h>

int main(){
    char a[100], b[100];
    gets(a);
    gets(b);
    for (int i = 0; i < 100; i++) {
        int x = a[i] - b[i];
        if (x) {
            printf("%d", x);
            return 0;
        }
        if (a[i] == 0 || b[i] == 0) {
            break;
        }
    }
    printf("%d", 0);
    return 0;
}