#include <cstdio>

//core: 使得temp左侧的元素都**不超过**temp, temp右侧的元素都大于temp
int partition(int a[], int left, int right) {
    int temp = a[left];
    while (left < right) {
        while (left < right && a[right] > temp) {
            right--;
        }
        a[left] = a[right];
        while (left < right && a[left] <= temp) {
            left++;
        }
        a[right] = a[left];
    }

    //when left == right
    a[left] = temp;
    return left;
}

void quick_sort(int a[], int left, int right) {
    if (left < right) {
        int pos = partition(a, left, right);
        quick_sort(a, left, pos - 1);   //pos位置已经确定了
        quick_sort(a, pos + 1, right);
    }
}

//快速排序
//平均时间复杂度为O(nlogn),最坏时间复杂度为O(n^2)
int main() {
    int a[10] = {2, 6, 9, 5, 4, 8, 3, 1, 7, 0};
    int left = 0, right = 9;

    quick_sort(a, left, right);

    for (int i = left; i <= right; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}