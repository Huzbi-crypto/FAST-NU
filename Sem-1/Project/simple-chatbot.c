// Project name: Knight_bot
// This is a chatbot with various operations that it can perform. It has a converter, it can fetch html file, it can give basic answers. While it has some limited 
// features since C itself cannot really support the actual chatbot's features and libraries this shows that it is possible to create a chatbot that you can 
// use in your everday life to make it easier, productive, and most of all, FUN!
/*
       Made by TMG-sub:
              Areeb ur Rehman 22k-6003
              Huzefa Saifuddin (Huzbi) 22K-5125
*/
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Dummy functions for converters
int volume();
int temperature();
int weight();
int distance();
int currency();

// Verfication
void teacher_ver() {
  FILE *admin_auth;
  admin_auth = fopen("admin_auth-details.txt", "w");

  char user_name[100], admin_pwd[100];

  printf("Please enter the admin name you would like to use: ");
  scanf(" %s", user_name);
  printf("Got it %s\n", user_name);
  printf("Please enter a password as well: ");
  scanf(" %s", admin_pwd);

  fprintf(admin_auth, " Username: %s | Password: %s", user_name, admin_pwd);
  fclose(admin_auth);

  printf("Got it. Done.\n");
}
void converter() {
  int choice;
  char y_n;
options:
  printf("Press (1) for Temperature Converter\nPress (2) for Weight "
         "Converter\nPress (3) for Distance Converter\nPress (4) for Currency "
         "Converter\n"
         "Press (5) for Volume Converter\nYour Decision: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    temperature();
    break;
  case 2:
    weight();
    break;
  case 3:
    distance();
    break;
  case 4:
    currency();
    break;
  case 5:
    volume();
    break;
  }
yes_no:
  printf("Want to do it again? (Y/n)\n");
  scanf(" %c", &y_n);
  if (y_n == 'y') {
    goto options;
  } else if (y_n == 'n') {
    printf("Sure! The converter shall be closed!\n");
  } else {
    printf("It seems you have entered the wrong key, I could not percieve "
           "whether you want to continue or not.\n");
    goto yes_no;
  }
}
// Pop Quiz Function
void pop_quiz() {
  char answer[100];
  int count = 0;
  printf("Beware you who treads this QUIZ! Once you enter you shall only "
         "return after completion!\n");
  printf("Beep Boop...\n");
  printf("Question 1!\n");
  printf("How many breeds of elephant are there? Just tell me the number, no "
         "need to tell their names\n");
  fgets(answer, sizeof(answer), stdin);
  fflush(stdin);
  if ((strcmp(answer, "3\n") == 0) || (strcmp(answer, "three\n") == 0)) {
    printf("Drum rolls please....\n");
    printf("Dun dun dun!\n");
    printf("Correct! You passed the first question! Genius!\n");
    count = count + 1;
  } else {
    printf("Weeh Wooh! Wrong mate! That is not the answer!\n");
    count = count - 1;
  }
  printf("What is Shakespeare's shortest play? You only have to tell then "
         "name, no need to tell the lines or words!\n");
  fgets(answer, sizeof(answer), stdin);
  fflush(stdin);
  if ((strcmp(answer, "The Comedy of Errors\n") == 0) ||
      (strcmp(answer, "the comedy of errors\n") == 0)) {
    printf("Drum rolls please....\n");
    printf("Dun dun dun!\n");
    printf("Correct yet again! You successfully passed the second question as "
           "well! Stunning performance!\n");
    count = count + 1;
  } else {
    printf("Oof! Wrong answer buddy! Thou not give up! Try again next time!\n");
    count = count - 1;
  }
  printf("What is the capital of Tanzania?\n");
  fgets(answer, sizeof(answer), stdin);
  fflush(stdin);
  if ((strcmp(answer, "Dodoma\n") == 0) || (strcmp(answer, "dodoma\n") == 0)) {
    printf("Drum rolls please....\n");
    printf("Dun dun dun!\n");
    printf("Correct yet again again!! You successfully passed the third "
           "question as well! Mind-blowing performance!\n");
    count = count + 1;
  } else {
    printf("Bam! Wrong one, challenger! Try again!\n");
    count = count - 1;
  }
  if (count > 2) {
    printf("Awesome performance, champ!\n");
    system("sleep 1");
    printf("Keep Learning!\n");
  } else if (count <= 1) {
    printf("Hmm, it was good...\n");
    system("sleep 1");
    printf("However, you need to improve! General Knowledge is important, "
           "challenger.\n");
  } else {
    printf("Absolute stellar performance! Awe-inspiring, truly!\n");
  }
}
// Constant so that it doesn't change
char user_input[100];

