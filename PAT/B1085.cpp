#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>

using namespace std;

struct school{
    double score_sum;
    int tws;    //题目要求的是整数部分！ 如果使用double进行排序可能会以为小数位不同，整数位相同的两个数产生前后差别
    string name;
    int count;
};

bool cmp(school s1, school s2){
    if (s1.tws != s2.tws) {     //!!!
        return s1.tws > s2.tws;
    } else {
        if (s1.count != s2.count) {
            return s1.count < s2.count;
        } else {
            return s1.name < s2.name;
        }
    }
}

int main() {

    int n;
    map<string, school> m;

    scanf("%d", &n);

    school s[n];

    char id[7], sch[7];
    double score;
    for (int i = 0; i < n; i++) {
        scanf("%s %lf %s", id, &score, sch);

        int len = strlen(sch);
        for (int j = 0; j < len; j++) {
            if (sch[j] >= 'A' && sch[j] <= 'Z') {
                sch[j] = sch[j] - 'A' + 'a';
            }
        }

        if(id[0] == 'T') {
            score *= 1.5;
        } else if (id[0] == 'B') {
            score /= 1.5;
        }

        string temp = sch;
        m[temp].score_sum += score;
        m[temp].name = temp;
        m[temp].count++;
    }

    int size = 0;
    map<string, school>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        s[size] = iter->second;
        s[size].tws = (int) s[size].score_sum;
        size++;
    }

    sort(s, s + size, cmp);

    printf("%d\n", size);
    int ranking = 1;
    for(int i = 0; i < size; i++){
        if (i != 0) {
            if (s[i].tws != s[i - 1].tws) {
                ranking = i + 1;
            }
        }
        printf("%d %s %d %d\n", ranking, s[i].name.c_str(), s[i].tws, s[i].count);
    }


    return 0;
}