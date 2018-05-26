#include <cstdio>
const int max = 100010; //for safe.
int school[max] = {0}; //int array initialization is very very important!!!

int main() {
    //maxScore must be initialized
    //int num will be a large random number if not initialized
    //and in this question, most score may less than this random number.
    //why -1? because score may be 0.
    int n, schoolNo, score, maxSchool, maxScore = -1;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &schoolNo, &score);
        school[schoolNo] += score;
    }

    for (int i = 0; i < max; i++) {
        if (school[i] > maxScore) {
            maxSchool = i;
            maxScore = school[i];
        }
    }

    printf("%d %d", maxSchool, maxScore);


    return 0;
}