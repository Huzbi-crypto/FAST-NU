//A program to enter a 4 or more digit, take the sum of it's individual digits and output: the number of digits, sum, square root of
//that sum

#include <stdio.h>

int sqrt_new(int sum)
{
    int sum_half = 0;
    sum_half = sum / 2;

    for (int i = 0; i < 10; i++)
    {
        sum_half = (sum_half + sum/sum_half) / 2;
    }

    return sum_half;
}

int main()
{
    int number;
    int separator = 0, count = 0, sum = 0;
    int root = 0;

    scanf("%d", &number);

    while (number != 0) 
    {
        separator = number % 10;
        sum = sum + separator;
        count = count + 1;
        number = number / 10;
    }

    int sqrt_sum = sqrt_new(sum);

    printf("Number of digits: %d\nSum of individual digits: %d\nSquare root of sum: %d", count, sum, sqrt_sum);

    return 0;
    
}