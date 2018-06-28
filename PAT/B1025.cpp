#include <cstdio>

struct Node {
    int data;
    int next;
};

void swap(int a[], int left, int k) {
    int x = k / 2;
    int right = left + k - 1;
    int temp;
    for (int i = left; i < left + x; i++) {
        temp = a[i];
        a[i] = a[right - (i - left)];
        a[right - (i - left)] = temp;
    }
}

int main() {
    Node nodes[100010];
    int adds[100010];

    int first, n, k;
    scanf("%d %d %d", &first, &n, &k);

    int add, data, next;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &add, &data, &next);
        nodes[add].data = data;
        nodes[add].next = next;
    }

    int p = first;
    int length = 0;
    while (p != -1) {
        adds[length++] = p;
        p = nodes[p].next;
    }

    int left = 0;
    while (left + k - 1 < length) { //尼玛。。。存在不属于链表内的结点 这里不能用n判断链表长度 否则最后一个测试点无法通过
        swap(adds, left, k);
        left += k;
    }

    for (int i = 0; i < length - 1; i++) {
        printf("%05d %d %05d\n", adds[i], nodes[adds[i]].data, adds[i + 1]);
    }

    printf("%05d %d %d\n", adds[length - 1], nodes[adds[length - 1]].data, -1);


    return 0;
}