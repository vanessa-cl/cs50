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
    string key = argv[1];

    //will describe how to use the program if the input has more than one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //checks if the key is bigger than the number of letters of the alphabet
    if (strlen(key) < 26 || strlen(key) > 26)
    {
        printf("The key must contain 26 characters \n");
        return 1;
    }

    char keyLetters[26];
    //iterate the key inserted to check if it is a valid key
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        //converts the key to uppercase
        key[i] = toupper(key[i]);

        //checks if a character is not alphabetic
        if (!isalpha(key[i]))
        {
            printf("The key must contain only alphabetic characters\n");
            return 1;
        }

        //checks for repeated characters in the key
        for (int j = 0, m = strlen(keyLetters); j < 26; j++)
        {
            if (key[i] == keyLetters[j])
            {
                printf("The key must not contain repeated letters\n");
                return 1;
            }
        }
        keyLetters[i] = key[i];
    }

    //asks the user for the text to encipher
    string inputText = get_string("plaintext: ");
    encipherText(inputText, key);
}

int encipherText(string text, string key)
{
    //array to store the new text
    char cipherText[strlen(text)];

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