#include "pch.h"
#include "ClassText.h"
#include "framework.h"

char Symbol::getCharacter() {
	return character;
}

void Symbol::setCharacter(char c) {
	character = c;
}

int Symbol::strlen(const char* str) {
	int counter = 0;
	while (str[counter] != '\0') {
		counter++;
	}
	return counter;
}

void Symbol::strcopy(char* destination, const char* source) {
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

Word::Word(const char* str) {
	int length = strlen(str);
	word = new char[length + 1];
	strcopy(word, str);
}

Word::Word(const Word& other) {
	int length = strlen(other.word);
	word = new char[length + 1];
	strcopy(word, other.word);
}

Word::~Word() {
	delete[]word;
}

const char* Word::getWord() const {
	return word;
}

void Word::setWord(const char* value) {
	delete[] word;
	int length = strlen(value);
	word = new char[length + 1];
	strcopy(word, value);
}

Word& Word::operator=(const Word& other) {
	if (this != &other) {
		delete[] word;
		int length = strlen(other.word);
		word = new char[length + 1];
		strcopy(word, other.word);
	}
	return *this;
}

Word Word::operator+(const Word& other) {
	int length1 = strlen(word);
	int length2 = strlen(other.word);
	char* tmp = new char[length1 + length2 + 1];
	strcopy(tmp, word);
	strcopy(tmp + length1, other.word);
	Word result(tmp);
	delete[]tmp;
	return result;
}

char& Word::operator[](int index) {
	return word[index];
}

Paragraph::Paragraph(const char* str) {
	int length = strlen(str);
	paragraph = new char[length + 1];
	strcopy(paragraph, str);
}

Paragraph::Paragraph(const Paragraph& other) {
	int length = strlen(other.paragraph);
	paragraph = new char[length + 1];
	strcopy(paragraph, other.paragraph);
}

Paragraph::~Paragraph() {
	delete[]paragraph;
}

const char* Paragraph::getParagraph() const {
	return paragraph;
}

void Paragraph::setParagraph(const char* c) {
	delete[] paragraph;
	int length = strlen(c);
	paragraph = new char[length + 1];
	strcopy(paragraph, c);
}

Paragraph& Paragraph::operator=(const Paragraph& other) {
	if (this != &other) {
		delete[] paragraph;
		int length = strlen(other.paragraph);
		paragraph = new char[length + 1];
		strcopy(paragraph, other.paragraph);
	}
	return *this;
}

bool Paragraph::isEmpty() const {
	if (paragraph == nullptr) {
		return true;
	}
	else {
		return paragraph[0] == '\0';
	}
}

int Paragraph::strLen() {
	int counter = 0;
	while (paragraph[counter] != '\0') {
		counter++;
	}
	return counter;
}
