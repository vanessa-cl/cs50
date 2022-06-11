#include <stdio.h>
#include <cs50.h>

void buildPyramid(int height);

int main(void)
{
    int height = 0;
    //Should ask a height to the user
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //Should build a pyramid using the height
    buildPyramid(height);
}

void buildPyramid(int height)
{
    //Loop to create new lines
    for (int i = 0; i < height; i++)
    {
        //Loop to add the white spaces on the first pyramid
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }
        //Loop to add the hashes of the first pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //Add the center white spaces
        printf("  ");
        //Loop to add the hashes of the second pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}