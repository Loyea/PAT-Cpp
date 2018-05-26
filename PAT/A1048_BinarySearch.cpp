#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int coins[100010] = {0};

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    sort(coins, coins + n);

    for (int i = 0; i < n; i++) {
        int sub = m - coins[i];
        if (sub <= 0 || sub > 500) {
            continue;
        }
        int left = i + 1, right = n - 1, mid;
        //left = i + 1 确保了排除再次找到同个币的问题
        while (left <= right) {
            mid = (left + right) / 2;
            if (coins[mid] == sub) {
                printf("%d %d", coins[i], coins[mid]);
                return 0;
            } else if (coins[mid] > sub) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    printf("No Solution");

    return 0;
}