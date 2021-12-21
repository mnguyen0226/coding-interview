
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
#define MIN_BALANCE 500
class InsufficientFunds {};

///////////////////////////////////////////////////////////////////////////////////////////////////
class Account
{
private:
	long accountNumber;
	string firstName;
	string lastName;
	float balance;
	static long NextAccountNumber;
public:
	Account() {} // default constructor
	Account(string fname, string lname, float balance); // pameterized constructor
	long getAccNo() { return accountNumber; }
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	float getBalance() { return balance; }

	void Deposit(float amount);
	void Withdraw(float amount);
	static void setLastAccountNumber(long accountNumber);
	static long getLastAccountNumber();

	// Make these override as friend to get access to all private and protected of Account
	friend ofstream& operator<<(ofstream& ofs, Account& acc);
	friend ifstream& operator>>(ifstream& ifs, Account& acc);
	friend ostream& operator<<(ostream& os, Account& acc);
};
long Account::NextAccountNumber = 0; // Start to keep track of the next numberr

///////////////////////////////////////////////////////////////////////////////////////////////////
class Bank
{
private:
	map<long, Account> accounts; // Create a map of account number and the Account object
public:
	Bank();
	Account OpenAccount(string fname, string lname, float balance);
	Account BalanceEnquiry(long accountNumber);
	Account Deposit(long accountNumber, float amount);
	Account Withdraw(long accountNumber, float amount);
	void CloseAccount(long accountNumber);
	void ShowAllAccounts();
	~Bank();
};

///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	Bank b;
	Account acc;

	int choice;
	string fname, lname;
	long accountNumber;
	float balance;
	float amount;
	cout << "***Banking System***" << endl;
	do
	{
		cout << "\n\tSelect one option below ";
		cout << "\n\t1 Open an Account";
		cout << "\n\t2 Balance Enquiry";
		cout << "\n\t3 Deposit";
		cout << "\n\t4 Withdrawal";
		cout << "\n\t5 Close an Account";
		cout << "\n\t6 Show All Accounts";
		cout << "\n\t7 Quit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter First Name: ";
			cin >> fname;
			cout << "Enter Last Name: ";
			cin >> lname;
			cout << "Enter initil Balance: ";
			cin >> balance;
			acc = b.OpenAccount(fname, lname, balance);
			cout << endl << "Congradulation Account is Created" << endl;
			cout << acc;
			break;
		case 2:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			acc = b.BalanceEnquiry(accountNumber);
			cout << endl << "Your Account Details" << endl;
			cout << acc;
			break;
		case 3:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			cout << "Enter Balance:";
			cin >> amount;
			acc = b.Deposit(accountNumber, amount);
			cout << endl << "Amount is Deposited" << endl;
			cout << acc;
			break;
		case 4:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			cout << "Enter Balance:";
			cin >> amount;
			acc = b.Withdraw(accountNumber, amount);
			cout << endl << "Amount Withdrawn" << endl;
			cout << acc;
			break;
		case 5:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			b.CloseAccount(accountNumber);
			cout << endl << "Account is Closed" << endl;
			cout << acc;
		case 6:
			b.ShowAllAccounts();
			break;
		case 7: break;
		default:
			cout << "\nEnter corret choice";
			exit(0);
		}
	} while (choice != 7);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Pameterized Constructor
Account::Account(string fname, string lname, float balance)
{
	NextAccountNumber++;
	accountNumber = NextAccountNumber;
	firstName = fname;
	lastName = lname;
	this->balance = balance;
}

// Account Deposit
void Account::Deposit(float amount)
{
	balance += amount;
}

// Account Withdraw
void Account::Withdraw(float amount)
{
	if (balance - amount < MIN_BALANCE)
		throw InsufficientFunds();
	balance -= amount;
}

// Account set the create account object with account number
void Account::setLastAccountNumber(long accountNumber)
{
	NextAccountNumber = accountNumber;
}

// Account get the next account numer
long Account::getLastAccountNumber()
{
	return NextAccountNumber;
}

// Override the << operator to show the current account object information and output that to terminal
ofstream& operator<<(ofstream& ofs, Account& acc)
{
	ofs << acc.accountNumber << endl;
	ofs << acc.firstName << endl;
	ofs << acc.lastName << endl;
	ofs << acc.balance << endl;
	return ofs;
}

// Override the >> operator to show the current account object information and input that to file
ifstream& operator>>(ifstream& ifs, Account& acc)
{
	ifs >> acc.accountNumber;
	ifs >> acc.firstName;
	ifs >> acc.lastName;
	ifs >> acc.balance;
	return ifs;

}

// Override the << for cout << printing
ostream& operator<<(ostream& os, Account& acc)
{
	os << "First Name:" << acc.getFirstName() << endl;
	os << "Last Name:" << acc.getLastName() << endl;
	os << "Account Number:" << acc.getAccNo() << endl;
	os << "Balance:" << acc.getBalance() << endl;
	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Bank Default Constructor
Bank::Bank()
{
	Account account;
	ifstream infile;
	infile.open("Bank.data");
	
	// Open file
	if (!infile)
	{
		cout<<"Error in Opening! File Not Found!!"<<endl;
		return;
	}
	while (!infile.eof()) // While there are still some info in the file then
	{
		infile >> account; // Insert line by line into account
		accounts.insert(pair<long, Account>(account.getAccNo(), account)); // apppend to map
	}

	Account::setLastAccountNumber(account.getAccNo()); 

	infile.close();

}

// Bank Open Account
Account Bank::OpenAccount(string fname, string lname, float balance)
{
	ofstream outfile;
	Account account(fname, lname, balance);
	accounts.insert(pair<long, Account>(account.getAccNo(), account));

	outfile.open("Bank.data", ios::trunc);

	// Append to map
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();
	return account;
}

// Bank Check Balance, return an Account
Account Bank::BalanceEnquiry(long accountNumber)
{
	map<long, Account>::iterator itr = accounts.find(accountNumber);
	return itr->second;
}

// Bank Deposit $ into Account, return an Account
Account Bank::Deposit(long accountNumber, float amount)
{
	map<long, Account>::iterator itr = accounts.find(accountNumber);
	itr->second.Deposit(amount);
	return itr->second;
}

// Bank Withdraw $ from Account , return an Account
Account Bank::Withdraw(long accountNumber, float amount)
{
	map<long, Account>::iterator itr = accounts.find(accountNumber);
	itr->second.Withdraw(amount);
	return itr->second;
}

// Bank Close Account
void Bank::CloseAccount(long accountNumber)
{
	map<long, Account>::iterator itr = accounts.find(accountNumber);
	cout << "Account Deleted" << itr->second;
	accounts.erase(accountNumber);
}

// Bank show all account
void Bank::ShowAllAccounts()
{
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		cout << "Account " << itr->first << endl << itr->second << endl;
	}
}

// Bank Destructor
Bank::~Bank()
{
	ofstream outfile;
	outfile.open("Bank.data", ios::trunc);

	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();
}