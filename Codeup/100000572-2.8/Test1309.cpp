#include <stdio.h>

struct student{
    int num;
    int name[20];
    int score1;
    int score2;
    int score3;
};

int main() {
    student stu[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d %s %d %d %d", &stu[i].num, stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].score3);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d %s %d %d %d\n", stu[i].num, stu[i].name, stu[i].score1, stu[i].score2, stu[i].score3);
    }

    return 0;
}