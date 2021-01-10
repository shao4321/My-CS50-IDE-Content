#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc > 2 || argc < 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    int j = 0;
    bool fileOpened = false;
    char jpgFilename[10];

    FILE *img;
    FILE *file = fopen(argv[1], "r");

    if(file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    BYTE *buffer = malloc(512 * sizeof(BYTE));
    
    // file ends before fread could read 512 elements
    while(fread(buffer, 512, 1, file) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(fileOpened == false)
            {
                sprintf(jpgFilename, "%03i.jpg", j);
                img = fopen(jpgFilename, "a");
                fileOpened = true;
                fwrite(buffer, 512, 1, img);
            }
            else
            {
                fclose(img);
                fileOpened = false;
                j++; 
                sprintf(jpgFilename, "%03i.jpg", j);
                img = fopen(jpgFilename, "a");
                fileOpened = true;
                fwrite(buffer, 512, 1, img);
            }
        }
        else
        {
            if(fileOpened == true) //already found JPEG
            {
                fwrite(buffer, 512, 1, img);
                //keep writing into the JPEG, read 512 bytes and check it, repeat multiple times until end of memory card
            }
            else
            continue;
        }
    }

    fclose(img);
    fclose(file);
    free(buffer);
}
