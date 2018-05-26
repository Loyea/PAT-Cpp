#include <cstdio>
#include <algorithm>
using namespace std;

struct question {
    int num;
    int score;
    int len;
    char ans[6];
    int wrongCount = 0;
};

bool cmp(question q1, question q2){
    if (q1.wrongCount > q2.wrongCount) {
        return true;
    } else if (q1.wrongCount == q2.wrongCount) {
        if (q1.num < q2.num) {
            return true;
        }
    }
    return false;
}

int main() {
    question que[110];
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int temp;
        scanf("%d %d %d ", &que[i].score, &temp, &que[i].len);
        que[i].num = i + 1;
        for (int j = 0; j < que[i].len; j++) {
            scanf("%c", &que[i].ans[j]);
            getchar();
        }
    }

    for (int i = 0; i < n; i++) {
        int score = 0;
        for (int j = 0; j < m; j++) {
            getchar();//for (
            int s;
            scanf("%d", &s);
            if (s != 0) {
                getchar();
            }
            if (s != que[j].len) {
                que[j].wrongCount++;
                int temp = 2 * s + 1;
                if (s == 0) {
                    temp = 2;
                }
                while (temp--) {
                    getchar();
                }
                continue;
            } else {
                bool allRight = true;
                for (int k = 0; k < s; k++) {
                    char answer;
                    scanf("%c", &answer);
                    getchar(); //for space after every option answer. and the ) after the last option answer.
                    if (answer != que[j].ans[k]) {
                        allRight = false;
                        //here can't break the for loop. because should read the behind input.
                    }
                }
                if (allRight) {
                    score += que[j].score;
                } else {
                    que[j].wrongCount++;
                }
            }
            getchar(); //for the space after the each ')', and the '\n' of the each line.
        }
        printf("%d\n", score);
    }

    sort(que, que + m, cmp);

    if (que[0].wrongCount > 0) {
        printf("%d", que[0].wrongCount);
        for (int i = 0; i < m; i++) {
            if (que[i].wrongCount == que[0].wrongCount) {
                printf(" %d", que[i].num);
            }
        }
    } else {
        printf("Too simple");
    }


    return 0;
}