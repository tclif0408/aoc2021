#include <stdio.h>

int main()
{
	FILE *inputFile = 0;
	char filepath[] = "input.txt";
	int slidingWindow[3];
	int headInput;
	int tailInput;
	int slidingWindowIndex = 0;
	int increaseCount = 0;
	
	inputFile = fopen(filepath, "r");
	
	fscanf(inputFile, "%d%d%d", &slidingWindow[0], &slidingWindow[1], &slidingWindow[2]);
	tailInput = slidingWindow[0];
	
	while (fscanf(inputFile, "%d", &headInput) == 1)
	{
		if (headInput > tailInput)
		{
			increaseCount++;
		}
		
		slidingWindow[slidingWindowIndex % 3] = headInput;
		slidingWindowIndex++;
		tailInput = slidingWindow[slidingWindowIndex % 3];
	}
	
	printf("The total number of increases is %d.\n", increaseCount);
	
	return 0;
}
