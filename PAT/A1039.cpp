#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 26 * 26 * 26 * 10 + 10;

vector<int> vi[M];

int get_id(char name[]) {
    int result = 0;
    for (int i = 0; i < 3; i++) {
        result = result * 26 + (name[i] - 'A');
    }
    result = result * 10 + (name[3] - '0');
    //见书本P110，出现数字的话，直接将数字加到末尾，也就是把前面的乘以10加上数字
    return result;
}

int main() {
    char name[5];
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++) {
        int course, m;
        scanf("%d %d", &course, &m);
        for (int j = 0; j < m; j++) {
            scanf("%s", name);
            int id = get_id(name);
            vi[id].push_back(course);
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = get_id(name);
        sort(vi[id].begin(), vi[id].end());
        printf("%s %d", name, vi[id].size());
        for (int j = 0; j < vi[id].size(); j++) {
            printf(" %d", vi[id][j]);
        }
        printf("\n");
    }


    return 0;
}