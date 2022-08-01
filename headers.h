#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


#ifndef FUNC
#define FUNC

char logs[4][50]; // Global variable, used for the logging actions

// Functions explained in the functions file
void printFancyMenu( int position );
void printMap( char map_matrix[16][31] );
void initializeMap(char map_matrix[16][31], short LEVEL_TYPE );
void updateLogs( char logs[4][50]);
void delay(double number_of_seconds);

#endif // FUNC

// Colors for printf
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m" // Resets the color to normal

#define THE_MAP_TITLE 219 // The char of the actual map

#define GAME_NAME "SNAKE IN CONSOLE" // Used when you print the fancy menu
#define OUTER_WALL 177 // The char used by the outer wall
#define CUB_TITLE 219 // Used for the fancy menu, change to make the menu borders different

#define PLAYER 2 // Symbol of the head of the snake
#define FRUIT 3  // Symbol of the fruit
#define POWER_UP 4  // Symbol of the POWER UP
#define BODY '0' // Symbol of the snake body




