#include <cstdio>
#include <algorithm>

using namespace std;

struct team {
    int num = 0;
    int scores[10010];
    int ts;
} t[100];

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j <n;j++){
            if (j == 0) {
                scanf("%d", &t[i].ts);
                continue;
            }
            int s;
            scanf("%d", &s);
            if (s >= 0 && s <= m) {
                t[i].scores[t[i].num++] = s;
            }
        }
        sort(t[i].scores, t[i].scores + t[i].num);
        int sum = 0;
        for (int k = 1; k < t[i].num - 1; k++) {
            sum += t[i].scores[k];
        }
        double g1 = (double)sum / (t[i].num - 2);
        double avg = ((double)(g1 + t[i].ts)) / 2;
        printf("%d\n", (int) (avg + 0.5));
    }

    return 0;
}