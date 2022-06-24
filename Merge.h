#pragma once
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int*>& A1, vector<int*>& A2, vector<int*>& A, int n)
{
	int  i = 0, j = 0, k = 0;
	int mitad = n / 2;
	while (i < mitad && j < n - mitad) {
		if (*A1[i] < *A2[j])
		{
			A[k] = A1[i];
			i++; k++;
		}
		else {
			A[k] = A2[j];
			j++; k++;
		}
	}
	while (i < mitad) {
		A[k] = A1[i];
		i++; k++;
	}
	while (j < n - mitad) {
		A[k] = A2[j];
		j++; k++;
	}
}
