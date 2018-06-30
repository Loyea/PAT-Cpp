#include <cstdio>
#include <cstring>
struct Question {
    double score;
    int option_size, answer_size;
    char answer[6];
    int answers[6];
    Question() {
        memset(answers, 0, sizeof(answers));
    }
};



int main() {
    Question q[110];
    int wrong[110][5] = {0};
    int op_len = 0;

    int max = 0;

    int n, m;
    scanf("%d%d", &n, &m);
    double score;
    int option_size, answer_size;
    for (int i = 0; i < m; i++) {
        scanf("%lf %d %d ", &score, &option_size, &answer_size);
        q[i].score = score;
        q[i].option_size = option_size;
        q[i].answer_size = answer_size;
        for (int j = 0; j < answer_size; j++) {
            char temp;
            scanf("%c", &temp);
            q[i].answer[j] = temp;
            q[i].answer[j + 1] = 0;
            q[i].answers[temp - 'a'] = 1;
            getchar();
        }
    }

    for (int i = 0; i < n; i++) {
        double score_total = 0;
        for (int j = 0; j < m; j++) {
            int ans_num;
            char ans[6] = "";
            scanf("(%d", &ans_num);
            for (int k = 0; k < ans_num; k++) {
                char temp;
                scanf(" %c", &temp);
                ans[k] = temp;
                ans[k + 1] = 0;
            }
            scanf(")");
            getchar();

            if (strcmp(ans, q[j].answer) == 0) {
                score_total += q[j].score;
            } else {
                bool flag = true;

                for (int z = 0; z < q[j].answer_size; z++) {
                    wrong[j][q[j].answer[z] - 'a']++;
                }

                for (int z = 0; z < ans_num; z++) {
                    if (q[j].answers[ans[z] - 'a'] == 1) {
                        wrong[j][ans[z] - 'a']--;
                    } else {
                        wrong[j][ans[z] - 'a']++;
                        flag = false;
                    }
                }

                if (flag) {
                    score_total += q[j].score / (double) 2;
                }

            }

        }
        printf("%.1f\n", score_total);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 5; j++) {
            if (wrong[i][j] > max) {
                max = wrong[i][j];
            }
        }
    }

    if (max == 0) {
        printf("Too simple");
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 5; j++) {
                if (wrong[i][j] == max) {
                    printf("%d %d-%c\n", max, i + 1, 'a' + j);
                }
            }
        }
    }

    return 0;
}