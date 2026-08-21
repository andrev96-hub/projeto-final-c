#include <stdio.h>
#include <stdlib.h>



#define board_width 10
#define board_height 20

int board[board_height][board_width] = {0};
int current_piece[4][4];
int piece_X = 0;
int piece_y = 0;
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

void initboard(){
    int h, w;
    for (h=0; h<board_height;){
        for (w=0; w<board_width;){
            board[h][w] = 0;    
        }
    }
}
 int Piece(){
    int random= rand() % 4;  //escolher uma das 4 formas
    int h,w;
    for (h=0 ; h<4; h++){
        for (w=0; w<4;w++){
            current_piece[h][w] = shapes[random][h][w];  // piece vai ser igual a random????
        }
    }
}

 int collision(int newX, int newY){ // ir para a nova posicao e ver se colide com outra peca ou parede
    int h, w;
    for (h=0; h<4;h++){
        for (w=0;w<4;w++){
        if (current_piece[h][w] ==1){
            int boardX = newX + w; 
            int boardY = newY + h;
        }
    }

 }
