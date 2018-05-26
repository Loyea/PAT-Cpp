#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a[100010];
    int coin_count[510] = {0};

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        coin_count[a[i]]++;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        int sub = m - a[i];
        if (sub <= 0 || sub > 500) {
            continue;
        }
        if ((sub != a[i] && coin_count[sub] > 0) || (sub == a[i] && coin_count[sub] > 1)) {
            printf("%d %d", a[i], sub);
            return 0;
        }

    }

    printf("No Solution");


    return 0;
}