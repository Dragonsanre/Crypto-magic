#include <stdio.h>
#include <string.h>
#include "Cryptomagic.h"
#pragma warning(disable : 4996)
// FUNCTION      : main
		// DESCRIPTION   :
		//   gathers the data from user and sends it to its designated function
		// PARAMETERS    : 
		//   char* filename, decrypedfile
		// RETURNS       : 
		//   int
int main(int argc, char *argv[])
{
	
	int size;
	char point[255] = { "" };
	char* point2[255] = { "" };
	char line[100] = { "" };
	char name[255] = { "" };
	char* filename = name;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			size = strlen(argv[1]);
			strcpy((char*)point, argv[1]);
			if (strcmp((char*)point + (size - 4), ".txt") == 0)
			{
				strncpy(filename, point, size - 4);
				strcat(filename, ".crp");
				encrypt(filename, point);

			}
			else
			{
				strcat(point, ".txt");
				size = size + 4;
				strncpy(filename, point, size - 4);
				strcat(filename, ".crp");
				encrypt(filename, point);

			}
		}
		else if (argc == 3)
		{
			strcpy((char*)point, argv[1]);
			if (strcmp((char*)point, "-encrypt") == 0)
			{
				size = strlen(argv[2]);
				strcpy((char*)point, argv[2]);
				if (strcmp((char*)point + (size - 4), ".txt") == 0)
				{
					strncpy(filename, point, size - 4);
					strcat(filename, ".crp");
					encrypt(filename, point);

				}
				else
				{
					strcat(point, ".txt");
					size = size + 4;
					strncpy(filename, point, size - 4);
					strcat(filename, ".crp");
					encrypt(filename, point);

				}
			}
			else if (strcmp((char*)point, "-decrypt") == 0)
			{
				size = strlen(argv[2]);
				strcpy((char*)point, argv[2]);
				if (strcmp((char*)point + (size - 4), ".crp") == 0)
				{
					strncpy(filename, point, size - 4);
					strcat(filename, ".txt");
					decrypt(filename, point);
				}
				else
				{
					strcat(point, ".crp");
					size = size + 4;
					strncpy(filename, point, size - 4);
					strcat(filename, ".txt");
					decrypt(filename, point);
				}
			}
		}
		else
		{
			printf("too many arguments for this command");
		}
	}
	{
		printf("argument list is empty.");
	}
}


