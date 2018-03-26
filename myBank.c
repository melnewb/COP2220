//Melissa Newball
//March 24, 2018
//My Bank program - user defined functions using both pass by reference and pass by copy parameters, simple loops and conditions

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXCREDIT -4500

//FUNCTION PROTOTYPES

//greets the user
void Greeting();

//displays the list of options available
//prompts for the user's selection and sets the value of the selection
void RunBankChoices(int *choice);

//takes one double argument and one character argument
//displays the current balance of the account ('C' checking, 'S' savings, 'R' credit)
void AccountBalance(double account, char letter);

//takes reference to all the bank account money values and the menu selection
//makes the decision of which transaction should be done
void TransactionDecision(int num, double *cPtr, double *sPtr, double *rPtr);

//takes a reference to the selected account balance
//gets the added amount from the user and adds it to the account
void DepositMoney(double *accountPtr);

//takes a reference to the selected account balance
//gets the withdrawal amount from the user
//checks to see if there is enough money available OR enough credit available
//subtracts the money from the account if available
void WithdrawMoney(double *accountPtr, char letter);

int main()
{
	int choice;
	double checking = 480.45;
	double savings = 124.62;
	double credit = -2134.78;
	
	Greeting();

	//RunBankChoices(&choice); //STEP 6. Works.
	//printf("You have chosen %d", choice); test to see if value is available in main. works.

	//Step 12. 3 function calls to account balance.
	AccountBalance(checking, 'C');
	AccountBalance(savings, 'S');
	AccountBalance(credit, 'R');

	//STEP 8. A loop that allows the user to continue to make transactions.
	//A choice of -1 will stop the loop. Remember to initialize choice. p273
	do {
		RunBankChoices(&choice);
		TransactionDecision(choice, &checking, &savings, &credit); //step 14.
	} while (choice != -1);

	return 0;
}

//FUNCTION DEFINITIONS

//greets the user
void Greeting()
{
	printf("******************************\n");
	printf("\nWelcome to the Bank of COP 2220\n\nIt is a pleasure to manage your checking, savings, and credit accounts.\n");
}

//displays the list of options available
//prompts for the user's selection and sets the value of the selection
void RunBankChoices(int *choice)
{
	int pick;

	printf("\n------------------------\n");
	printf("(1) to DEPOSIT to CHECKING\n");
	printf("(2) to WITHDRAW from CHECKING\n");
	printf("(3) to DEPOSIT to SAVINGS\n");
	printf("(4) to WITHDRAW from SAVINGS\n");
	printf("(5) to DEPOSIT to CREDIT\n");
	printf("(6) to TAKE an ADVANCE from CREDIT\n");
	printf("(7) for all ACCOUNT BALANCES\n");
	printf("\n(-1) to QUIT\n");
	printf("\nSelect an option: ");
	scanf("%d", &pick);

	//printf("You have chosen %d", pick); test. works.

	*choice = pick;
}

//takes one double argument and one character argument
//displays the current balance of the account ('C' checking, 'S' savings, 'R' credit)
void AccountBalance(double account, char letter)
{
	//multiple-alternative nested if p209
	
	//checking account
	if (letter == 'C')
		printf("\n-- You currently have $%.2f in your checking account.\n", account);
	
	//savings account
	else if (letter == 'S')
		printf("\n-- You currently have $%.2f in your savings account.\n", account);
	
	//credit balance
	else if (letter == 'R')
		printf("\n-- You currently have $%.2f credit balance.\n", account);
}

//takes reference to all the bank account money values and the menu selection
//makes the decision of which transaction should be done
void TransactionDecision(int num, double *cPtr, double *sPtr, double *rPtr)
{
	//there will be nested conditions inside this.

	//user deposits to checking
	if (num == 1)
	{
		printf("\nThe transaction you chose was: 1\nDEPOSIT to CHECKING\n");
		AccountBalance(*cPtr, 'C');
		DepositMoney(cPtr);
		AccountBalance(*cPtr, 'C');
	}
	else if (num == 2)
	{
		printf("\nThe transaction you chose was: 2\nWITHDRAW from CHECKING\n");
		AccountBalance(*cPtr, 'C');
		WithdrawMoney(cPtr, 'C');
		AccountBalance(*cPtr, 'C');
	}
	else if (num == 3)
	{
		printf("\nThe transaction you chose was: 3\nDEPOSIT to SAVINGS\n");
		AccountBalance(*sPtr, 'S');
		DepositMoney(sPtr);
		AccountBalance(*sPtr, 'S');
	}
	else if (num == 4)
	{
		printf("\nThe transaction you chose was: 4\nWITHDRAW from SAVINGS\n");
		AccountBalance(*sPtr, 'S');
		WithdrawMoney(sPtr, 'S');
		AccountBalance(*sPtr, 'S');
	}
	else if (num == 5)
	{
		printf("\nThe transaction you chose was: 5\nDEPOSIT to CREDIT\n");
		AccountBalance(*rPtr, 'R');
		DepositMoney(rPtr);
		AccountBalance(*rPtr, 'R');
	}
	else if (num == 6)
	{
		printf("\nThe transaction you chose was: 6\nTAKE an ADVANCE from CREDIT\n");
		AccountBalance(*rPtr, 'R');
		WithdrawMoney(rPtr, 'R');
		AccountBalance(*rPtr, 'R');
	}
	else if (num == 7)
	{
		printf("\nThe transaction you chose was: 7\nVIEW ALL BALANCES\n");
		AccountBalance(*cPtr, 'C');
		AccountBalance(*sPtr, 'S');
		AccountBalance(*rPtr, 'R');
	}
	else if (num == -1)
	{
		printf("\nThe action you chose was: -1\nCLOSE PROGRAM\n");
		printf("\nGoodbye.\n");
	}
	else
	{
		printf("\nInvalid entry. Please try again.\n");
	}
}

//takes a reference to the selected account balance
//gets the added amount from the user and adds it to the account
void DepositMoney(double *accountPtr)
{
	double deposit;
	printf("\nHow much would you like to deposit? ");
	scanf("%lf", &deposit);
	*accountPtr = *accountPtr + deposit;
}

//takes a reference to the selected account balance
//gets the withdrawal amount from the user
//checks to see if there is enough money available OR enough credit available
//subtracts the money from the account if available
void WithdrawMoney(double *accountPtr, char letter)
{
	double withdrawal;

	//if withdrawing from checking or savings
	if (letter == 'C' || letter == 'S')
	{
		printf("\nEnter the amount to be Withdrawn: ");
		scanf("%lf", &withdrawal);

		if (withdrawal <= *accountPtr)
		{
			*accountPtr = *accountPtr - withdrawal;
		}
		else
		{
			printf("Insufficient funds.");
		}
	}

	//withdrawing from credit
	else if (letter == 'R')
	{
		printf("\nEnter the amount to be Withdrawn: ");
		scanf("%lf", &withdrawal);
		
		if ((*accountPtr - withdrawal) < MAXCREDIT)
		{
			printf("\n*** There is not enough credit available for this transaction.\n");
			printf("\n*** The maximum credit allowed is $-4500.00\n");
			printf("\n*** Contact customer service about raising your credit line.\n\n");
		}
		else
		{
			*accountPtr = *accountPtr - withdrawal;
		}
	}
}