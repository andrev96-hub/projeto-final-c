#include <stdio.h>  
#include <stdlib.h>  //lib para a funcao rand() prar gerar numeros aleatorios
#include <conio.h>   // lib para a funcao _getch(), para as teclas 
//include <windows.h>

// Definir o board
#define board_width 10
#define board_height 20

int board[board_height][board_width] = {0};
int current_piece[4][4];
int x = 3;
int y = 0;
int score = 0;
int game_over = 0;


int shapes[4][4][4]={
    {
        {0,1,1,0},
        {0,1,1,0}, // quadrado
        {0,0,0,0},
        {0,0,0,0}
    },

    {
        {0,0,0,0},
        {1,1,1,1},  // Linha
        {0,0,0,0},
        {0,0,0,0}
    },

    {
        {0,1,0,0},
        {1,1,1,0}, // T?
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {1,0,0,0},
        {1,0,0,0},
        {1,1,1,0}, // L
        {0,0,0,0}
    }
};

void init_board(){
    int h, w;
    for (h=0; h<board_height;h++){
        for (w=0; w<board_width;w++){
            board[h][w] = 0;    
        }
    }
}
 void Piece(){
    x =3;
    y =0;
    int random= rand() % 4;  //escolher uma das 4 formas
    int h,w;
    for (h=0 ; h<4; h++){
        for (w=0; w<4;w++){
            current_piece[h][w] = shapes[random][h][w];
        }
    }
}

 int collision(int newX, int newY){ // ir para a nova posicao e ver se colide com outra peca ou parede
    int h, w;
    for (h=0; h<4;h++){
        for (w=0;w<4;w++){
            if (current_piece[h][w] == 1){
                int boardX = newX + w;
                int boardY = newY + h;
                if (boardX < 0 || boardX >= board_width ||
                    boardY < 0 || boardY >= board_height ||
                    board[boardY][boardX] == 1){
                    return 1;
                }
            }
        }
    }
    return 0;
 }

 void lock() {
    int h, w;
    for (h = 0;h<4;h++){
        for(w=0;w<4;w++){
            if(current_piece[h][w] ==1){
                board[y + h][x + w] = 1;
            }
        }
    }
 }

void game() {
    int h, w;
    for (h = 0; h < 20; h++) { // 20 altura
        printf("|");
        for (w = 0; w < 10; w++) { // 10 largura
            
            if (h >= y && h < y + 4 && w >= x && w < x + 4 && current_piece[h - y][w - x] == 1) {
                printf("O");
            } else if (board[h][w] == 1) { 
                printf("X");
            } else {
             printf("."); // vazio
            }
        }
        printf("|\n");
    }
}
                            
                        
int main(void) {
    init_board();
    Piece();

    char input_key;

    while (game_over == 0) {
        game();
        input_key = _getch();

        if (input_key == 'a') {
            if (collision(x - 1, y) == 0) {
                x = x - 1;
            }
        } else if (input_key == 'd') {
            if (collision(x + 1, y) == 0) {
                x = x + 1;
            }
        } else if (input_key == 's') {
            if (collision(x, y + 1) == 0) {
                y = y + 1;
            } else {
                lock();
                Piece();
            }
        }
    }

    return 0;
}

            
        

    
