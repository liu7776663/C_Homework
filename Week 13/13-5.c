#include <stdio.h>
#include <malloc.h>
#include <string.h>

char input[1000];

struct Word
{
	char* token;
	int length;
};

struct Word count[100];

int split();
void rank(int length);

int main()
{
	gets_s(input, 1000);
	
	int length = split();

	rank(length);

	printf("%s", count[0].token);
	return 0;
}

int split()
{
	int i = 1;

	char *token;
	const char *delim = " ";
	char *next_token;

	token = strtok_s(input, delim, &next_token);
	count[0].token = malloc(strlen(token));
	count[0].token = token;

	while (token != NULL)
	{
		token = strtok_s(NULL, delim, &next_token);
		if (token == NULL)
		{
			break;
		}
		count[i].token = malloc(strlen(token));
		count[i].token = token;
		count[i].length = strlen(token);
		i++;
	}

	return i;
}

void rank(int length)
{
	struct Word temp;

	for (int i = 0; i < length; i++)
	{
		for (int j = length - 1; j > i; j--)
		{
			if (count[j - 1].length < count[j].length)
			{
				temp = count[j - 1];
				count[j - 1] = count[j];
				count[j] =temp;
			}
		}
	}
}