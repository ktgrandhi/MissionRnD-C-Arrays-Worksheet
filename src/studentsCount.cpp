
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	int index;
	if (Arr == NULL)
		return NULL;
	if (len <= 0||score<0)
		return NULL;
	*lessCount = 0;
	*moreCount = 0;
	if (len == 1)
	{
		if (Arr[0]>score)
			*moreCount = 1;
		else
		{
			if (Arr[0] < score)
				*lessCount = 1;
			else
			{
				*lessCount = 0;
			}
		}
	}
	else
	{
		for (index = 0; index < len; index++)
		{
			
			if (Arr[index] > score)
				{
					*moreCount=*moreCount+1;
				}
			else
			{
				if (Arr[index] < score)
				{
					*lessCount = *lessCount+1;
				}
			}
			
		}
	}
	
	
}
