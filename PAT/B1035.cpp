#include <stdio.h>
#include <algorithm>

using namespace std;


int n, origin[110], duplicate[110], target[110];

bool isSame(int a[], int b[], int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void p_array(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", a[i]);
        if (i != len - 1) {
            printf(" ");
        }
    }
}

bool merge_sort(int a[], int len) {
    bool flag = false;
    for (int step = 2; step / 2 <= len; step *= 2) {
        for (int i = 0; i < len; i += step) {
            sort(a + i, a + min(i + step, len));
        }
        if (flag) {
            printf("Merge Sort\n");
            p_array(a, len);
            return true;
        } else {
            flag = isSame(a, target, len);
        }
    }
    return false;
}

bool insertion_sort(int a[], int len) {
    bool flag = false;
    for (int i = 1; i < len; i++) {
        int temp = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;

        if (flag) {
            printf("Insertion Sort\n");
            p_array(a, len);
            return true;
        } else {
            flag = isSame(a, target, len);
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        duplicate[i] = origin[i];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &target[i]);
    }

    if (!merge_sort(origin, n)) {
        insertion_sort(duplicate, n);
    }


    return 0;
}