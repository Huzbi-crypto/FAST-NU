#include <stdio.h>

int main()
{
    int number;

    scanf("%d", &number);

    for (int i = 1; i <= number; i++)
    {
        if ((i % 2) != 0)
        {
            for (int j = 1; j <= 10; j++)
            {
                printf("%d * %d = %d\n", i, j, i*j);
            }
            
        }
        
    }

    return 0;
    
}