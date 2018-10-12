#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Compare_Message.h"
#include <locale.h>
#define MAX_STR 256


int main()
{

    setlocale(LC_ALL, "");

    int i, response;
    char message[256];
    char letters[256];
    int check;

    printf("Program to determine if the text message can be composed out of the chosen letters. \n");

    printf("Write your message: \n");
    fgets(message,MAX_STR,stdin);

    while(message[0]=='\n')
    {
        printf("Write your message: \n");
        fgets(message,MAX_STR,stdin);
    }


    printf("Write the group of letters to use: \n");
    fgets(letters,MAX_STR,stdin);

    while(letters[0]=='\n')
    {
        printf("Write the group of letters to use: \n");
        fgets(letters,MAX_STR,stdin);
    }
//check if there are only letters
    for(i = 0; i<(strlen(letters)-1); i++)
    {
        check=isalpha(letters[i]);

        while(check==0)
        {
            printf("Detected other characters besides letters.\n ");
            printf("Write the group of letters to use: \n");
            fgets(letters,MAX_STR,stdin);
            check=isalpha(letters[i]);
            i=0;
        }

    }


    //Compare strings:
    response=Compare_Message(message, letters);

    printf("\nThe text message can be composed out of the letters: ");
    if(response)
        printf(" True \n");
    else
        printf(" False \n");

    memset(letters, 0, MAX_STR);
    memset(message, 0, MAX_STR);

    return 0;

}
