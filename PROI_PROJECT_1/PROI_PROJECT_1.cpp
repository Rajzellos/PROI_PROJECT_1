#include "pch.h"
#include "LettersAndOccurances.h"
#include <iostream>
#include <conio.h>

using namespace std;

void displayMenuList(LettersAndOccurances, LettersAndOccurances);

int main()
{
	LettersAndOccurances first{};
	LettersAndOccurances second{};
	LettersAndOccurances third{};
	char key = 9;
	string userGivenText;
	
	while (key!=0) {
		displayMenuList(first, second);
		cout << endl << "What's your choice? ";
		key = _getch();		
		cout << key << endl;
		switch (key)
		{
		case '1':
			system("cls");
			cout << first;
			break;
		case '2':
			system("cls");
			cout << second;
			break;
		case '3':
			system("cls");
			cout << "Podaj tekst do String 1:" << endl;
			cin.clear();
			getline(cin, userGivenText);
			first.setText(userGivenText);
			system("cls");
			break;
		case '4':
			system("cls");
			cout << "Podaj tekst do String 2:" << endl;
			cin.clear();
			getline(cin, userGivenText);
			second.setText(userGivenText);
			system("cls");
			break;
			
		case '5':
			first += second;
			system("cls");
			break;

		case '6':
			if (first.getLetterAmount() < second.getLetterAmount()){
				third = first;
				first = second;
				second = third;
				third.setText("");
			}
			else {
				third = second;
				second = first;
				first = third;
				third.setText("");
			}
			system("cls");
			break;
		case '7':
			system("cls");
			cout << "Czy Histogramy: \n" << first.getText() << endl << "oraz\n" << second.getText() << endl << "sa rowne?  ";
			if (first == second)
				cout << "TAK" << endl;
			else
				cout << "NIE" << endl;
			break;
		case '8':
			cout << "Co chcesz dodac?\n";
			cin.clear();
			getline(cin, userGivenText);
			first.addText(userGivenText);
			system("cls");
			break;
		case '0':
			exit(0);
		default:
			break;
		}
	}
	
}

void displayMenuList(LettersAndOccurances first, LettersAndOccurances second) {
	cout << "Pierwszy String:\t" << first.getText() << endl;
	cout << "Drugi String: \t\t" << second.getText() << endl;
	cout << "1. Wyswietl Histogram 1" << endl;
	cout << "2. Wyswietl Histogram 2" << endl;
	cout << "3. Wprowadz/zmien Strin numer 1" << endl;
	cout << "4. Wprowadz/zmien String numer 2" << endl;
	cout << "5. Dodaj String 2 do String 1" << endl;
	cout << "6. Zamien Stringi" << endl;
	cout << "7. Sprawdz czy Histogramy sa rowne" << endl;
	cout << "8. Dodaj tekst do String 1" << endl;
	cout << "0. Exit" << endl;
}