#include <stdio.h>

void input(int* a){
    for (int i = 0; i < 10; i++) {
        scanf("%d", a + i);
    }
}

void swap(int* a){
    int *max = a, *min = a;
    for (int i = 0; i < 10; i++) {
        if (*(a + i) > *max) {
            max = a + i;
            continue;
        }
        if (*(a + i) < *min) {
            min = a + i;
        }
    }

    int temp = *a;
    *a = *min;
    *min = temp;

    int temp2 = *(a + 9);
    *(a + 9) = *max;
    *max = temp2;
}

void output(int* a){
    for (int i = 0; i < 10; i++) {
        printf("%d", *(a + i));
        if (i == 9) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
}

int main() {
    int a[10];
    input(a);
    swap(a);
    output(a);
    return 0;
}