#include <stdio.h>


int main() {

    int a, b;
    scanf("%d%d", &a, &b);
    int* p1 = &a;
    int* p2 = &b;
    if (*p1 > *p2) {
        printf("%d %d", *p1, *p2);
    } else {
        printf("%d %d", *p2, *p1);
    }
    return 0;
}