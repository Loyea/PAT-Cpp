#include <cstdio>
#include <algorithm>

using namespace std;

struct student {
    int id, grade[4];
};

int now = 0;

bool cmp(student s1, student s2) {
    return s1.grade[now] > s2.grade[now];
}

char courses[4] = {'A', 'C', 'M', 'E'};
student stu[2010];
int ranking[1000000][4] = {0};    //一维代表id

//不使用map实现
int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3;
    }


    for (now = 0; now < 4; now++) {
        sort(stu, stu + n, cmp);
        ranking[stu[0].id][now] = 1;
        for (int i = 1; i < n; i++) {
            if (stu[i].grade[now] == stu[i - 1].grade[now]) {
                ranking[stu[i].id][now] = ranking[stu[i - 1].id][now];
            } else {
                ranking[stu[i].id][now] = i + 1;
            }
        }
    }

    while (m--) {
        int id;
        scanf("%d", &id);
        if (ranking[id][0] == 0) { //ranking can be 0. 0 means this id not exists.
            printf("N/A\n");
        } else {
            int best_ranking = ranking[id][0];
            int best_ranking_index = 0;
            for (int i = 1; i < 4; i++) {
                if (ranking[id][i] < best_ranking) {
                    best_ranking = ranking[id][i];
                    best_ranking_index = i;
                }
            }
            printf("%d %c\n", best_ranking, courses[best_ranking_index]);
        }
    }

    return 0;
}