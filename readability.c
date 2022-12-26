#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L = average number of letters per 100 words in the text
    // S = average number of sentences per 100 words in the text

    string text = get_string("Text: ");
    // word is seperated by space
    // sentence is seperated by period, exclamation point, question mark

    float L = (count_letters(text) / (float) count_words(text)) * 100;
    float S = (count_sentences(text) / (float) count_words(text)) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}


int count_letters(string text)
{
    int letter = 0;

    for (int x = 0, i = strlen(text); x < i; x++)
    {
        if ((text[x] >= 65) && (text[x] <= 90))
        {
            letter = letter + 1;
        }
        else if ((text[x] >= 97) && (text[x] <= 122))
        {
            letter = letter + 1;
        }
        else
        {
            letter = letter + 0;
        }
    }
    return  letter;
}



int count_words(string text)
{
    int word = 1;
    for (int y = 0, j = strlen(text); y < j; y++)
    {
        if (text[y] == 32)
        {
            word = word + 1;
        }
        else
        {
            word = word + 0;
        }
    }
    return word;
}



int count_sentences(string text)
{
    int sentence = 0;
    for (int z = 0, k = strlen(text); z < k; z++)
    {
        if (text[z] == 46 || text[z] == 33 || text[z] == 63)
        {
            sentence = sentence + 1;
        }
        else
        {
            sentence = sentence + 0;
        }
    }
    return sentence;
    // contain at least one word
    // will not start or end with a space
    // will not have multiple spaces in a row
    // attempt a solution that tolerate multiple spaces between words or no words
}