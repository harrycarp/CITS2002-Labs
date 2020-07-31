#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Compile this program with:
//      cc -std=c99 -Wall -Werror -o rotate rotate.c

// Author: Harry Carpenter 22723303
// Compiled with WSL C99

#define ROT 3

//  The rotate function returns the character ROT positions further along the
//  alphabetic character sequence from c, or c if c is not lower-case

char rotate(char c)
{
    // Check if c is lower-case or not
    if (islower(c))
    {
        // The ciphered character is ROT positions beyond c,
        // allowing for wrap-around
        return ('a' + (c - 'a' + ROT) % 26);
    }
    else if(isupper(c))
    {
        //5. Extended for Uppercase support
        return toupper('a' + (tolower(c) - 'a' + ROT) % 26);
    }
    else
    {
        //is something is whack, return c
        return c;
    }
}

//  Execution of the whole program begins at the main function

int main(int argcount, char *argvalue[])
{
    // Exit with an error if the number of arguments (including
    // the name of the executable) is not precisely 2
    if(argcount != 2)
    {
        fprintf(stderr, "%s: program expected 1 argument, but instead received %d\n",
                argvalue[0], argcount-1);
        exit(EXIT_FAILURE);
    }
    else
    {
        // Define a variable for a later loop
        int i;
        // Calculate the length of the first argument
        int length = strlen(argvalue[1]);

        // Loop for every character in the text
        for(i = 0; i < length; i++)
        {
            // Determine and print the ciphered character
            printf("%c : %c : position %i \n", rotate(argvalue[1][i]), argvalue[1][i], i);
        }

        // Print one final new-line character
        printf("\n");

        // Exit indicating success
        exit(EXIT_SUCCESS);
    }
    return 0;
}