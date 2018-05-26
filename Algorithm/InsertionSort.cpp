#include <cstdio>

const int len = 10;

void insertion_sort(int a[]) {
    for (int i = 1; i < len; i++) {
        int temp = a[i];
        int j = i;
        while (j > 0 && temp < a[j - 1]) {  //j>0 最后j=1,循环完成之后 j == 0
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

int main() {
    int a[len] = {2, 6, 9, 5, 4, 8, 3, 1, 7, 0};


    insertion_sort(a);

    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}