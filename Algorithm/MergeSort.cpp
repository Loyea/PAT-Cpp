#include <cstdio>
#include <algorithm>

using namespace std;

const int max_n = 100;

int min(int a, int b) {
    return a < b ? a : b;
}

void merge(int a[], int l1, int r1, int l2, int r2) {
    int i = l1, j = l2, temp[max_n], index = 0;
    //temp用于存放合并后的数组，长度应该大于等于数组a的原始长度
    //index代表temp的长度
    while (i <= r1 && j <= r2) {
        if (a[i] <= a[j]) {
            temp[index++] = a[i++];
        } else {
            temp[index++] = a[j++];
        }
    }

    while (i <= r1) {   //因为r1是数组a的下边的缘故，所以可以取到
        temp[index++] = a[i++];
    }

    while(j <= r2) {
        temp[index++] = a[j++];
    }

    for (i = 0; i < index; i++) {
        a[l1 + i] = temp[i];
    }
}


void merge_sort_recursive(int a[], int left, int right) {
    if (left < right) { //!!! if !!!
        int mid = (left + right) / 2;
        merge_sort_recursive(a, left, mid);
        merge_sort_recursive(a, mid + 1, right);
        merge(a, left, mid, mid + 1, right);
    }
}

void merge_sort(int a[], int length) {
    for (int step = 2; step / 2 <= length; step *= 2) {
        for (int i = 0; i < length; i += step) {
            int mid = i + step / 2 - 1;
            if (mid + 1 <= length) {   //判断右区间存在
                //左区间为[i, mid]，右区间为[mid + 1, min(i + step - 1, n)]
                merge(a, i, mid, mid + 1, min(i + step - 1, length - 1));
                //length - 1 是因为这里使用的全是数组下标
            }
        }
    }
}

void merge_sort_algorithm(int a[], int length) {
    for (int step = 2; step / 2 <= length; step *= 2) {
        for (int i = 0; i < length; i += step) {
            sort(a + i, a + min(i + step, length));
            //sort排序第二个参数是指排序最后一个元素的下一个元素地址，所以并非下标
            //所以i+step无需减一; 如果是到数组最后一个元素的话，即a+length
        }
    }
}


//归并排序 递归实现
int main() {

    int a[10] = {2, 6, 9, 5, 4, 8, 3, 1, 7, 0};
    int left = 0, right = 9;

    merge_sort_recursive(a, left, right);

    printf("Merge Sort Recursive:\n");
    for (int i = left; i <= right; i++) {
        printf("%d ", a[i]);
    }


    printf("\n\nMerge Sort:\n");
    int b[10] = {2, 6, 9, 5, 4, 8, 3, 1, 7, 0};
    merge_sort(b, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", b[i]);
    }

    printf("\n\nMerge Sort With Algorithm:\n");
    int c[10] = {2, 6, 9, 5, 4, 8, 3, 1, 7, 0};
    merge_sort_algorithm(c, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}