//
// Created by Roy Hsu on 2018/3/10.
//

#include <stdio.h>

int main(){

    int a = 1, b = 0;
    for (int i = 0; i < 20; i++) {
        int temp = a + b;
        printf("%d\n", temp);
        a = b;
        b = temp;
    }

    return 0;
}