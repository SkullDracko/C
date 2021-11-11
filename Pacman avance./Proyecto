#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#define H 30
#define W 60

void Input();
void Display();
void Initialize();
void Move_Sprites();

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

char Juego[H][W] = {
    { "############################################################" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "#                                                          #" },
    { "############################################################" },
};

int main(){
    Initialize();
    while(1){
        Input();
        Move_Sprites();
        Display(); 

        Sleep( 100 );
    }
}

void Initialize(){
    for (int i = 0; i < H; i++)
        for (int j= 0; j < W; j++){
            // Dibujar Comida.
            if(Juego[i][j] == ' ')
                Juego[i][j] = '.';
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
}

void Display(){
    system("cls");
    system("COLOR 6");
    for (int i = 0; i < H; i++){
        for (int j= 0; j < W; j++){
            printf("%c", Juego[i][j]);
        }  
        printf("\n");
    }
    printf("Score: %d\n", Player.Comida);
}
