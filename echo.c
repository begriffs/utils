#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;

	while (*++argv)
		printf("%s ", *argv);
	putchar('\n');
}
