#include <cstdio>
#include <algorithm>

using namespace std;

const int max_n = 40010;

struct applicant {
    int id, ge, gi, gf, choice[5];
};

bool cmp(applicant a1, applicant a2) {
    if (a1.gf != a2.gf) {
        return a1.gf > a2.gf;
    } else {
        return a1.ge > a2.ge;
    }
}

int quota[105];

int admitted[105][max_n];
int admitted_count[105] = {0};

applicant last_admit[105];
bool stop_admit[105] = {false};

applicant app[max_n];

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &quota[i]);
    }

    for (int i = 0; i < n; i++) {
        int ge, gi, gf;
        scanf("%d %d", &ge, &gi);
        gf = ge + gi;
        app[i].id = i;
        app[i].ge = ge;
        app[i].gi = gi;
        app[i].gf = gf;
        for (int j = 0; j < k; j++) {
            scanf("%d", &app[i].choice[j]);
        }
    }

    sort(app, app + n, cmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int choice = app[i].choice[j];
            if (quota[choice] > 0) {
                //招生人数剩余不为0
                admitted[choice][admitted_count[choice]] = app[i].id;
                admitted_count[choice]++;
                quota[choice]--;
                last_admit[choice] = app[i];
                //被录取 跳出j循环
                break;
            } else{
                //招生人数剩余为0
                if(admitted_count[choice] > 0) {
                    if (!stop_admit[choice]) {
                        //尚未确认是否还有同最后一位一样成绩的存在
                        if (app[i].gf == last_admit[choice].gf && app[i].ge == last_admit[choice].ge) {
                            admitted[choice][admitted_count[choice]] = app[i].id;
                            admitted_count[choice]++;
                            //被录取 跳出j循环
                            break;
                        } else {
                            stop_admit[choice] = true;
                        }
                    } else {
                        //该学校已停止招生
                    }
                } else {
                    //do nothing.
                    //剩余人数和已招生人数都为0，说明该学校不招生
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (admitted_count[i] == 0) {
            printf("\n");
            continue;
        }

        sort(admitted[i], admitted[i] + admitted_count[i]);
        for (int j = 0; j < admitted_count[i]; j++) {
            printf("%d", admitted[i][j]);
            if (j != admitted_count[i] - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }

    return 0;
}