#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int a[110][2048] = {{0}};
    int num = 0;
    int result[110];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);

        a[i][0] = temp;
        int index = 1;
        while (temp != 1) {
            if (temp % 2 == 0) {
                temp /= 2;
            } else {
                temp = (3 * temp + 1) / 2;
            }
            a[i][index++] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = a[i][0];
        bool covered = false;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 1; k < 2048; k++) {
                int y = a[j][k];
                if (y == 0) {
                    break;
                }
                if (x == y) {
                    covered = true;
                }
            }
            if (covered) {
                break;
            }
        }
        if (!covered) {
            result[num++] = x;
        }
    }

    sort(result, result + num, cmp);

    for (int i = 0; i < num; i++) {
        printf("%d", result[i]);
        if (i != num - 1) {
            printf(" ");
        }
    }

    return 0;
}