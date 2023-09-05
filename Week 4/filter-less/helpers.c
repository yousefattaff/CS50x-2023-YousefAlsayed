#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            float sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            float sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Clamping to ensure values are within the valid range [0, 255]
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            else if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            else if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }

            image[i][j].rgbtRed = (BYTE) sepiaRed;
            image[i][j].rgbtGreen = (BYTE) sepiaGreen;
            image[i][j].rgbtBlue = (BYTE) sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // Loop only up to width / 2
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j]; // Swap with the corresponding pixel on the other side
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int count = 0;

            // Iterate over the neighboring pixels within the 3x3 box
            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        sumBlue += image[x][y].rgbtBlue;
                        sumGreen += image[x][y].rgbtGreen;
                        sumRed += image[x][y].rgbtRed;
                        count++;
                    }
                }
            }

            temp[i][j].rgbtBlue = round((float) sumBlue / count);
            temp[i][j].rgbtGreen = round((float) sumGreen / count);
            temp[i][j].rgbtRed = round((float) sumRed / count);
        }
    }

    // Update the image with the blurred result
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
