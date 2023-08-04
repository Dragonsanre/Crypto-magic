/*  
*  FILE          : EncryptionOrDecryption.c 
*  PROJECT       : SENG2030 - Assignment #1 
*  PROGRAMMER    : Alex Palmer
*  FIRST VERSION : 2020-1-24 
*  DESCRIPTION   : 
*    The functions in this file are used to encrypt and decrypt a file */
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
// FUNCTION      : encrypt
		// DESCRIPTION   :
		//   encrypts the file within the paramerts into a given crp filename
		// PARAMETERS    : 
		//   char* filename, decrypedfile
		// RETURNS       : 
		//   int
int encrypt(char* filename, char* decryptedfile)
{
	FILE* fp = NULL;
	FILE* fp2 = NULL;
	int cr = 0;
	char hex[240] = { "" };
	int location = 0;
	char line[120] = { "" };
	int asciiValue;
	int outChar;
	int remainder;
	char encrypted[250] = { "" };

	int size;
	fp = fopen(decryptedfile, "r");
	fp2 = fopen(filename, "w");
	if (fp != NULL && fp2 != NULL)
	{
		while (fgets(line, 120, fp) != NULL)
		{
			size = strlen(line);

			for (int count = 0; count < size; count++)
			{
				asciiValue = line[count];
				if (asciiValue == 9)
				{
					strcat((char*)encrypted, "TT");

				}
				else if (asciiValue == 13 || asciiValue == 10)
				{
					fprintf(fp2, "\n");
				}
				else
				{
					outChar = asciiValue - 16;
					if (outChar < 32)
					{
						outChar = (outChar - 32) + 144;
						fprintf(fp2, "%0.2x", outChar);
					}
					else
					{
						fprintf(fp2, "%0.2x", outChar);
					}
				}
			}
		}
		fclose(fp);
		fclose(fp2);
		fp = NULL;
		fp2 = NULL;
	}
	else
	{
		printf("couldn't open file");
	}

	return 0;
}
// FUNCTION      : decrypt
		// DESCRIPTION   :
		//   decrypts the file within the paramerts into a given txt filename
		// PARAMETERS    : 
		//   char* filename, encrypedfile
		// RETURNS       : 
		//   int
int decrypt(char* filename, char* encryptedfile)
{
	FILE* fp = NULL;
	FILE* fp2 = NULL;
	int cr = 0;
	int location = 0;
	char line[255] = { "" };
	int asciiValue;
	int outChar;
	int secondcharacter;
	char character = 0;
	char encrypted[250] = { "" };
	char hex[2] = { "" };
	int count = 0;
	char letter[255] = { "" };
	char* pletter = letter;

	int size;
	fp = fopen(encryptedfile, "r");
	fp2 = fopen(filename, "w");
	if (fp != NULL && fp2 != NULL)
	{
		while (fgets(line, 255, fp) != NULL)
		{
			size = strlen(line);
			count = 0;
			while (count < size)
			{
				strncpy((char*)hex, line + count, 2);
				if (strcmp(hex, "TT") == 0)
				{
					fprintf(fp2, "\t");
				}
				if (hex[0] == '\n')
				{
					fprintf(fp2, "\n");
				}
				else
				{
					outChar = hex[0] - '0';
					if (outChar >= 0 && outChar <= 9)
					{
						outChar = outChar * 16;
					}
					else
					{
						outChar = hex[0] - 'A';
						if (outChar <= 25 && outChar >= 0)
						{
							outChar = (outChar + 10) * 16;
						}
						else
						{
							outChar = hex[0] - 'a';
							outChar = (outChar + 10) * 16;
						}
					}
					secondcharacter = hex[1] - '0';
					if (secondcharacter >= 0 && secondcharacter <= 9)
					{
						secondcharacter = secondcharacter;
					}
					else
					{
						secondcharacter = hex[1] - 'A';
						if (secondcharacter >= 0 && secondcharacter <= 25)
						{
							secondcharacter = secondcharacter + 10;
						}
						else
						{
							secondcharacter = hex[1] - 'a';
							secondcharacter = secondcharacter + 10;
						}
					}
					outChar = outChar + secondcharacter;
					outChar = outChar + 16;
					if (outChar > 127)
					{
						outChar = (outChar - 144) + 32;
					}
					character = outChar;
					letter[0] = character;
					fprintf(fp2, pletter);
				}
				count = count + 2;
			}

		}
	}
	return 0;
}