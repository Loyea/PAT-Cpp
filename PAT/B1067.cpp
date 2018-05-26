#include <cstdio>
#include <cstring>

int main(){
    int n;
    char pw[21];
    scanf("%s %d", pw, &n);
    getchar();	//read the break in the first line.
    int times = 0;
    char end[2] = "#";
    while(true){
        char temp[100010];
        gets(temp);

        if(strcmp(end, temp)==0){
            return 0;
        }

        if(strcmp(pw, temp) == 0){
            printf("Welcome in\n");
            return 0;
        } else {
            printf("Wrong password: %s\n", temp);
        }

        times++;
        if(times == n){
            printf("Account locked\n");
            return 0;
        }
    }

    return 0;
}