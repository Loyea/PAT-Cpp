#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void getNumber(int x, int *max, int *min) {
    char a[6];
    sprintf(a, "%04d", x);
    int len = strlen(a);
    sort(a, a + len);
    int max_temp = 0, min_temp = 0;
    int p = 1;
    for (int i = 0; i < len; i++) {
        int current_digi = a[i] - '0';
        min_temp = min_temp * 10 + current_digi;
        max_temp = p * current_digi + max_temp;
        p *= 10;
    }
    *max = max_temp;
    *min = min_temp;
}

int main() {
    int x;
    scanf("%d", &x);
    int max, min;
    getNumber(x, &max, &min);
    int result = max - min;
    printf("%04d - %04d = %04d\n", max, min, result);
    while (result != 0 && result != 6174) {
        getNumber(result, &max, &min);
        result = max - min;
        printf("%04d - %04d = %04d\n", max, min, result);
    }

    return 0;
}