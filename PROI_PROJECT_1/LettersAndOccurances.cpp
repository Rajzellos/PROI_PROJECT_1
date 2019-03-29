#include "pch.h"
#include "LettersAndOccurances.h"


const Letter * LettersAndOccurances::first() const
{
	const Letter * pnt = this->head;
	return pnt;
}

const Letter * LettersAndOccurances::last() const
{
	const Letter * pnt = this->tail;
	return pnt;
}

std::string LettersAndOccurances::getText() const
{
	return this->textHistogramed;
}

void LettersAndOccurances::setText(std::string newText)
{
	this->letterAmount = 0;
	for (int i = 0; i < newText.size(); ++i) {
		this->addLetter(newText[i]);
	}
	this->textHistogramed = newText;
}

void LettersAndOccurances::addText(std::string newText)
{
	for (int i = 0; i < newText.size(); ++i) {
		this->addLetter(newText[i]);
	}
	this->textHistogramed = this->getText() + newText;
}

unsigned int LettersAndOccurances::getLetterAmount() const
{
	return this->letterAmount;
}

void LettersAndOccurances::increaseLetterAmount()
{
	this->letterAmount += 1;
}

/*
void LettersAndOccurances::setLetterAmount(unsigned int letterAmount)
{
	this->letterAmount = letterAmount;
}
*/

LettersAndOccurances::LettersAndOccurances()
{
	this->letterAmount = 0;
	this->head = nullptr;
	this->tail = nullptr;
}


LettersAndOccurances::LettersAndOccurances(const LettersAndOccurances & copy)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->textHistogramed = copy.textHistogramed;
	for (int i = 0; i < this->textHistogramed.length(); ++i) {
		this->addLetter(this->textHistogramed[i]);
	}
}


LettersAndOccurances::LettersAndOccurances(std::string stringGiven)
{
	this->letterAmount = 0;
	for (int i = 0; i < stringGiven.size(); ++i) {
		this->addLetter(stringGiven[i]);
	}
	this->textHistogramed = stringGiven;
	//std::cout << this->getLetterAmount();
}

void LettersAndOccurances::addLetter(char letter)
{
	this->increaseLetterAmount();
	Letter * letter_pnt;
	if (head != nullptr) {
		letter_pnt = head;
		while (letter_pnt != nullptr) {
			if (letter_pnt->getLetter() == letter) {
				letter_pnt->increaseOccurances();
				break;
			}
			else {
				letter_pnt = letter_pnt->next;
			}
		}
		if (letter_pnt == nullptr) {
			letter_pnt = new Letter(letter);
			tail->next = letter_pnt;
			tail = letter_pnt;
			tail->next = nullptr;
		}
	}

	else
	{
		letter_pnt = new Letter(letter);
		letter_pnt->next = nullptr;
		head = letter_pnt;
		tail = letter_pnt;
	}
}

LettersAndOccurances::~LettersAndOccurances()
{
}

void LettersAndOccurances::printLetterList()
{
	Letter * temp = head;
	while (temp != nullptr) {
		std::cout << "Letter: " << temp->getLetter() << '\t' << "Occurances: " << temp->getOccurances() << std::endl;
		temp = temp->next;
	}
}

void LettersAndOccurances::printFrequency()
{
	Letter * temp = head;
	while (temp != nullptr) {
		std::cout << "Letter: " << temp->getLetter() << '\t' << "Czestotliwosc: " << temp->getOccurances() << '/' << this->getLetterAmount() << std::endl;
		temp = temp->next;
	}
}



LettersAndOccurances operator+(LettersAndOccurances firstHistogram, const LettersAndOccurances & secondHistogram)
{
	firstHistogram += secondHistogram;
	return firstHistogram;
}

bool operator==(const LettersAndOccurances & firstHistogram, const LettersAndOccurances & secondHistogram)
{
	LettersAndOccurances mergedHistogram = firstHistogram + secondHistogram;
	const Letter * merged_pnt = mergedHistogram.first();
	const Letter * origin_pnt = secondHistogram.first();
	for (; merged_pnt != nullptr; merged_pnt = merged_pnt->next) {
		for (; origin_pnt != nullptr; origin_pnt = origin_pnt->next) {
			if (merged_pnt->getLetter() == origin_pnt->getLetter()) {
				if (merged_pnt->getOccurances() != 2 * origin_pnt->getOccurances()) { //mergedHistogram is a combination of two exact Histograms, so each letter occurancy is doubled
					return false;
				}
				else {
					origin_pnt = secondHistogram.first();
					break;
				}
			}
		}
		if (origin_pnt == nullptr)
			return false;
	}
	return true;	//we checked all elements in mergedHistogram and no false returned, so return true
}

bool operator!=(const LettersAndOccurances & firstHistogram, const LettersAndOccurances & secondHistogram)
{
	return !(firstHistogram == secondHistogram);
}

LettersAndOccurances LettersAndOccurances::operator+=(LettersAndOccurances secondHistogram)
{
	this->addText(secondHistogram.getText());
	for (int i = 0; i < secondHistogram.getText().length(); ++i) {
		this->addLetter(secondHistogram.getText()[i]);
	}
	return LettersAndOccurances();
}


std::ostream & operator<<(std::ostream & output, const LettersAndOccurances & list)
{
	output << "TEXT: " << list.getText() << '\n';
	Letter * temp = list.head;
	while (temp != nullptr) {
		output << "Letter: " << temp->getLetter() << '\t' << "Occurances: " << temp->getOccurances() << '\t' << "Czestotliwosc: " << temp->getOccurances() << '/' << list.getLetterAmount() << std::endl;
		temp = temp->next;
	}
	return output;
}

/*
LettersAndOccurances LettersAndOccurances::operator+(LettersAndOccurances secondHistogram)
{
	Letter * origin_pnt = this->tail;
	Letter * new_pnt = secondHistogram.head;
	while (new_pnt != nullptr) {
		this->addLetter(new_pnt->getLetter());
		this->tail = new_pnt;
		new_pnt = new_pnt->next;
	}
	return LettersAndOccurances();
}
*/