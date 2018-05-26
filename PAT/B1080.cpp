#include <cstdio>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct student{
    string name;
    double bc;
    double qz;
    double qm;
    int g;
    student(){
        bc = qz = qm = -1;
    }
};

bool cmp(student s1, student s2){
    if (s1.g != s2.g) {
        return s1.g > s2.g;
    } else {
        return s1.name < s2.name;
    }
}

int main() {
    int p, m, n;

    map<string, student> mp;

    scanf("%d%d%d", &p, &m, &n);

    while (p--){
        char a[20];
        double score;
        scanf("%s %lf", a, &score);
        string s = a;
        mp[s].name = s;
        mp[s].bc = score;
    }

    while (m--){
        char a[20];
        double score;
        scanf("%s %lf", a, &score);
        string s = a;
        mp[s].name = s;
        mp[s].qz = score;
    }

    while (n--){
        char a[20];
        double score;
        scanf("%s %lf", a, &score);
        string s = a;
        mp[s].name = s;
        mp[s].qm = score;
    }

    student s[mp.size()];
    int num = 0;

    map<string, student>::iterator iter;
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second.bc >= 200) {
            int temp_g;
            if (iter->second.qz > iter->second.qm) {
                temp_g = (int) (iter->second.qz * 0.4 + iter->second.qm * 0.6 + 0.5);
            } else {
                temp_g = (int) iter->second.qm;
            }
            iter->second.g = temp_g;
            if (temp_g >= 60) {
                s[num++] = iter->second;
            }
        }
    }

    sort(s, s + num, cmp);

    for (int i = 0; i < num; i++) {
        printf("%s %d %d %d %d\n", s[i].name.c_str(), (int)s[i].bc, (int)s[i].qz, (int)s[i].qm, s[i].g);
    }


    return 0;
}