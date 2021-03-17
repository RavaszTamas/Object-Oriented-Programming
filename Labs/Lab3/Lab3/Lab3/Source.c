#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <math.h>
#include <assert.h>
#include <string.h>

	/*
	precondition:
	input:
	output:
	postcondition:
	*/


//Definition of a point using a strucure with two integers for the x and y coordiantes
typedef struct 
{
	int XCoord;
	int YCoord;
}point;


int GreatestCommonDivisor(int number1, int number2)
{
	/*
	Greatest Common Divisor, calcualtes the greates comon divisor for the 
			number1 and number2
	precondition: number1 and number2 - integers
	input: number1 - integer
		   number2 - integer
	output:number1 - modified as the greatest common divisor,integer
	postcondition: the return value can't be zero
	*/
	int auxilliaryNumber = 0;
	while(number2)
	{
		auxilliaryNumber = number1 % number2;
		number1 = number2;
		number2 = auxilliaryNumber;
	}
	return number1;
}


int isSamePoints(point First, point Second)
{
	/*
	Check wether two points are equal, meaning they have the same coordiantes
	precondition: First and Second must be of point type, already defined
	input: First, Second - point structures with XCoord and YCoord atributes
	output: 1 if they are equal
			o if they are not equal
	postcondition: none
	*/
	if (First.XCoord == Second.XCoord && First.YCoord == Second.YCoord )
		return 1;
	return 0;
}

void PrintPointVector(int startIndex, int finishIndex,point pointArray[])
{
	/*
	Display the point array between the start and endindex
	precondition: The startIndex is smaller or equal than the finishIndex
	input:startIndex - integer the starting index of the output on the array
		  finishIndex - integer the ending index of the output of the array
	output: to the console the values between the indexes
	postcondition: none
	*/
	for(int i = startIndex; i <= finishIndex; i++)
		printf("%d %d ",pointArray[i].XCoord,pointArray[i].YCoord); 
}

void evaluateChange(int* end, int* start, int* tempEnd, int* tempStart)
{
	/*
	Checks if the tempStart tempEnd values contain a larger interval than start end
	precondition:end < start and tempEnd < tempStart
	input: end, start,tempEnd,tempStart - pointers to these integer values
	output: none - the values of the input are changed accordingly
	postcondition: nnoe
	*/

	if(*tempEnd - *tempStart > *end - *start)
	{
		*end = *tempEnd;
		*start = *tempStart;
	}
		
}


point* readPoints(int* length)
{
	/*
	Reads a line where are an even amount of numbers where the first is the XCoordinate and the second is the YCoordinate
	precondition: length should be 0 because we don't have any elements yet
	input: length - integer should be 0
	output:the pointer to the point array
	postcondition: at least one element in the list
	*/
	//scanf("%[^'\n']s",someVariable);

	char someString[1000000];
	scanf("%[^'\n']s",someString);

	

	point* arrayOfPoints = (point*) calloc(10000,sizeof(point));

	if (arrayOfPoints == NULL)
		exit(0);
	*length = 0;

	char* param;
	int paramnumber = 0;

	param = strtok(someString," \n");

	while(param != NULL)
	{

		paramnumber = atoi(param);
		arrayOfPoints[*length].XCoord = paramnumber;

		param = strtok(NULL, " \n");
		paramnumber = atoi(param);
		arrayOfPoints[*length].YCoord = paramnumber;
		*length = *length + 1;

		param = strtok(NULL, " \n");


	}
	
	/*
	int stringlength = 0;
	while(1)
	{
		scanf("%s",readString);
		sscanf(readString,"%d",&arrayOfPoints[*length].XCoord);
		scanf("%s",readString);
		sscanf(readString,"%d",&arrayOfPoints[*length].YCoord);
		*length = *length + 1;
		scanf("%c",&character);
		if(character == '\n')
			break;
	}*/


	return arrayOfPoints;
}

int checkForStartDuplicate(int length, point* arrayOfPoints)
{
	/*
	Checks if there are duplicates at the start, and if yes returns the index where the duplicates end
	precondition: the length and array are already defined and correclty constructed
	input: length - integer representing the length of the array
		   arrayOfPoints- a pointer representing the address to the point array
	output: returns the index where the duplicates end
	postcondition: none
	*/

	int tempIndex = 0;

	while(isSamePoints(arrayOfPoints[tempIndex],arrayOfPoints[tempIndex+1]) == 1 && tempIndex < length)
		tempIndex++;

	return tempIndex;
}

