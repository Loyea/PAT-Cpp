#include <stdio.h>
#include <cstring>

struct person {
    char name[20];
    int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};

int main() {

    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        char a[20]= {};
        scanf("%s", a);
        if (strcmp(a, "Li") == 0) {
            leader[0].count++;
        } else if (strcmp(a, "Zhang") == 0) {
            leader[1].count++;
        } else {
            leader[2].count++;
        }
    }

    printf("Li:%d\n", leader[0].count);
    printf("Zhang:%d\n", leader[1].count);
    printf("Fun:%d\n", leader[2].count);

    return 0;
}