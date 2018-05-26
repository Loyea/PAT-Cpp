#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int l[10010] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    sort(l, l + n);
    double length = l[0];
    for (int i = 1; i < n; i++) {
        length = length / 2 + (double)l[i] / 2;
    }
    printf("%d", (int) length);
    return 0;
}