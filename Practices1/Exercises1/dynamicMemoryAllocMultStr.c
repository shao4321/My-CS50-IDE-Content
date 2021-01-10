// Online C compiler to run C online.
// Write C code in this online editor and run it.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int totalstrings, stringsize;

    printf("Number of strings: ");
    scanf("%d", &totalstrings);
    printf("Size of string: ");
    scanf("%d", &stringsize);

    fflush(stdin);

    char **array = malloc(totalstrings * sizeof(char *));

    for (int i = 0; i < totalstrings; ++i)
    {
        array[i] = (char *)malloc(stringsize + 1);
        if(array[i] == NULL)
        {
            printf("Error storing string.\n");
            return 1;
        }
        printf("Enter Name %d: ", i + 1);
        scanf("%s", array[i]);
    }

    for (int i = 0; i < totalstrings; ++i)
    {
        printf("Hello, %s\n", array[i]);
    }

    for (int i = 0; i < totalstrings; ++i)
    {
        free(array[i]);
    }

    free(array);

    return 0;
}