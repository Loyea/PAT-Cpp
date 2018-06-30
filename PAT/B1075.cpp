#include <cstdio>

struct Node {
    int data;
    int next;
};

int main() {

    Node nodes[100010];
    int adds[100010];

    int add1[100010], add2[100010], add3[100010];
    int len1 = 0, len2 = 0, len3 = 0;

    int first, n, k;
    scanf("%d%d%d", &first, &n, &k);

    int add, data, next;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &add, &data, &next);
        nodes[add].data = data;
        nodes[add].next = next;
    }

    int p = first;
    int list_length = 0;
    while (p != -1) {
        adds[list_length++] = p;
        p = nodes[p].next;
    }

    for (int i = 0; i < list_length; i++) {
        int current_data = nodes[adds[i]].data;
        if (current_data < 0) {
            add1[len1++] = adds[i];
        } else if (current_data <= k) {
            add2[len2++] = adds[i];
        } else {
            add3[len3++] = adds[i];
        }
    }

    for (int i = len1; i < len1 + len2; i++) {
        add1[i] = add2[i - len1];
    }

    for (int i = len1 + len2; i < len1 + len2 + len3; i++) {
        add1[i] = add3[i - len1 - len2];
    }

    for (int i = 0; i < list_length - 1; i++) {
        printf("%05d %d %05d\n", add1[i], nodes[add1[i]].data, add1[i + 1]);
    }
    printf("%05d %d %d\n", add1[list_length - 1], nodes[add1[list_length - 1]].data, -1);

    //坑点参考1025

    return 0;
}