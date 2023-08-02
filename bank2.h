#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <random>

using namespace std;

void Coords(int x, int y);

class Time
{
private:
	int dates;
public:
	int getDates();
	void setDates(int day, int month, int year);
	void datesInput();
};

class Registration
{
private:
	string firstName;
	string lastName;
	int age;
	int contactNumber;
public:
	Registration(
		string firstName,
		string lastName,
		int age,
		int contactNumber) :
		firstName(firstName),
		lastName(lastName),
		age{ age },
		contactNumber{ contactNumber } {}
	Registration(
		string firstName,
		string lastName) : Registration(firstName, lastName, age = 0, contactNumber = 0)
	{}
	Registration() {}
	friend ostream& operator<<(ostream& output, const Registration& reg)
	{
		output << "( " << reg.firstName << ", " << reg.lastName << " )";
		return output;
	}
	int getAge();
	int getContacteNumber();
	void setAge(int value);
	void setContactNumber(int value);
	void personInput();
	void example();
};

class DebitOrders
{
private:
	Time time;
	Registration person;
	int firsDigitsOfTheCard;
	int secondDigitsOfTheCard;
	double balance;
	double balance1 = 0;
	double balance2 = 0;
	double balance3 = 0;
	ofstream fbalance, ftops;
	double balance_;
	double choice3;
public:
	virtual void topUpBalance();
	void viewBalance();
	void withdrawBalance();
	void spendMoney();
	virtual void viewReport();
	virtual void topCategories();
	friend class UDebCard;
};

class CreditOrders
{
private:
	Time time;
	Registration person;
	int firsDigitsOfTheCard;
	int secondDigitsOfTheCard;
	double balance;
	double balance1 = 0;
	double balance2 = 0;
	double balance3 = 0;
	ofstream fbalance, ftops;
	double balance_;
	double choice3;
public:
	virtual void topUpBalance();
	void viewBalance();
	void withdrawBalance();
	void spendMoney();
	virtual void viewReport();
	virtual void topCategories();
	friend class LeoCredCard;
};

class LeoCredCard : public CreditOrders
{
public:
	void topUpBalance() override;
	void viewReport() override;
	void topCategories() override;
};

class UDebCard : public DebitOrders
{
public:
	void topUpBalance() override;
	void viewReport() override;
	void topCategories() override;
};

class MyCard
{
private:
	Time time;
	Registration person;
	int firsDigitsOfTheCard;
	int secondDigitsOfTheCard;
	double balance;
	double balance1 = 0;
	double balance2 = 0;
	double balance3 = 0;
	ofstream fbalance, ftops;
	double balance_;
	short choice;
	short choice2;
	double choice3;
public:
	void begin();
	virtual void createCard();
	virtual void menu();
	friend class LeoBank;
	friend class Ubank;
};

class LeoBank : public MyCard
{
public:
	void createCard() override;
	void menu() override;
};

class Ubank : public MyCard
{
public:
	void createCard() override;
	void menu() override;
};

class Bank
{
public:
	void createCard(MyCard* card);
	void menu(MyCard* card);
};

void run();