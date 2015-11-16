/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<malloc.h>
void * removeArrayDuplicates(int *Arr, int len)
{
	
	int Reference[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, count = 0, index, value = 0;
	if (Arr == NULL || len < 0)
		return NULL;
	for (index = 0; index < len; index++)
	{
		if (Reference[Arr[index]] == 0)
		{
			count++;
			Reference[Arr[index]] = 1;
		}
	}
	if (count == len)
	{
		return Arr;
	}
	else
	{
		for (index = 0; index < 10; index++)
		{
			if (Reference[index] == 1)
			{
				Arr[value++] = index;
			}
			if (value == count)
			{
				break;
			}
		}
		return Arr;
	}
	
}