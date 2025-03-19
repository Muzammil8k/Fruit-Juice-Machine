#include<iostream>

using namespace std;

class CashRegister
{
	int cashInRegister;//cash that is available in cash register
public:
	CashRegister();
	//default constructor that initiaizes 500 to cashInRegister
	//were suposing that by default cash register has 500 rupees

	CashRegister(int cash);
	//parametrized constructor that initiaizes value to cashInRegister
	//if cash value is negative or zero than 500 will be added

	void inputCash(int cash);
	//adds cash to existing cash in register

	int withdrawCash(int cash);
	//withdraw desired amount

	int getCash();
	//returns cash amount in register
};

class Dispensor
{
	int cost;
	int numberOfItems;
public:
	Dispensor();
	//Default constructor that sets default cost 100 and numberOfItems 50

	Dispensor(int price, int items);
	//parametrized constructor that sets price and total items

	int getCost();
	//returns cost

	int getNumberOfItems();
	//return total number of items

	void makeSale(int quantity);
	//reduces the total number of items by quantity entered and calculates cost
};

void menu();
void makeSale(Dispensor& type,CashRegister counter);

int main()
{
	CashRegister counter1;
	Dispensor appleJuice(100, 80);
	Dispensor mangoJuice(150, 50);
	Dispensor orangeJuice(100, 100);
	Dispensor mixFruitJuice(200, 30);
	int choice;

	menu();
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		makeSale(appleJuice, counter1);
		break;
	case 2:
		makeSale(mangoJuice, counter1);
		break;
	case 3:
		makeSale(orangeJuice, counter1);
		break;
	case 4:
		makeSale(mixFruitJuice, counter1);
		break;
	case 0:
		exit(0);
	default:
		cout << "*************************" << endl;
		cout << "Invalid option" << endl;
		cout << "*************************" << endl;

	}
}

/*******************************************
Class CashRegister function definations
********************************************/
CashRegister::CashRegister()
{
	cashInRegister = 500;
}

CashRegister::CashRegister(int cash)
{
	if (cash >= 0)
		cashInRegister = cash;
	else
		cashInRegister = 500;
}

void CashRegister::inputCash(int cash)
{
	if (cash < 0)
		cash = -cash;
	cashInRegister += cash;
}

int CashRegister::withdrawCash(int cash)
{
	cashInRegister -= cash;
	return cash;
}

int CashRegister::getCash()
{
	return cashInRegister;
}

/*******************************************
Class Dispensor function definations
********************************************/
Dispensor::Dispensor()
{
	cost = 100;
	numberOfItems = 50;
}

Dispensor::Dispensor(int price, int items)
{
	if (price > 0)
		cost = price;
	else
		cost = 100;

	if (items > 0)
		numberOfItems = items;
	else
		numberOfItems = 50;
}

int Dispensor::getCost()
{
	return cost;
}

int Dispensor::getNumberOfItems()
{
	return numberOfItems;
}

void Dispensor::makeSale(int quantity)
{
	numberOfItems -= quantity;
}

void menu()
{
	cout << "*************************" << endl;
	cout << "Welcome to Juice Shop" << endl;
	cout << "*************************" << endl;
	cout << "1. Apple Juice" << endl;
	cout << "2. Mango Juice" << endl;
	cout << "3. Orange Juice" << endl;
	cout << "4. Mix Fruit Juice" << endl;
	cout << "0. Exit" << endl;
	cout << "*************************" << endl;
}

void makeSale(Dispensor& type, CashRegister counter)
{
	int amount1;
	int amount2;
	int quantity;

	if (type.getNumberOfItems() > 0)
	{
		cout << "Enter quantity: ";
		cin >> quantity;

		while (quantity <= 0)
		{
			cout << "*************************" << endl;
			cout << "Quantity must be greater than 0" << endl;
			cout << "Enter quantity: ";
			cin >> quantity;
		}

		cout << "*************************" << endl;
		cout << "Deposit " << (type.getCost() * quantity) << " Rs: ";
		cin >> amount1;

		while (amount1 < (type.getCost() * quantity))
		{
			cout << "*************************" << endl;
			cout << "PLease deposit another " << (type.getCost() * quantity) - amount1 << " Rs: ";
			cin >> amount2;
			amount1 += amount2;
		}

		if (amount1 >= type.getCost())
		{
			counter.inputCash(amount1);
			type.makeSale(quantity);
			cout << "*************************" << endl;
			cout << "Enjoy your drink" << endl;
			cout << "Change: " << counter.withdrawCash(amount1-(type.getCost() * quantity)) << " Rs" << endl;
			cout << "*************************" << endl;
		}
	}
	else
	{
		cout << "*************************" << endl;
		cout << "Drink is out of stock" << endl;
		cout << "*************************" << endl;
	}
}
