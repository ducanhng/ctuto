/* sorting algorithms library

1. Quick sort(use pivot as median)
2. Shell sort
3. Selection sort
4. Insertion sort
5. Bubble sort
6. Merge sort
7. Heap sort

author: ducanhng
date created: 23 June 2011
*/

#include <stdio.h>
#include "mysort.h"
#include "mystr.h"

// Simple selection sort.
void selectionsort(char *ptarr[],int n)
{
	int i,j,k;
	for (i = 0; i <= n; i++)
	{
		k = i;
		for (j = i+1; j <= n; j++)
			// Compare with other elements in arrays to find minimum element
			if (strlen(ptarr[k]) > strlen(ptarr[j]))
				k = j;
		if (k != i)
			swap(ptarr,k,i);
	}
}

void insertionsort(char *ptarr[], int n)
{
	int i,j;
	for (i = 1; i <= n; i++)
	{
		j = i-1;
		char *additem;
		additem = ptarr[i];
		// Insert new element by move other element.
		while (j>=0 && strlen(additem) < strlen(ptarr[j]))
		{
			// increase 1 postion
			ptarr[j+1] = ptarr[j--];
		}
		// Insert here
		ptarr[j+1] = additem;
	}
}

void bubblesort(char *ptarr[], int n)
{
	int i,j;
	for (i = 0;i < n;i++)
	{
		for (j = n; j > i; j--)
		{
			if (strlen(ptarr[j]) < strlen(ptarr[j-1]))
				swap(ptarr,j,j-1);
		}
	}	
}
// The improvement of insertion short with gap greater than 1 :)
void shellsort(char *ptarr[],int n)
{
	int inc,gap,i,j;
	inc = n/2;
	// Loop gap element that intend to insert
	for (gap = n/2;gap > 0; gap /= 2)
	{
		for (i = gap; i <=n; i++)
		{
			j = i - gap;
			while (j>=0 && strlen(ptarr[j+gap]) < strlen(ptarr[j]))
			{
				swap(ptarr,j,j+gap);
				j -= gap;
			}
		}
	}
}

// Simple Quick sort by choosing pivot as median.
void qsort(char *ptarr[], int left, int right)
{
	// Choose pivot as median
	// Partition follow by pivot
	// Less than pivot on the left, greater than pivot on the right
	
	if (left >= right)
		return;	
	int pivot, i, j, pos;
	pivot = (left + right)/2;
	// move pivot to the end of array
	// There are some strategies to move pivot: left, right or middle
	swap(ptarr, pivot,right);
	pos = left;
	for (i = left;i < right ;i++)
	{
		if (strlen(ptarr[i]) < strlen(ptarr[right]))
		{
			swap(ptarr, i, pos);
			pos++;
		}
	}
	swap(ptarr,right,pos);

	qsort(ptarr,left,pos-1);
	qsort(ptarr,pos+1, right);
}

void mergesort(char *ptarr[], int left, int right)
{
	if (right <= left) return;
	int mid = (left + right)/2;
	mergesort(ptarr, left, mid);
	mergesort(ptarr, mid+1, right);
	merge(ptarr, left, mid, right);
}

void merge(char *ptarr[], int left, int mid, int right)
{
	char *buff[100];
	int buffindex,i,pos;
	i = left;
	buffindex = left;
	pos = mid+1;
	while (i <= mid && pos <= right)
	{
		if (strlen(ptarr[i]) < strlen(ptarr[pos]))
			buff[buffindex++] = ptarr[i++];
		else
			buff[buffindex++] = ptarr[pos++];
	}

	//Continue to process tail
	while (i <= mid)
	{
		buff[buffindex++] = ptarr[i++];
	}
	while (pos <= right)
	{
		buff[buffindex++] = ptarr[pos++];
	}
	// copy to buff to array	
	for (i = left; i < buffindex; i++)
		ptarr[i] = buff[i];
	
}

void heapsort(char *ptarr[], int nlines)
{
	// Make heap.
	heapify(ptarr,nlines);
	
	// loop nline - 1 swaping root to end of heap, make a heap.
	int endnode = nlines;
	while (endnode > 0)
	{
		swap(ptarr,0,endnode);
		endnode--;
		if (endnode > 0)
			heapify(ptarr,endnode);
	} 
	 
}

// Follow psuedocode in wiki
void heapify(char *ptarr[], int nlines)
{
	// Make heap from liner character array.
	int endparent,greaternode;
	endparent = nlines/2;
	
	while (endparent >= 0)
	{
		// If choosed child node have value greater than another node.
		greaternode = endparent*2+1;
		if (greaternode <= nlines)
		{
			// always has two child node from parent, and compare.	
			if ((greaternode+1) <= nlines && strlen(ptarr[greaternode]) < strlen(ptarr[greaternode+1]))
			{
				greaternode++;
			}

			// Compare greater node with its parent. If it greater than parent then swap.
			if (strlen(ptarr[greaternode]) > strlen(ptarr[endparent]))
			{
				swap(ptarr,greaternode, endparent);
			}
		}
		
		// Decrease endparent
		endparent--;
	}	
}

// swap position between two numbers in an character pointer array
void swap(char *ptarr[], int pos1, int pos2 )
{
	char *temp;
	temp = ptarr[pos1];
	ptarr[pos1] = ptarr[pos2];
	ptarr[pos2] = temp;
}

