#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STEP 20
int a[MAX_STEP][4];

int b[MAX_STEP];
char *name[] = {  "空手",  "带狼",  "带羊",  "带菜" };

void search(int iStep)

{

    int i;

    if (a[iStep][0] + a[iStep][1] + a[iStep][2] + a[iStep][3] == 4)

    {

        for (i = 0; i < iStep; i++)

        {

            if (a[i][3] == 0)
            {

                printf("%s到对岸\n", name[b[i] + 1]);

            }

            else

            {

                printf("%s回本岸\n", name[b[i] + 1]);

            }

        }

        printf("\n");

        return;

    }



    for (i = 0; i < iStep; i++)

    {

        if (memcmp(a[i], a[iStep], sizeof(a[i])) == 0)

        {

            return;

        }

    }

    if (a[iStep][1] != a[iStep][3] && (a[iStep][2] == a[iStep][1] || a[iStep][0] == a[iStep][1]))

    {

        return;

    }

    for (i = -1; i <= 2; i++)

    {

        b[iStep] = i;

        memcpy(a[iStep + 1], a[iStep], sizeof(a[iStep + 1]));

        a[iStep + 1][3] = 1 - a[iStep + 1][3];

        if (i == -1)

        {

            search(iStep + 1);

        }

        else if (a[iStep][i] == a[iStep][3])

        {

            a[iStep + 1][i] = a[iStep + 1][3];

            search(iStep + 1);

        }

    }

}
int main()
{

    search(0);

    return 0;

}
