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
	if (strcmp("-", name) == 0)
		return stdin;
	return fopen(name, "r");
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
		current = file_or_stdin(*argv);
		output(current);
		if (current != stdin)
			fclose(current);
	}
	return EXIT_SUCCESS;
}
