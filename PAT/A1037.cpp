#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(long long a, long long b) {
    return a > b;
}

int main() {
    int nc, np;
    scanf("%d", &nc);

    long long cp[100010] = {0}, pd[100010] = {0};

    for (int i = 0; i < nc; i++) {
        scanf("%lld", &cp[i]);
    }


    scanf("%d", &np);

    for (int i = 0; i < np; i++) {
        scanf("%lld", &pd[i]);
    }

    sort(cp, cp + nc, cmp);
    sort(pd, pd + np, cmp);

    long long sum = 0;

    for (int i = 0; i < nc && i < np && cp[i] > 0 && pd[i] > 0; i++) {
        sum += cp[i] * pd[i];
    }

    sort(cp, cp + nc);
    sort(pd, pd + np);

    for (int i = 0; i < nc && i < np && cp[i] < 0 && pd[i] < 0; i++) {
        sum += cp[i] * pd[i];
    }

    printf("%lld", sum);

    return 0;
}