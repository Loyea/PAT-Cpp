#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

struct info {
    string name;
    string pw;
    bool modified;
    info() {
        modified = false;
    }
};

int main() {
    info infos[1010];
    int n;
    scanf("%d", &n);
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> infos[i].name;
        cin >> infos[i].pw;
        int len = infos[i].pw.length();
        for (int j = 0; j < len; j++) {
            if(infos[i].pw[j] == '1') {
                infos[i].pw[j] = '@';
                infos[i].modified = true;
            } else if (infos[i].pw[j] == '0') {
                infos[i].pw[j] = '%';
                infos[i].modified = true;
            } else if (infos[i].pw[j] == 'l') {
                infos[i].pw[j] = 'L';
                infos[i].modified = true;
            } else if (infos[i].pw[j] == 'O') {
                infos[i].pw[j] = 'o';
                infos[i].modified = true;
            }
        }
        if (infos[i].modified == true) {
            count++;
        }
    }

    if (count > 0) {
        printf("%d\n", count);
        for (int i = 0; i < n; i++) {
            if (infos[i].modified == true) {
                printf("%s %s\n", infos[i].name.c_str(), infos[i].pw.c_str());
            }
        }
    } else {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    }


    return 0;
}