#include <bits/stdc++.h>
using namespace std;

char field[10][10];

bool is_empty_exist(int x, int y) {
    int src_x = (x-1)*3+1;
    int src_y = (y-1)*3+1;
    
    for (int i=src_x; i < src_x+3; i++) {
        for (int j=src_y; j < src_y+3; j++) {
            if(field[i][j] == '.') return true;
        }
    }
    return false;
}
void fill_empty(int x, int y) {
    int src_x = (x-1)*3+1;
    int src_y = (y-1)*3+1;
    for (int i=src_x; i < src_x+3; i++) {
        for (int j=src_y; j < src_y+3; j++) {
            if(field[i][j] == '.') field[i][j] = '!';
        }
    }
}

int main() {
    int x, y;
    for (int i=0; i <3; i++) {
        scanf("%c%c%c %c%c%c %c%c%c\n", &field[1+i*3][1], &field[1+i*3][2], &field[1+i*3][3], &field[1+i*3][4], &field[1+i*3][5], &field[1+i*3][6], &field[1+i*3][7], &field[1+i*3][8], &field[1+i*3][9]);
        scanf("%c%c%c %c%c%c %c%c%c\n", &field[2+i*3][1], &field[2+i*3][2], &field[2+i*3][3], &field[2+i*3][4], &field[2+i*3][5], &field[2+i*3][6], &field[2+i*3][7], &field[2+i*3][8], &field[2+i*3][9]);
        scanf("%c%c%c %c%c%c %c%c%c\n", &field[3+i*3][1], &field[3+i*3][2], &field[3+i*3][3], &field[3+i*3][4], &field[3+i*3][5], &field[3+i*3][6], &field[3+i*3][7], &field[3+i*3][8], &field[3+i*3][9]);
        scanf("\n");
    }
    cin >> x >> y;
    while(x > 3) { x -= 3; };
    while(y > 3) { y -= 3; };
    
    if (is_empty_exist(x, y)) {
        fill_empty(x, y);
    } else {
        for (int i=1;i<=3; i++) {
            for (int j=1; j<=3; j++) {
                if (i==x && j==y) continue;
                fill_empty(i, j);
            }
        }
    }
    
    for (int i=0; i <3; i++) {
        printf("%c%c%c %c%c%c %c%c%c\n", field[1+i*3][1], field[1+i*3][2], field[1+i*3][3], field[1+i*3][4], field[1+i*3][5], field[1+i*3][6], field[1+i*3][7], field[1+i*3][8], field[1+i*3][9]);
        printf("%c%c%c %c%c%c %c%c%c\n", field[2+i*3][1], field[2+i*3][2], field[2+i*3][3], field[2+i*3][4], field[2+i*3][5], field[2+i*3][6], field[2+i*3][7], field[2+i*3][8], field[2+i*3][9]);
        printf("%c%c%c %c%c%c %c%c%c\n", field[3+i*3][1], field[3+i*3][2], field[3+i*3][3], field[3+i*3][4], field[3+i*3][5], field[3+i*3][6], field[3+i*3][7], field[3+i*3][8], field[3+i*3][9]);
        printf("\n");
    }
    //dump
    // for (int i=1;i<=9; i++) {
    //     for (int j=1;j<=9; j++) {
    //         printf("%c", field[i][j]);
    //     }
    //     putchar('\n');
    // }
    // cout << x << ' ' << y << endl;
    return 0;
}