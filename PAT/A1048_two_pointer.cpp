#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    //core: two pointer 的核心在于递增序列


    int n, m;

    int coins[100010];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    sort(coins, coins + n);

    int i = 0, j = n - 1;
    while (i < j) {
        if (coins[i] + coins[j] == m) {
            printf("%d %d", coins[i], coins[j]);
            return 0;
        } else if (coins[i] + coins[j] < m) {
            i++;
        } else {
            j--;
        }
    }

    printf("No Solution");
    return 0;
}