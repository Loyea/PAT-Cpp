#include <stdio.h>

struct person{
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int cls;
        char position[10];
    }category;
};

int main() {
    person per[100];
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d %s %c %c", &per[i].num, per[i].name, &per[i].sex, &per[i].job);
        if (per[i].job == 's') {
            scanf("%d", &per[i].category.cls);
        } else {
            scanf("%s", per[i].category.position);
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d %s %c %c ", per[i].num, per[i].name, per[i].sex, per[i].job);
        if (per[i].job == 's') {
            printf("%d\n", per[i].category.cls);
        } else {
            printf("%s\n", per[i].category.position);
        }
    }
    return 0;
}