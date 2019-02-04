#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int s, a[10010];
    int m, n;
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + s, cmp);

    int sqr = (int) sqrt(1.0 * s);

    for (int i = sqr; i >= 1; i--) {
        if (s % i == 0) {
            n = i;
            m = s / i;
            break;
        }
    }

    int table[m][n]; //TODO c++ 可以申请动态数组？

    int x = 0, y = 0;

    int y_left = 0, y_right = n - 1;
    int x_up = 1, x_bottom = m - 1;

    int index = 0;

    while (index < s) {
        while(y <= y_right && index < s) {
            table[x][y++] = a[index++];
        }
        y--;//修正
        x++;//向下
        y_right--;
        while (x <= x_bottom && index < s) {
            table[x++][y] = a[index++];
        }
        x--;//修正
        y--;//向左
        x_bottom--;
        while (y >= y_left && index < s) {
            table[x][y--] = a[index++];
        }
        y++;//修正
        x--;//向上
        y_left++;
        while (x >= x_up && index < s) {
            table[x--][y] = a[index++];
        }
        x++;//修正
        y++;//向右
        x_up++;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", table[i][j]);
            if (j != n - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }

    return 0;
}