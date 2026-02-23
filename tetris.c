#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 22
#define HEIGHT 20
#define mapSize (WIDTH * (HEIGHT + 1) + 1)

char tetrisMap[mapSize];

enum blocks
{
    SQUARE,
    straightL,
    inverseL,
    STICK,
    straightZ,
    inverseZ,
    T
};

typedef struct
{
    enum blocks type;
    char body[2][4];
} tetrisBlock;

void initializeBlock(tetrisBlock block)
{
    switch (block.type)
    {
    case SQUARE:
        for (int row = 0, col = 0; row < 2; row++, col = 0)
        {
            block.body[row][col] = ' ';
            block.body[row][col+1] = ' ';
            block.body[row][col+2] = 'x';
            block.body[row][col+3] = 'x';
        }
        //DEBUG
        break;

    case straightL:
        block.body[0][0] = ' ';
        block.body[0][1] = ' ';
        block.body[0][2] = ' ';
        block.body[0][3] = 'x';
        block.body[1][0] = ' ';
        block.body[1][1] = 'x';
        block.body[1][2] = 'x';
        block.body[1][3] = 'x';
        //DEBUG
        break;

    case inverseL:
        block.body[0][0] = ' ';
        block.body[0][1] = 'x';
        block.body[0][2] = ' ';
        block.body[0][3] = ' ';
        block.body[1][0] = ' ';
        block.body[1][1] = 'x';
        block.body[1][2] = 'x';
        block.body[1][3] = 'x';
        //DEBUG
        break;

    case STICK:
        block.body[0][0] = ' ';
        block.body[0][1] = ' ';
        block.body[0][2] = ' ';
        block.body[0][3] = ' ';
        block.body[1][0] = 'x';
        block.body[1][1] = 'x';
        block.body[1][2] = 'x';
        block.body[1][3] = 'x';
        //DEBUG
        break;

    case straightZ:
        block.body[0][0] = 'x';
        block.body[0][1] = 'x';
        block.body[0][2] = ' ';
        block.body[0][3] = ' ';
        block.body[1][0] = ' ';
        block.body[1][1] = 'x';
        block.body[1][2] = 'x';
        block.body[1][3] = ' ';
        //DEBUG
        break;

    case inverseZ:
        block.body[0][0] = ' ';
        block.body[0][1] = 'x';
        block.body[0][2] = 'x';
        block.body[0][3] = ' ';
        block.body[1][0] = 'x';
        block.body[1][1] = 'x';
        block.body[1][2] = ' ';
        block.body[1][3] = ' ';
        //DEBUG
        break;

    case T:
        block.body[0][0] = ' ';
        block.body[0][1] = 'x';
        block.body[0][2] = ' ';
        block.body[0][3] = ' ';
        block.body[1][0] = 'x';
        block.body[1][1] = 'x';
        block.body[1][2] = 'x';
        block.body[1][3] = ' ';
        //DEBUG
        break;

    default:
        printf("System internal error while initializing a block");
        break;
    }
}

// Tetris map generator
void map_generate()
{
    int cont = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        tetrisMap[cont++] = '|';
        for (int j = 0; j < (WIDTH - 2) / 2; j++)
        {
            tetrisMap[cont++] = ' ';
            tetrisMap[cont++] = ' ';
        }
        tetrisMap[cont++] = '|';
        tetrisMap[cont++] = '\n';
    }
    tetrisMap[cont] = '\0';
}

void print_map()
{
    int i = 0;
    while (tetrisMap[i] != '\0')
    {
        printf("%c", tetrisMap[i]);
        i++;
    }
}

// Screen clearing
void clear_screen()
{

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    map_generate();
    print_map();
}