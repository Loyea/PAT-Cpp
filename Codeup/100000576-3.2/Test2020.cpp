#include <cstdio>
#include <cstring>

struct student{
    int num;
    char name[255];
    char gender[255];
    int age;
} stu[25];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m, target;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %s %s %d", &stu[i].num, stu[i].name, stu[i].gender, &stu[i].age);
        }
        scanf("%d", &target);
        for (int i = 0; i < m; i++) {
            if (stu[i].num == target) {
                printf("%d %s %s %d\n", stu[i].num, stu[i].name, stu[i].gender, stu[i].age);
                break;
            }
        }
    }

    return 0;
}