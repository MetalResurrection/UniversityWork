#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int BinaryToDecimal();
int DecimalToBinary();
int DecimalToHexadecimal();
int HexadecimalToDecimal();

int main() {
    printf("How do you wanna convert?\n");  //Part of the code that asks the user what they want
    bool run = 1;
    while (run) {
            int ConversionNumber = 1;

            while (1) {
    printf("[1] Binary to Decimal? \n[2] Decimal to Binary? \n[3] Hexadecimal to Decimal? \n[4] Decimal to Hexadecimal?\n[5] END TASK\n");
    scanf("%d", &ConversionNumber);
    if (ConversionNumber < 1 || ConversionNumber > 5) {
        printf("Please insert a valid number (1-5)!\n");
    } else {
    break;
    }
}

    if(ConversionNumber == 1) {                             //The different choices and the functions following them
        printf("Starting Binary to Decimal.\n");
        BinaryToDecimal();
    }

    if (ConversionNumber == 2) {
        printf("Starting Decimal to Binary.\n");
        DecimalToBinary();
    }

    if (ConversionNumber == 3) {
        printf("Starting Hexadecimal to Decimal.\n");
        HexadecimalToDecimal();
    }

    if (ConversionNumber == 4) {
        printf("Starting Decimal to Hexadecimal.\n");
        DecimalToHexadecimal();
    }

    if (ConversionNumber == 5) {
        break;
    }


    };

return 0;
}

int BinaryToDecimal() {                   //Function that turns Binary numbers into Decimal numbers
    char BinaryString[65];
    int DecimalValue = 1;
    int total = 0;
    int BinaryLength = 0;


while (1) {
printf("Please write your number \n");


scanf("%s", BinaryString);

 bool ValidNumbers = 1;
 BinaryLength = strlen(BinaryString);                                  //Gets the length of the number which is later used in (for) to check if all the numbers are valid (0 and 1's)

 for (int i = (BinaryLength-1); i >= 0; i--) {                      //Checks if the number contains number that arent 0 or 1
        if(BinaryString[i] != '0' && BinaryString[i] != '1') {
            ValidNumbers = 0;
            break;
        }
 }
  if (!ValidNumbers) {
    printf("Number is not a binary number, please use only 1's and 0's\n\n");
    }else {
        break;
    }
  }
  for (int i = (BinaryLength-1); i >= 0; i--) {
    if (BinaryString[i] == '1') total += DecimalValue;
    DecimalValue *= 2;
  }

       printf("Decimal Number:  %d\n\n", total);


  };







  int DecimalToBinary() {                                  //Function that turns Decimal numbers into Binary
      int DecimalNumber;
      bool IsEqualToZero = 0;

      while(1) {
        printf("Please enter a non-negative decimal number: \n");

        if (scanf("%d", &DecimalNumber) != 1) {                              //Checks if the number has letters in it
                printf("Invalid input, please use digits only.\n\n");

        while (getchar() != '\n');
        continue;
        }

        if (DecimalNumber < 0) {
            printf("Please enter a positive number. \n\n");                 //Checks if the inserted number in positive
        } else {
        break;}
      }

      if (DecimalNumber == 0) {
        printf("Binary number: 0 \n\n");                                       //Checks if the inserted number is equal to zero, if so it prints out Binary umber = 0
        IsEqualToZero = 1;

      }
      if(IsEqualToZero != 1) {

      int Binary[32];
      int i = 0;
      int Temp = DecimalNumber;

      while (Temp > 0) {
       Binary[i] = Temp % 2;
       Temp = Temp / 2;
       i++;
      }

      printf("Binary number: ");
      for (int j= i - 1; j >= 0; j--) {
        printf("%d", Binary[j]);
      }
      printf("\n\n");

      }

  }

















  int HexadecimalToDecimal(){                        //Function that turns Hexadecimal numbers into Decimal
      char HexString[65];
      int DecimalNumber;

      while(1) {
        printf("Please enter a Hexadecimal number \n");
        scanf("%s", HexString);

        bool IsValid = 1;
        int HexLength = strlen(HexString);

        for (int i = (HexLength-1); i < 0; i--) {                                              //Checks if the given number is withing the ranges of 0-9 and A-F
            char c = HexString[i];
            if (!((c >= '0' &&   c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
                IsValid = 0;
                break;
            }
        }
        if (!IsValid) {
            printf("Invalid input! Please use only digits (0-9) and letters (A-F).\n");
        } else {
        break;
        }



      }

      sscanf(HexString, "%x", &DecimalNumber);    //Converts the string into a int

      printf("Decimal number %d, \n\n", DecimalNumber);

  };

















  int DecimalToHexadecimal() {                       //Function that turns Decimal numbers into Hexadecimal
       int DecimalNumber;

      while(1) {
        printf("Please enter a decimal number: \n");

        if (scanf("%d", &DecimalNumber) != 1) {                           //Checks if numbers are being typed and not letters
                printf("Invalid input, please use digits only.\n\n");

        while (getchar() != '\n');
        continue;
        }

        else {
        break;}
      }

      if(DecimalNumber < 0) {                                      //If the inputed number is negative, it gives a negative Hexadecimal number
        DecimalNumber *= -1;
        printf("Hexadecimal number: -%X\n\n", DecimalNumber);
      } else {
      printf("Hexadecimal number: %X\n\n", DecimalNumber); }
  };






