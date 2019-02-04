#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, a[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n, cmp);

    int e = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1) {
            e = i + 1;
        } else {
            break;
        }
    }

    printf("%d", e);

    //这道题的教训就是别想太多。。本来还想着二分法。。。事实发现如此简单

    return 0;
}