#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define KST 50
class Competition {
public:
	char* universityName = new char[KST];
	char* date = new char[KST];
	int amountOfVictories = 0;
	void getCompetitions();
};
class Battle {
public:
	char* university1 = new char[KST];
	char* university2 = new char[KST];
	char* command1 = new char[KST];
	char* command2 = new char[KST];
	int score1, score2;
	void getBattles();
};
Competition* getCompetitions(int* size);
Battle* getBattles(int* size);
void sortUniversities(Competition mas[], int size);
void printUniversities(Competition mas[], int size);
void countVictories(Battle battles[], Competition competitions[], int size1, int size2);

int main(int argc, const char* argv[]) {
	int sizeC = 0, sizeB = 0;
	Competition* masC;
	Battle* masB;

	masC = getCompetitions(&sizeC);
	masB = getBattles(&sizeB);
	countVictories(masB, masC, sizeB, sizeC);
	sortUniversities(masC, sizeC);
	printUniversities(masC, sizeC);
}

void sortUniversities(Competition* mas, int size) {//сортування вставками
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && mas[j - 1].amountOfVictories > mas[j].amountOfVictories; j--)
			swap(mas[j - 1], mas[j]);
}
void printUniversities(Competition mas[], int size) {
	cout << "Sorted universities:" << endl;
	for (int i = 0; i < size; i++) {
		cout << mas[i].universityName << "-" << mas[i].amountOfVictories << endl;
	}
}

Competition* getCompetitions(int* size) {
	int sizeC = 0;
	Competition masC[KST];
	for (int i = 0; i < KST; i++) {
		cout << "Enter university name:" << endl;
		cin>>masC[i].universityName;
		if (!strcmp(masC[i].universityName, ""))
			break;
		cout << "Enter the date of competition:" << endl;
		cin >> masC[i].date;
		sizeC++;
	}
	*size = sizeC;
	return masC;
}
Battle* getBattles(int* size) {
	int sizeB = 0;
	Battle masB[KST];
	for (int i = 0; i < 3; i++) {
		cout << "Enter the university of command1:" << endl;
		cin>>masB[i].university1;
		if (!strcmp(masB[i].university1, ""))
			break;
		cout << "Enter the name of command1:" << endl;
		cin>>masB[i].command1;
		cout << "Enter the score of command1:" << endl;
		cin >> masB[i].score1; getchar();
		cout << "Enter the university of command2:" << endl;
		cin>>masB[i].university2;
		cout << "Enter the name of command2:" << endl;
		cin >> masB[i].command2;
		cout << "Enter the score of command2:" << endl;
		cin >> masB[i].score2; getchar();
		sizeB++;
	}
	*size = sizeB;
	return masB;
}
void countVictories(Battle * battles, Competition * competitions, int size1, int size2) {
	char* winner = new char[KST];
	for (int i = 0; i < size1; i++) {

		if (battles[i].score1 > battles[i].score2) {
			winner = battles[i].university1;
		}
		else
			winner = battles[i].university2;
		for (int i = 0; i < size2; i++) {
			if (!strcmp(competitions[i].universityName, winner)) {
				competitions[i].amountOfVictories++;
				break;
			}
		}
	}

}