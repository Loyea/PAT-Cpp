#include <cstdio>

const int len = 10;

void selection_sort(int a[]) {
    for (int i = 0; i < len; i++) {
        int k = i;
        for (int j = i; j < len; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

int main() {
    int a[len] = {2, 6, 9, 5, 4, 8, 3, 1, 7, 0};


    selection_sort(a);

    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}