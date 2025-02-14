#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00;
            int ave = round(average);

            image[i][j].rgbtRed = ave;
            image[i][j].rgbtGreen = ave;
            image[i][j].rgbtBlue = ave;
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
            int s_red = round(0.393 * image[i][j].rgbtRed  + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            if (s_red >= 255)
            {
                s_red = 255 ;
            }

            int s_green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            if (s_green >= 255)
            {
                s_green = 255 ;
            }

            int s_blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            if (s_blue >= 255)
            {
                s_blue = 255 ;
            }

            image[i][j].rgbtRed = s_red;
            image[i][j].rgbtGreen = s_green;
            image[i][j].rgbtBlue = s_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE empty = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = empty;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE empty[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            empty[y][x] = image[y][x];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float majmoo = 0;
            float red_sum = 0;
            float green_sum = 0;
            float blue_sum = 0;

            for (int ud = -1; ud < 2; ud++)
            {
                for (int rl = -1; rl < 2; rl++)
                {
                    int temp_ud = i + ud;
                    int temp_rl = j + rl;

                    if (temp_rl < 0 || temp_rl > width - 1 || temp_ud < 0 || temp_ud > height - 1)
                    {
                        continue;
                    }

                    red_sum += (float)empty[i + ud][j + rl].rgbtRed;
                    green_sum += (float)empty[i + ud][j + rl].rgbtGreen;
                    blue_sum += (float)empty[i + ud][j + rl].rgbtBlue;

                    majmoo++;
                }
            }

            image[i][j].rgbtRed = round(red_sum / majmoo);
            image[i][j].rgbtGreen = round(green_sum / majmoo);
            image[i][j].rgbtBlue = round(blue_sum / majmoo);
        }
    }

    return;
}
