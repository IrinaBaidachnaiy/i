#pragma once
bool predicate(int sum, int sum2);
void sortRowsOfArr(int** arr, bool(*predicate)(int, int), int n, int m);
int summa(int** arr, int m, int k);
void amountOfCriteria(int& good, int& neither, int& bad, int n, int m, int** arr);