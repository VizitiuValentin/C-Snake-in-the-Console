#include "headers.h"


// Prints the fancy menu --------------------------------------------------------------------------------------------------------
void printFancyMenu( int position )
{
    if (position == 0)
    {
        system("cls");
        printf( GAME_NAME "\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>1. START  <%c\n", CUB_TITLE, CUB_TITLE);
        printf("\033[0m");

        printf("%c 2. OPTIONS %c\n", CUB_TITLE, CUB_TITLE);
        printf("%c 3. INFO    %c\n", CUB_TITLE,CUB_TITLE);

        printf("%c 4. EXIT    %c\n"
               "%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to choose an option, press ENTER when done\n");
        fflush(stdin);
    }

    if (position == 1)
    {
        system("cls");
        printf( GAME_NAME "\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("%c 1. START   %c\n", CUB_TITLE, CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>2. OPTIONS<%c\n", CUB_TITLE,CUB_TITLE);
        printf("\033[0m");
        printf("%c 3. INFO    %c\n", CUB_TITLE,CUB_TITLE);

        printf("%c 4. EXIT    %c\n"
               "%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to choose an option, press ENTER when done\n");
        fflush(stdin);
    }

    if (position == 2) // INFO
    {
        system("cls");
        printf( GAME_NAME "\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("%c 1. START   %c\n", CUB_TITLE, CUB_TITLE);


        printf("%c 2. OPTIONS %c\n", CUB_TITLE,CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>3. INFO   <%c\n", CUB_TITLE,CUB_TITLE);
        printf("\033[0m");

        printf("%c 4. EXIT    %c\n", CUB_TITLE,CUB_TITLE);

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to choose an option, press ENTER when done\n");
        fflush(stdin);
    }

    if (position == 3)
    {
        system("cls");
        printf( GAME_NAME "\n\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("%c 1. START   %c\n", CUB_TITLE, CUB_TITLE);


        printf("%c 2. OPTIONS %c\n", CUB_TITLE,CUB_TITLE);
        printf("%c 3. INFO    %c\n", CUB_TITLE,CUB_TITLE);

        printf("\033[0;31m");
        printf("%c>4. EXIT   <%c\n", CUB_TITLE,CUB_TITLE);
        printf("\033[0m");

        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", CUB_TITLE, CUB_TITLE,CUB_TITLE, CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE,CUB_TITLE, CUB_TITLE, CUB_TITLE);
        printf("\n\n> Use the W, A, S, D keys to choose an option, press ENTER when done\n");
        fflush(stdin);
    }

}

// Prints the map --------------------------------------------------------------------------------------------------------------

void printMap( char map_matrix[16][31])
{
    int i,j;
    char chart[32] = {OUTER_WALL, OUTER_WALL, OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,
                      OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL,OUTER_WALL, OUTER_WALL, OUTER_WALL
                     };

    printf(RED "%s" RESET, chart);
    printf("   ACTION LOG: \n");
    for (i=0; i<15 ; i++)
    {
        printf(RED "%c", OUTER_WALL); // Puts the first outer wall
        for (j=0; j <= 29 ; j++)
        {
            if (map_matrix[i][j] == PLAYER)
            {
                printf( BLUE "%c", PLAYER);
            }
            else if (map_matrix[i][j] == FRUIT)
            {
                printf( YELLOW "%c", FRUIT);
            }
            else if (map_matrix[i][j] == POWER_UP)
            {
                printf( GREEN "%c",POWER_UP);
            }
            else if (map_matrix[i][j] == BODY)
            {
                printf( CYAN "%c", BODY);
            }
            else printf( RED "%c", map_matrix[i][j]);
        }
        printf( RED "%c", OUTER_WALL); // Puts the right outer wall

        if (i == 1 ) printf("   %s", logs[0]);
        if (i == 2 ) printf("   %s", logs[1]);
        if (i == 3 ) printf("   %s", logs[2]);
        if (i == 4 ) printf("   %s", logs[3]);
        if (i == 5 ) printf("   %s", logs[4]);
        printf("\n");
    }
    printf(RED "%s" RESET, chart);
}

// Map initializer, fills the map with the chosen level =====================================================================
void initializeMap(char map_matrix[16][31], short LEVEL_TYPE )
{
    int i, j;

    if (LEVEL_TYPE == 0) // NOTHING
    {
        for (i=j=0; i <= 15; )
        {
            map_matrix[i][j] = ' ';
            j++;
            if (j==30)
            {
                map_matrix[i][30] = '\0';
                j=0;
                i++;
            }
        }

    }

    if (LEVEL_TYPE == 1) // BOX
    {
        for (i=j=0; i <= 15; ) // ENTIRELY FILLS with spaces
        {
            map_matrix[i][j] = ' ';
            j++;
            if (j==30)
            {
                j=0;
                i++;
            }
        }
        for(i=0; i <= 29; i++)
        {
            // The top and bottom borders
            map_matrix[0][i] = THE_MAP_TITLE;
            map_matrix[14][i] = THE_MAP_TITLE;
            if (i < 15) // The right and left boreders
            {
                map_matrix[i][30] = '\0';
                map_matrix[i][0] = THE_MAP_TITLE;
                map_matrix[i][29] = THE_MAP_TITLE;
            }
        }
    }
    if (LEVEL_TYPE == 2) // BOX opened in the middle and 2 middle lines
    {
        for (i=j=0; i <= 15; ) // ENTIRELY FILLS with spaces
        {
            map_matrix[i][j] = ' ';
            j++;
            if (j==30)
            {
                j=0;
                i++;
            }
        }
        for(i=0; i <= 29; i++)
        {
            // The top and bottom borders
            map_matrix[0][i] = THE_MAP_TITLE;
            map_matrix[14][i] = THE_MAP_TITLE;
            if (i < 15) // The right and left boreders
            {
                map_matrix[i][30] = '\0';
                map_matrix[i][0] = THE_MAP_TITLE;
                map_matrix[i][29] = THE_MAP_TITLE;
            }
        }

        for (j=6; j < 24 ; j++) map_matrix[4][j] = THE_MAP_TITLE;
        for (j=6; j < 24 ; j++) map_matrix[10][j] = THE_MAP_TITLE;
        for (j=12; j < 18 ; j++) map_matrix[14][j] = ' ';
        for (j=12; j < 18 ; j++) map_matrix[0][j] = ' ';
        for (i=5; i < 10 ; i++) map_matrix[i][0] = ' ';
        for (i=5; i < 10 ; i++) map_matrix[i][29] = ' ';
    }

    if (LEVEL_TYPE == 3) // LOL
    {
        for (i=j=0; i <= 15; ) // ENTIRELY FILLS with spaces
        {
            map_matrix[i][j] = ' ';
            j++;
            if (j==30)
            {
                j=0;
                i++;
            }
        }

        for (i=0, j=0; i < 15;)
        {
            if (rand() % 100 < 7)
            {
                map_matrix[i][j] = THE_MAP_TITLE;
            }
            j++;
                if (j == 30)
                {
                    j=0;
                    i++;
                }
        }

    }
}

// TO UPDATE THE LOGS --------------------------------------------------------------------------------------------
void updateLogs( char logs[4][50])
{
    strcpy(logs[4], logs[3]);
    strcpy(logs[3], logs[2]);
    strcpy(logs[2], logs[1]);
    strcpy(logs[1], logs[0]);
}

void delay(double number_of_seconds)
{
    // Converting time into milli_seconds
    double milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
