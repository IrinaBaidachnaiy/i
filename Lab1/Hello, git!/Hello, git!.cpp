#include <iostream>
#include <fstream>
#include <iomanip>
#include "FunctionSort.h"
using namespace std;
void errNameInFile(char* nameIn) {
	ifstream infile(nameIn);
	while (!infile.is_open()){
		cout << "The file doesn`t exist!\nEnter the name of file again: ";
		cin.getline(nameIn, 30);
		infile.open(nameIn);
	}
	infile.close();
}
void errNameOutFile(char* nameOut) {
	char txt[5] = ".txt";
	int counter, k;
	bool check;
	do{
		k = 0, counter = 0, check = true;
		for (int i = 0; nameOut[i] != '\0'; i++) {
			counter++;
		}
		for (int i = counter - 4; i <= counter; i++, k++) {
			if (txt[k] != nameOut[i]) {
				check = false;
			}
		}
		if (check == false){
			cout << "You entered an incorrect name of the OUT file. \nTry agin: ";
			cin.getline(nameOut, 30);
		}
	} while (check == false);
}
void enterToArr(char* nametxt, int n, int m, int** arr) {
	int elements, counter = 0;
	ifstream infile(nametxt);
	while (infile >> elements) {
		counter++;
	}
	infile.close();
	infile.open(nametxt);
	infile >> n;
	infile >> m;
	if (n * m <= counter) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				infile >> arr[i][j];
			}
		}
	}
	else {
		cout << "\nIn the file doesn`t enough the elements. In this file must be " << n * m << " elements!\nBut in your file " << counter - 2 << " elements!" << endl;
		exit(0);
		system("pause");
	}
	infile.close();
}
void outputFile(int** arr, int n, int m, char* nameOuttxt) {
	int good = 0, neither = 0, bad = 0;
	ofstream outfile(nameOuttxt);
	outfile << "Sorting by sum of the rows:" << endl;
	sortRowsOfArr(arr, predicate, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			outfile << setw(4) << arr[i][j];
		}
		outfile << endl;
	}
	amountOfCriteria(good, neither, bad, n, m, arr);
	outfile << "\nAmount of GOOD numbers = " << good << ", of NEITHER numbers = " << neither << ", of BAD numbers = " << bad << endl;
	cout << "\nSo, you can move to your out file to watch the result :)" << endl;
}
void inputFile() {
	char nameIntxt[30], nameOuttxt[30];
	int n, m;
	cout << "You didn`t enter enough parameters for programm\nInput the name of the file which will be reading: ";
	cin.getline(nameIntxt, 30);
	errNameInFile(nameIntxt);
	cout << "Input the \'OUT\' file with .txt: ";
	cin.getline(nameOuttxt, 30);
	errNameOutFile(nameOuttxt);
	ifstream infile(nameIntxt);
	infile >> n;
	infile >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	infile.close();

	enterToArr(nameIntxt, n, m, arr);
	outputFile(arr, n, m, nameOuttxt);

	for (int i = 0; i < n; i++) {
		delete[]arr[i];
	}
	delete[]arr;
}
int main(int argc, char* argv[]) {
	int n, m;
	char* nameOuttxt;
	cout << "Hello user! Welcome to my programm!)" << endl;
	if (argc > 2){
		int k = 3; // ѕользователь первые два параметра пишет дл€ размерности матрицы
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		nameOuttxt = _strdup(argv[argc - 1]);
		if (n * m > argc - 4) {
			inputFile(); // ≈сли пользователь ввел недостаточное кол-во аргументов дл€ матрицы
		}
		else{
			int** arr = new int* [n];
			for (int i = 0; i < n; i++) {
				arr[i] = new int[m];
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++, k++) {
					arr[i][j] = atoi(argv[k]);
				}
			}

			errNameOutFile(nameOuttxt);
			outputFile(arr, n, m, nameOuttxt);

			for (int i = 0; i < n; i++) {
				delete[]arr[i];
			}
			delete[]arr;
		}
	}
	else{ // ≈сли пользователь не ввел аргументы дл€ командной строки
		inputFile();
	}
	system("pause");
}
