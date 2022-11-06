//A program to input 5 numbers in an array and print them in descending order
#include <stdio.h>

int main()
{
    float array[8];

    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &array[i]);

        if (i == 4)
        {
            for (int j = 4; j >= 0; j--)
            {
                printf("Array[%d]: %.2f\n", j, array[j]);
            }
        }
    }

    return 0;
}
