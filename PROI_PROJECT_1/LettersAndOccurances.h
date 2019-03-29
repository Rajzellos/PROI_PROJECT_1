#ifndef LETTERSANDOCCURANCES_H
#define LETTERSANDOCCURANCES_H
#include "Letter.h"
#include <string>
#include <iostream>
class LettersAndOccurances
{
private:
	Letter * head, *tail;
	std::string textHistogramed;
	unsigned int letterAmount;
public:
	const Letter * first() const;
	const Letter * last() const;

	std::string getText() const;
	void setText(std::string newText);
	void addText(std::string newText);
	unsigned int getLetterAmount() const;
	void increaseLetterAmount();
	//void setLetterAmount(unsigned int letterAmount);
	LettersAndOccurances();
	LettersAndOccurances(const LettersAndOccurances & copy);
	LettersAndOccurances(std::string stringGiven);
	void addLetter(char letter);
	~LettersAndOccurances();
	void printLetterList();
	void printFrequency();


	//LettersAndOccurances operator +(const LettersAndOccurances secondHistogram);
	LettersAndOccurances operator +=(LettersAndOccurances secondHistogram);

	friend std::ostream & operator << (std::ostream &  output, const LettersAndOccurances & list);

};
LettersAndOccurances operator +(LettersAndOccurances firstHistogram, const LettersAndOccurances & secondHistogram);
bool operator ==(const LettersAndOccurances & firstHistogram, const LettersAndOccurances & secondHistogram);
bool operator !=(const LettersAndOccurances & firstHistogram, const LettersAndOccurances & secondHistogram);

#endif LETTERSANDOCCURANCES_H