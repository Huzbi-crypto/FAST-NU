#include <stdio.h>
#define MAX_LENGTH 100

int myFunction(int sizeofArray)
{
    int myArray[sizeofArray];
    int count_one=0, count_two=0, count_three=0, count_four=0, count_five=0, count_six=0, count_seven=0, count_eight=0, count_nine=0, count_zero=0;

    for (int i = 0; i < sizeofArray; i++) {
    printf("Enter a random number betweeon 0 and 10: ");
    scanf("%d", &myArray[i]);
    switch (myArray[i]) {
        case 1:
        count_one = count_one + 1;
        continue;
        case 2:
        count_two = count_two + 1;
        continue;
        case 3:
        count_three = count_three + 1;
        continue;
        case 4:
        count_four = count_four + 1;
        continue;
        case 5:
        count_five = count_five + 1;
        continue;
        case 6:
        count_six = count_six + 1;
        continue;
        case 7:
        count_seven = count_seven + 1;
        continue;
        case 8:
        count_eight = count_eight + 1;
        continue;
        case 9:
        count_nine = count_nine + 1;
        continue;
        case 0:
        count_zero = count_zero + 1;
        continue;
    }
    }

    printf("Number|Counts\n1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n7: %d\n8: %d\n9: %d\n0: %d\n", count_one, count_two, count_three, count_four, count_five, count_six, count_seven, count_eight, count_nine, count_zero);
    return 0;
}

int main()
{
    int sizeofArray;

    printf("Enter size of array: ");
    scanf("%d", &sizeofArray);

    myFunction(sizeofArray);
    return 0;
}