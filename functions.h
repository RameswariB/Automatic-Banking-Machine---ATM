#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Global Variable Declaration

struct Account {
	string number;
	string client;
	string pin;
	float balance;
};
int nbAcc;
int currAcc = 0;
Account tabAccounts[200];
//defining functions
void DisplayTitle(string title,bool isTitle) {

	if (isTitle) {
		int i;
		for (i = 0; i < title.length(); i++) {
			title[i] = char(toupper(title[i]));
		}
	}
	
	if (isTitle) {
		cout << "\t\t";
	}
	else {
		cout << "\t";
	}
	for (int i = 0; i < title.length(); i++) {
		cout << title[i];
	}
	cout << "\n";
	if (isTitle) {
		cout << "\t\t";
	}
	else {
		cout << "\t";
	}

	for (int i = 0; i < title.length(); i++) {
		cout << "-";
	}
	cout << "\n";
}
int ReadAllAccounts() {
	ifstream myFile;
	int i = 0;
	myFile.open("Account.txt");
	while (myFile.eof() == false)  // !myfile.eof()
	{
		string temp;
		getline(myFile, tabAccounts[i].number);
		getline(myFile, tabAccounts[i].client);
		getline(myFile, tabAccounts[i].pin);
		myFile >> temp;
		tabAccounts[i].balance = stof(temp);
		myFile.ignore();
		i++;

	}
	myFile.close();
	return i;
}

string GetAccNoNumber() {
	string accNo;
	do {
		cout << "Entrez votre numero de compte :";
		getline(cin, accNo);
	
	} while (accNo =="");
	return accNo;
}
void PrintName(string accNo) {
	for (int i = 0; i < nbAcc; i++) {
		if (tabAccounts[i].number == accNo) {
			cout << "\n \t Bienvenue "<<tabAccounts[i].client<<endl;
		}
	}
}
string GetPinNumber() {
	string pin;
	do {
		cout << "Entrez votre nip :";
		getline(cin, pin);

	} while (pin == "");
	return pin;
}

bool validateAccPin(string accNo, string pin) {
	bool check = false;;
	for (int i = 0; i < nbAcc; i++) {
		if (tabAccounts[i].number == accNo && tabAccounts[i].pin == pin) {
			currAcc = i;
			check = true;
		}
	}
	return check;
}

void DisplayMenu() {
	cout << "\n";
	cout << "Choisir votre transaction \n ";
	cout << "\t 1 - Pour Deposer \n";
	cout << "\t 2 - Pour Retirer \n";
	cout << "\t 3 - Pour Consulter \n";

}
int getchoice() {
	int choice;
	do {
		cout << "Entrez Votre Choix <1-3> :";
		cin >> choice;
	} while (choice < 0 ||choice > 3);
	return choice;
}
float DepositeFunction() {
	float dipositeAmt;
	do {
		cout << "Enterz le montant a deposer :";
		cin >> dipositeAmt;
	} while (dipositeAmt < 2 || dipositeAmt >= 20000);
	
	return dipositeAmt;
}
float WithdrawFunction() {
	int withdrawAmt;
	int minAmt = 20;
	int maxAmt = 500;
	bool correctAmt=false;
	do {
		cout << "Entrez le montant a retirer :";
		cin >> withdrawAmt;

		if ((withdrawAmt% minAmt == 0) && (withdrawAmt >= minAmt) && (withdrawAmt <=maxAmt) && (tabAccounts[currAcc].balance > withdrawAmt)) {
			correctAmt = true;
		}
		else if ((withdrawAmt % minAmt != 0) || (withdrawAmt <= minAmt) || (withdrawAmt >= maxAmt) ||  (tabAccounts[currAcc].balance <= withdrawAmt)) {

			if ((withdrawAmt % minAmt != 0) || (withdrawAmt <= minAmt) || (withdrawAmt >= maxAmt)) {
				cout << "Veuillez entrer un montant valide entre 20 $ et 500 $, et son multiple par 20 \n";
			}
			else if (tabAccounts[currAcc].balance <= withdrawAmt){
				cout << "Veuillez saisir un montant valide ...\n";
			}
		}
	} while (correctAmt==false);

	return withdrawAmt;
}
void writeToFile(float diposite, bool isDiposite) {
	ofstream myFile;
	myFile.open("Account.txt");
	for (int i = 0; i < nbAcc; i++) {
		myFile << tabAccounts[i].number << endl;
		myFile << tabAccounts[i].client << endl;
		myFile << tabAccounts[i].pin << endl;
		if (i == currAcc) {
			if (isDiposite) {
				tabAccounts[i].balance += diposite;
			}
			else {
				tabAccounts[i].balance -= diposite;
			}
		}
		if (i < (nbAcc - 1)) {

			myFile << tabAccounts[i].balance << endl;
		}
		else {
			myFile << tabAccounts[i].balance;
		}

	}
	myFile.close();
}
void DisplayCurrentAccount() {

	cout << "\n\n";
	cout << "------la transaction a reussi--------- \n";
	cout << "Les infos du compte\n";
	cout << "\tNumro :"<< tabAccounts[currAcc].number<<"\n";
	cout << "\tClient :" << tabAccounts[currAcc].client << "\n";
	cout << "\tNip :" << tabAccounts[currAcc].pin << "\n";
	cout << "\tSolde $ :" << tabAccounts[currAcc].balance << "\n\n";

	cout << "Merci d'avoir utiliser nos services\n\n";
}

void DisplayThankYouNote() {
	cout << "\n\n\n";
	cout << "\t ___________    __        __    __________     _______________\n";
	cout << "\t| |______  /   / /       / /   /  _____  /    /______________/\n";
	cout << "\t| |      | |   | |       | |   | |     | |          |  |\n";
	cout << "\t| |______| |   | |_______| |   | |     | |          |  |\n";
	cout << "\t| |______  |   | |_______| |   | |     | |          |  |\n";
	cout << "\t| |      | |   | |       | |   | |     | |          |  |\n";
	cout << "\t| |______| |   | |       | |   | |_____| |     _____|  |_____\n";
	cout << "\t|_|________/   |_/       |_/   |_________/    /______________/ () () () () ()....\n";
	cout << "\n\n\n";
	cout << "\t\t\t\tLaSalle Collage - Analyste de programme informatique\n";
	cout << "\t\t\t\tNom de l'étudiant: Rameswariben Vipul Bhoi\n";
	cout << "\t\t\t\tNuméro d'étudiant: 2033034\n";
	cout << "\t\t\t\tAnnée - 2021\n";
	cout << "\n\n";
	cout << "\t\t\t\tMerci,.... \n";
	cout << "\n\n";
}
