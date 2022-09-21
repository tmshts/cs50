#include "helpers.h"
#include <math.h>
#include <stdbool.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++) //iterate through any rows
    {
        for (int j = 0; j < width; j++) //iterate through any columns
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00;
//at least one number has to be float -> 3.00
            int average1 = round(average);

            image[i][j].rgbtRed = average1; //set the new value = average1
            image[i][j].rgbtGreen = average1;
            image[i][j].rgbtBlue = average1;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++) //iterate through any rows
    {
        for (int j = 0; j < width; j++) //iterate through any columns
        {

            float sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue; //set sepia value
            float sepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            float sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            int sepiaRed1 = round(sepiaRed);
            int sepiaGreen1 = round(sepiaGreen);
            int sepiaBlue1 = round(sepiaBlue);

            image[i][j].rgbtRed = sepiaRed1; //change original value for sepia value
            image[i][j].rgbtGreen = sepiaGreen1;
            image[i][j].rgbtBlue = sepiaBlue1;

            if (sepiaRed1 > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiaGreen1 > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaBlue1 > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++) //iterate through any rows
    {
        for (int j = 0; j < (width / 2); j++) //iterate through any columns
//till middle because of swap
        {
            RGBTRIPLE temp = image[i][j]; //RGBTRIPLE typedef struct
            image[i][j] = image[i][width - 1 - j]; //change value
            image[i][width - 1 - j] = temp; //set changed value
//helpers.c:78:37: error: assigning to 'RGBTRIPLE' from incompatible type 'double (double)'
        }
    }

    return;
}

bool is_valid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE get_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int red_value = 0;
    int blue_value = 0;
    int green_value = 0;
    int count = 0;

    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
            if(is_valid_pixel(new_i, new_j, height, width))
            {
                count++;
                red_value += image[new_i][new_j].rgbtRed;
                green_value += image[new_i][new_j].rgbtGreen;
                blue_value += image[new_i][new_j].rgbtBlue;
            }
        }
    }

    RGBTRIPLE blur; //new values
    blur.rgbtRed = round((float)red_value / count);
    blur.rgbtGreen = round((float)green_value / count);
    blur.rgbtBlue = round((float)blue_value / count);

    return blur;

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width]; //copy

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = get_blur(i, j, height, width, image);
        }
    }

    for (int i = 0; i < height; i++) //copy back to the original image
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
