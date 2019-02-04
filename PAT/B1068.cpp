#include <cstdio>

const int n = (1 << 24);

struct coordinate {
    int x, y;
};

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int colors[n] = {0};
int main() {

    int pixel[1010][1010] = {0};

    coordinate result;
    int size = 0;

    int m, n, tol;
    scanf("%d%d%d", &m, &n, &tol);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &pixel[i][j]);
            colors[pixel[i][j]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int color = pixel[i][j];
            if (colors[color] != 1) {//审题不清！没看到唯一颜色的点，导致无法ac
                continue;
            }
            bool valid = true;

            for (int x_offset = -1; x_offset <= 1; x_offset++) {
                for (int y_offset = -1; y_offset <= 1; y_offset++) {
                    if (x_offset == 0 && y_offset == 0) {
                        continue;
                    }
                    int temp_x = i + x_offset;
                    int temp_y = j + y_offset;
                    if(temp_x >=0 && temp_x < n && temp_y >=0 && temp_y < m) {
                        int vicinity_color = pixel[temp_x][temp_y];
                        if (abs(color - vicinity_color) <= tol) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) {
                    break;
                }
            }

            if (valid) {
                size++;
                result.x = i;
                result.y = j;
            }
        }
    }

    if (size == 0) {
        printf("Not Exist");
    } else if (size == 1) {
        printf("(%d, %d): %d", result.y + 1, result.x + 1, pixel[result.x][result.y]);
    } else {
        printf("Not Unique");
    }


    return 0;
}