#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#define buffer_size 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use a correct usage\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("The forensic image cannot be opened for reading.\n");
        return 1;
    }

    unsigned char buffer[buffer_size]; //unsigned char works as bite pointer
    //alocate memory for one block size
    FILE *images = NULL;//create a new file where I write recovered pictures
    //each block has 512 bytes
    //images pointer now points to anything
    int count_jpeg = 0;
    char filename [8];//000.jpg\0

    while(fread(buffer, sizeof(buffer), 1, file)) //look at each block
//in each block I check whether I find the JPEG file
    {
        //first 3 bytes + 1 additional byte to find a JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (images != NULL)
            {
                fclose(images);
            }
            sprintf(filename, "%03i.jpg", count_jpeg);
            images = fopen(filename, "w");
            count_jpeg++;
        }
        if (images != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, images);
        }
    }
    fclose(file);
    fclose(images);
    //free(buffer);
    return 0;
}