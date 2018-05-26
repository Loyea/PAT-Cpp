#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int k;

struct testee {
    int id;
    int grade[5];
    int sum;
    int perfect_count;
    bool valid_testee;
    testee() {
        id = 100010; //取超过题目范围的id作为默认值，因为需要从小到大排序，能保证所有存在的考试都在前面。
        sum = 0;
        perfect_count = 0;
        memset(grade, -1, sizeof(grade));
    }
    void compute_sum() {
        sum = 0;
        for (int i = 0; i < k; i++) {
            if (grade[i] != -1) {
                sum = sum + grade[i];
            }
        }
    }
} tt[100010];

bool cmp(testee t1, testee t2) {
    if (t1.sum != t2.sum) {
        return t1.sum > t2.sum;
    } else {
        if (t1.perfect_count != t2.perfect_count) {
            return t1.perfect_count > t2.perfect_count;
        } else {
            return t1.id < t2.id;
        }
    }
}

int main() {

    
    int n, m, score[5] = {0};
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < k; i++) {
        scanf("%d", &score[i]);
    }

    while (m--) {
        int id, p_id, s;
        scanf("%d %d %d", &id, &p_id, &s);
        tt[id].id = id;
        if (s >= 0) {
            tt[id].valid_testee = true;
        }
        if (s == -1) {
            s = 0;
        }
        if (s > tt[id].grade[p_id - 1]) {
            tt[id].grade[p_id - 1] = s;
            tt[id].compute_sum();
            if (s == score[p_id - 1]) {
                tt[id].perfect_count++;
            }
        }
    }

    sort(tt, tt + 100010, cmp);

    int r = 1;
    for (int i = 0; i < 100010; i++) {
        if (!tt[i].valid_testee) {
            break;
        }
        if (i > 0 && tt[i].sum != tt[i - 1].sum) {
            r = i + 1;
        }
        printf("%d %05d %d ", r, tt[i].id, tt[i].sum);
        for (int j = 0; j < k; j++) {
            if (tt[i].grade[j] == -1) {
                printf("-");
            } else {
                printf("%d", tt[i].grade[j]);
            }
            if (j == k - 1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }

    return 0;
}