#include <cstdio>

struct node{
    int add;
    int nn;
    int value;
};

int getAddByValue(int value, node nodes[], int m){
    for (int i = 0; i < m; i++) {
        if (nodes[i].value == value) {
            return nodes[i].add;
        }
    }
}

node getNodeByAdd(int add, node nodes[], int m){
    for (int i = 0; i < m; i++) {
        if (nodes[i].add == add) {
            return nodes[i];
        }
    }
}

int main() {

    int n1, m, k;

    int num = 0;
    int values[100010] = {0};

    node nodes[100010];

    scanf("%d%d%d", &n1, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &nodes[i].add, &nodes[i].value, &nodes[i].nn);
//        values[i] = nodes[i].value;
    }

    int n = 0;
    int v[100010];

    //todo
    for (int i = 0; i < m; i++) {
        node temp = getNodeByAdd(n1, nodes, m);
        v[n++] = temp.value;
        n1 = temp.nn;
    }

    for (int i = 0; i < m; i++) {
        if (v[i] < 0) {
            values[num++] = v[i];
        }
    }
    for (int i = 0; i < m; i++) {
        if (v[i] >= 0 && v[i] <= k) {
            values[num++] = v[i];
        }
    }
    for (int i = 0; i < m; i++) {
        if (v[i] > k) {
            values[num++] = v[i];
        }
    }

    for (int i = 0; i < m; i++) {
        int add, next;
        add = getAddByValue(values[i], nodes, m);
        if (i != m - 1) {
            next = getAddByValue(values[i + 1], nodes, m);
        }

        if (i != m - 1) {
            printf("%05d %d %05d\n", add, values[i], next);
        } else {
            printf("%05d %d -1\n", add, values[i]);
        }

    }

    return 0;
}