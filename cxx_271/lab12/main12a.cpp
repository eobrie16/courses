#include <stdio.h>
#include <string.h>

int writefile(char * f)
{
	const int MAX = 80;
	char buffer[MAX];
    FILE *in;

    in = fopen(f,"r");
    if (in == NULL)
    {
       printf("Unable to open %s\n", f);
       return -1;
    }
    
	while (fgets(buffer, sizeof(buffer), in) != NULL)
		fwrite(buffer, 1, strlen(buffer), stdout);

}

int main(int argc, char *argv[])
{
	for (int i=1; i<argc; i++)
		writefile(argv[i]);

	return 0;
}
