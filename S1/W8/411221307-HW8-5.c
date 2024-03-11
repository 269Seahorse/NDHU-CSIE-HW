#include <stdio.h>

int main(){
    char board[19][19];
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            scanf("%c", &board[i][j]);
        }
    }
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 15; j++){
            if(board[i][j] == 'O' && board[i][j+1] == 'O' && board[i][j+2] == 'O' && board[i][j+3] == 'O' && board[i][j+4] == 'O'){
                printf("White");
                return 0;
            }
            if(board[i][j] == 'X' && board[i][j+1] == 'X' && board[i][j+2] == 'X' && board[i][j+3] == 'X' && board[i][j+4] == 'X'){
                printf("Black");
                return 0;
            }
        }
    }
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 19; j++){
            if(board[i][j] == 'O' && board[i+1][j] == 'O' && board[i+2][j] == 'O' && board[i+3][j] == 'O' && board[i+4][j] == 'O'){
                printf("White");
                return 0;
            }
            if(board[i][j] == 'X' && board[i+1][j] == 'X' && board[i+2][j] == 'X' && board[i+3][j] == 'X' && board[i+4][j] == 'X'){
                printf("Black");
                return 0;
            }
        }
    }
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(board[i][j] == 'O' && board[i+1][j+1] == 'O' && board[i+2][j+2] == 'O' && board[i+3][j+3] == 'O' && board[i+4][j+4] == 'O'){
                printf("White");
                return 0;
            }
            if(board[i][j] == 'X' && board[i+1][j+1] == 'X' && board[i+2][j+2] == 'X' && board[i+3][j+3] == 'X' && board[i+4][j+4] == 'X'){
                printf("Black");
                return 0;
            }
            if(board[i][j+4] == 'O' && board[i+1][j+3] == 'O' && board[i+2][j+2] == 'O' && board[i+3][j+1] == 'O' && board[i+4][j] == 'O'){
                printf("White");
                return 0;
            }
            if(board[i][j+4] == 'X' && board[i+1][j+3] == 'X' && board[i+2][j+2] == 'X' && board[i+3][j+1] == 'X' && board[i+4][j] == 'X'){
                printf("Black");
                return 0;
            }
        }
    }
    printf("No winner");
}