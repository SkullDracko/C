#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Game[100][100];
int Revealed[100][100];
int Sides = 10;

void Menu();
void Display();
void Create();
void Reveal();
void Create();
void Update();

int main()
{
    Menu();
    return 0;
}
void Menu()
{
    printf("Minesweeper: SkullDracko Edition.\n");
    printf("1. Play\n2. Exit\n");
    int i=0;
    do
    {
        scanf("%d", &i);
    }
    while(i<1 && i>2);
    switch(i)
    {
        case 1:
            Create();
            Reveal();
        break;
        case 2:
            return;
        break;
    }
}

void Create()
{
    for(int i=0;i<=Sides-1;i++)
    {
        int Mine = (rand() % Sides);
        for(int k=0; k<=Sides-1; k++)
        {
            Revealed[i][k] = 0;
            if(k==Mine) 
                Game[i][k] = 9;
            else
                Game[i][k] = 0;
        }
    }
    Update();
}

void Update()
{
    for(int i=0;i<=Sides-1;i++)
    {
        for(int k=0; k<=Sides-1; k++)
        {
            if(Game[i][k]==9)
            {
        
                if(k!=Sides-1){
                    if(Game[i][k+1]!=9) Game[i][k+1]+=1;
                }
                if(k!=0){ 
                    if(Game[i][k-1]!=9) Game[i][k-1]+=1;
                }
               
                if(i!=0)
                {
                    if(Game[i-1][k]!=9) Game[i-1][k]+=1;
                   
                    if(k!=Sides-1){
                       if(Game[i-1][k+1]!=9) Game[i-1][k+1]+=1; 
                    } 
                    if(k!=0){
                        if(Game[i-1][k-1]!=9) Game[i-1][k-1]+=1;  
                    }  
                }
                
                if(i!=Sides-1)
                {
                    if(Game[i+1][k]!= 9) Game[i+1][k]+=1;
                    
                    if(k!=Sides-1){
                        if(Game[i+1][k+1]!=9) Game[i+1][k+1]+=1;  
                    } 
                    if(k!=0){
                        if(Game[i+1][k-1]!=9) Game[i+1][k-1]+=1;     
                    } 
                }
            }
        }
    }    
    Display();
}


void Display()
{
   
    for (int i = 0; i <= Sides-1; i++){
        for (int k = 0; k <= Sides-1; k++){
            if(Revealed[i][k] == 1)
                if(Game[i][k]==9)
                    printf("x");
                else
                    printf("%d", Game[i][k]);
            else
                printf("-");
        }
        printf("\n");
    } 
}


int CheckWin()
{   
    int l=0;
    for (int i = 0; i <= Sides-1; i++){
        for (int k = 0; k <= Sides-1; k++){
            if(Game[i][k]!=9){
                if(Revealed[i][k]==1)l++;
            }
        }
    }
    
    if(l==(Sides-1)*Sides) 
        return 1;
    else
        return 0;
}

void Reveal()
{
    int i,k;
    printf("Please Enter the Y Position you want to choose:\n");
    scanf("%d", &i);
    printf("Please Enter the X Position you want to choose:\n");
    scanf("%d", &k);
    i=i-1;
    k=k-1;
   
    if(Revealed[i][k]==1)
    {
        printf("That spot was already Revealed.\n"); 
        Reveal();
    }
  
    else
    {
        Revealed[i][k]=1;
       
        if(Game[i][k]==9)
        {
            Display();
            printf("You lost!\n");
            Menu();
        }
        else if(CheckWin()==1)
        {
            Display();
            printf("You won!\n");
            Menu();
        }
        else
        {
        
        Display();
        Reveal();
        }
    }
}
