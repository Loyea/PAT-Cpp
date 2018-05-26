#include <cstdio>

const int len = 10;

void bubble_sort(int a[]) {
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[len] = {2, 6, 9, 5, 4, 8, 3, 1, 7, 0};


    bubble_sort(a);

    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}