#include <stdio.h>
#include <string.h>
int count_weight(const char *word)
{
    int count = 0;
    for( int i = 0; word[i] != '\0' ; i++ )
    {
        char temp = toupper((unsigned char)word[i]);
        int ascii_number = temp;
        count  = count + ascii_number  - 65 +1;
    }
    return count;
}


int main()
{

    const int MAX_LEN = 100;
    char line[MAX_LEN];
    int weight = 0;

    if (fgets(line, MAX_LEN, stdin) == NULL)
    {
        return -1;
    }
    char *word = strtok(line, " \n");

    do
    {
        weight = (count_weight(word)>weight) ? count_weight(word):weight;
    }
    while (word = strtok(NULL, " \n"));

    printf("%d",weight);


    return 0;
}

