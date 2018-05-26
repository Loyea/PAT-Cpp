#include <cstdio>
#include <cstring>

int main() {

    char name[10000][15];
    char no[10000][15];
    int score[10000];
    
    int n;
    scanf("%d", &n);
    int num = 0;
    while (n--) {
        scanf("%s %s %d", name[num], no[num], &score[num]);
        num++;
    }

    for (int i = 1; i < num; i++) {
        for (int j = 0; j < num - i; j++) {
            if (score[j] < score[j + 1]) {
                int temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
                char tempno[15];
                strcpy(tempno, no[j]);
                strcpy(no[j], no[j+1]);
                strcpy(no[j+1], tempno);
                char tempname[15];
                strcpy(tempname, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], tempname);
            }
        }
    }

    printf("%s %s\n", name[0], no[0]);
    printf("%s %s", name[num-1], no[num-1]);
    
    return 0;
}