// The curl function that fetches html pages of the site user will enter
void html_fetch(char *ans) {
  CURL *curl = curl_easy_init();
  CURLcode response;

  FILE *file;

  file = fopen("./fetched.html", "w");

  if (!curl) {
    fprintf(stderr, "ERROR!\n");
  }

  curl_easy_setopt(curl, CURLOPT_URL, ans);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

  response = curl_easy_perform(curl);
  if (response != CURLE_OK) {
    fprintf(stderr, "Response failed.\n");
  } else {
    printf("See if it worked.\n");
  }
  curl_easy_cleanup(curl);
}

// Main Bot Operations
int main() {
  char name[50];
  char os[50];
  char windows_fetch[200];
  char site_nme[500];
  char choice;
  char verification_one[100];

  printf("Welcome lad! I am the knightly bot in your command\n");

  printf("Lad, before we start, might I know your name: ");
  scanf(" %s", name);
  getchar();

  printf("Greetings, ser %s\n", name);

  printf("While I know you are excited to start using the bot right away, "
         "please have patience.\n");
  printf(
      "There is something I'd like to ask.\nAre you sir Nadeem or Miss "
      "Sumaiyah? They might have special priviliges besides the creators: "); // A check for seeing if the user is the specified teacher or not
  fgets(verification_one, sizeof(verification_one), stdin);
  fflush(stdin);
  if ((strcmp(verification_one, "i am sir Nadeem\n") == 0) ||
      (strcmp(verification_one, "i am miss Sumaiyah\n") == 0)) {
    printf("Hello, creators' teacher!\n");
    system("sleep 1");
    printf("Nice meeting you here!\n");
    teacher_ver();
  }
  while (1) {
    printf("==>");
    // User gives any input
    fgets(user_input, 100, stdin);
    // Different choices based on what user enters
    if ((strcmp(user_input, "hi\n") == 0) ||
        (strcmp(user_input, "yo\n") == 0) ||
        (strcmp(user_input, "hello\n") == 0) ||
        (strcmp(user_input, "whats up\n") == 0) ||
        (strcmp(user_input, "what's up\n") == 0)) {
      printf("Tell me, %s. How art thou doing today?\n", name);
      fgets(user_input, 100, stdin);
      if (strcmp(user_input, "good\n") == 0) {
        printf("That is good to know. What shalt thou intend to do?\n");
      } else if ((strcmp(user_input, "not good\n") == 0)) {
        printf("That is sad to know. I hope there is someone with whom thou "
               "can talk thy heart out!\nNonetheless, I shall help thou with "
               "thy tasks, or thy orders. All I need is your command!\n");
      } else if ((strcmp(user_input, "normal\n")) ||
                 (strcmp(user_input, "so so\n") == 0)) {
        printf("I see, thou shan't get disappointed ser %s. Tomorrow shall be "
               "a great day!\nFor now, how about surfing through the web for "
               "learning or for entertainment!\nJust tell me your command!\n",
               name);
      }

    }
    // Goodbye
    else if ((strcmp(user_input, "exit\n") == 0) ||
             (strcmp(user_input, "bye\n") == 0) ||
             (strcmp(user_input, "bii\n") == 0)) {
      system("clear");
      printf("Farewell, let's meet again very soon %s!\n", name);
      break;
    }

    // Commands given to the bot to open basic stuff
    else if ((strcmp(user_input, "who created you\n") == 0) ||
             (strcmp(user_input, "Who created you?\n") == 0) ||
             (strcmp(user_input, "Who created you\n") == 0 ||
              (strcmp(user_input, "who created you?\n") == 0))) {
      printf("My owner is a very smart person who doesn't like to tell anyone "
             "about his identity.\nHowever, I shall tell thou that he is a "
             "student of FAST NU and he is a genius!\n");
    }

    // basic talks
    else if ((strcmp(user_input, "what can you do\n") == 0) ||
             (strcmp(user_input, "what do you do\n") == 0) ||
             (strcmp(user_input, "what is your purpose\n") == 0)) {
      printf("I am since in the stages of learning, I can only perform tasks "
             "that are taught to me.\n");
      printf("However, for you, %s, I can perform basic tasks and will also "
             "run a multi-purpose converter that I am sure will be helpful to "
             "you in your work!\n",
             name);
      printf("Anything more?\n");
    }

    else if ((strcmp(user_input, "i don't know\n") == 0) ||
             (strcmp(user_input, "i dunno\n") == 0) ||
             (strcmp(user_input, "idk\n") == 0 ||
              (strcmp(user_input, "i dont know?\n") == 0))) {
      printf("Gain knowledge lad. I have knowledge that I can depart but you "
             "shall ask first.\n "
             "Read Books, our creator loves to read books.\n Do the same and "
             "you will gain knowledge from people that spent years gaining the "
             "same knowledge.\n "
             "Hence, you shall become as great as creator! %s good luck on "
             "your journey!\n",
             name);
    }

    // Commands to open sites
    else if ((strcmp(user_input, "open weather\n") == 0) ||
             (strcmp(user_input, "show me weather news\n") == 0) ||
             (strcmp(user_input, "what's the weather\n") == 0) ||
             (strcmp(user_input, "whats the weather\n") == 0)) {
      printf("Showing weather news...\n");
      system("xdg-open "
             "https://www.weather.com/wx/today/"
             "?lat=24.92&lon=67.09&locale=en_US&par=google&temp=c");
      printf("Looks like the weather is marvelous today\n");
    }

    else if ((strcmp(user_input, "open youtube\n") == 0) ||
             (strcmp(user_input, "open yt\n") == 0)) {
      printf("Opening YouTube...\n");
      system("xdg-open https://www.youtube.com/");
      printf("Opened YouTube\n");
    }

    else if ((strcmp(user_input, "open google\n") == 0) ||
             (strcmp(user_input, "search\n") == 0)) {
      printf("Opening the search...\n");
      system("xdg-open https://www.google.com/");
      printf("Opened the search\n");
    }

    else if ((strcmp(user_input, "open whatsapp\n") == 0)) {
      printf("Opening WhatsApp...\n");
      system("xdg-open https://web.whatsapp.com/");
      printf("Opened WhatsApp\n");
    }

    else if ((strcmp(user_input, "open spotify\n") == 0) ||
             (strcmp(user_input, "open Spotify\n") == 0)) {
      printf("Opening Spotify...\n");
      system("xdg-open https://open.spotify.com/");
      printf("Opened Spotify\n");
    }

    else if ((strcmp(user_input, "open dawn\n") == 0) ||
             (strcmp(user_input, "open dawn news\n") == 0)) {
      printf("Opening Dawn...\n");
      system("xdg-open https://www.dawn.com/");
      printf("Opened Dawn\n");
    }

    else if ((strcmp(user_input, "open facebook\n") == 0) ||
             (strcmp(user_input, "open fb\n") == 0)) {
      printf("Opening Facebook...\n");
      system("xdg-open https://www.facebook.com/");
      printf("Opened Facebook\n");
    }

    else if ((strcmp(user_input, "open instagram\n") == 0) ||
             (strcmp(user_input, "open insta\n") == 0)) {
      printf("Opening Instagram...\n");
      system("xdg-open https://www.instagram.com/");
      printf("Opened Instagram\n");
    }

    else if ((strcmp(user_input, "open stackoverflow\n") == 0) ||
             (strcmp(user_input, "open stackexchange\n") == 0) ||
             (strcmp(user_input, "open stack overflow\n") == 0)) {
      printf("Opening Stack Overflow...\n");
      system("xdg-open https://stackoverflow.com/");
      printf("Opened Stack Overflow\n");
    }

    else if ((strcmp(user_input, "open github\n") == 0) ||
             (strcmp(user_input, "open Github\n") == 0) ||
             (strcmp(user_input, "open the site that has a cat logo\n") == 0)) {
      printf("Opening Github...\n");
      system("xdg-open https://github.com");
      printf("Opened Github\n");
    }

    else if ((strcmp(user_input, "open twitter\n") == 0) ||
             (strcmp(user_input, "open tweety\n") == 0) ||
             (strcmp(user_input, "open elon power\n") == 0)) {
      printf("Opening Twitter...\n");
      system("xdg-open https://twitter.com/");
      printf("Opened Twitter\n");
    }

    // Fetching html file
    else if ((strcmp(user_input, "fetch an html file\n") == 0) ||
             (strcmp(user_input, "i want to download a site\n") == 0) ||
             (strcmp(user_input, "i have a site to download\n") == 0)) {
      printf("Are you on Windows or Linux/MacOS?\n");
      fflush(stdin);
      fgets(os, sizeof(os), stdin);
      fflush(stdin);
      if ((strcmp(os, "windows") == 0) || (strcmp(os, "Windows") == 0)) {
        printf("The process to download your preferred site's html page will "
               "be a bit long.\n");
        printf("I can show you the procedure if you want to know.\nShall I "
               "tell you?\n");
        scanf(" %c", &choice);
        if ((choice == 'y') || (choice == 'Y')) {
          printf("You will have to download libcurl first of all. That is "
                 "important as I would not be able to fetch otherwise.\n");
          printf("I will open the link to the Windows download page of libcurl "
                 "and also a StackOverFlow post to elaborate if you might find "
                 "it difficult to download and install.\n");
          system("start https://curl.se/dlwiz/");
          printf("This is a wizard that will help you find your system's "
                 "architecture suited version of curl.\n");
          system("start "
                 "https://stackoverflow.com/questions/9507353/"
                 "how-do-i-install-and-use-curl-on-windows");
          printf("This post will help in your understanding of the "
                 "installation of curl a lot more.");
          printf("Once all is done, the fun will begin.\nWhen you are done, "
                 "just say 'fetch html -windows', without the single "
                 "apostrophe commas, of course.\n");
          fgets(os, sizeof(os), stdin);
          fflush(stdin);
          if (strcmp(windows_fetch, "fetch html -windows") == 0) {
            printf("Enter your site PROPERLY. That is important as I will "
                   "either download the wrong html file or I might not be able "
                   "to fetch it.\n");
            scanf("%s", site_nme);
            html_fetch(site_nme);
          }
        } else {
          printf("Alright, then please enter your site PROPERLY. That is "
                 "important as I will either download the wrong html file or I "
                 "might not be able to fetch it.\n");
          scanf("%s", site_nme);
          html_fetch(site_nme);
        }
      } else if ((strcmp(os, "linux") == 0) || (strcmp(os, "Linux") == 0) ||
                 (strcmp(os, "macos") == 0) || (strcmp(os, "MacOS") == 0) ||
                 (strcmp(os, "macOS"))) {
        printf("Alright, then please enter your site PROPERLY. That is "
               "important as I will either download the wrong html file or I "
               "might not be able to fetch it.\n");
        scanf("%s", site_nme);
        html_fetch(site_nme);
      } else {
        printf("Couldn't find your OS here, sorry. I know there are many, but "
               "I am a sophisticated bot.\nI don't store so much.\n");
      }
    }

    // Command to execute the converter
    else if ((strcmp(user_input, "open converter\n") == 0) ||
             (strcmp(user_input, "converter\n") == 0) ||
             (strcmp(user_input, "i want to convert something\n") == 0) ||
             (strcmp(user_input, "i want to converter\n") == 0)) {
      printf("Sure! Opening in a second!\n");
      converter();
    }

    // Command to execute a General Knowledge Pop Quiz
    else if ((strcmp(user_input, "open pop quiz\n") == 0) ||
             (strcmp(user_input, "take a pop quiz\n") == 0) ||
             (strcmp(user_input, "open quiz\n") == 0) ||
             (strcmp(user_input, "take a quiz\n") == 0)) {
      pop_quiz();
    }

    // if the command doesn't exist output this
    else {
      printf("Haha! %s, the command was unreadable!\n", name);
      printf("You might try again please! I am insufficient but sufficient for "
             "the creator!\n");
    }
  }

  return 0;
}

