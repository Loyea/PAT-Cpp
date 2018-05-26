#include <cstdio>
#include <algorithm>

using namespace std;

struct counter{
    int d;
    int count;
    counter(){
        d = 0;
        count = 0;
    }
};

bool cmp(counter c1, counter c2){
    return c1.d > c2.d;
}

int main() {

    counter counter[10010];

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        int diff;
        if (temp > i) {
            diff = temp - i;
        } else {
            diff = i - temp;
        }
        counter[diff].d = diff;
        counter[diff].count++;
    }

    sort(counter, counter + 10010, cmp);

    for (int i = 0; i < 10010; i++) {
        if (counter[i].count <= 1) {
            continue;
        }
        printf("%d %d\n", counter[i].d, counter[i].count);
    }

    return 0;
}