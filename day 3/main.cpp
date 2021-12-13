#include <stdio.h>
#include <stdlib.h>

struct columnTally
{
	int ones;
	int zeroes; // zeros??? not thinking about this
};

int main()
{
	FILE *inputFile;
	int columnIndex = 0;
	int columnCount = 0;
	columnTally *tallies;
	char nextBit;
	int binaryDigitDecimalValue = 1;
	int gammaRate = 0;
	int epsilonRate = 0;
	
	inputFile = fopen("input.txt", "r");
	
	while (fscanf(inputFile, "%c", &nextBit) == 1)
	{
		if (nextBit == '\n')
		{
			break;
		}
		else
		{
			columnCount++;
		}
	}
	
	tallies = (columnTally *)malloc(sizeof(columnTally) * columnCount);
	fseek(inputFile, 0, SEEK_SET);
	
	for (int i = 0; i < columnCount; i++)
	{
		tallies[i].zeroes = 0;
		tallies[i].ones = 0;
	}
	
	while (fscanf(inputFile, "%c", &nextBit) == 1)
	{
		if (nextBit == '1')
		{
			tallies[columnIndex].ones++;
			columnIndex++;
		}
		else if (nextBit == '0')
		{
			tallies[columnIndex].zeroes++;
			columnIndex++;
		}
		
		if (columnIndex == columnCount)
		{
			columnIndex = 0;
		}
	}
	
	for (int i = columnCount - 1; i >= 0; i--)
	{
		if (tallies[i].ones > tallies[i].zeroes)
		{
			gammaRate += binaryDigitDecimalValue;
		}
		else
		{
			epsilonRate += binaryDigitDecimalValue;
		}
		
		binaryDigitDecimalValue *= 2;
	}
	
	printf("The gamma and epsilon rates are %d and %d, respectively.\n", gammaRate, epsilonRate);
	printf("The power consumption is %d\n", gammaRate * epsilonRate);
	
	return 0;
}