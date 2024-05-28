#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
//mkdir -v -m

//multiple files
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int flag = mkdir(argv[1], 0777);
        if (flag == -1)
        {
            perror("fufu\n");
        }
    }
    else if (argc > 2)
    {
        if (!strcmp(argv[1], "-v"))
        {
            int flag = mkdir(argv[2], 0777);
            if (flag == -1)
            {
                perror("fufu\n");
            }
            else
            {
                printf("%s directory created enjoy mf\n", argv[1]);
            }
        }
        else if (!strcmp(argv[1], "-m"))
        {
            if (argc == 4)
            {
                int flag = mkdir(argv[3], atoi(argv[2]));
                if (flag == -1)
                {
                    perror("fufu\n");
                }
            }
        }
        else
        {
            printf("fufu\n");
            return 1;
        }
    }
    return 0;
}