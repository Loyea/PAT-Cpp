#include <stdio.h>

int main() {
    char* a = "I love China!";

    int n;
    scanf("%d", &n);

    printf("%s\n", a+n);
    return 0;
}