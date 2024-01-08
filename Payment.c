#include "Payment.h"

int main()
{
	ST_transaction *transaction;
	ST_transaction transact;
	transaction = &transact;
	
	//intialaization of the balance&number array 
	
	ST_accountBalance *ptr_balance;
	ST_accountBalance accounts[10];
	/*
	accounts[0]={0100.00,123456789};
	accounts[1]={6000.00,234567891};
	accounts[2]={3250.25,567891234};
	accounts[3]={1500.12,456789123};
	accounts[4]={0500.00,258649173};
	accounts[5]={2100.00,654923719};
	accounts[6]={0000.00,971362485};
	accounts[7]={0001.00,793148625};
	accounts[8]={0010.12,123123456};
	accounts[9]={0000.55,456789321};
	*/
	
	//fuctions calling
	fillCardData(transaction);
	fillTerminalData(transaction);
	checkAmount(transaction);
	checkExpiryDate(transaction);
	saveTransactionIntoServer(transaction);
	checkBalance(transaction,ptr_balance);
	
	printf("Do you want to continue?\n");
	printf("if yes press 1\n");
	int repeat;
	scanf("%i",&repeat);
	if(repeat=1)
	{
		fillCardData(transaction);
		fillTerminalData(transaction);
		checkAmount(transaction);
		checkExpiryDate(transaction);
		saveTransactionIntoServer(transaction);
		checkBalance(transaction,ptr_balance);
	}
	else{
		return 0;
	}
	

}