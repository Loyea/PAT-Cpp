#include <cstdio>
#include <algorithm>

using namespace std;

const int max_n = 110;

int n, origin[max_n], target[max_n], temp[max_n];

bool isSame(int a[], int b[], int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void print_array(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", a[i]);
        if (i != len - 1) {
            printf(" ");
        }
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}


bool merge_sort(int a[], int length) {
    bool flag = false;
    for(int step = 2; step / 2 <= length; step *= 2){
        for (int i = 0; i < length; i += step) {
            sort(a + i, a + min(i + step, length));
        }
        if (flag) {
            printf("Merge Sort\n");
            print_array(a, length);
            return true;
        } else {
            if (isSame(a, target, length)) {
                flag = true;
            }
        }
    }
    return false;
}

bool insertion_sort(int a[], int length) {
    bool flag = false;
    for (int i = 1; i < length; i++) {
        int temp = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
        if (flag) {
            printf("Insertion Sort\n");
            print_array(a, length);
            return true;
        } else {
            if (isSame(a, target, length)) {
                flag = true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        temp[i] = origin[i];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &target[i]);
    }

    if (insertion_sort(origin, n)) {
        return 0;
    }

    merge_sort(temp, n);

    return 0;
}