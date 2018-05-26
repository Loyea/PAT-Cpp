#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct shooter {
    int num;
    double distance;
};

bool cmp(shooter s1, shooter s2){
    return s1.distance < s2.distance;
}

int main() {
    shooter s[10010];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d %d", &s[i].num, &x, &y);
        s[i].distance = sqrt(x * x + y * y);
    }
    sort(s, s + n, cmp);
    printf("%04d %04d", s[0].num, s[n - 1].num);
    return 0;
}