#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> vi[2510];

char name[40010][5];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int c;
        scanf("%s %d", name[i], &c);
        for (int j = 0; j < c; j++) {
            int temp;
            scanf("%d", &temp);
            vi[temp].push_back(i);
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, vi[i].size());
        sort(vi[i].begin(), vi[i].end(), cmp);
        for (int j = 0; j < vi[i].size(); j++) {
            printf("%s\n", name[vi[i][j]]);
        }
    }


    return 0;
}