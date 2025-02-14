#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define new_size 512

int error();
int open_file_error(char file_name[]);
bool isipg_header(uint8_t buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return error();
    }

    char *inputfile = argv[1];
    if (inputfile == NULL)
    {
        return error();
    }

    FILE *input_myfile = fopen(inputfile, "r");
    if (input_myfile == NULL)
    {
        return open_file_error(inputfile);
    }

    char file_name[8];
    FILE *output_myfile = NULL;
    uint8_t buffer[new_size];
    int jpg = 0;

    while (fread(buffer, sizeof(uint8_t), new_size, input_myfile) || feof(input_myfile) == 0)
    {
        if (isipg_header(buffer))
        {
            if (output_myfile != NULL)
            {
                fclose(output_myfile);
            }

            sprintf(file_name, "%03i.jpg", jpg);
            output_myfile = fopen(file_name, "w");
            jpg ++;
        }

        if (output_myfile != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, output_myfile);
        }
    }

    if (output_myfile != NULL)
    {
        fclose(output_myfile);
    }

    if (input_myfile != NULL)
    {
        fclose(input_myfile);
    }

    return 0;
}

int error()
{
    printf("Usage: ./recover IMAGE\n");
    return 1;
}

int open_file_error(char file_name[])
{
    printf("not found %s to open\n", file_name);
    return 2;
}

bool isipg_header(uint8_t buffer[])
{
    return buffer[0] == 0xff
           && buffer[1] == 0xd8
           && buffer[2] == 0xff
           && (buffer[3] & 0xf0) == 0xe0;
}