//A program to tell on the basis of marks and experience what should the examinee get

#include <stdio.h>
#define MAX_LENGTH 100

int myFunction(int marks)
{
    int experience;
    char job;

    if (marks < 60 && marks >= 50)
    {
        job = 'T';
    }
    else if (marks >= 60 && marks < 70)
    {
        printf("Experience: ");
        scanf("%d", &experience);
        if (experience >= 1)
        {
            job = 'A';
        }
    }
    else if (marks >= 70)
    {
        printf("Experience: ");
        scanf("%d", &experience);
        if (experience >= 1)
        {
            job = 'S';
        }
    }

    switch (job)
    {
        case 'T':
            printf("You're applied for Trainee Engineer");
            return 0;
            break;
        case 'A':
            printf("You're applied for Associate Developer");
            return 0;
            break;
        case 'S':
            printf("You're applied for Assistant Developer");
            return 0;
            break;
        default:
            printf("Try again later");
            return 0;
            break;
    }
}

int main()
{
    int marks;

    printf("Marks: ");
    scanf("%d", &marks);

    myFunction(marks);
    return 0;
}
