#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
//rm -f 
//rm -i
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int flag = remove(argv[1]);
        if (flag == -1)
        {
            perror("fufu\n");
        }
    }
    else if (argc > 2)
    {
        if (!strcmp(argv[1], "-f"))
        {
            remove(argv[2]);
        }
        else if (!strcmp(argv[1], "-i"))
        {
            char conf;
            printf("Really?? (y/n)\t");
            scanf("%c", &conf);
            if (conf == 'y')
            {
                int flag = remove(argv[2]);
                if (flag == -1)
                {
                    perror("fufu\n");
                }
            } else if (conf == 'n'){
                printf("phew\n");
            } else {
                perror("fufu invalid argument, not deleted\n");
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