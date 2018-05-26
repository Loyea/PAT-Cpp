#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long n, p;

    long long a[100010];

    scanf("%lld %lld", &n, &p);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a, a + n);

    int max_size = 0;

    for (int i = 0; i < n; i++) {
        //因为 M <= m * p;
        //即寻找第一个大于M的数
        long long M = a[i] * p;
        int left = i, right = n;

        while (left < right) {
            int mid = (left + right) / 2;
            if (a[mid] > M) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left - i > max_size) {
            max_size = left - i;
        }
    }

    printf("%d", max_size);

    return 0;
}