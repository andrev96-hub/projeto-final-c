#include <stdio.h>  
#include <stdlib.h>   // lib para rand()
#include <conio.h>   // _getch() e _kbhit()
#include <windows.h>
#include <time.h>


#define board_width 10
#define board_height 20

int board[board_height][board_width] = {0};
int current_piece[4][4];
int x = 3;
int y = 0;
int score = 0;
int game_over = 0;
int next_piece_type =0;

int shapes[4][4][4] = {
    {
        {0,1,1,0},
        {0,1,1,0}, // Quadrado
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,0,0,0},
        {1,1,1,1}, // Linha
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {0,1,0,0},
        {1,1,1,0}, // T
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

void init_board() {
    for (int h = 0; h < board_height; h++) {
        for (int w = 0; w < board_width; w++) {
            board[h][w] = 0;    
        }
    }
}

int collision(int piece[4][4], int newX, int newY) {
    for (int h = 0; h < 4; h++) {
        for (int w = 0; w < 4; w++) {
            if (piece[h][w] == 1) {
                int boardX = newX + w;
                int boardY = newY + h;
                
                if (boardX < 0 || boardX >= board_width ||
                    boardY < 0 || boardY >= board_height ||
                    board[boardY][boardX] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void Piece() {
    x = 3;
    y = 0;
    for (int h = 0; h < 4; h++) {
        for (int w = 0; w < 4; w++) {
            current_piece[h][w] = shapes[next_piece_type][h][w];
        }
    }
    next_piece_type = rand() % 4;
    if (collision(current_piece, x, y)) {
        game_over = 1;
    }
}

void rotate_piece() {
    int temp[4][4];
    for (int h = 0; h < 4; h++) {
        for (int w = 0; w < 4; w++) {
            temp[w][3 - h] = current_piece[h][w];
        }
    }
    if (!collision(temp, x, y)) {
        for (int h = 0; h < 4; h++) {
            for (int w = 0; w < 4; w++) {
                current_piece[h][w] = temp[h][w];
            }
        }
    }
}

void lock() {
    for (int h = 0; h < 4; h++) {
        for (int w = 0; w < 4; w++) {
            if (current_piece[h][w] == 1) {
                board[y + h][x + w] = 1;
            }
        }
    }
}

void clear_lines() {
    for (int h = board_height - 1; h >= 0; h--) {
        int full = 1;
        for (int w = 0; w < board_width; w++) {
            if (board[h][w] == 0) {
                full = 0;
                break;
            }
        }
        if (full) {
            score += 100;
            for (int move_h = h; move_h > 0; move_h--) {
                for (int w = 0; w < board_width; w++) {
                    board[move_h][w] = board[move_h - 1][w];
                }
            }
            for (int w = 0; w < board_width; w++) {
                board[0][w] = 0;
            }
            h++;
        }
    }
}

void game() {
    
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    printf("Pontuacao: %d\n", score);
    printf("+----------+\n");
    for (int h = 0; h < board_height; h++) {
        printf("|");
        for (int w = 0; w < board_width; w++) {
            if (h >= y && h < y + 4 && w >= x && w < x + 4 && current_piece[h - y][w - x] == 1) {
                printf("O");
            } else if (board[h][w] == 1) { 
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("|");

        
        if (h == 0) {
            printf("  PROXIMA PECA:");
        } else if (h >= 1 && h <= 4) {
            printf("  ");
            int preview_row = h - 1;
            for (int pw = 0; pw < 4; pw++) {
                if (shapes[next_piece_type][preview_row][pw] == 1) {
                    printf("O");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("+----------+\n");
}

int main(void) {
    
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);

    system("cls");
    srand((unsigned int)time(NULL));
    next_piece_type = rand() % 4;
    init_board();
    Piece();

    int timer = 0;

    while (!game_over) {
        game();

        if (_kbhit()) {
            char input_key = _getch();
            if (input_key == 'a' && !collision(current_piece, x - 1, y)) {
                x--;
            } else if (input_key == 'd' && !collision(current_piece, x + 1, y)) {
                x++;
            } else if (input_key == 's' && !collision(current_piece, x, y + 1)) {
                y++;
            } else if (input_key == 'w') {
                rotate_piece();
            }
        }

        if (timer > 10) {
            if (!collision(current_piece, x, y + 1)) {
                y++;
            } else {
                lock();
                clear_lines();
                Piece();
            }
            timer = 0;
        }

        timer++;
        Sleep(30);
    }

    system("cls");
    printf("GAME OVER!\nPontuacao Final: %d\n", score);
    return 0;
}