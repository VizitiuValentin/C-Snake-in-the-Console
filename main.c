/*
* Made by VIZITIU VALENTIN IULIAN
* 19.12.2021
* 3 - 4 days
* 500 lines of code
*/

#include "headers.h"

int main()
{
    system("cls"); // Needed once so colors display correctly

    char map_matrix[16][31]; // 15 linii si 30 elemente pe fiecare rand + 1 spatiu pt '\0'
    char menu_option, menu_position, control_key;

    int location_y, location_x, current_direction; // X = coloana, Y = linia
    int body[10000][2];
    int del_x, del_y, q=0, p=0;
    int LENGTH = 0;
    int board_color = 0, player_color = 0;
    int its_first_frame;
    int dif_choise;
    int frame, frame_counter = -1;

    float DIFFICULTY, initial_Dif;

    short fruit_flag=0, fruit_flag1=0, power_flag=0, level_type=-1;
    short EXIT_LOOP_BREAKER = 0; // For pressing ESC to leave current game...

    FILE *save_file = fopen("save_file.txt", "r+");
    if (save_file == NULL)
    {
        save_file = fopen("save_file.txt", "w+"); // Creates new file if it doesn't exist already
        fprintf(save_file, "%d", 0);
    }


    int high_score;

    // 1 = Up    / W
    // 2 = Left  / A
    // 3 = Down  / S
    // 4 = Right / D

    srand(time(0)); // Sets the current time as seed for the rand() function. DONT PUT IT IN THE FUNCTION ITSELF

    while (1)
    {
// =====================================================================================================
        printFancyMenu(menu_position);
        menu_option = toupper(getch());

        if (menu_option == 'S') menu_position++;
        if (menu_option == 'W') menu_position--;

        if (menu_position == 4) menu_position = 0;
        if (menu_position == -1) menu_position = 3;

        if (menu_position == 0 && menu_option == 0xd) menu_option = 1;
        if (menu_position == 1 && menu_option == 0xd) menu_option = 2;
        if (menu_position == 2 && menu_option == 0xd) menu_option = 3;
        if (menu_position == 3 && menu_option == 0xd) menu_option = 4;

        for (int i = 0; i < 10000 ; i++) // Fills the matrix that stored old position with 0
            body [i][0] = 0;
// =====================================================================================================
        if (menu_option > 0 && menu_option < 5) // ignore, optimization
            switch(menu_option)
            {
            case 1:
                printf("\e[?25h"); // Enables the cursor

                // Reset so no bugs if previous games happened
                fruit_flag = 0;
                power_flag = 0;
                LENGTH = 0;
                q=0;
                p=0;
                its_first_frame = 1;
                dif_choise = 0;
                DIFFICULTY = -1;
                frame = 0;
                fruit_flag1 = 1;
                EXIT_LOOP_BREAKER = 0;

                rewind(save_file);
                fscanf(save_file, "%d", &high_score); // Reads the save file for earlier high scores

                short start_spot = rand() % 4;

                switch (start_spot) // Determinates the starting location out of the 4 spots
                {
                case 0:
                    location_x = 5;
                    location_y = 3;
                    current_direction = 4;
                    break;
                case 1:
                    location_x = 5;
                    location_y = 11;
                    current_direction = 4;
                    break;
                case 2:
                    location_x = 24;
                    location_y = 3;
                    current_direction = 2;
                    break;
                case 3:
                    location_x = 24;
                    location_y = 11;
                    current_direction = 2;
                    break;
                }
// =====================================================================================================
// Difficulty selection...
                for (;;)
                {
                    fflush(stdin);
                    system("cls");
                    printf("Pick a difficulty: \n\nTIP: The difficulty changes how quick the snake moves. The recommended is FAST.\n"
                           "Tip2: Hold the CTRL key and use your mouse wheel to zoom in and out easily\n\n"
                           GREEN  "1. EASY\n"
                           YELLOW "2. MEDIUM\n"
                           BLUE "3. FAST\n"
                           RED "4. AS FAST AS POSSIBLE\n" RESET
                           "============================\nType the number next to the mode and press ENTER: " );
                    scanf("%d", &dif_choise);
                    switch (dif_choise)
                    {
                    case 1:
                        DIFFICULTY = 0.3;
                        break;
                    case 2:
                        DIFFICULTY = 0.2;
                        break;
                    case 3:
                        DIFFICULTY = 0.1;
                        break;
                    case 4:
                        DIFFICULTY = 0.03;
                        break;
                    default:
                        fflush(stdin);
                        printf("INVALID OPTION!\nPLEASE INPUT THE NUMBER NEXT TO THE DIFFICULTY'S NAME AND PRESS ENTER!\n");
                        printf("Press any key to continue...");
                        getch();
                    }
                    if (DIFFICULTY != -1) break;
                }
                initial_Dif = DIFFICULTY;

// LEVEL SELECTION =====================================================================================
                for (;;)
                {

                    int flag3 = 0;
                    fflush(stdin);
                    system("cls");
                    printf("Pick a level layout:\n"
                           GREEN  "1. No walls\n"
                           YELLOW "2. Box\n"
                           BLUE "3. Box with cut edges and 2 middle lines\n"
                           RED "4. Randomized\n" RESET
                           "============================\nType the number next to the level and press ENTER: " );
                    fflush(stdin);
                    scanf("%d", &dif_choise);
                    switch (dif_choise)
                    {
                    case 1:
                        level_type = 0;
                        flag3 = 1;
                        break;
                    case 2:
                        level_type = 1;
                        flag3 = 1;
                        break;
                    case 3:
                        level_type = 2;
                        flag3 = 1;
                        break;
                    case 4:
                        level_type = 3;
                        flag3 = 1;
                        break;
                    default:
                        fflush(stdin);
                        printf("INVALID OPTION!\nPLEASE INPUT THE NUMBER NEXT TO THE DIFFICULTY'S NAME AND PRESS ENTER!\n");
                        printf("Press any key to continue...");
                        getch();
                        break;
                    }
                    if (flag3 == 1) break;
                }
                initializeMap( map_matrix, level_type ); // Initializes the map with the chosen level
// =====================================================================================================
                printf("\e[?25l"); // Hides the cursor, so there are no artifacts while playing
                for (;;)
                {
                    if (EXIT_LOOP_BREAKER == 1)
                    {
                        printf( RESET );
                        break;
                    }
                    frame++;
                    frame_counter--;
                    system("cls");
                    printMap(map_matrix);
                    printf( GREEN "\n\nSnake Length: %d" RESET, LENGTH);
                    printf( YELLOW "\nHigh score: %d" RESET, high_score);
                    printf( MAGENTA "\n\nUse WASD to move around.");
                    // Head Position:( %d, %d)\n" RESET, location_y, location_x);
                    // printf( CYAN "Frame Number: %d", frame);
                    if(frame_counter > -1) printf( GREEN "\nPower up time left: %d frames", frame_counter);
                    if (frame_counter == 0)
                    {
                        DIFFICULTY = initial_Dif;
                    }
// =====================================================================================================
                    // Fruit placement...
                    if (fruit_flag == 0 && its_first_frame == 0)
                    {
                        int x,y;
                        while (1)
                        {
                            // Sets random (y, x) coord for the fruit
                            y = rand() % 14 + 1;
                            x = rand() % 28 + 1;
                            if (map_matrix[y][x] != ' ') continue; // If the spot is not empty tries again

                            map_matrix[y][x] = FRUIT;
                            fruit_flag = 1;
                            break;

                        }
                    }
// =====================================================================================================
                    // POWER-UP placement...
                    if (power_flag == 0 && rand() % 100 == 1 && its_first_frame == 0)
                    {
                        int x,y;
                        while (1)
                        {
                            // Sets random (y, x) coord for the power up
                            y = rand() % 14 + 1;
                            x = rand() % 28 + 1;
                            if (map_matrix[y][x] != ' ') continue; // If the spot is not empty tries again

                            map_matrix[y][x] = POWER_UP;
                            power_flag = 1;
                            updateLogs(logs);
                            strcpy(logs[0], CYAN "A POWER UP APPEARED!" RESET);
                            break;
                        }
                    }
// =====================================================================================================
// IF a key is pressed the game calculates the next move and so on, if ESC it exits UPDATE: no need, its easy to die and leave
                    delay(DIFFICULTY); // Adds delay to wait for a key, if no key pressed continues
                    if ( _kbhit() )
                    {
                        control_key = 0;
                        fflush(stdin);
                        control_key = toupper(getch());
                        fflush(stdin);

// W ===================================================================================================
                        switch (control_key)
                        {
                        case 27: // Pressing ESC
                            EXIT_LOOP_BREAKER = 1;
                            break;
                        case 'W':
                            if (map_matrix[location_y-1][location_x] != ' ' && map_matrix[location_y-1][location_x] != FRUIT  && map_matrix[location_y-1][location_x] != POWER_UP)
                            {
                                updateLogs(logs);
                                strcpy(logs[0], "You can't move that way!");
                            }

                            else current_direction = 1;
                            break;

// A ===================================================================================================
                        case 'A':

                            if (map_matrix[location_y][location_x-1] != ' ' && map_matrix[location_y][location_x-1] != FRUIT && map_matrix[location_y][location_x-1] != POWER_UP)
                            {
                                updateLogs(logs);
                                strcpy(logs[0], "You can't move that way!");
                            }
                            else current_direction = 2;
                            break;

// S ===================================================================================================
                        case 'S':

                            if (map_matrix[location_y+1][location_x] != ' ' && map_matrix[location_y+1][location_x] != FRUIT && map_matrix[location_y+1][location_x] != POWER_UP)
                            {
                                updateLogs(logs);
                                strcpy(logs[0], "You can't move that way!");
                            }
                            else current_direction = 3;
                            break;

// D ===================================================================================================
                        case 'D':

                            if (map_matrix[location_y][location_x+1] != ' ' && map_matrix[location_y][location_x+1] != FRUIT && map_matrix[location_y][location_x+1] != POWER_UP)
                            {
                                updateLogs(logs);
                                strcpy(logs[0], "You can't move that way!");
                            }
                            else current_direction = 4;
                            break;
                        default:
                            break;
                        }
                    }
// ===================================================================================================
                    // Always does this even if no key was pressed
                    // NEXT MOVMENT
                    if (current_direction == 4)
                    {
                        map_matrix[location_y][location_x] = ' ';
                        location_x++;
                        if (location_x == 30) location_x = 0;
                    }
                    else if (current_direction == 3)
                    {
                        map_matrix[location_y][location_x] = ' ';
                        location_y++;
                        if (location_y == 15) location_y = 0;
                    }
                    else if (current_direction == 2)
                    {
                        map_matrix[location_y][location_x] = ' ';
                        location_x--;
                        if (location_x == -1) location_x = 29;
                    }
                    else  if (current_direction == 1)
                    {
                        map_matrix[location_y][location_x] = ' ';
                        location_y--;
                        if (location_y == -1) location_y = 14;
                    }
// ===================================================================================================
                    /* This has nothing to do with how the last segment is deleted
                    *  It only spawns a BODY in your previous position
                    *  After eating a fruit , a body part always appears in your last head position
                    */
                    if (LENGTH > 0)
                    {
                        map_matrix[location_y][location_x] == PLAYER;

                        if (current_direction == 1) //UP
                        {
                            if (location_y == 14)
                                map_matrix[0][location_x] = BODY;
                            else map_matrix[location_y+1][location_x] = BODY;

                        }

                        else if (current_direction == 2) // LEFT
                        {
                            if (location_x == 29)
                                map_matrix[location_y][0] = BODY;
                            else map_matrix[location_y][location_x+1] = BODY;
                        }

                        else if (current_direction == 3) // DOWN
                        {
                            if (location_y == 0)
                                map_matrix[14][location_x] = BODY;
                            else map_matrix[location_y-1][location_x] = BODY;
                        }

                        else if (current_direction == 4) // RIGHT
                        {
                            if (location_x == 0)
                                map_matrix[location_y][29] = BODY;
                            else map_matrix[location_y][location_x-1] = BODY;
                        }
                    } // End of if
// ===================================================================================================
                    if (map_matrix[location_y][location_x] == FRUIT || its_first_frame > 0) // EAT FRUITS
                    {
                        LENGTH++;
                        fruit_flag1 = 0;
                        if (its_first_frame == 0) fruit_flag--;
                        if (its_first_frame == 0)
                        {
                            updateLogs(logs);
                            strcpy(logs[0], YELLOW "YOU ATE A FRUIT! CURRENT LENGTH +1" RESET );
                        }

                        // Makes your initial length 2, then switched to normal
                        if (its_first_frame != 0) its_first_frame++;
                        if (its_first_frame == 3) its_first_frame = 0;

                    }
// ===================================================================================================
                    else if (map_matrix[location_y][location_x] == POWER_UP) // EAT POWER
                    {
                        power_flag = 0;
                        updateLogs(logs);
                        strcpy(logs[0], CYAN "YOU ATE A POWER UP!" RESET );

                        int power_type = rand() % 2;

                        if (power_type == 0) // Places 5 extra hearts on  the map
                        {
                            fruit_flag += 5;
                            updateLogs(logs);
                            strcpy(logs[0], CYAN "5 MORE FRUITS APPEAREED!!!" RESET );
                            for (int x=0; x < 5 ; x++)
                            {
                                int x,y;
                                while (1)
                                {
                                    // Sets random (y, x) coord for the fruit
                                    y = rand() % 14 + 1;
                                    x = rand() % 28 + 1;
                                    if (map_matrix[y][x] != ' ') continue; // If the spot is not empty tries again
                                    map_matrix[y][x] = FRUIT;
                                    break;
                                }
                            }
                        }

                        if (power_type == 1)
                        {
                            updateLogs(logs);
                            strcpy(logs[0], CYAN "SPEED LOWERED FOR 25 FRAMES!!!" RESET );

                            DIFFICULTY = 0.3;
                            frame_counter = 25;
                        }

                    }
// ===================================================================================================
                    // For checking if you died
                    else if ( map_matrix[location_y][location_x] != ' ')
                    {
                        printf( CYAN "\nGAME OVER!\nPress ENTER to return to the main menu...\n" RESET);
                        fflush(stdin);
                        while (1)
                        {
                            char ok = getch();
                            if (ok == 0xd) break;
                        }
                        break;
                    }
// ===================================================================================================
                    if (LENGTH > 0) // Stores the current position in a matrix, for the segment deletion later
                    {
                        body[q][0] = current_direction;
                        q++;
                    }

// ===================================================================================================
                    // Deletes the last BODY segment of the snake, based on the LENGTH
                    if (LENGTH > 0 && fruit_flag1 == 1) // If ate a fruit skip a deletition
                    {
                        del_x = location_x;
                        del_y = location_y;

                        body[p][0] = 5; // Deletes the stored direction of the deleted segment
                        p++;
                        for (int i = p-1; i <= 10000 ; i++)
                        {
                            if      (body[i][0] == 1) // UP, W
                            {
                                del_y++;
                                if (del_y == 15) del_y = 0;
                            }
                            else if (body[i][0] == 2) // LEFT, A
                            {
                                del_x++;
                                if (del_x == 30) del_x = 0;
                            }
                            else if (body[i][0] == 3) // DOWN, S
                            {
                                del_y--;
                                if (del_y == -1) del_y = 14;
                            }
                            else if (body[i][0] == 4) // RIGHT, D
                            {
                                del_x--;
                                if (del_x == -1) del_x = 29;
                            }
                        }
                        map_matrix[del_y][del_x] = ' '; // Deletes segment
                    }
                    fruit_flag1 = 1;
// ===================================================================================================

                    // Needed, don't delete, don't worry. Puts the snakes head on the new position
                    map_matrix[location_y][location_x] = PLAYER;
                } // END OF 'FOR' loop

                if (LENGTH > high_score)
                {
                    high_score = LENGTH;
                    rewind(save_file);
                    fprintf(save_file, "%-10d", high_score);
                }

                break;
// OPTIONS =====================================================================================================================
            case 2:
                for (char option_choise;;)
                {
                    system("cls");
                    fflush(stdin);
                    printf(RESET "What do you wish to change?" RESET);
                    printf(YELLOW "\n\nR. Reset the high score" RESET);
                    printf(BLUE "\nM. Return to the main menu" RESET);

                    printf("\n==============================================="
                           "\nPlease select an option >");
                    scanf("%c", &option_choise);
                    option_choise = toupper(option_choise);

                    switch (option_choise)
                    {
                    case 'R':
                        system("cls");

                        printf("The current high score is %d, it will be reset to 0.\nThis option cannot be reversed.", high_score);
                        printf( RED "\nAre you SURE that you wish to reset the high score? (Y / N)\n" RESET);

                        fflush(stdin);
                        scanf("%c", &option_choise);
                        option_choise = toupper(option_choise);
                        fflush(stdin);

                        if (option_choise != 'Y') break;


                        rewind(save_file);
                        fprintf(save_file, "%-10d", 0);
                        rewind(save_file);
                        fscanf(save_file, "%d", &high_score);

                        printf("\nSuccessfully reset the high score to %d\nPress any key to continue.", high_score);
                        getch();
                        break;
                    case 'M':
                        break;
                    default:
                        printf(RED "Invalid option. Please type the letter next to the option's name and press ENTER." RESET);
                        getch();
                        break;
                    }
                    if (option_choise == 'M') break;
                }
                system("cls");
                break;
//==============================================================================================================================
            case 3:
                system("cls");
                printf(GREEN "Game created by: VIZITIU VALENTIN IULIAN\n" );
                printf( CYAN "Date: 19.12.2021\nGroup: 3112b\n" RESET);
                printf("\nUse WASD to change the direction of the snake..\nWhen you eat a " YELLOW
                       "FRUIT" RESET " (or the hearts), your snake length will be increased by 1\n"
                       GREEN "POWER-UPS" RESET " have a 1 percent (1 in 100) chance to appear every frame\n"
                       "The possible power-ups are:\n"
                       "- 5 extra FRUITS appear on the map\n"
                       "- you will move at a slow speed for 25 frames\n");

                printf("\nPress any key to return to the main menu...\n");
                getch();
                fflush(stdin);
                break;

            case 4:
                system("cls");
                printf(GREEN "THANKS FOR PLAYING!\n\n" RESET);
                return 0;
                // If you add more cases to the switch put a break above this comment
            } // SWITCH END ( menu option )
    }// WHILE END ( infinite menu )
    fclose(save_file);
}// MAIN END


