#include "functions.h"

void main() {

	//local variable declaration;
	int choice = 0;
	
	string accNo;
	bool check = false;
	float amount;
	nbAcc = ReadAllAccounts();
	string pin;
	DisplayTitle("banque royale",true);
	DisplayTitle("guichet Automatique Bancaire", false);
	accNo=GetAccNoNumber();
	PrintName(accNo);
	pin= GetPinNumber();
	check=validateAccPin(accNo, pin);
	if (check == true) {
		DisplayMenu();
		choice=getchoice();
		switch (choice) {
		case 1:
			amount=DepositeFunction();
			writeToFile(amount,true);
			DisplayCurrentAccount();
			break;
			
		case 2:
			amount = WithdrawFunction();
			writeToFile(amount,false);
			DisplayCurrentAccount();
			break;
		case 3: 
			DisplayCurrentAccount();
			break;
		}

	}
	else {
		cout << "Vous avez entré broche invalide, s’il vous plaît essayer à nouveau plus tard \n";
		
	}
	
	system("pause");

	system("CLS");
	
	DisplayThankYouNote();
	
}