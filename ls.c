#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
//ls -1 -Q
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		DIR *d;
		struct dirent *dir;
		d = opendir(".");
		if (d)
		{
			while ((dir = readdir(d)) != NULL)
			{
				if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..") && dir->d_name[0] != '.')
				{
					printf("%s ", dir->d_name);
				}
			}
			closedir(d);
		}
		printf("\n");
	}
	else if (argc == 2)
	{
		if (!strcmp(argv[1], "-1"))
		{
			DIR *d;
			struct dirent *dir;
			d = opendir(".");
			// printf("-1");
			if (d)
			{
				while ((dir = readdir(d)) != NULL)
				{
					if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..") && dir->d_name[0] != '.')
					{
						printf("%s\n", dir->d_name);
					}
				}
				closedir(d);
			}
		}
		else if (!strcmp(argv[1], "-Q"))
		{
			DIR *d;
			struct dirent *dir;
			d = opendir(".");
			if (d)
			{
				while ((dir = readdir(d)) != NULL)
				{
					if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..") && dir->d_name[0] != '.')
					{
						printf("\"%s\" ", dir->d_name);
					}
				}
				closedir(d);
			}
			printf("\n");
		}
		else
		{
			printf("fufu\n");
			return 1;
		}
	}
	else
	{
		printf("fufu\n");
		return 1;
	}
	return 0;
}