int temperature() {
  int temp_choice;
  float temperature, converted_temp = 0;

  printf("Press (1) for Fahrenheit to Celsius\nPress (2) for Celsius to "
         "Fahrenheit\nYour Decision: ");
  scanf("%d", &temp_choice);

  switch (temp_choice) {
  case 1:
    printf("Enter your Fahrenheit Temperature: ");
    scanf("%f", &temperature);
    converted_temp = (temperature - 32.0) * (5.0 / 9.0);
    printf("Your Temperature: %.2f\n", converted_temp);
    return 0;
    break;

  case 2:
    printf("Enter your Celsius Temperature: ");
    scanf("%f", &temperature);
    converted_temp = (temperature * (5.0 / 9.0)) + 32.0;
    printf("Your Temperature: %.2f\n", converted_temp);
    return 0;
    break;
  default:
    printf("Invalid Input\n");
    return 0;
    break;
  }
  // REMEMBER TO TAKE THE OUTPUT OUTSIDE RATHER THAN KEEP IT INSIDE THE CASES
  // REMEMBER TO ADD PARAMETERS TO THE FUNCTIONS
}

int weight() {
  int weight_choice;
  float weight, converted_weight = 0;

  printf("Press (1) for Pounds to Kilograms\nPress (2) for Kilograms to "
         "Pounds\nYour Decision: ");
  scanf("%d", &weight_choice);

  switch (weight_choice) {
  case 1:
    printf("Enter your weight in Pounds: ");
    scanf("%f", &weight);
    converted_weight = weight / 2.2;
    printf("Your Weight: %.2f\n", converted_weight);
    return 0;
    break;
  case 2:
    printf("Enter your weight in Kilograms: ");
    scanf("%f", &weight);
    converted_weight = weight * 2.2;
    printf("Your Weight: %.2f\n", converted_weight);
    return 0;
    break;
  default:
    printf("Invalid Input\n");
    return 0;
    break;
  }
  // REMEMBER TO TAKE THE OUTPUT OUTSIDE RATHER THAN KEEP IT INSIDE THE CASES
  // REMEMBER TO ADD PARAMETERS TO THE FUNCTIONS
}

