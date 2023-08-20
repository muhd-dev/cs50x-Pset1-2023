#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // This will declare the int variable for various variables?
    int height, row, hash, space;
    do
    {
        height = get_int("Height: ");
    }
    // This will make sure height is not less than 1 or greater than 8
    while (height < 1 || height > 8);

    //This will print new line as ROW
    for (row = 0; row < height; row++)
    {
        // This will print SPACE
        for (space = height - row - 1; space > 0; space--)
        {
            printf(" ");
        }
        // This will print the hashes(#)
        for (hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}