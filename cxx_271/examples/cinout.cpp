// stdio.c
#include <stdio.h>
#include <string.h>

int main()
{
    int c;
    FILE *in, *out;

    in = fopen("main.cpp","r");
    if (in == NULL)
    {
       printf("Unable to open file.in\n");
       return -1;
    }
    out = fopen("file.out","w");
    if (out == NULL)
    {
       printf("Unable to open file.out\n");
       return -1;
    }
/*  Character at a time
    while((c = fgetc(in)) != EOF)
        fputc(c,out);
		*/

	/*  Line at a time
	char cbuff[500];
	while (fgets(cbuff, sizeof(cbuff), in) != NULL)
		fwrite(cbuff, 1, strlen(cbuff), out);
		*/

	char cbuff[200]; 
	int numBytesRead;
	do
	{
		numBytesRead = fread(cbuff, 1, sizeof(cbuff), in);
		if (numBytesRead > 0)
		{
			fwrite(cbuff, 1, numBytesRead, out);
		}
	}while (numBytesRead > 0);

}
