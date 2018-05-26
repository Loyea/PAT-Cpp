#include <cstdio>
#include <algorithm>

using namespace std;

struct testee {
    long long num;
    int score;
    int location;
    int local_rank;
    int final_rank;
};

bool cmp(testee t1, testee t2) {
    if (t1.score != t2.score) {
        return t1.score > t2.score;
    } else {
        return t1.num < t2.num;
    }
}

int main() {

    int size = 0;
    testee testee1[30010];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        size += k;
        int start = size - k;
        for (int j = start; j < size; j++) {
            scanf("%lld %d", &testee1[j].num, &testee1[j].score);
            testee1[j].location = i + 1;
        }
        sort(testee1 + start, testee1 + size, cmp);
        testee1[start].local_rank = 1;
        for (int j = start + 1; j < size; j++) {
            int index = j - start + 1;
            if (testee1[j].score != testee1[j - 1].score) {
                testee1[j].local_rank = index;
            } else {
                testee1[j].local_rank = testee1[j - 1].local_rank;
            }
        }
    }

    sort(testee1, testee1 + size, cmp);
    testee1[0].final_rank = 1;
    for (int i = 1; i < size; i++) {
        if (testee1[i].score != testee1[i - 1].score) {
            testee1[i].final_rank = i + 1;
        } else {
            testee1[i].final_rank = testee1[i - 1].final_rank;
        }
    }

    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%013lld %d %d %d\n", testee1[i].num, testee1[i].final_rank, testee1[i].location, testee1[i].local_rank);
    }

    return 0;
}