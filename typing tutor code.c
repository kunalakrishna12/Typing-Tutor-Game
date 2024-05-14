#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main()
{
srand(time(0));
char words[][20] = {
 "hello",
 "world",
 "typing",
 "tutor",
 "game"
};
int numWords = sizeof(words) / sizeof(words[0]);
int correct_letters = 0, incorrect_letters = 0;
while (1)
{
 int input[10],i;
 double timetaken;
 clock_t t;
int randomIndex = rand() % numWords;
 char *randomWord = words[randomIndex];
 t = clock();
 printf("Type the following word:\n%s\n", randomWord);
 char typedWord[20];
 scanf("%s", typedWord);
 t = clock() - t;
 timetaken = ((double)t)/CLOCKS_PER_SEC;
 int len = strlen(randomWord);
 for(i = 0; i < len; i++) {
 if (typedWord[i] == randomWord[i])
 correct_letters++;
 else
 incorrect_letters++;
 }
 printf("Correct letters: %d, Incorrect letters: %d\n", correct_letters, incorrect_letters);
 printf("Timetake:%.1fsec",timetaken);
 if (strcmp(typedWord, randomWord) == 0) {
 printf("Correct!\n");
 correct_letters = 0;
 incorrect_letters = 0;
 } else {
 printf("Incorrect. The correct word was:\n%s\n", randomWord);
 correct_letters = 0;
 incorrect_letters = 0;
 }
 printf("Do you want to continue? (y/n) \n");
 scanf("%s", input);
 if (input[0] == 'n')
{
 printf("Game over");
break;
 }
}
return 0;
}
