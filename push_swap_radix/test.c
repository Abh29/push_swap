#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int size = atol(argv[1]);
	int l = 0;
	while (size >> l)
		l++;
	printf("size : %d\n", l);
	return 0;
}
