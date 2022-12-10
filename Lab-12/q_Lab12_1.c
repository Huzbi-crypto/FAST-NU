//Lab Manual - Q1 - Take two strings -> Store them in individual text files -> Merge the strings into a third text file
//Huzefa Saifuddin - 22K-5125
#include <stdio.h>
#include <stdlib.h>

void rnd_fileone();
void rnd_filetwo();

void merge_onetwo();

//main driver
int main()
{   
    //first string input
    printf("Starting first string input.\n"); 
    system("sleep 1"); //this is a linux terminal commmand that will pause for 1 second
    rnd_fileone();

    //second string input
    printf("Now, starting second string input.\n");
    system("sleep 1");
    rnd_filetwo();
    
    //merging the strings to a third text file
    printf("Lastly, merging both strings in a third text file.\n");
    system("sleep 1");
    merge_onetwo();
    
    system("sleep 1");

    //end
    printf("All completed. Check your text files now.\n");

    return 0;
}

//first string function
void rnd_fileone()
{
    FILE *fptr_one;
    char string_one[100];
    fptr_one = fopen("text_file-1.txt", "w");

    printf("Enter your string: ");
    fgets(string_one, sizeof(string_one), stdin); fflush(stdin); //"resets" the stdin

    fprintf(fptr_one, "First String: %s", string_one);

    fclose(fptr_one);
}

//second string function
void rnd_filetwo()
{
    FILE *fptr_two;
    char string_two[100];
    fptr_two = fopen("text_file-2.txt", "w");

    printf("Enter your string: ");
    fgets(string_two, sizeof(string_two), stdin); fflush(stdin); //"resets" the stdin

    fprintf(fptr_two, "Second String: %s", string_two);

    fclose(fptr_two);
}

//merge function
void merge_onetwo()
{
    FILE *rptr_one; FILE *rptr_two; FILE *fptr_merge;
    char str_one[100], str_two[100];

    rptr_one = fopen("text_file-1.txt", "r");
    rptr_two = fopen("text_file-2.txt", "r");
    fptr_merge = fopen("mergedText-file.txt", "w");

    //reading from first text file
    while (fgets(str_one, sizeof(str_one), rptr_one) != NULL) {
    fprintf(fptr_merge, "%s", str_one);
    }
    
    fclose(rptr_one);

    //reading from second text file
    while (fgets(str_two, sizeof(str_two), rptr_two) != NULL) {
    fprintf(fptr_merge, "%s"
    "--------------------------------------------------Merged Files Completed--------------------------------------------------\n", str_two);
    }

    fclose(rptr_two);
    fclose(fptr_merge);

}
