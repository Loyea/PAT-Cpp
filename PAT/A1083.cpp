#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct student {
    string name, id;
    int grade;
} stu[100010];

bool cmp(student s1, student s2) {
    return s1.grade > s2.grade;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[12], id[12];
        scanf("%s %s %d", name, id, &stu[i].grade);
        stu[i].name = name;
        stu[i].id = id;
    }
    int min, max;
    scanf("%d %d", &min, &max);

    sort(stu, stu + n, cmp);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (stu[i].grade >= min && stu[i].grade <= max) {
            count++;
            printf("%s %s\n", stu[i].name.c_str(), stu[i].id.c_str());
        }
    }

    if (count == 0) {
        printf("NONE");
    }

    return 0;
}