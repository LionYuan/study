#include <stdio.h>

int main()
{
	FILE *f = fopen("t.txt", "r");
	long size;
	if (f == NULL)
	{
		//
		perror("error opening file.");
	}
	else
	{
		fseek(f, 0, SEEK_END);
	    size = ftell(f);
		fclose(f);

		printf("%ld\n", size); 
	}

	return 0;
}