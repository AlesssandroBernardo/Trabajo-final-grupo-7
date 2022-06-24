#pragma once
#include "Merge.h"

using namespace std;

void mergeSort(vector<int*>& A, int n) {
	if (n > 1) {
		int mitad = n / 2;
		vector<int*> A1;
		for (int i = 0; i < mitad; i++)
		{
			A1.push_back(new int(0));
		}
		vector<int*> A2;
		for (int i = 0; i < n - mitad; i++)
		{
			A2.push_back(new int(0));

		}
		for (int i = 0; i < mitad; i++)
		{
			A1.push_back(new int(*A[i]));
			A1[i] = A[i];
		}
		for (int i = mitad; i < n; i++)
		{
			A2.push_back(new int(*A[i]));
			A2[i - mitad] = A[i];
		}
		mergeSort(A1, mitad);
		mergeSort(A2, n - mitad);
		Merge(A1, A2, A, n);

	}
}
