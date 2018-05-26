#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct person {
    string name;
    int age, worth;
} per[100010];

bool cmp(person s1, person s2) {
    if (s1.worth != s2.worth) {
        return s1.worth > s2.worth;
    } else {
        if (s1.age != s2.age) {
            return s1.age < s2.age;
        } else {
            return s1.name < s2.name;
        }
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        char name[10];
        scanf("%s %d %d", name, &per[i].age, &per[i].worth);
        per[i].name = name;
    }

    sort(per, per + n, cmp);

    for (int i = 1; i <= k; i++) {
        int max, amin, amax, count = 0;
        scanf("%d%d%d", &max, &amin, &amax);
        printf("Case #%d:\n", i);
        for (int j = 0; j < n; j++) {
            if (per[j].age >= amin && per[j].age <= amax) {
                count++;
                printf("%s %d %d\n", per[j].name.c_str(), per[j].age, per[j].worth);
                if (count == max) {
                    break;
                }
            }
        }
        if (count == 0) {
            printf("None\n");
        }
    }


    return 0;
}