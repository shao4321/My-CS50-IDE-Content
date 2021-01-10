#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i, k;
    float blueS[height][width];
    float greenS[height][width];
    float redS[height][width];
    float average[height][width];

    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            blueS[i][k] = image[i][k].rgbtBlue;
            greenS[i][k] = image[i][k].rgbtGreen;
            redS[i][k] = image[i][k].rgbtRed;

            average[i][k] = round((blueS[i][k] + greenS[i][k] + redS[i][k]) / 3);
        }
    }

    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            image[i][k].rgbtBlue = average[i][k];
            image[i][k].rgbtGreen = average[i][k];
            image[i][k].rgbtRed = average[i][k];
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int i, k;
    float blueS[height][width];
    float greenS[height][width];
    float redS[height][width];
    float sepiaBlue[height][width], sepiaGreen[height][width], sepiaRed[height][width];

    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            blueS[i][k] = image[i][k].rgbtBlue;
            greenS[i][k] = image[i][k].rgbtGreen;
            redS[i][k] = image[i][k].rgbtRed;

            sepiaBlue[i][k] = round((0.272 * redS[i][k]) + (0.534 * greenS[i][k]) + (0.131 * blueS[i][k]));
            sepiaGreen[i][k] = round((0.349 * redS[i][k]) + (0.686 * greenS[i][k]) + (0.168 * blueS[i][k]));
            sepiaRed[i][k] = round((0.393 * redS[i][k]) + (0.769 * greenS[i][k]) + (0.189 * blueS[i][k]));

            if(sepiaBlue[i][k] > 255)
            sepiaBlue[i][k] = 255;

            if(sepiaGreen[i][k] > 255)
            sepiaGreen[i][k] = 255;

            if(sepiaRed[i][k] > 255)
            sepiaRed[i][k] = 255;
        }
    }

    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            image[i][k].rgbtBlue = sepiaBlue[i][k];
            image[i][k].rgbtGreen = sepiaGreen[i][k];
            image[i][k].rgbtRed = sepiaRed[i][k];
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i, k, j;
    int blueS[height][width], greenS[height][width], redS[height][width];

    for(i = 0; i < height; i++)
    {
        for(k = width - 1, j = 0; k >= 0; k--, j++)
        {
            blueS[i][j] = image[i][k].rgbtBlue;
            greenS[i][j] = image[i][k].rgbtGreen;
            redS[i][j] = image[i][k].rgbtRed;
        }
    }

    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            image[i][k].rgbtBlue = blueS[i][k];
            image[i][k].rgbtGreen = greenS[i][k];
            image[i][k].rgbtRed = redS[i][k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i, k, j;
    float blueS[height][width], newBlue[height][width];
    float greenS[height][width], newGreen[height][width];
    float redS[height][width], newRed[height][width];

    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            blueS[i][k] = image[i][k].rgbtBlue;
            greenS[i][k] = image[i][k].rgbtGreen;
            redS[i][k] = image[i][k].rgbtRed;
        }
    }
    
    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            if(i > 0 && i < height - 1)
            {
                if(k > 0 && k < width - 1)
                {
                    newBlue[i][k] =  round((blueS[i-1][k-1] + blueS[i-1][k] + blueS[i-1][k+1] +
                                blueS[i][k-1] + blueS[i][k] + blueS[i][k+1] +
                                blueS[i+1][k-1] + blueS[i+1][k]+ blueS[i+1][k+1]) / 9);

                    newGreen[i][k] =  round((greenS[i-1][k-1] + greenS[i-1][k] + greenS[i-1][k+1] +
                                    greenS[i][k-1] + greenS[i][k] + greenS[i][k+1] +
                                    greenS[i+1][k-1] + greenS[i+1][k]+ greenS[i+1][k+1]) / 9);
    
                    newRed[i][k] =  round((redS[i-1][k-1] + redS[i-1][k] + redS[i-1][k+1] +
                                    redS[i][k-1] + redS[i][k] + redS[i][k+1] +
                                    redS[i+1][k-1] + redS[i+1][k]+ redS[i+1][k+1]) / 9);
                }
               
            }

            else if(i == 0)
            {
                if(k > 0 && k < width - 1)
                {
                    newBlue[i][k] =  round((blueS[i][k-1] + blueS[i][k] + blueS[i][k+1] +
                                blueS[i+1][k-1] + blueS[i+1][k]+ blueS[i+1][k+1]) / 6);

                    newGreen[i][k] =  round((greenS[i][k-1] + greenS[i][k] + greenS[i][k+1] +
                                    greenS[i+1][k-1] + greenS[i+1][k]+ greenS[i+1][k+1]) / 6);
    
                    newRed[i][k] =  round((redS[i][k-1] + redS[i][k] + redS[i][k+1] +
                                    redS[i+1][k-1] + redS[i+1][k]+ redS[i+1][k+1]) / 6);
                }
                
                else if(k == 0 || k == width - 1)
                {
                    newBlue[i][k] =  round((blueS[i][k] + blueS[i][k+1] +
                                    blueS[i+1][k]+ blueS[i+1][k+1]) / 4);
    
                    newGreen[i][k] =  round((greenS[i][k] + greenS[i][k+1] +
                                    greenS[i+1][k]+ greenS[i+1][k+1]) / 4);
    
                    newRed[i][k] =  round((redS[i][k] + redS[i][k+1] +
                                    redS[i+1][k]+ redS[i+1][k+1]) / 4);
                }
                
            }

            else if(k == 0)
            {
                if(i > 0 && i < height - 1)
                {
                    newBlue[i][k] =  round((blueS[i-1][k] + blueS[i-1][k+1] + blueS[i][k] +
                                blueS[i][k+1] + blueS[i+1][k]+ blueS[i+1][k+1]) / 6);

                    newGreen[i][k] =  round((greenS[i-1][k] + greenS[i-1][k+1] + greenS[i][k] +
                                    greenS[i][k+1] + greenS[i+1][k]+ greenS[i+1][k+1]) / 6);
    
                    newRed[i][k] =  round((redS[i-1][k] + redS[i-1][k+1] + redS[i][k] +
                                    redS[i][k+1] + redS[i+1][k]+ redS[i+1][k+1]) / 6);
                }
                
                else if(i == 0 || i == height - 1)
                {
                    newBlue[i][k] =  round((blueS[i][k] + blueS[i][k+1] +
                                    blueS[i+1][k]+ blueS[i+1][k+1]) / 4);
    
                    newGreen[i][k] =  round((greenS[i][k] + greenS[i][k+1] +
                                    greenS[i+1][k]+ greenS[i+1][k+1]) / 4);
    
                    newRed[i][k] =  round((redS[i][k] + redS[i][k+1] +
                                    redS[i+1][k]+ redS[i+1][k+1]) / 4);
                }
                
            }
            
        }
    }

    for(i = 0; i < height; i++)
    {
        for(k = 0; k < width; k++)
        {
            image[i][k].rgbtBlue = newBlue[i][k];
            image[i][k].rgbtGreen = newGreen[i][k];
            image[i][k].rgbtRed = newRed[i][k];
        }
    }

    return;
}
