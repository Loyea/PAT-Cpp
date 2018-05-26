#include <cstdio>
#include <cstring>

struct student{
    char num[255];
    char name[255];
    char gender[255];
    int age;
} stu[1010];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s %s %s %d", stu[i].num, stu[i].name, stu[i].gender, &stu[i].age);
        }
        int m;
        scanf("%d", &m);
        while (m--) {
            char temp[255];
            scanf("%s", temp);
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (strcmp(temp, stu[i].num) == 0) {
                    found = true;
                    printf("%s %s %s %d\n", stu[i].num, stu[i].name, stu[i].gender, stu[i].age);
                    break;
                }
            }
            if (!found) {
                printf("No Answer!\n");
            }
        }
    }
    return 0;
}