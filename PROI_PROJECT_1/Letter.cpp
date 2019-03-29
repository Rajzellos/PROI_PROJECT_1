#include "pch.h"
#include "Letter.h"

char Letter::getLetter() const
{
	return this->letter;
}

void Letter::setLetter(char single_letter)
{
	this->letter = single_letter;
}

unsigned int Letter::getOccurances() const
{
	return this->occurances;
}

void Letter::increaseOccurances()
{
	this->occurances += 1;
}

Letter::Letter(std::string one_letter)
{

}

Letter::Letter(char one_letter)
{
	this->letter = one_letter;
	this->occurances = 1;
}

Letter::~Letter()
{
}
