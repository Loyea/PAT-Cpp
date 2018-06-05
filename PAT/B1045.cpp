#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = (1 << 31) - 1;


int main() {
    int n, a[100010], result[100010], index = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int leftMax[100010] = {0}, rightMin[100010];

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > leftMax[i - 1]) {
            leftMax[i] = a[i - 1];
        } else {
            leftMax[i] = leftMax[i - 1];
        }
    }

    rightMin[n - 1] = INF;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] < rightMin[i + 1]) {
            rightMin[i] = a[i + 1];
        } else {
            rightMin[i] = rightMin[i + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > leftMax[i] && a[i] < rightMin[i]) {
            result[index++] = a[i];
        }
    }

    printf("%d\n", index);
    for (int i = 0; i < index; i++) {
        printf("%d", result[i]);
        if (i != index - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}