void Solve(int lengthOfPointArray, point* arrayOfPoints, int* startIndex, int* endIndex)
{
	/*
	Given the length the array, and the startIdx, endIdx of the result find the longest contiguos suvsequence as such that all the points are on
	the same line
	precondition: the length and the array a correctly deinfec, startIdx, endIdx should be 0
	input: length - length of the array integer
		   arrayOfPoints - point type integer of the arrayOfPoints
		   startIdx - integer
		   endIDx - integer
	output: startIdx, endIdx as the results
	postcondition: startIdx < endIdx
	*/

	if (lengthOfPointArray == 0)
		return;
	if (lengthOfPointArray == 1)
	{
		*startIndex = 0;
		*endIndex = 0;
		return;
	}

	*endIndex = checkForStartDuplicate(lengthOfPointArray,arrayOfPoints);

	if (*endIndex == lengthOfPointArray-1)
	{
		*startIndex = 0;
		*endIndex = lengthOfPointArray-1;
		return;
	}

	int i = 0;

	*startIndex = 0;

	int tempStartIdx = 0;
	int tempEndIdx = *endIndex;
	int XDifference = 0;
	int YDifference = 0;
	int currentGCD = 0;
	int previousXDIfference = 0;
	int previousYDifference = 0;

	previousXDIfference = arrayOfPoints[tempEndIdx+1].XCoord - arrayOfPoints[tempEndIdx].XCoord;
	previousYDifference = arrayOfPoints[tempEndIdx+1].YCoord - arrayOfPoints[tempEndIdx].YCoord;

	currentGCD = GreatestCommonDivisor(previousXDIfference,previousYDifference);

	previousXDIfference = previousXDIfference / currentGCD;
	previousYDifference = previousYDifference / currentGCD;

	for(i = *endIndex; i < lengthOfPointArray - 1; i++)
	{
		
			XDifference = arrayOfPoints[i+1].XCoord - arrayOfPoints[i].XCoord;
			YDifference = arrayOfPoints[i+1].YCoord - arrayOfPoints[i].YCoord;
			if(XDifference == 0 && YDifference == 0)
			{
				tempEndIdx++;
				continue;
			}
			currentGCD = abs(GreatestCommonDivisor(XDifference,YDifference));
			XDifference = XDifference / currentGCD;
			YDifference = YDifference / currentGCD;

			if (previousXDIfference == XDifference && previousYDifference == YDifference)
			{
				tempEndIdx++;
			}
			else
			{
				evaluateChange(endIndex,startIndex,&tempEndIdx,&tempStartIdx);		
				tempStartIdx = tempEndIdx;
				tempEndIdx++;
				previousXDIfference = XDifference;
				previousYDifference = YDifference;
			}
	}
	evaluateChange(endIndex,startIndex,&tempEndIdx,&tempStartIdx);		

	
}
		/*
		if (!(arrayOfPoints[i+1].XCoord - arrayOfPoints[i].XCoord == 0 && arrayOfPoints[i+1].YCoord - arrayOfPoints[i].YCoord == 0))
		{
		}
		*/
void UI(int length, point* arrayOfPoints)
{
	int startidx, endidx;
	arrayOfPoints = readPoints(&length);
	Solve(length,arrayOfPoints,&startidx,&endidx);
	PrintPointVector(startidx,endidx,arrayOfPoints);
	free(arrayOfPoints);

}

void testAll()
{

	assert(GreatestCommonDivisor(1,2) == 1);
	assert(GreatestCommonDivisor(1000,50) == 50);
	assert(GreatestCommonDivisor(1024, 16) == 16);
	assert(GreatestCommonDivisor(-1,0) == 12);
	
	point one;
	one.XCoord = 1;
	one.YCoord = 1;

	point second;
	second.XCoord = 1;
	second.YCoord = 1;

	assert(isSamePoints(one,second) == 1);

	second.XCoord = 2;
	second.YCoord = 2;

	assert(isSamePoints(one,second) == 0);


	int length = 0;
	int startidx, endidx;
	int startidxtemp, endidxtemp;
	startidxtemp = 1;
	endidxtemp = 11;
	startidx = 0;
	endidx = 5;

	evaluateChange(&endidx,&startidx,&endidxtemp,&startidxtemp);

	assert(startidx == 1);
	assert(endidx == 11);
	startidx = 0;
	endidx = 0;

	point* arrayOfPoints = NULL;
	arrayOfPoints = (point*)calloc(1000,sizeof(point));

	int i = 0;
	length = 50;

	for(i = 0; i < length; i++)
	{
		arrayOfPoints[i].XCoord = i;
		arrayOfPoints[i].YCoord = i;
	}

	Solve(length,arrayOfPoints,&startidx,&endidx);

	assert(startidx == 0);
	assert(endidx == 49);

	i = 0;
	length = 101;

	for(i = 0; i < 50; i++)
	{
		arrayOfPoints[i].XCoord = i;
		arrayOfPoints[i].YCoord = i;
	}

	for(i = 0; i < 51; i++)
	{
		arrayOfPoints[i+50].XCoord = i;
		arrayOfPoints[i+50].YCoord = i;
	}

	Solve(length,arrayOfPoints,&startidx,&endidx);

	assert(startidx == 50);
	assert(endidx == 100);

	i = 0;
	length = 101;

	for(i = 0; i < 50; i++)
	{
		arrayOfPoints[i].XCoord = 0;
		arrayOfPoints[i].YCoord = i;
	}

	for(i = 0; i < 51; i++)
	{
		arrayOfPoints[i+50].XCoord = i;
		arrayOfPoints[i+50].YCoord = 0;
	}

	Solve(length,arrayOfPoints,&startidx,&endidx);

	assert(startidx == 50);
	assert(endidx == 100);

	free(arrayOfPoints);
	//system("pause");

}

int main()
{
	int lengthOfArray = 0;
	point* arrayOfPoints = NULL;
	//testAll();
	UI(lengthOfArray,arrayOfPoints);
	
	_CrtDumpMemoryLeaks();

	//system("pause");

	return 0;

}