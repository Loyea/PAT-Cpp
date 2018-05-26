#include <stdio.h>
#include <cstring>


void swap(char* &a, char* &b){
    char* temp = a;
    a = b;
    b = temp;
}

int main() {

    char a[255], b[255], c[255];
    gets(a);
    gets(b);
    gets(c);

    char* pa = a;
    char* pb = b;
    char* pc = c;

    if (strcmp(pa, pb) > 0) {
        swap(pa, pb);
    }

    if (strcmp(pb, pc) > 0) {
        swap(pb, pc);
    }

    if (strcmp(pa, pb) > 0) {
        swap(pa, pb);
    }

    printf("%s\n", pa);
    printf("%s\n", pb);
    printf("%s", pc);


    return 0;
}