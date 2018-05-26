#include <cstdio>
#include <algorithm>

using namespace std;

struct mooncake {
    double amount, sell, price;
} m[1010];

bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}

int main() {
    int n;
    double d;

    scanf("%d %lf", &n, &d);

    for (int i = 0; i < n; i++) {
        scanf("%lf", &m[i].amount);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf", &m[i].sell);
        m[i].price = m[i].sell / m[i].amount;
    }

    sort(m, m + n, cmp);

    double profit = 0;
    for (int i = 0; i < n; i++) {
        if (d >= m[i].amount) {
            profit += m[i].sell;
            d -= m[i].amount;
        } else {
            profit += d * m[i].price;
            d = 0;
        }
        if (d == 0) {
            break;
        }
    }

    printf("%.2f", profit);

    return 0;
}