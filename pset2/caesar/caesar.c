#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//ASCII codes necessary to the counters
const int A_UP_LETTER = 65;
const int Z_UP_LETTER = 90;
const int A_LOW_LETTER = 97;
const int Z_LOW_LETTER = 122;

int encipherText(int key, string text);

//the first argument is the number of arguments inserted by the user
//the second is a array with the arguments
//argv[0] is the argument that calls the program (./caesar)
//argv[1] is the key
int main(int argc, string argv[])
{
    //will describe how to use the program if the input has more than one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //iterate the key inserted by the user
    for (int k = 0, n = strlen(argv[1]); k < n; k++)
    {
        //checking if one of the arguments is not an integer
        if (isalpha(argv[1][k]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //converting the string (ASCII code) to an integer
    int key = atoi(argv[1]) % 26;
    //asking for the input text
    string inputText = get_string("plaintext: ");
    encipherText(key, inputText);
}

int encipherText(int key, string text)
{
    //creating a array using the length of the input string to store the cipher letters
    char cipherText[strlen(text)];
    //the loop will iterate while i is less then the string length
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //uppercase and lowcase letters will be rotated
        if (text[i] >= A_UP_LETTER && text[i] <= Z_UP_LETTER)
        {
            cipherText[i] = ((text[i] + key - A_UP_LETTER) % 26) + A_UP_LETTER;
        }
        else if (text[i] >= A_LOW_LETTER && text[i] <= Z_LOW_LETTER)
        {
            cipherText[i] = ((text[i] + key - A_LOW_LETTER) % 26) + A_LOW_LETTER;
        }
        //the other characters will be preserved
        else
        {
            cipherText[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", cipherText);
    return 0;
}