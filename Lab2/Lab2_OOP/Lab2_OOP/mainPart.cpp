#include <iostream>
#include <fstream>
#include "ClassText.h"
#pragma comment(lib, "MyLibLab2.lib")
using namespace std;

// Overloaded operator <<
ostream& operator<<(ostream& os, const char* str) {
	while (*str) {
		os << *str;
		++str;
	}
	return os;
}
// Overloaded operator >>
istream& operator>>(istream& is, const char& str) {
	is >> str;
	return is;
}

void errNameInFile(char* nameIn) {
	ifstream infile(nameIn);
	while (!infile.is_open()) {
		cout << "\tThe file doesn`t exist!\n\tEnter the name of file again: ";
		cin.getline(nameIn, 30);
		infile.open(nameIn);
	}
	infile.close();
}
void errNameOutFile(char* nameOut) {
	char txt[5] = ".txt";
	int counter, k;
	bool check;
	do {
		k = 0, counter = 0, check = true;
		for (int i = 0; nameOut[i] != '\0'; i++) {
			counter++;
		}
		for (int i = counter - 4; i <= counter; i++, k++) {
			if (txt[k] != nameOut[i]) {
				check = false;
			}
		}
		if (check == false) {
			cout << "\tYou entered an incorrect name of the OUT file. \n\tTry agin: ";
			cin.getline(nameOut, 30);
		}
	} while (check == false);
}

