#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int m[100010] = {0};

    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        a++;
        b++;
        m[a] = b;
        m[b] = a;
    }

    int k;
    scanf("%d", &k);
    int c[100010] = {0};
    int size = 0;
    for(int i = 0; i < k; i++){
        int temp;
        scanf("%d", &temp);
        temp++;
        if(m[temp] != 0){
            m[temp] = 0;
        } else {
            c[size++] = temp;
        }
    }

    for(int i = 0; i < 100010; i++){
        int temp = m[i];
        if(temp != 0) {
            if(m[temp] != 0){
                continue;
            }
            c[size++] = temp;
        }
    }

    printf("%d\n", size);

    sort(c, c + size);

    for(int i = 0; i < size; i++){
        printf("%05d", c[i] - 1);
        if (i != size - 1) {
            printf(" ");
        }
    }

    return 0;
}