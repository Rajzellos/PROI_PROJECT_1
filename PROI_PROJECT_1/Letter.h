#ifndef LETTER_H
#define LETTER_H

#include <string>
class Letter
{
private:
	char letter;
	unsigned int occurances;
public:

	Letter * next;
	char getLetter() const;
	void setLetter(char single_letter);
	unsigned int getOccurances() const;
	void increaseOccurances();
	Letter(std::string one_letter);
	Letter(char one_letter);
	~Letter();
};

#endif LETTER_H