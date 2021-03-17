#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <math.h>

int gcd(int a, int b)
{
	int m = 0;
	while(b)
	{
		m = a % b;
		a = b;
		b = m;
	}
	return a;
}


typedef struct 
{
	int XCoord;
	int YCoord;
}point;

int equalPoints(point First, point Second)
{
	if (First.XCoord == Second.XCoord && First.YCoord == Second.YCoord )
		return 1;
	return 0;
}

void PrintPointVector(int startIndex, int finishIndex,point pointArray[])
{
	for(int i = startIndex; i <= finishIndex; i++)
		printf("%d %d ",pointArray[i].XCoord,pointArray[i].YCoord); 
}

void evaluateChange(int* end, int* start, int* tempEnd, int* tempStart)
{
	if(*tempEnd - *tempStart > *end - *start)
	{
		*end = *tempEnd;
		*start = *tempStart;
	}
		
}


point* readPoints(int* length)
{
	scanf("%d", length);
	point* arrayOfPoints = (point*) calloc(length,sizeof(point));
	for(int i = 0; i < *length; i++)
	{
		scanf("%d",&arrayOfPoints[i].XCoord);
		scanf("%d",&arrayOfPoints[i].YCoord);
	}
	return arrayOfPoints;
}

int checkForStartDuplicate(int length, point* arrayOfPoints)
{
	int tempIndex = 0;

	while(equalPoints(arrayOfPoints[tempIndex],arrayOfPoints[tempIndex+1]) == 1 && tempIndex < length)
		tempIndex++;

	return tempIndex;
}

void DetermineStart()
{

}

void Solve(int length, point* arrayOfPoints, int* startIdx, int* endIdx)
{
	if (length == 0)
		return;
	if (length == 1)
	{
		*startIdx = 0;
		*endIdx = 0;
		return;
	}

	*endIdx = checkForStartDuplicate(length,arrayOfPoints);

	if (*endIdx == length-1)
	{
		//PrintPointVector(0,length-1,arrayOfPoints);
		*startIdx = 0;
		*endIdx = length-1;
		return;
	}

	int i = 0;

	*startIdx = 0;

	int tempStartIdx = 0;
	int tempEndIdx = *endIdx;
	int XDifference = 0;
	int YDifference = 0;
	int currentGCD = 0;
	int previousXDIfference = 0;
	int previousYDifference = 0;

	previousXDIfference = arrayOfPoints[tempEndIdx+1].XCoord - arrayOfPoints[tempEndIdx].XCoord;
	previousYDifference = arrayOfPoints[tempEndIdx+1].YCoord - arrayOfPoints[tempEndIdx].YCoord;

	currentGCD = gcd(previousXDIfference,previousYDifference);

	previousXDIfference = previousXDIfference / currentGCD;
	previousYDifference = previousYDifference / currentGCD;

	for(i = *endIdx; i < length - 1; i++)
	{
		
			XDifference = arrayOfPoints[i+1].XCoord - arrayOfPoints[i].XCoord;
			YDifference = arrayOfPoints[i+1].YCoord - arrayOfPoints[i].YCoord;
			if(XDifference == 0 && YDifference == 0)
				tempEndIdx++;
				continue;
			currentGCD = abs(gcd(XDifference,YDifference));
			XDifference = XDifference / currentGCD;
			YDifference = YDifference / currentGCD;

			if (previousXDIfference == XDifference && previousYDifference == YDifference)
			{
				tempEndIdx++;
			}
			else
			{
				evaluateChange(endIdx,startIdx,&tempEndIdx,&tempStartIdx);		
				tempStartIdx = tempEndIdx;
				tempEndIdx++;
				previousXDIfference = XDifference;
				previousYDifference = YDifference;
			}
	}
	evaluateChange(endIdx,startIdx,&tempEndIdx,&tempStartIdx);		

	
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

int main()
{
	int length = 0;
	point* arrayOfPoints = NULL;
	UI(length,arrayOfPoints);
	
	_CrtDumpMemoryLeaks();

	system("pause");

	return 0;

}