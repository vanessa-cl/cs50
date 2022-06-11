#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

//ASCII codes necessary to the counters
const int SPACE = 32;
const int EXCLAMATION_MARK = 33;
const int PERIOD = 46;
const int QUESTION_MARK = 63;
const int A_UP_LETTER = 65;
const int Z_UP_LETTER = 90;
const int A_LOW_LETTER = 97;
const int Z_LOW_LETTER = 122;

void analyzeText(string text);
void getTextGrade(int words, int sentences, int letters);

int main(void)
{
    //ask the text to the user
    string inputText = get_string("Text: ");
    //calling the function to analyze the input text
    analyzeText(inputText);
}

void analyzeText(string text)
{
    //initial count values
    int words = 0;
    int letters = 0;
    int sentences = 0;
    
    //the loop will iterate for each character in the input text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //if an character is a space then the word count will increment
        if (text[i] == SPACE)
        {
            words++;
        }
        //if an character is a period, question mark or exclamation mark then the sentences count will increment
        else if (text[i] == PERIOD || text[i] == QUESTION_MARK || text[i] == EXCLAMATION_MARK)
        {
           zsentences++;
        }
        //if an character is a uppercase or lowcase letter the letters count will increment
        else if ((text[i] >= A_UP_LETTER && text[i] <= Z_UP_LETTER) || (text[i] >= A_LOW_LETTER && text[i] <= Z_LOW_LETTER))
        {
            letters++;
        }
    }
    //after the text is iterated we call the function that will calculate the grade
    getTextGrade(words + 1, sentences, letters);
}

void getTextGrade(int words, int sentences, int letters)
{
    //getting the L and S values for the formula and casting float on all int values
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    //applying the Coleman-Liau formula using the L and S values
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    //select an message for the output based on the index value
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}