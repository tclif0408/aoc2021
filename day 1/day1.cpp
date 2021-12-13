#include <stdio.h>

int main()
{
	FILE *inputFile = 0;
	char filepath[] = "input.txt";
	int increaseCounter = 0;
	int currentData;
	int lastData;
	
	inputFile = fopen(filepath, "r");	
	fscanf(inputFile, "%d", &lastData);
	
	while (fscanf(inputFile, "%d", &currentData) == 1)
	{
		if (currentData > lastData)
		{
			increaseCounter++;
		}
		
		lastData = currentData;
	}
	
	printf("Total number of increases: %d.\n", increaseCounter);
	
	return 0;
}
