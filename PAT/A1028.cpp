#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct student {
    int id, grade;
    string name;
} stu[100010];

bool cmp_1(student s1, student s2) {
    return s1.id < s2.id;
}

bool cmp_2(student s1, student s2) {
    if (s1.name != s2.name) {
        return s1.name < s2.name;
    } else {
        return s1.id < s2.id;
    }
}

bool cmp_3(student s1, student s2) {
    if (s1.grade != s2.grade) {
        return s1.grade < s2.grade;
    } else {
        return s1.id < s2.id;
    }
}

int main() {
    int n, c;
    scanf("%d%d", &n, &c);

    for (int i = 0; i < n; i++) {
        char name[10];
        scanf("%d %s %d", &stu[i].id, name, &stu[i].grade);
        stu[i].name = name;
    }

    if (c == 1) {
        sort(stu, stu + n, cmp_1);
    } else if (c == 2) {
        sort(stu, stu + n, cmp_2);
    } else if (c == 3) {
        sort(stu, stu + n, cmp_3);
    }

    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name.c_str(), stu[i].grade);
    }

    return 0;
}