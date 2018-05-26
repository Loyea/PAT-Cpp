#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct person {
    char name[10];
    int height;
};

bool cmp(person p1, person p2){
    if (p1.height > p2.height) {
        return true;
    } else if (p1.height == p2.height) {
        if (strcmp(p1.name, p2.name) < 0) {
            return true;
        }
    }
    return false;
}

int main() {
    person persons[10010];

    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i <n; i++){
        scanf("%s %d", persons[i].name, &persons[i].height);
    }

    sort(persons, persons + n, cmp);

    int m = n / k;
    int x = n % k;
    int start = 0;
    for (int i = 0; i < k; i++) {
        int len = m;
        if (i == 0) {
            len = m + x;
        }
        int left, right;
        if (len % 2 == 0) {
            left = len - 1;
            right = len - 2;
        } else {
            left = len - 2;
            right = len - 1;
        }
        for (int j = left; j >= 1; j -= 2) {
            printf("%s ", persons[start + j].name);
        }
        for (int j = 0; j <= right; j += 2) {
            printf("%s", persons[start + j].name);
            if (j != right) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
        start += len;
    }

    return 0;
}