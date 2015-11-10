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
#include<string.h>

struct student {
	char name[10];
	int score;
};
void merge(struct student *s, int start, int end, int mid);
void mergesort(struct student *s, int start, int end)
{
	int mid;
	if (start< end)
	{
		mid = (start + end) / 2;
		mergesort(s, start, mid);
		mergesort(s, mid + 1, end);
		merge(s, start, end, mid);
	}
	return;
}
void merge(struct student *s, int start, int end, int mid)
{
		int i, j, k;
		struct student c[50];
		i = start;
		k = start;
		j = mid + 1;
		while (i <= mid && j <= end)
		{
			if (s[i].score > s[j].score)
			{
				c[k].score = s[i].score;
				strcpy(c[k].name,s[i].name);
				k++;
				i++;
			}
			else
			{
				c[k].score = s[j].score;
				strcpy(c[k].name,s[j].name);
				k++;
				j++;
			}

		}
		
		while (j<=end)
		{
			c[k].score = s[j].score;
			strcpy (c[k].name ,s[j].name);
			k++;
			j++;
		}
		while (i <= mid)
		{
			c[k].score = s[i].score;
			strcpy(c[k].name, s[i].name);
			k++;
			i++;
		}
		for ( i = start; i < k; i++)
		{
			s[k].score = c[j].score;
			strcpy(s[k].name,c[j].name);
		}
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len < 0)
		return NULL;
	mergesort(students, 0, len);
	
}