#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

#define H 30
#define W 60

void Input();
void Display();
void Initialize();
void Move_Sprites();
void Move_Ghosts();

// Estructuras Principales para el Juego.
struct Position {
    int x;
    int y;
};

struct Pacman {
    struct Position position;
    int vx;
    int vy;
    int Vidas;
    bool Persiguiendo;
    int Comida;
};

struct Fantasma {
    struct Position position;
    int vx;
    int vy;
    bool Persiguiendo;
};

// Definir Personajes para empezar Juego.
struct Fantasma Fantasmas[5];
struct Pacman Player = {
    {
        .x = 1,
        .y = 1,
    },
    .vx = 0,
    .vy = 0,
    .Vidas = 3,
    .Persiguiendo = false,
    .Comida = 0
};

bool Mover = false;
char Juego[H][W] = {
    { "############################################################" },
    { "#                          ######                          #" },
    { "#   ####  ##########       ######       ##########  ####   #" },
    { "#   ####  ##########       ######       ##########  ####   #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#   ####   #        ####################        #   ####   #" },
    { "#          #                 ##                 #          #" },
    { "#          #####             ##             #####          #" },
    { "#          #                 ##                 #          #" },
    { "#          #                                    #          #" },
    { "#                                                          #" },
    { "#          #        #########  #########        #          #" },
    { "#          #        #                  #        #          #" },
    { "#          #        #                  #        #          #" },
    { "#          #        ####################        #          #" },
    { "#                                                          #" },
    { "#                   ####################                   #" },
    { "#                            ##                            #" },
    { "#                            ##                            #" },
    { "#     #######    ########    ##    ########    #######     #" },
    { "#           #                                  #           #" },
    { "#           #                                  #           #" },
    { "####                ####################                ####" },
    { "#        ##                  ##             ##             #" },
    { "#        ##                  ##             ##             #" },
    { "#    ##########              ##         ##########         #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "############################################################" },
};

int main(){
    Initialize();
    while(1){
        Input();
        Move_Sprites();
        Move_Ghosts();
        Display();
    }
}

void Initialize(){
    for (int i = 0; i < H; i++)
        for (int j= 0; j < W; j++){
            // Dibujar Comida.
            if(Juego[i][j] == ' ')
                Juego[i][j] = '.';
        }

    for (int i = 0; i < 5; i++){
        Fantasmas[i].vx = 0;
        Fantasmas[i].vy = 0;
        Fantasmas[i].Persiguiendo = true;

        int x,y;
        do{
            x = 1 + rand() % (W-1);
            y = 1 + rand() % (H-1);
        } while(Juego[y][x] != '.');
        Fantasmas[i].position.x = x;
        Fantasmas[i].position.y = y;
        Juego[y][x] = 'F';
    }
}


void Input(){
    if(kbhit()){
        char C_1 = getch();
        if(C_1 == -32){
            char C_2 = getch();

            Player.vx = 0;
            Player.vy = 0;

            switch(C_2){
                case 72: Player.vy = -1; break;
                case 80: Player.vy = +1; break;
                case 75: Player.vx = -1; break;
                case 77: Player.vx = +1; break;
            }
        }
    }
}

void Move_Sprites(){
    Juego[Player.position.y][Player.position.x] = ' ';

    int nx = Player.vx + Player.position.x;
    int ny = Player.vy + Player.position.y;

    if(Juego[ny][nx] == '#'){
        Player.vx = 0;
        Player.vy = 0;
    }

    Player.position.x += Player.vx;
    Player.position.y += Player.vy;

    if(Juego[ny][nx] == '.')
        Player.Comida++;

    Juego[Player.position.y][Player.position.x] = 'O';

    Mover = !Mover;
}

void Move_Ghosts(){
    // Fantasmas
    if(Mover == true){
        for (int i = 0; i < 5; i++){
            int x = Fantasmas[i].position.x;
            int y = Fantasmas[i].position.y;
            Juego[y][x] = '.';

            if(x > Player.position.x){
                x--;
            } else if(x < Player.position.x){
                x++;
            } else if(x == Player.position.x){
                if(y > Player.position.y){
                    y--;
                } else if(y < Player.position.y){
                    y++;
                }
            }

            Fantasmas[i].position.x = x;
            Fantasmas[i].position.y = y;
            Juego[y][x] = 'F';
        }
    }
}

void Display(){
    system("cls");
    for (int i = 0; i < H; i++){
        for (int j= 0; j < W; j++){
            if(Juego[i][j] == '#')
                printf("%c", Juego[i][j]);
            else if(Juego[i][j] == '.')
                printf("%c", Juego[i][j]);
            else if(Juego[i][j] == 'O')
                printf("%c", Juego[i][j]);
            else if(Juego[i][j] == 'F')
                printf("%c", Juego[i][j]);
            else
                printf("%c", Juego[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", Player.Comida);
}
