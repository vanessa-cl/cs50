#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//ASCII codes necessary to check if the characters are either uppercase or lowercase
const int A_UP_LETTER = 65;
const int Z_UP_LETTER = 90;
const int A_LOW_LETTER = 97;
const int Z_LOW_LETTER = 122;

//uses both alphabets to replace the key on the encipher function
const string UPPERCASE_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string LOWERCASE_ALPHABET = "abcdefghijklmnopqrstuvwxyz";

int encipherText(string text, string key);

//the first argument is the number of arguments inserted by the user
//the second is a array with the inserted arguments

int main(int argc, string argv[])
{
    //will describe how to use the program if the input has more than one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //checks if the key is bigger than the number of letters of the alphabet
    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("The key must contain 26 characters \n");
        return 1;
    }

    char keyLetters[26];
    //iterate the key inserted to check if it is a valid key
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        //checks if a character is not alphabetic
        if (!isalpha(argv[1][i]))
        {
            printf("The key must contain only alphabetic characters\n");
            return 1;
        }

        //checks for lowercase characters
        if (argv[1][i] >= A_LOW_LETTER && argv[1][i] <= Z_LOW_LETTER)
        {
            //converts the key to uppercase
            argv[1][i] = toupper(argv[1][i]);
        }

        //checks for repeated characters in the key
        for (int j = 0; j < 26; j++)
        {
            if (argv[1][i] == keyLetters[j])
            {
                printf("Key: %c\n", argv[1][i]);
                printf("Key Letters: %c\n", keyLetters[j]);
                printf("The key must not contain repeated letters\n");
                return 1;
            }
            keyLetters[j] = argv[1][i];
        }
    }

    //asks the user for the text to encipher
    string inputText = get_string("plaintext: ");
    encipherText(inputText, argv[1]);
}

int encipherText(string text, string key)
{
    //array to store the new text
    char cipherText[strlen(text) + 1];

    //loops through the text characters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //loops through the alphabet
        for (int j = 0; j < 26; j++)
        {
            //checks if the text character is a uppercase letter
            if (text[i] >= A_UP_LETTER && text[i] <= Z_UP_LETTER)
            {
                //checks if the text character is present in the uppercase alphabet
                if (text[i] == UPPERCASE_ALPHABET[j])
                {
                    //replaces the found letter for the respective key in uppercase
                    cipherText[i] = toupper(key[j]);
                }
            }
            //checks if the text character is a lowercase letter
            else if (text[i] >= A_LOW_LETTER && text[i] <= Z_LOW_LETTER)
            {
                //checks if the text character is present in the lowercase alphabet
                if (text[i] == LOWERCASE_ALPHABET[j])
                {
                    //replaces the found letter for the respective key in lowercase
                    cipherText[i] = tolower(key[j]);
                }
            }
            //the other characters will be preserved
            else
            {
                cipherText[i] = text[i];
            }
        }
    }
    printf("ciphertext: %s\n", cipherText);
    return 0;
}