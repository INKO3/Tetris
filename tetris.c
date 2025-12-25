#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 22
#define HEIGHT 20
#define mapSize (WIDTH * (HEIGHT + 1) + 1)

char tetrisMap[mapSize];

enum blocks {
    SQUARE, straightL, inverseL, STICK, straightZ, inverseZ, T
};

//Tetris map generator
void map_generate(){
    int cont = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        tetrisMap[cont++] = '|';
        for (int j = 0; j < (WIDTH-2)/2; j++)
        {
            tetrisMap[cont++] = ' ';
            tetrisMap[cont++] = ' '; 
        }
        tetrisMap[cont++] = '|';
        tetrisMap[cont++] = '\n';
    } 
    tetrisMap[cont] = '\0';   
}

void print_map(){
    int i = 0;
    while (tetrisMap[i] != '\0')
    {
        printf("%c", tetrisMap[i]);
        i++;
    }
}

//Screen clearing
void clear_screen() {
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}





int main(){
    map_generate();
    print_map();
}