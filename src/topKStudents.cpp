/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void swap(struct student *a, struct student *b) {
	struct student temp = *a;
	*a = *b;
	*b = temp;
}

void sorting(struct student *array, int len) {
	int outerIndex, innerIndex;
	for (int outerIndex= 0; outerIndex< len - 1; ++outerIndex) {
		for (int innerIndex = 0; innerIndex< len - outerIndex- 1; ++innerIndex) {
			if (array[innerIndex].score < array[innerIndex+ 1].score) {
				swap(&array[innerIndex], &array[innerIndex + 1]);
			}
		}
	}
}

struct student ** topKStudents(struct student *students, int len, int K) {
	struct student **topKStudents;
	int index;
	if (students==NULL||len<0||K<1)
		return NULL;
	sorting(students, len);
	topKStudents = (struct student **)malloc(K*sizeof(struct student *));
	for (index = 0; index < K; index++)
	{
		topKStudents[index] = (struct student *)malloc(sizeof(struct student));
	}
	for ( index = 0; index < K; index++)
	{
		topKStudents[index] = &students[index];
	}
	return topKStudents;

}
