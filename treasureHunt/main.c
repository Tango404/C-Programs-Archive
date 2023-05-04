#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define MULTIPLE5 5

#define MAX_LIVES 10
#define MIN_LIVES 1

#define MAX_MOVES 15
#define MIN_MOVES 3

#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10

struct playerInfo
{
    int lives;
    char symbol;
    char history[MAX_PATH_LENGTH];
    int treasureCounter;
    int nextMove;

};

struct gameInfo
{
    int moves;
    int pathLength;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
};

int flag = 0; 
int flag2 = 0;
int i = 0;
int j = 0;

int main(void)
{

    struct playerInfo player; // To access the struct playerInfo use player.[variable]
    struct gameInfo game; // To access the struct gameInfo use game.[variable]

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

        for (i = 0; i <= MAX_PATH_LENGTH; ++i)
        {
            player.history[i] = '-';
        };

        do
        {

        printf("Set the number of lives: ");
        scanf(" %d", &player.lives);

            if (player.lives > MAX_LIVES || player.lives < MIN_LIVES)
            {
                printf("     Must be between 1 and 10!\n");
            }
            else
            {
                printf("Player configuration set-up is complete\n\n");
            }
        } while (player.lives > MAX_LIVES || player.lives < MIN_LIVES);

        printf("GAME Configuration\n");
        printf("------------------\n");

        do
        {

        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf(" %d", &game.pathLength);

            if (game.pathLength % 5 == 0)
            {
                if (game.pathLength >= MIN_PATH_LENGTH && game.pathLength <= MAX_PATH_LENGTH)
                {
                    flag = 0;
                }
                else
                {
                    printf("     Must be a multiple of 5 and between 10-70!!!\n");
                    flag = 1;
                }
            }
            else
            {
                printf("     Must be a multiple of 5 and between 10-70!!!\n");
                flag = 1;
            }

        } while (flag == 1);


        do
        {

        printf("Set the limit for number of moves allowed: ");
        scanf(" %d", &game.moves);

            if (game.moves > MAX_MOVES || game.moves < MIN_MOVES)
            {
                printf("    Value must be between 3 and 15\n");
            }

        } while (game.moves > MAX_MOVES || game.moves < MIN_MOVES);


    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n"
            "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);


/* This for loop allows the user to input number values 5 times and stores in the index's of game.bombs, 
it does it as many times as the path length */



        for (i = 0; i < game.pathLength; i += 5)
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

            for (j = 0; j < 5; j++)
            {
                scanf(" %d", &game.bombs[i + j]);
            } 
        }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n"
            "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);


/* This for loop allows the user to input number values 5 times and stores in the index's of game.treasure, 
it does it as many times as the path length */


        for (i = 0; i < game.pathLength; i+=5) 
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

            for (j = 0; j < 5; j++)
            {
                scanf(" %d", &game.treasure[i + j]); // In line scanf function, remember the arrays index starts at 0 and then moves up
            }
            
        }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");

// This for loop will go through each index of the game.bombs struct and display the values

        for (i = 0; i < game.pathLength; i++)
        {
            printf("%d", game.bombs[i]);
        }

    printf("\n");
    printf("   Treasure   : ");

// This for loop will go through each index of the game.treasure struct and display the values

        for (i = 0; i < game.pathLength; i++) 
        {
            printf("%d", game.treasure[i]);
        };

    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================");
    printf("\n\n");

    player.treasureCounter = 0;
    player.nextMove = 0;

    flag = 0;
    flag2 = 0;
    
    do{           
        if (flag == 1)
        {
            printf("\n\n");
            if (player.nextMove > 0)
            {
                for (i = 0; i < player.nextMove; i++)
                {   
                    printf(" ");
                }
                printf(" %c", player.symbol);
            }
        }
        else
        {
            printf (" ");
        }

        if (flag2 == 1)
        {
            printf("\n");
            printf("  ");
            
        }
        else
        {
            printf (" ");
        }
        
        flag = 1;
        flag2 = 1;

        for (i = 0; i < game.pathLength; i++)
        {
            printf("%c", player.history[i]);
        };
        
        printf("\n");
        printf("  ");

        
        for (i = 0, j = 1; i < game.pathLength; i += 10, j++)
        {
            printf("|||||||||%d", j);
        };

        printf("\n");
        printf("  ");

        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        };

        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasureCounter, game.moves);
        printf("+---------------------------------------------------+\n");

        do
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf(" %d", &player.nextMove);

            if (player.nextMove < 1 || player.nextMove > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
            
        } while (player.nextMove < 1 || player.nextMove > game.pathLength);

        i = player.nextMove-1;
            if (player.history[i] == '.' || player.history[i] == '$' || player.history[i] == '&' || player.history[i] == '!')
            {
                printf("\n===============> Dope! You've been here before!");
            }
            else if ((game.treasure[i] == 1) && (game.bombs[i] == 1))
            {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]");
                player.history[i] = '&';
                player.treasureCounter++;
                game.moves -= 1;
                player.lives -= 1;
            }
            else if (game.bombs[i] == 1)
            {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]");
                player.history[i] = '!';
                game.moves -= 1;
                player.lives -= 1;
            }
            else if (game.treasure[i] == 1)
            {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]");
                player.history[i] = '$';
                game.moves -= 1;
                player.treasureCounter++;
            }
            else if (game.bombs[i] == 0 || game.treasure[i] == 0)
            {
                printf("\n===============> [.] ...Nothing found here... [.]");
                player.history[i] = '.';
                game.moves -= 1;
            }
            if(player.lives == 0)
            {
                printf("\n\nNo more LIVES remaining!");
            }

        
    } while (game.moves > 0 && player.lives > 0);

        if (flag == 1)
        {
            printf("\n\n");
            if (player.nextMove > 0)
            {
                for (i = 0; i < player.nextMove; i++)
                {   
                    printf(" ");
                }
                printf(" %c", player.symbol);
            }
        }
        else
        {
            printf (" ");
        }

        if (flag2 == 1)
        {
            printf("\n");
            printf("  ");
            
        }
        else
        {
            printf (" ");
        }
        
        flag = 1;
        flag2 = 1;

        for (i = 0; i < game.pathLength; i++)
        {
            printf("%c", player.history[i]);
        };
        
        printf("\n");
        printf("  ");

        
        for (i = 0, j = 1; i < game.pathLength; i += 10, j++)
        {
            printf("|||||||||%d", j);
        };

        printf("\n");
        printf("  ");

        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        };

        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasureCounter, game.moves);
        printf("+---------------------------------------------------+\n\n");


        printf("##################\n");
        printf("#   Game over!   #\n");
        printf("##################\n\n");

        printf("You should play again and try to beat your score!\n");


    return 0;
}