void menuObj(int index, Paragraph* Obj) {
	Paragraph a;
	char clear;
	if (Obj[index].isEmpty() == '\0') {
		cout << "\n\tDo you want to clear your object of the class?\n\t1 - Yes\n\t0 - No\n\tYour choice: ";
		cin >> clear;
		while (clear != '1' && clear != '0') {
			cout << "You entered an incorrect data. Try again! Your choice: ";
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> clear;
		}
		if (clear == '0') {
			return;
		}
	}
	char menuObj, * inpSymb, * inpWord, * inpParag;
	bool exit = false, input = false;
	do {
		cout << "\n\tWhat do you want to do?\n\t1 - Enter a symbol\n\t2 - Enter a word\n\t3 - Enter a paragragh\n\t0 - Back\n\tYour choice: ";
		cin >> menuObj;
		switch (menuObj) {
		case '1': {
			cout << "\tEnter a simbol: ";
			inpSymb = new char[2];
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> inpSymb;
			Obj[index] = inpSymb;
			delete[]inpSymb;
			input = true;
			cout << "\t[Done! Choose 3-rd menu item to visualise the object!]" << endl;
			break;
		}
		case '2': {
			cout << "\tEnter a word: ";
			inpWord = new char[30];
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> inpWord;
			for (int i = 0; inpWord[i] != '\0'; i++) {
				if (inpWord[i] == ' ') {
					cout << "Your text read until space!" << endl;
				}
			}
			Obj[index] = inpWord;
			delete[]inpWord;
			input = true;
			cout << "\t[Done! Choose 3-rd menu item to visualise the object!]" << endl;
			break;
		}
		case '3': {
			cout << "\tEnter a paragraph: ";
			inpParag = new char[1000];
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(inpParag, 1000);
			Obj[index] = inpParag;
			delete[]inpParag;
			input = true;
			cout << "\t[Done! Choose 3-rd menu item to visualise the object!]" << endl;
			break;
		}
		case '0':
			exit = true;
			break;
		default:
			cout << "\tUser, you entered an incorrect menu item." << endl;
			break;
		}
		if (exit == true) {
			break;
		}
	} while (exit != true && input != true);
}
void menuInOutFile(int index, Paragraph* Obj, int& quantObj) {
	char menuItemInOut, * q, element, infile[30], outfile[30], * p, data;
	bool exit = false;
	int counter = 0;
	do {
		cout << "\n\tWhat do you want to do?\n\t1 - Input to the file\n\t2 - Output the file\n\t0 - Back\n\tYour choice: ";
		cin >> menuItemInOut;
		switch (menuItemInOut) {
		case '1': {
			q = new char[1000];
			cout << "\tEnter the name of the in-file: ";
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(infile, 30);
			errNameInFile(infile);
			ifstream is(infile);
			is >> noskipws;
			while (is >> element) {
				counter++;
			}
			is.close();
			is.open(infile);
			for (int i = 0; i < counter; i++) {
				is >> q[i];
			}
			q[counter] = '\0';
			is.close();
			Paragraph a = Paragraph(q);
			Obj[index] = a;
			delete[]q;
			cout << "\t[Done! Choose 3-rd menu item to visualise the object!]" << endl;
		}
				break;
		case '2': {
			cout << "\tEnter the name of the out-file: ";
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(outfile, 30);
			errNameOutFile(outfile);
			cout << "\n\t\tDo you want to enter an old data or a new?\n\t\t1 - Old data\n\t\t2 - New data\n\t\t0 - Back\n\t\tYoue chioce: ";
			cin >> data;
			if (data == '1') {
				ofstream os(outfile);
				cout << "\t\tOld Data!" << endl;
				if (Obj[index].isEmpty() == true) {
					cout << "\t\t[Your object is empty!]" << endl;
				}
				else {
					os << Obj[index].getParagraph();
					cout << "\t\t[Done! Check your out-file!]" << endl;
				}
				os.close();
			}
			else if (data == '2') {
				ofstream os(outfile);
				cout << "\t\tEnter a new data!" << endl;
				p = new char[1000];
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\n> ";
				cin.getline(p, 1000);
				for (int i = 0; p[i] != '\0'; i++) {
					os << p[i];
				}
				os.close();
				Paragraph b = Paragraph(p);
				Obj[index] = b;
				delete[]p;
				cout << "[Done! Check your out-file and 3-rd menu item to visualise object!]" << endl;
			}
			else {
				data = '0';
			}
		}
			break;
		case '0':
			exit = true;
			break;
		default:
			cout << "\tUser, you entered an incorrect menu item. Try again!" << endl;
			break;
		}
	} while (exit != true);
}
void menuToDo(int index, Paragraph* Obj) {
	char menuItemToDo, * replacement;
	bool exit = false;
	int indexText, indexChange;
	do {
		cout << "\n\tWhat do you want to do?\n\t1 - Length of text\n\t2 - Change the text\n\t3 - Change color of the text\n\t0 - Back\n\tYour choice: ";
		cin >> menuItemToDo;
		switch (menuItemToDo) {
		case '1':
			if (Obj[index].isEmpty() == true) {
				cout << "\t[Your object is empty!]" << endl;
			}
			else {
				cout << "\tYour text in the object has " << Obj[index].strLen() << " characters!" << endl;
			}
			break;
		case '2':
			replacement = new char[30];
			cout << "\tEnter a part of the word or character which will be replacement: ";
			cin >> replacement;
			cout << "\tEnter the index of the text which we`ll start with : ";
			cin >> indexText;
			while (!cin || indexText < 0 || indexText > Obj[index].strLen()) {
				cout << "\tYou entered an incorrect data. Try again! Your choice: ";
				cin.clear();
				cin.ignore(32767, '\n');
				cin >> index;
			}
			cout << "\tEnter quantity of symbols which will be change: ";
			cin >> indexChange;
			while (!cin || indexChange < 0) {
				cout << "\tYou entered an incorrect data. Try again! Your choice: ";
				cin.clear();
				cin.ignore(32767, '\n');
				cin >> index;
			}
			Obj[index](indexText, indexChange) = replacement;
			cout << "\t[Done! Check 3-rd menu item to visualise the object!]" << endl;
			delete[]replacement;
			break;
		case '3': {
			char i = '1';
			char* color = new char[2], * background = new char[2];
			Word inputColor, inputBackground, wordColor = "color ", result;

			for (; i != '0';) {
				cout << "\n\t\tEnter the number of the colors:\n\t\t0 - Black\n\t\t1 - Blue\n\t\t2 - Green\n\t\t3 - Light Blue\n\t\t4 - Red\n\t\t5 - Purpule\n\t\t6 - Yellow\n\t\t7 - White\n\t\t8 - Grey\n\t\tYour choice about background of the text: ";
				cin >> background;
				inputBackground.setWord(background);
				result = wordColor + inputBackground;

				cout << "\t\tNow, color of the text: ";
				cin.clear();
				cin.ignore(32767, '\n');
				cin >> color;
				inputColor.setWord(color);
				result = result + inputColor;

				system(result.getWord());
				cout << "\t\tAre you sure? 1 - No, 0 - Yes\n\t\tYour answer: ";
				cin.clear();
				cin.ignore(32767, '\n');
				cin >> i;
				while (i != '1' && i != '0') {
					cout << "\t\tYou entered an incorrect data. Try again\n\t\tYour choice: ";
					cin >> i;
				}
			}
			delete[]color;
			delete[]background;
			i = '1';
			break;
		}
		case '0':
			exit = true;
			break;
		default:
			cout << "\tUser, you entered an incorrect menu item." << endl;
			break;
		}
	} while (exit != true);
}
int main() {
	char menuItem = '1';
	int quantObj, index;
	Paragraph* Obj;
	cout << "Hello user! Welcome to my programm!\nEnter a number of the objects which will be created\nQuantity: ";
	cin >> quantObj;
	while (!cin || quantObj < 1) {
		cout << "You entered an incorrect number of the objects. Try again! Your number: ";
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> quantObj;
	}
	Obj = new Paragraph[quantObj];
	cout << "Choose which object you will work with (1 - " << quantObj << ")\nYour choice: ";
	cin >> index;
	while (!cin || index < 1 || index > quantObj) {
		cout << "You entered an incorrect data. Try again! Your choice: ";
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> index;
	}
	index -= 1;
	do {
		cout << "\n~~~You have " << quantObj << " objects. You`re working with " << index + 1 << " object~~~\nChoose the menu item:\n1 - Create objects of class\n2 - In/out-put objects to disk\n3 - Visualize objects\n4 - To do something with data/objects\n5 - Change the object\n0 - Close the programm\nYour choice: ";
		cin >> menuItem;
		switch (menuItem) {
		case '1':
			menuObj(index, Obj);
			break;
		case '2':
			menuInOutFile(index, Obj, quantObj);
			break;
		case '3':
			if (Obj[index].isEmpty() == true) {
				cout << "\n[Your object is empty!]" << endl;
			}
			else {
				cout << "\n> " << Obj[index].getParagraph() << endl;
			}
			break;
		case '4':
			menuToDo(index, Obj);
			break;
		case '5':
			cout << "\nChoose which object you will work with (1 - " << quantObj << ")\nYour choice: ";
			cin >> index;
			while (!cin || index < 1 || index > quantObj) {
				cout << "You entered an incorrect data. Try again! Your choice: ";
				cin.clear();
				cin.ignore(32767, '\n');
				cin >> index;
			}
			index -= 1;
			break;
		case '0':
			cout << "\nSee you next time. Goodbye!" << endl;
			break;
		default:
			cout << "User, you entered an incorrect menu item." << endl;
			break;
		}
	} while (menuItem != '0');
	delete[]Obj;
	exit(0);
	system("pause");
}