#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

struct solution {
    int left, right;
    LL pay;
};

bool cmp(solution a, solution b) {
    if (a.pay != b.pay) {
        return a.pay < b.pay;
    } else {
        return a.left < b.left;
    }
}

int main() {

    LL sum[100010] = {0};
    solution sol[100010];
    int sol_count = 0;

    int n;
    LL m;
    scanf("%d %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        LL temp;
        scanf("%lld", &temp);
        sum[i] = sum[i - 1] + temp;
    }

    for (int i = 1; i <= n; i++) {
        int left = i, right = n, mid;
        LL left_sum = sum[left - 1];
        while (left < right) {
            mid = (left + right) / 2;
            if (sum[mid] - left_sum >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        LL pay = sum[right] - left_sum;
        if (pay >= m) {
            sol[sol_count].left = i;
            sol[sol_count].right = right;
            sol[sol_count].pay = pay;
            sol_count++;
        }
    }

    sort(sol, sol + sol_count, cmp);

    LL pay_actually = sol[0].pay;
    for (int i = 0; i < sol_count; i++) {
        if (sol[i].pay == pay_actually) {
            printf("%d-%d\n", sol[i].left, sol[i].right);
        } else {
            break;
        }
    }

    return 0;
}