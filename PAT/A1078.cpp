#include <cstdio>
#include <cmath>

const int maxn = 10010;

bool is_prime(int n) {
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0 || n < 2) {
        return false;
    }
    int sqr = (int) sqrt(1.0 * n);
    for (int i = 3; i <= sqr; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int find_prime_big_than_n(int n) {
    for (int i = n + 1; i < maxn; i++) {
        if (is_prime(i)) {
            return i;
        }
    }
}

int main() {
    int m, n;
    int input[maxn];
    bool hash_table[maxn] = {false};
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    int tsize;
    if (is_prime(m)) {
        tsize = m;
    } else {
        tsize = find_prime_big_than_n(m);
    }

    for (int i = 0; i < n; i++) {
        int h = input[i] % tsize;
        if (hash_table[h]) {
            //根据题意，进行正向的平方探查法
            bool found = false;
            for (int j = 1; j < tsize; j++) {
                int temp = input[i] + j * j;
                h = temp % tsize;
                if (!hash_table[h]) {
                    found = true;
                    printf("%d", h);
                    hash_table[h] = true;
                    break;  //这个break很重要！！ 没有的话就超时了！！！
                }
            }
            if (!found) {
                printf("-");
            }

        } else {
            printf("%d", h);
            hash_table[h] = true;
        }
        if (i != n - 1) {
            printf(" ");
        }
    }

    return 0;
}