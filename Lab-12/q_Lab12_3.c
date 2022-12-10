// Lab Manual - Q3 - Take 20 students data -> Store them in a text file -> Read
// students data according to scores asked by the user 
// Huzefa Saifuddin - 22K-5125
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct std_data
{
    char std_id[50];
    char std_name[100];
    char gender[50];
    float quiz_one, quiz_two;
    float mid_term, finals, total_score;
};

//prototypes
struct std_data students_info();
void write_std_data(struct std_data *std_data);

//main driver
int main()
{
    struct std_data std_data[3];

    printf("*********************************************************WECLOME TO STUDENT DATA CENTER*********************************************************\n");
    printf("Please wait, the process will start in a bit...\n");
    system("sleep 1");

    // called the function to write students' data
    *std_data = students_info();

    printf("Data taken.\n");
    system("sleep 1");

    // now starting the writing process
    printf("Now starting the process of writing...\n");
    write_std_data(std_data);
    printf("\nWriting completed successfully.\n");
    system("sleep 1");

    return 0;

}

//student data function
struct std_data students_info()
{
    struct std_data data[3];

    for (int i = 0; i < 3; i++) {
    printf("Data for Student #%d\n", i+1);
    printf("Enter student ID: ");
    scanf(" %s", data[i].std_id);
    printf("wait a bit...\n"); system("sleep 1");
    
    printf("Enter student's name: ");
    scanf(" %s", data[i].std_name);
    printf("wait a bit...\n"); system("sleep 1");

    printf("Enter student's gender: ");
    scanf(" %s", data[i].gender);
    printf("wait a bit...\n"); system("sleep 1");

    printf("Enter student's quiz #1 score: ");
    scanf("%f", &data[i].quiz_one);
    printf("wait a bit...\n"); system("sleep 1");

    printf("Enter student's quiz #2 score: ");
    scanf("%f", &data[i].quiz_two);
    printf("wait a bit...\n"); system("sleep 1");

    printf("Enter student's mid-term's score: ");
    scanf("%f", &data[i].mid_term);
    printf("wait a bit...\n"); system("sleep 1");

    printf("Enter student's final term's score: ");
    scanf("%f", &data[i].finals);
    printf("**********************************************************************************************************************\n");
    if (i != 2) 
        printf("starting again...\n\n"); system("sleep 1");

    (data + i)->total_score = ((data + i)->quiz_one) + ((data + i)->quiz_two) + ((data + i)->mid_term) + ((data + i)->finals);
    }
    
    return *data;

}

//writing student data function
void write_std_data(struct std_data *std_data)
{
    FILE *fwrite;
    fwrite = fopen("text_files/student_data.txt", "w");

    if (fwrite == NULL) {
        printf("ERROR! Cannot open the FILE.\n");
        exit(1);
    }

    fprintf(fwrite, "--------------------------------------------STUDENT DATA COLLECTION CENTER--------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("writing student's ID...\n");
        fprintf(fwrite, "Student #%d:\nStudent's ID: %s\n", (i+1), std_data[i].std_id);
        system("sleep 1");

        printf("writing student's name...\n");
        fprintf(fwrite, "Student's name: %s\n", std_data[i].std_name);
        system("sleep 1");

        printf("writing student's gender...\n");
        fprintf(fwrite, "Student's gender: %s\n", std_data[i].gender);
        system("sleep 1");

        printf("writing student's quiz #1 score...\n");
        fprintf(fwrite, "Student's quiz #1's score: %.2f\n", std_data[i].quiz_one);
        system("sleep 1");

        printf("writing student's quiz #2 score...\n");
        fprintf(fwrite, "Student's quiz #2's score: %.2f\n", std_data[i].quiz_two);
        system("sleep 1");

        printf("writing student's mid-term's score...\n");
        fprintf(fwrite, "Student's mid-term's score: %.2f\n", std_data[i].mid_term);
        system("sleep 1");

        printf("writing student's final term's score...\n");
        fprintf(fwrite, "Student's final term's score: %.2f\n", std_data[i].finals);
        system("sleep 1");

        fprintf(fwrite, "***********************************************************************************************************************\n");

        printf("Student #%d data written...\n", (i+1));
        if (i != 2) 
            printf("starting again...\n\n"); system("sleep 1");
        system ("sleep 1");
    }

    fclose(fwrite);

}
