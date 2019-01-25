#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(FILE *fp)
{
	int c;
	while ((c = getc(fp)) != EOF)
		putchar(c);
	if (ferror(fp))
	{
		perror("cat");
		exit(EXIT_FAILURE);
	}
}

FILE *file_or_stdin(const char *name)
{
	FILE *fp;
	if (strcmp("-", name) == 0)
		return stdin;
	if ((fp = fopen(name, "r")) == NULL)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	return fp;
}

int main(int argc, char **argv)
{
	FILE *current;

	if (argc == 1)
	{
		output(stdin);
		return EXIT_SUCCESS;
	}

	while (*++argv)
	{
		if (strcmp("-u", *argv) == 0)
		{
			setvbuf(stdout, NULL, _IONBF, 0);
			continue;
		}

		current = file_or_stdin(*argv);
		output(current);
		if (current != stdin)
			fclose(current);
	}
	return EXIT_SUCCESS;
}
