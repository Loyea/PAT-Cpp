#include <stdio.h>

struct student{
    int num;
    int name[20];
    int score1;
    int score2;
    int score3;
    double avg;
};

void sort(student a[]){
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10 - i; j++) {
            if (a[j].avg < a[j + 1].avg) {
                student temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    student stu[10];
    double sum1, sum2 ,sum3, avg1, avg2, avg3;
    for (int i = 0; i < 10; i++) {
        scanf("%d %s %d %d %d", &stu[i].num, stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].score3);
        stu[i].avg = ((double) (stu[i].score1 + stu[i].score2 + stu[i].score3)) / 3;
        sum1 += stu[i].score1;
        sum2 += stu[i].score2;
        sum3 += stu[i].score3;
    }

    avg1 = sum1 / 10;
    avg2 = sum2 / 10;
    avg3 = sum3 / 10;

    sort(stu);

    printf("%.2f %.2f %.2f \n", avg1, avg2, avg3);
    printf("%d %s %d %d %d\n", stu[0].num, stu[0].name, stu[0].score1, stu[0].score2, stu[0].score3);

    return 0;
}