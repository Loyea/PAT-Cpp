#include <cstdio>
#include <algorithm>

using namespace std;

int getFriendNum(int a){
    int temp = 0;
    do {
        temp += a % 10;
        a /= 10;
    } while (a != 0);
    return temp;
}

int main() {

    int a[10010] = {0};
    int af[10010] = {0};

    int size = 0;
    int f[10010] = {0};

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        af[i] = getFriendNum(a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (af[i] == af[j]) {
                bool exists = false;
                for (int k = 0; k < size; k++) {
                    if (f[k] == af[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    f[size] = af[i];
                    size++;
                }
            }
        }
    }

    sort(f, f + size);
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d", f[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }

    return 0;
}