int distance() {
  int distance_choice;
  float distance, converted_dist = 0;

  printf("Press (1) for Meters to Kilometers\nPress (2) for Kilometers to "
         "Meters\nYour Decision: ");
  scanf("%d", &distance_choice);

  switch (distance_choice) {
  case 1:
    printf("Enter your distance in Meters: ");
    scanf("%f", &distance);
    converted_dist = distance / 1000;
    printf("Your distance in Kilometers: %.2f\n", converted_dist);
    return 0;
    break;
  case 2:
    printf("Enter your distance in Kilometers: ");
    scanf("%f", &distance);
    converted_dist = distance * 1000;
    printf("Your distance in Kilometers: %.2f\n", converted_dist);
    return 0;
    break;
  default:
    printf("Invalid Input\n");
    return 0;
    break;
  }
  // REMEMBER TO TAKE THE OUTPUT OUTSIDE RATHER THAN KEEP IT INSIDE THE CASES
  // REMEMBER TO ADD PARAMETERS TO THE FUNCTIONS
}

int currency() {
  int curr_choice;
  float curr, converted_curr = 0, curr_rate;
  float other_curr_rate;

  printf("Press (1) for USD to PKR\nPress (2) for PKR to USD\nPress (3) for "
         "your choice to PKR\nYour Decision: ");
  scanf("%d", &curr_choice);

  switch (curr_choice) {
  case 1:
    printf("Enter USD to PKR rate: ");
    scanf("%f", &curr_rate);
    printf("Enter your amount in USD: ");
    scanf("%f", &curr);
    converted_curr = curr_rate * curr;
    printf("Your currency change is: %.2f\n", converted_curr);
    return 0;
    break;
  case 2:
    printf("Enter PKR to USD rate: ");
    scanf("%f", &curr_rate);
    printf("Enter your amount in USD: ");
    scanf("%f", &curr);
    converted_curr = curr_rate * curr;
    printf("Your currency change is: %.2f\n", converted_curr);
    return 0;
    break;
  case 3:
    printf("Enter your other currency to PKR rate: ");
    scanf("%f", &curr_rate);
    printf("Enter your amount in that amount: ");
    scanf("%f", &curr);
    converted_curr = curr_rate * curr;
    printf("Your currency change is: %.2f\n", converted_curr);
    return 0;
    break;
  default:
    printf("Invalid Input\n");
    return 0;
    break;
  }
  // REMEMBER TO TAKE THE OUTPUT OUTSIDE RATHER THAN KEEP IT INSIDE THE CASES
  // REMEMBER TO ADD PARAMETERS TO THE FUNCTIONS
}

