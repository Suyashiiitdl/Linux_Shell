#include <stdio.h>
#include <time.h>
//date -u -R
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        time_t t; // not a primitive datatype
        time(&t);

        printf("IST %s", ctime(&t));
    }
    //date -u
    else if (argc == 2)
    {
        if (!strcmp(argv[1], "-u"))
        {
            time_t now = time(&now);

            if (now == -1)
            {

                puts("The time() function failed");
            }

            struct tm *ptm = gmtime(&now);

            if (ptm == NULL)
            {

                puts("The gmtime() function failed");
            }

            printf("UTC %s", asctime(ptm));
        }
        //date -R 
        else if (!strcmp(argv[1], "-R"))
        {
            // https://zetcode.com/articles/cdatetime/#:~:text=The%20example%20prints%20the%20current,s%22%2C%20asctime(ptm))%3B
            char buf[999] = {0};

            time_t rawtime = time(NULL);
            //check time works
            if (rawtime == -1)
            {
                puts("The time() function failed");return 1;
            }

            struct tm *ptm = localtime(&rawtime);

            if (ptm == NULL)
            {
                puts("The localtime() function failed");return 1;
            }
            // Mon, 31 Oct 2022 18:04:45 +0530
            strftime(buf, 999, "%a, %e %b %G %H:%M:%S %z", ptm);
            puts(buf);
        }
        else
        {
            printf("fufu\n");
            return 1;
        }
    }
    return 0;
}
