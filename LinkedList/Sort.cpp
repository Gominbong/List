#include <stdio.h>
#include "UsefulHeap.h"
#include<stdlib.h>
int PriComp(int n1, int n2) {
	return n2 - n1;
}

void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	int i;
	HeapInit(&heap, pc);
	for (i = 0; i < n; i++) {
		HInsert(&heap, arr[i]);
	}

	for (i = 0; i < n; i++) {
		arr[i] = HDelete(&heap);
	}
}

void Start4() {
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}



void MergeTwoArea(int arr[], int left, int mid, int right) {
	int leftindex = left;
	int rightindex = mid + 1;
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int startindex = left;

	while (leftindex <= mid && rightindex <= right) {
		if (arr[leftindex] <= arr[rightindex]) {
			sortArr[startindex] = arr[leftindex++];
		}
		else {
			sortArr[startindex] = arr[rightindex++];
		}
		startindex++;
	}

	if (leftindex > mid) {
		for (i = rightindex; i <= right; i++, startindex++) {
			sortArr[startindex] = arr[i];
		}
	}
	else {
		for (i = leftindex; i <= mid; i++, startindex++) {
			sortArr[startindex] = arr[i];
		}
	}
	for (i = left; i <= right; i++) {
		arr[i] = sortArr[i];
	}
	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);
		MergeTwoArea(arr, left, mid, right);
	}
}

void Start5() {
	int arr[7] = { 3,2,4,1,7,6,5 };

	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	
	for (int i = 0; i < 7; i++) {
		printf("%d", arr[i]);
	}
}

void Swap(int arr[], int index1, int index2){
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}


int Partition(int arr[], int left, int right){
	int pivot = arr[left]; 
	int low = left + 1;
	int high = right;

	while (low <= high)   
	{
		while (pivot > arr[low]) {
			low++;
		}

		while (pivot < arr[high]) {
			high--;
		}
		if (low <= high) {
			Swap(arr, low, high);
		}
	}
	Swap(arr, left, high);  
	return high;
}

void QuickSort(int arr[], int left, int right){
	if (left <= right){
		int pivot = Partition(arr, left, right); 
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

void Start6() {
	int arr[7] = { 3,2,4,1,7,6,5 };
	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}
