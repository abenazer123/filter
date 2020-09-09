#include "helpers.h"
#include <stdio.h>
// void a_blue(int h, int w, RGBTRIPLE image);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {
            // RGBTRIPLE pixle = image[i][j];
            int avg = ((image[i][j].rgbtBlue) + (image[i][j].rgbtGreen) + (image[i][j].rgbtRed)) /3;
            image[i][j].rgbtBlue = avg;
            printf("rgbtBlue: %i\n", image[i][j].rgbtBlue);
            image[i][j].rgbtGreen = avg;
            printf("rgbtGreen: %i\n", image[i][j].rgbtGreen);
            image[i][j].rgbtRed = avg;
            printf("rgbtRed: %i\n", image[i][j].rgbtRed);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {
            if ( j <= (width - 1)/2)
            {
                RGBTRIPLE pixle = image[i][j];
                int new_pos = (width - 1) - j;
                image[i][j] = image[i][new_pos];
                image[i][new_pos] = pixle;
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    printf("I am getting called");
    for ( int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {
            // // RGBTRIPLE pixle = image[i][j];
            // int blue_avg = a_blue(height, width, image[height][width]);
            // // ((image[i][j].rgbtBlue) + (image[i][j-1].rgbtblue) + (image[i][j+1].rgbtBlue)) /3;
            // int green_avg =
            // // ((image[i][j].rgbtGreen) + (image[i][j-1].rgbtGreen) + (image[i][j+1].rgbtGreen)) /3;
            // int red_avg =
            // // ((image[i][j].rgbtRed) + (image[i][j-1].rgbtRed) + (image[i][j+1].rgbtRed)) /3;
            // image[i][j].rgbtBlue = blue_avg;
            // // printf("rgbtBlue: %i\n", image[i][j].rgbtBlue);
            // image[i][j].rgbtGreen = green_avg;
            // // printf("rgbtGreen: %i\n", image[i][j].rgbtGreen);
            // image[i][j].rgbtRed = red_avg;
            // // printf("rgbtRed: %i\n", image[i][j].rgbtRed);
            // a_blue(i, j, image[height][width]);
            int blue = 0;
            int green = 0;
            int red = 0;
            int count = 0;
            for ( int h = i - 1 ; h <= i + 1; h++)
            {
                if (h >= 0)
                {
                    int start = j - 1;
                    while (start <= j + 1)
                    {
                        if ( start >= 0)
                        {
                            blue += (image[h][start].rgbtBlue);
                            green += (image[h][start].rgbtGreen);
                            red += (image[h][start].rgbtRed);
                            start++;
                            count++;
                            printf("Count: %i\n", count);
                        }
                    }
                }
            }
            image[i][j].rgbtBlue = blue/count;
            image[i][j].rgbtGreen = green/count;
            image[i][j].rgbtRed = red/count;
        }
    }
}

// void a_blue(int h, int w, RGBTRIPLE image[height][width])
// {
//     int blue = 0;
//     int green = 0;
//     int red = 0;
//     for ( int i = h - 1 ; i <= h + 1; i++)
//     {
//         int start = w - 1;
//         while (start <= w + 1)
//         {
//             blue += (image[i][w].rgbtBlue);
//             green += (image[i][w].rgbtGreen);
//             red += (image[i][w].rgbtRed);
//             start++;
//         }
//     }
//     image[h][w].rgbtBlue = blue;
//     image[h][w].rgbtGreen = green;
//     image[h][w].rgbtRed = red;
// }

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
