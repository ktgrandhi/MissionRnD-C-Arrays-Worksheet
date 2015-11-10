/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int index, index1 = -1, index2 = -1, count = 0,temp;
	if (len < 0 || Arr == NULL)
		return NULL;
	for (index = 0; index < len; index++)
	{
		if (count == 0)
		{
			
			if (index < len - 1 && Arr[index + 1]  <Arr[index] )
			{
				index1 = index;
				count++;
			}
		}
		else
		{
			if (count == 1)
			{
				if (index<len - 1 && Arr[index]<Arr[index - 1] && Arr[index]<Arr[index + 1] && Arr[index + 1]>Arr[index - 1])
				{
					index2 = index;
					count++;
					break;
				}
				if (index == len - 1)
				{
					index2 = index;
					count++;
					break;
				}
			}
		}
	}
	if (index1 != -1 && index2 != -1)
	{
		temp = Arr[index1];
		Arr[index1] = Arr[index2];
		Arr[index2] = temp;
	}
}