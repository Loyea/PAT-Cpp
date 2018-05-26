#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int maxn = 10000;

struct ranking {
    char course;
    int rank;
};

struct student {
    string id;
    int c, m, e, a;
    ranking r[4];
} stu[maxn];

bool cmp_c(student s1, student s2){
    return s1.c > s2.c;
}

bool cmp_m(student s1, student s2){
    return s1.m > s2.m;
}

bool cmp_e(student s1, student s2){
    return s1.e > s2.e;
}

bool cmp_a(student s1, student s2){
    return s1.a > s2.a;
}


bool cmp_stu_rnk(ranking r1, ranking r2) {
    if (r1.rank != r2.rank) {
        return r1.rank < r2.rank;
    } else {
        if (r1.course == 'A') {
            return true;
        } else if (r1.course == 'C') {
            if (r2.course != 'A') {
                return true;
            }
        } else if (r1.course == 'M') {
            if (r2.course != 'A' && r2.course != 'C') {
                return true;
            }
        } else if (r1.course == 'E') {
            return false;
        }
    }
}

int main() {
    int n, m1;
    scanf("%d%d", &n, &m1);

    int count = 0;

    while (n--) {
        char id[10];
        int c, m, e, a;
        scanf("%s%d%d%d", id, &c, &m, &e);
        a = (c + m + e) / 3;
        stu[count].id = id;
        stu[count].c = c;
        stu[count].m = m;
        stu[count].e = e;
        stu[count].a = a;
        count++;
    }

    sort(stu, stu + count, cmp_c);
    stu[0].r[0].rank = 1;
    stu[0].r[0].course = 'C';
    for (int i = 1; i < count; i++) {
        stu[i].r[0].course = 'C';
        if (stu[i].c != stu[i - 1].c) {
            stu[i].r[0].rank = i + 1;
        } else {
            stu[i].r[0].rank = stu[i - 1].r[0].rank;
        }
    }

    sort(stu, stu + count, cmp_m);
    stu[0].r[1].rank = 1;
    stu[0].r[1].course = 'M';
    for (int i = 1; i < count; i++) {
        stu[i].r[1].course = 'M';
        if (stu[i].m != stu[i - 1].m) {
            stu[i].r[1].rank = i + 1;
        } else {
            stu[i].r[1].rank = stu[i - 1].r[1].rank;
        }
    }

    sort(stu, stu + count, cmp_e);
    stu[0].r[2].rank = 1;
    stu[0].r[2].course = 'E';
    for (int i = 1; i < count; i++) {
        stu[i].r[2].course = 'E';
        if (stu[i].e != stu[i - 1].e) {
            stu[i].r[2].rank = i + 1;
        } else {
            stu[i].r[2].rank = stu[i - 1].r[2].rank;
        }
    }

    sort(stu, stu + count, cmp_a);
    stu[0].r[3].rank = 1;
    stu[0].r[3].course = 'A';
    for (int i = 1; i < count; i++) {
        stu[i].r[3].course = 'A';
        if (stu[i].a != stu[i - 1].a) {
            stu[i].r[3].rank = i + 1;
        } else {
            stu[i].r[3].rank = stu[i - 1].r[3].rank;
        }
    }

    map<string, student> mp;
    for (int i = 0; i < count; i++) {
        mp[stu[i].id] = stu[i];
    }

    while (m1--) {
        char id[10];
        scanf("%s", id);
        string id_str = id;
        if (mp.find(id_str) == mp.end()) {
            printf("N/A\n");
        } else {
            sort(mp[id_str].r, mp[id_str].r + 4, cmp_stu_rnk);
            printf("%d %c\n", mp[id_str].r[0].rank, mp[id_str].r[0].course);
        }
    }

    return 0;
}