#include <cstdio>

//最基本的二分查找
//二分区间为[left, right]
//虽然对于一个数组来说，left取0或1都可以，但是一般取0
//即 [0, n-1]

//int mid = (left + right) / 2; 假如right大于int范围的一半，且要寻找的x处于数组靠后位置时
//left与right都可能大于int的一半，加法就会导致溢出
//所以用 int mid = left + (right - left) / 2; 比较安全
int binary_search(int a[], int left, int right, int x) {
    while (left <= right) { //小于等于号很重要！！！
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; //未找到
}

//问题2的左边界，求第一个大于等于x的位置
//无需判断x是否存在，我们要找的是第一个大于或等于x元素的位置
//二分区间为[0, n], 原因是查找的元素可能比序列中所有元素都大，很重要！！！
int lower_bound(int a[], int left, int right, int x) {
    while (left < right) {  //小于号很重要！！！
        int mid = (left + right) / 2;
        if (a[mid] >= x) {  //大于等于x说明第一个大于等于x的值就在mid或者mid的左侧
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left; //left==right时，left或right就是要查找的第一个大于等于x元素的左边界
}

//问题2的右边界，求第一个大于x元素的位置
//同样无需判断x是否存在
//二分区间为[0, n]
int upper_bound(int a[], int left, int right, int x) {
    while (left < right) {  //小于号很重要！！！
        int mid = (left + right) / 2;
        if (a[mid] > x) {  //仔细观察这就是我们要求的条件：大于x的元素。 又因为这个条件成立，说明第一个大于x元素的位置<=mid,所以将mid赋给right.
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}


int main() {

    //问题1. 在严格递增数列中寻找x的位置
    int a[10] = {1, 3, 5, 6, 7, 12, 14, 15, 19, 20};
    int x1 = 6;
    int result1 = binary_search(a, 0, 9, x1);
    printf("%d\n", result1);

    //问题2. 在递增序列中的元素可能存在重复，给定欲查询的元素x,
    //求出第一个大于等于x的元素位置L以及第一个大于x的元素位置R,
    //这样元素x在序列中的存在区间就是[L, R)

    int b[5] = {1, 3, 3, 3, 6};
    int x2 = 5;
    int left = lower_bound(b, 0, 5, x2);
    int right = upper_bound(b, 0, 5, x2);
    printf("[%d, %d)", left, right);

    return 0;
}