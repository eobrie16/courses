#include <stdio.h>
#include <string.h>                

const int MAX=256;

class myGrep
{
private:
	char buff[MAX];
	char * searchstr;
public:
	myGrep(char * s)
	{
		buff[0] = 0;
		searchstr = s;
	}

	int processFile(char * filename)
	{
		int line = 1;
		char output[MAX+100];
		
	    FILE *in;
		in = fopen(filename, "r");
		if (in == NULL)
		{
			printf("Unable to open %s\n", filename);
			return -1;
		}
		while (fgets(buff, sizeof(buff), in) != NULL)
		{
			if (strstr(buff, searchstr) != NULL)
			{
				sprintf(output, "%d : %s", line, buff);
				fwrite(output, 1, strlen(output), stdout);
			}
			line++;
		}
		return 0;
	}
};


int main(int argc, char *argv[])
{
    char * search;
	int i;

	if ((argc < 3) || (argc > 3))
		return -1;

	search = argv[1];
		
	myGrep filep(search);

	filep.processFile(argv[2]);

	return 0;
}
