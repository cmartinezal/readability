#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int get_coleman_liau_index(int words, int letters, int sentences);
void print_grade_level(int index);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = get_coleman_liau_index(words, letters, sentences);

    print_grade_level(index);
}

bool is_letter(char letter)
{
    string letters = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < strlen(letters); i++)
    {
        if (letters[i] == tolower(letter))
        {
            return true;
        }
    }
    return false;
}

int count_letters(string text)
{
    int letter_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (is_letter(text[i]))
        {
            letter_count += 1;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int word_count = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word_count += 1;
        }
    }
    return strlen(text) > 0 ? word_count : 0;
}

int count_sentences(string text)
{
    int sentence_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count += 1;
        }
    }
    return strlen(text) > 0 ? sentence_count : 0;
}

int get_coleman_liau_index(int words, int letters, int sentences)
{
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}

void print_grade_level(int index)
{
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
