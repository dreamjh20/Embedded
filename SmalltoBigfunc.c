#include <stdio.h>
#include "com.h"

char Switch(char A)
{
	A += ('A'-'a');
	printf("%c\n", A);
	return A;
}
