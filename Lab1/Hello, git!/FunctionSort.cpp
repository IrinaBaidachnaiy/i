#include "FunctionSort.h"
#include <iostream>
using namespace std;
bool predicate(int sum, int sum2){
	return (sum > sum2);
}
void sortRowsOfArr(int** arr, bool(*predicate)(int, int), int n, int m) {
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (!predicate(summa(arr, m, i), summa(arr, m, j))) {
				swap(arr[i], arr[j]);
			}
		}
	}
}
int summa(int** arr, int m, int index){
	int sum = 0;
	for (int j = 0; j < m; j++) {
		sum += arr[index][j];
	}
	return sum;
}
void amountOfCriteria(int& good, int& neither, int& bad, int n, int m, int** arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				good++;
			}
			else if (arr[i][j] < 0) {
				bad++;
			}
			else {
				neither++;
			}
		}
	}
}