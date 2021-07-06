#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 2
char ch[10] = {'#', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void square();
int win(char c);
void ask();
int main()
{
    square();
    ask();
    return 0;
}
void square()
{
    system("CLS");
    printf("      Tic-Tac-Toe\n\n\n");
    printf("    Player-1  V/S  Player-2\n\n");
    printf("    |    |    \n");
    printf("  %c | %c  | %c \n", ch[1], ch[2], ch[3]);

    printf("____|____|____\n");
    printf("    |    |    \n");

    printf("  %c | %c  | %c \n", ch[4], ch[5], ch[6]);

    printf("____|____|____\n");
    printf("    |    |    \n");

    printf("  %c | %c  | %c \n", ch[7], ch[8], ch[9]);

    printf("    |    |    \n");
}

int win(char c)
{
    int returnValue = 0;

    if (ch[1] == ch[2] && ch[2] == ch[3])
        returnValue = 1;
    else if (ch[4] == ch[5] && ch[5] == ch[6])
        returnValue = 1;
    else if (ch[7] == ch[8] && ch[8] == ch[9])
        returnValue = 1;
    else if (ch[1] == ch[4] && ch[4] == ch[7])
        returnValue = 1;
    else if (ch[2] == ch[5] && ch[5] == ch[8])
        returnValue = 1;
    else if (ch[3] == ch[6] && ch[6] == ch[9])
        returnValue = 1;
    else if (ch[1] == ch[5] && ch[5] == ch[9])
        returnValue = 1;
    else if (ch[3] == ch[5] && ch[5] == ch[7])
        returnValue = 1;
    else if (ch[1] != '1' && ch[2] != '2' && ch[3] != '3' && ch[4] != '4' && ch[5] != '5' && ch[6] != '6' && ch[7] != '7' &&
             ch[8] != '8' && ch[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return (returnValue);
}

void ask()
{
    int i = 0, returnValue = -1, count = 0;
    int visited;

    while (returnValue == -1)
    {
        ++i;
    label:
        if (i % 2 != 0)
        {
            visited = false;
            int j;
            scanf("%d", &j);
            if (ch[j] == 'X' || ch[j] == '#')
            {
                visited = true;
            }
            if (visited == false)
            {
                ch[j] = 'X';

                square();
                char temp = ch[j];
                returnValue = win(temp);
                ++count;
            }
            else
            {
                goto label;
            }
        }
        else
        {

            int k;
            scanf("%d", &k);
            if (ch[k] == '#' || ch[k] == 'X')
            {
                visited = true;
            }
            if (visited == false)
            {
                ch[k] = ch[0];
                square();
                char temp = ch[k];
                returnValue = win(temp);
                ++count;
            }
            else
            {
                goto label;
            }
        }

        if (count % 2 != 0 && returnValue == 1)
            printf("Player 1 Win\n");
        else if (count % 2 == 0 && returnValue == 1)
            printf("Player 2 win\n");
        else if (returnValue == 0)
            printf("Match draw\n");
    }
}