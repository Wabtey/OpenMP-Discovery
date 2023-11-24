#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
#include <omp.h>
#include <time.h>

int NB_WORDS = 10;
int STRING_MAX_SIZE = 20;

/* A function to generate random strings */
void gen_random(char *s, int len)
{
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; ++i)
    {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;
}

/* A function to print arrays of strings */
void printArrayStrings(char **array)
{

    for (int i = 0; i < NB_WORDS; i++)
    {
        printf("%s\n", array[i]);
    }
}

/* A function to print the counts */
void printArrayInt(int *count)
{

    for (int i = 0; i < 26; i++)
    {
        printf("%d ", count[i]);
    }
}

/* A function that maps a String to a count of characters */
void map1(char *c, int *count)
{

    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }
    // to be completed
}

int main()
{

    // init
    char *array[NB_WORDS];
    srand(time(NULL));
    for (int i = 0; i < NB_WORDS; i++)
    {
        int strSize = 1 + rand() % STRING_MAX_SIZE;
        array[i] = (char *)malloc(strSize * sizeof(char));
        gen_random(array[i], strSize);
    }

    printArrayStrings(array);

    // map (on a single word)
    int *count = (int *)malloc(26 * sizeof(int));
    map1(array[0], count);
    printArrayInt(count);

    return 0;
}
