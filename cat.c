#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
//cat -T -E

//multiple files
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        // https://codeforwin.org/2018/01/c-program-read-and-display-file-contents.html#read-character
        FILE *fptr;
        fptr = fopen(argv[1], "r");
        if (fptr == NULL)
        {
            perror("fufu no file");
        }
        char ch;
        do
        {
            ch = fgetc(fptr);
            putchar(ch);

        } while (ch != EOF);
        fclose(fptr);
    }
    else if (argc > 2)
    {
        if (!strcmp(argv[1], "-T"))
        {
            FILE *fptr;
            fptr = fopen(argv[2], "r");
            if (fptr == NULL)
            {
                perror("fufu no file");
            }
            char ch;
            do
            {
                ch = fgetc(fptr);
                if (ch == '\t')
                {
                    putchar('^');
                    putchar('I');

                }
                else
                {
                    putchar(ch);
                }

            } while (ch != EOF);
            fclose(fptr);
        }
        else if (!strcmp(argv[1], "-E"))
        {
            FILE *fptr;
            fptr = fopen(argv[2], "r");
            if (fptr == NULL)
            {
                perror("fufu no file");
            }
            char ch;
            do
            {
                ch = fgetc(fptr);
                if (ch == '\n')
                {
                    putchar('$');
                    putchar(ch);
                }
                else
                {
                    putchar(ch);
                }

            } while (ch != EOF);
            fclose(fptr);
        }
        else
        {
            printf("fufu\n");
            return 1;
        }
    }
    return 0;
}