#include <cstdio>

int main(){

    int t, k;
    scanf("%d%d",&t,&k);
    int tsum = t;
    while(k--){
        int n1, b, temp, n2;
        scanf("%d%d%d%d", &n1, &b, &temp, &n2);
        if(tsum - temp >= 0){
            if((n2 > n1 && b == 1)||(n2 < n1 && b == 0)){
                tsum += temp;
                printf("Win %d!  Total = %d.\n", temp, tsum);
            } else {
                tsum -= temp;
                printf("Lose %d.  Total = %d.\n", temp, tsum);
            }
        } else {
            printf("Not enough tokens.  Total = %d.\n", tsum);
        }
        if(tsum == 0){
            printf("Game Over.");
            break;
        }
    }

    return 0;
}