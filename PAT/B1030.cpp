#include <cstdio>
#include <algorithm>

using namespace std;

//最直观的做法，不适用复杂的算法
int main() {
    long long n, p;

    long long a[100010];

    scanf("%lld %lld", &n, &p);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a, a + n);

    int size = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] <= a[i] * p) {
            j++;
        }
        if (j - i > size) { //之所以是j-i是因为j指向的是符合完美数列的下一个元素下标
            size = j - i;
        }
    }

    printf("%d", size);


    return 0;
}