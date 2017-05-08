/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int dddd;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *x, int *y)
 
{
    int zzzz;
    zzzz = *x;
    *x = *y;
    *y = zzzz;
    }

 

int main(int argc, string argv[])
{
   
   
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    dddd = atoi(argv[1]);
    if (dddd < DIM_MIN || dddd > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < dddd; i++)
        {
            for (int j = 0; j < dddd; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < dddd - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}


void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}


void init(void)
{
    int n = dddd * dddd - 1;
    int i = 0;
    int j = 0;
    for(i = 0;i < dddd;i++)
    {
        for(j = 0;j < dddd;j++)
        {
            
            board[i][j] = n;
            n--;
            if (dddd % 2 == 0)
            {
                board[dddd - 1][dddd - 2] = 2;
                board[dddd - 1][dddd - 3] = 1;
                }
        }
    }
}


void draw(void)
{
    for (int i = 0; i < dddd; i++)
    {
        for (int j = 0; j < dddd; j++)
        {
            if (board[i][j] > 9)
            { 
                printf(" %i", board[i][j]);}
            if (board[i][j] > 0 && board[i][j] < 10)
            {   
                printf("%2i ",board[i][j]); }
            if (board[i][j] == 0)
            {
                printf(" _"); }
        } 
        printf("\n");
   }

    //jyfyf
}

