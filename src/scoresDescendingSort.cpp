/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>



struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	int outerIndex,innerIndex,temp;
	if (students == NULL || len < 0)
		return NULL;
	struct student swap;
	for (outerIndex = 0; outerIndex < len; outerIndex++)
	{
		temp = outerIndex;
		for (innerIndex = temp; innerIndex < len; innerIndex++)
		{
			if (students[temp].score < students[innerIndex].score)
				temp = innerIndex;
		}
		swap = students[outerIndex];
		students[outerIndex] = students[temp];
		students[temp] = swap;
	}
	
	
}