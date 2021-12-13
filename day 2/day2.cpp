#include <stdio.h>
#include <string.h>

int main()
{
	FILE *inputFile;
	char nextCommand[16];
	int nextParameter;
	int depth = 0;
	int distance = 0;
	int aim = 0;
	
	inputFile = fopen("input.txt", "r");
	
	while (fscanf(inputFile, "%s %d\n", &nextCommand, &nextParameter) == 2)
	{
		if (strcmp("forward", nextCommand) == 0)
		{
			distance += nextParameter;
			depth += (aim * nextParameter);
		}
		else if (strcmp("up", nextCommand) == 0)
		{
			aim -= nextParameter;
		}
		else if (strcmp("down", nextCommand) == 0)
		{
			aim += nextParameter;
		}
		else
		{
			printf("Unrecognized command.\n");
		}
	}
	
	printf("The final depth and distance are %d and %d, respectively.\n", depth, distance);
	printf("Their product is %d.\n", depth * distance);
	
	return 0;
}
