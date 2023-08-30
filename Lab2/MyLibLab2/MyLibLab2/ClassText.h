#pragma once
#include "pch.h"
#include "framework.h"
class Symbol {
protected:
	char character;
public:
	Symbol() : character('\0') {};
	~Symbol() {};
	Symbol(const char c) : character(c) {};
	char getCharacter();
	void setCharacter(char c);
	int strlen(const char* str);
	void strcopy(char* destination, const char* source);
};

class Word : public Symbol {
protected:
	char* word;
public:
	Word() : word(nullptr) {}
	Word(const char* str);
	Word(const Word& other);
	~Word();
	const char* getWord() const;
	void setWord(const char* value);
	// Overloaded operator =
	Word& operator=(const Word& other);
	// Overloaded operator +
	Word operator+(const Word& other);
	// Overloaded operator []
	char& operator[](int index);
};

class Paragraph : public Word {
private:
	char* paragraph;
public:
	Paragraph() : paragraph(nullptr) {}
	Paragraph(const char* str);
	Paragraph(const Paragraph& other);
	~Paragraph();
	const char* getParagraph() const;
	void setParagraph(const char* c);
	// Overloaded operator =
	Paragraph& operator=(const Paragraph& other);
	bool isEmpty() const;
	int strLen();
	class Proxy : public Symbol {
	protected:
		Paragraph& wordRef;
		int index;
	public:
		Proxy(Paragraph& wordObj, int i) : wordRef(wordObj), index(i) {}
		// Overloaded operator =
		Proxy& operator=(const char* replacement) {
			int length = strlen(replacement);
			strcopy(wordRef.paragraph + index, replacement);
			wordRef.paragraph[index + length] = '\0';
			return *this;
		}
	};
	// Overloaded operator ()
	Proxy operator()(int index, int length) {
		return Proxy(*this, index);
	}

};

