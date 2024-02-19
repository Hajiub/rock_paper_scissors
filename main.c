/*******************************************************************************
*
* Program: Rock Paper Scissors Game
*
* Author: Abraham the goat
*
*******************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXBUF 10
#define SIZE(array) (sizeof array / sizeof array[0]) 
static const char *choices[3] = {
    "paper",
    "rock",
    "scissors"
};

void panic(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr,"\n");
    va_end(ap);
    exit(1);
}

int getChoice(char *buffer, int lim)
{
    printf("Enter paper, rock, scissors: ");
    if(fgets(buffer, lim, stdin) == NULL)
        panic("couldn't read from stdin");

    else if (buffer[strlen(buffer) - 1] != '\n')
    {
       int c; 
       while ((c = getchar()) != '\n' && c != EOF);
    } 

    buffer[strcspn(buffer, "\n")] = '\0';
    return strlen(buffer);
}

void toLowerCase(char *str)
{
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int isValidChoice(char *choice)
{
    toLowerCase(choice);
    int left = 0;
    int right = SIZE(choices) - 1;
    int cond;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if ((cond = strcmp(choice, choices[mid])) == 0)
            return mid;

        else if (cond < 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int randint(int a, int b)
{
    
    return a + rand() % (b - a + 1);
}

int computerChoice()
{
    return randint(0, SIZE(choices) - 1);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    const char *prog = *av; 
    char buffer[MAXBUF];
    int human, computer;
    while (1) {
        getChoice(buffer, MAXBUF);
        if((human = isValidChoice(buffer)) == -1)
            panic("%s: Invalid choice re run the program bitch!", prog);

        computer = computerChoice();
        printf("You: %s, computer:  %s\n", choices[human], choices[computer]);
        if (computer == human)
            printf("Tie\n");

        else if (computer == 0) {
            if (human == 1)
                printf("Computer wins!\n");
            else 
                printf("You win!\n");
        }

        else if (computer == 1) {
            if (human == 0)
                printf("You win!\n");
            else
                printf("Computer wins!\n");
        }
        else if(computer == 2) {
            if (human == 0)
                printf("Computer wins!\n");
            else
                printf("You win!\n");
        } 
    }
    return 0;
}
