#include <stdio.h>
#include <ctype.h>

int main(void)
{
	putchar(toupper('a'));
	putchar('\n');
	putchar(toupper('1'));
	putchar('\n');
	putchar(toupper('A'));
	putchar('\n');
	putchar(toupper(0x34));
	putchar('\n');
	putchar(toupper(0x61));
	putchar('\n');
	return 0;
}
