#include <stdio.h>

struct student {
    int num;
    char name[20];
    char sex;
    int age;
};

int main() {
    student stu[20];
    student* ps = stu;
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d %s %c %d", &((*(ps + i)).num), (*(ps + i)).name, &((*(ps + i)).sex), &((*(ps + i)).age));
    }

    for (int i = 0; i < size; i++) {
        printf("%d %s %c %d\n", (*(ps + i)).num, (*(ps + i)).name, (*(ps + i)).sex, (*(ps + i)).age);
    }

    return 0;
}