//A program to find out whether an integer array of six elements is symmetric or not.
#include <stdio.h>

int main()
{
    int array[8];
    int k = 0, count = 0;

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &array[i]);

        if (i == 5)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("Array[%d]: %d\n", j, array[j]);

                while (k <= 6)
                {
                    if ((array[k] == array[5-k]))
                    {
                        count = count + 1;
                    }

                    k++;
                }
            }
        }
    }

    if (count == 6)
    {
        printf("Array is symmetric.\n");
    }
    else
    {
        printf("Array is not symmetric.\n");
    }

    return 0;

}
