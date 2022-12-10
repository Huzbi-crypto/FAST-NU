// Lab Manual - Q2 - Write content in a text file -> Store them in said text
// file -> Check and count each letter's occurance
//-> store the count of each letter's occurance in a new text file
// Huzefa Saifuddin - 22K-5125
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes
void write_content();
void count_occurs();

//main driver
int main() {
  // writing process
  printf("Process for writing starting in a bit.\n");
  system("sleep 1"); // Bash command, won't run on windows -replace with timeout
  write_content();
  system("sleep 1"); // Bash command, won't run on windows -replace with timeout
  printf("Process ended.\n");
  system("sleep 1"); // Bash command, won't run on windows -replace with timeout

  // letter counting process
  printf("Process for letter checking starting in a bit.\n");
  system("sleep 1");
  count_occurs();
  system("sleep 1");
  printf("Process ended.\n");
  printf("All tasks are completed.\n");
  system("sleep 0.5");
  printf("Closing the program.\n");
  system("sleep 1");

  return 0;
}

// function to enter content in text format
void write_content() {
  char *string;
  FILE *fwrite;

  fwrite = fopen("text_files/write.txt", "w");

  // setup for char *string
  printf("Enter string size: ");
  system("sleep 1"); // Bash command, won't run on windows -replace with timeout
  int size;
  scanf(" %d", &size);
  getchar();
  string = (char *)(malloc(size * sizeof(char)));

  // content that will be written
  printf("Enter your string: ");
  fgets(string, size, stdin);
  fflush(stdin);

  // content written in *fwrite
  fprintf(fwrite, "Content: %s", string);

  // closing the file
  fclose(fwrite);
}

void count_occurs() {
  char str_chk; // buffer

  // character counts
  int count = 0;

  // variables to count each letter's occurance separately
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0,
      k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0,
      u = 0, v = 0, w = 0, x = 0, y = 0, z = 0, special = 0;

  FILE *fcheck;
  FILE *foccur;
  fcheck = fopen("text_files/write.txt", "r");
  foccur = fopen("text_files/letter_count.txt", "w");

  // checking process
  while ((str_chk = fgetc(fcheck)) != EOF) {
    if ((str_chk == 'A') || (str_chk == 'a'))
      a = a + 1;
    else if ((str_chk == 'B') || (str_chk == 'b'))
      b = b + 1;
    else if ((str_chk == 'C') || (str_chk == 'c'))
      c = c + 1;
    else if ((str_chk == 'D') || (str_chk == 'd'))
      d = d + 1;
    else if ((str_chk == 'E') || (str_chk == 'e'))
      e = e + 1;
    else if ((str_chk == 'F') || (str_chk == 'f'))
      f = f + 1;
    else if ((str_chk == 'G') || (str_chk == 'g'))
      g = g + 1;
    else if ((str_chk == 'H') || (str_chk == 'h'))
      h = h + 1;
    else if ((str_chk == 'I') || (str_chk == 'i'))
      i = i + 1;
    else if ((str_chk == 'J') || (str_chk == 'j'))
      j = j + 1;
    else if ((str_chk == 'K') || (str_chk == 'k'))
      k = k + 1;
    else if ((str_chk == 'L') || (str_chk == 'l'))
      l = l + 1;
    else if ((str_chk == 'M') || (str_chk == 'm'))
      m = m + 1;
    else if ((str_chk == 'N') || (str_chk == 'n'))
      n = n + 1;
    else if ((str_chk == 'O') || (str_chk == 'o'))
      o = o + 1;
    else if ((str_chk == 'P') || (str_chk == 'p'))
      p = p + 1;
    else if ((str_chk == 'Q') || (str_chk == 'q'))
      q = q + 1;
    else if ((str_chk == 'R') || (str_chk == 'r'))
      r = r + 1;
    else if ((str_chk == 'S') || (str_chk == 's'))
      s = s + 1;
    else if ((str_chk == 'T') || (str_chk == 't'))
      t = t + 1;
    else if ((str_chk == 'U') || (str_chk == 'u'))
      u = u + 1;
    else if ((str_chk == 'V') || (str_chk == 'v'))
      v = v + 1;
    else if ((str_chk == 'W') || (str_chk == 'w'))
      w = w + 1;
    else if ((str_chk == 'X') || (str_chk == 'x'))
      x = x + 1;
    else if ((str_chk == 'Y') || (str_chk == 'y'))
      y = y + 1;
    else if ((str_chk == 'Z') || (str_chk == 'z'))
      z = z + 1;
    else
      special = special + 1;
    count = count + 1;
  }

  // writing the counts in the text file
  fprintf(
      foccur,
      "*****************************************************************Letter "
      "Occurances**************************************************************"
      "***\n"
      "A/a: %d\nB/b: %d\nC/c: %d\nD/d: %d\nE/e: %d\nF/f: %d\nG/g: %d\nH/h: "
      "%d\nI/i: %d\nJ/j: %d\nK/k: %d\nL/l: %d\nM/m: %d\nN/n: %d\nO/o: %d\nP/p: "
      "%d\nQ/q: %d\nR/r: %d\nS/s: %d\n"
      "T/t: %d\nU/u: %d\nV/v: %d\nW/w: %d\nX/x: %d\nY/y: %d\nZ/z: %d\nSpecial "
      "Characters: %d\nTotal Characters: %d\n"
      "------------------------------------------------------------------End "
      "of Letter "
      "Occurances--------------------------------------------------------------"
      "----",
      a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y,
      z, special, count);

  // closing both the content and occurance files
  fclose(fcheck);
  fclose(foccur);
}
