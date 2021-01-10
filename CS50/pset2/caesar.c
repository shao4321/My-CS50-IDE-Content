#include <stdio.h>
#include <cs50.h>
#include <string.h> //strlen
#include <stdlib.h> //atoi
#include <ctype.h> //isalpha

int main(int argc, string caesar[])
{
    int stringLength;
    int N, i, k;

    if (argc <= 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    stringLength = strlen(caesar[1]);

    for(i = 0; i < stringLength; i++)
    {
        if(isalpha(caesar[1][i]) != 0)
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }

    k = atoi(caesar[1]);

    string plainTxt = get_string("plaintext: ");
    N = strlen(plainTxt);

    int alphaVal[N], cipVal[N];

    for(i = 0; i < N; i++)
    {
        if(plainTxt[i] >= 'A' && plainTxt[i] <= 'Z')
        {
            alphaVal[i] = ((plainTxt[i] - 65) + k) % 26;
            cipVal[i] = alphaVal[i] + 65;
        }
        else if(plainTxt[i] >= 'a' && plainTxt[i] <= 'z')
        {
            alphaVal[i] = ((plainTxt[i] - 97) + k) % 26;
            cipVal[i] = alphaVal[i] + 97;
        }
        else
        cipVal [i] = plainTxt[i];
    }

    printf("ciphertext: ");

    for(i = 0; i < N; i++)
    {
    printf("%c", cipVal[i]);
    }
    printf("\n");
    return 0;

}