int volume() {
  int vol_choice;
  float vol, converted_vol = 0;
  float vol_conv;
  char operator;

  printf("Press (1) for Volume in Meterscube to Centimeterscube\nPress (2) for "
         "Centimeterscube to Meterscube\nPress (3) for other Volume "
         "conversions\nYour Decision: ");
  scanf("%d", &vol_choice);

  switch (vol_choice) {
  case 1:
    printf("Enter Volume: ");
    scanf("%f", &vol);
    converted_vol = vol * 1, 000, 000;
    printf("Your Volume: %.2f\n", converted_vol);
    return 0;
    break;
  case 2:
    printf("Enter Volume: ");
    scanf("%f", &vol);
    converted_vol = vol / 1, 000, 000;
    printf("Your Volume: %.2f\n", converted_vol);
    return 0;
    break;
  case 3:
    printf("Enter the desired conversion unit value: ");
    scanf("%f", &vol_conv);
    printf("Enter the volume: ");
    scanf("%f", &vol);
    printf("Enter operator: ");
    scanf(" %c", &operator);
    switch (operator) {
    case '*':
      converted_vol = vol * vol_conv;
      break;
    case '/':
      converted_vol = vol / vol_conv;
      break;
    default:
      break;
    }
    printf("Your Volume: %.2f\n", converted_vol);
    return 0;
    break;
  default:
    printf("Invalid Input\n");
    return 0;
    break;
  }
}
