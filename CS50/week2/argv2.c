#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv2[]) //argc is the number of words. //argv2 are the words
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1; //need specify value due to int main //Error code 1 will be printed //1 means failure
    }
    printf("hello, %s\n", argv2[1]);
    return 0;  //0 means success
}