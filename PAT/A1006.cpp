#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct student {
    string id;
    int sign_in_time;
    int sign_out_time;
};

bool cmp_sign_in(student s1, student s2){
    return s1.sign_in_time < s2.sign_in_time;
}

bool cmp_sign_out(student s1, student s2) {
    return s1.sign_out_time > s2.sign_out_time;
}

int main() {
    student stu[100010];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> stu[i].id;
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        stu[i].sign_in_time = h * 60 * 60 + m * 60 + s;
        scanf("%d:%d:%d", &h, &m, &s);
        stu[i].sign_out_time = h * 60 * 60 + m * 60 + s;
    }

    sort(stu, stu + n, cmp_sign_in);
    printf("%s ", stu[0].id.c_str());

    sort(stu, stu + n, cmp_sign_out);
    printf("%s", stu[0].id.c_str());

    return 0;
}