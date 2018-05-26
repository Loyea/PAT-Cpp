#include <cstdio>
#include <cstring>

int min(int a, int b){
    if(a > b){
        return b;
    } else {
        return a;
    }
}

bool is_letter(char a) {
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

bool is_digit(char a) {
    return a >= '0' && a <= '9';
}

char days[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    char s[4][61];
    for(int i = 0; i < 4; i++){
        scanf("%s", s[i]);
    }
    int len0 = strlen(s[0]);
    int len1 = strlen(s[1]);
    int temp = min(len0, len1);
    char first = 0, second = 0;
    for(int i = 0; i < temp; i++){
        if(first == 0 && s[0][i] >= 'A' && s[0][i] <= 'G'){
            if(s[0][i] == s[1][i]){
                first = s[0][i];
                continue;
            }
        }

        if(first != 0){
            if((s[0][i] >= 'A' && s[0][i] <= 'N') || is_digit(s[0][i])){
                if(s[0][i] == s[1][i]){
                    second = s[0][i];
                    break;
                }
            }
        }

    }


    int len2 = strlen(s[2]);
    int len3 = strlen(s[3]);
    temp = min(len2, len3);
    int mins = 0;
    for(int i = 0; i < temp; i++){
        if(is_letter(s[2][i])){
            if(s[2][i] == s[3][i]){
                mins = i;
                break;
            }
        }
    }

    int day = first - 'A';
    int hour = 0;
    if(second >= '0' && second <= '9'){
        hour = second - '0';
    } else {
        hour = second - 'A' + 10;
    }

    printf("%s %02d:%02d", days[day], hour, mins);

    return 0;
}