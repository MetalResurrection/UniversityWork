#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main() {

    char email[100];
    char *at, *dot;
    bool validEmail = false;
    FILE *file;




    printf("This program will get the domain after the @ symbol in the provided email.\n\n"
           "Please enter the email (It must contain one \"@\" symbol and a \".\" after it. It must also contain letters before the \"@\" and the \".\"\n");

           while(!validEmail) {

           if (scanf("%99s", email) != 1) {
            return 1;
           }


           at = strchr(email, '@');

           if(at == NULL || at == email || strchr(at+1, '@') != NULL) {
            printf("This email doesnt contain a \"@\" or it contains more than one \"@\" or contains no letters before @, please re-enter the email with the correct format.\n");
            continue;
           }

           dot = strchr(at+1, '.');

           if(dot == NULL || dot == at + 1 || *(dot + 1) == '\0') {
                printf("This email lacks a \".\", has too many \".\", doesnt have text after the \".\", please re-enter the email with the correct format.\n");
           continue;
           }

           validEmail = true;
           }

           file = fopen("emails.txt", "a");

           if (file == NULL) {
            printf("Error opening file.");
            return 1;
           }

           fprintf(file, "%s\n", email);
           fclose(file);

           printf("The email was saved into emails.txt");






return 0;
}
