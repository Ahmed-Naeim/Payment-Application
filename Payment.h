#include<stdio.h>
#include<string.h>


typedef enum EN_transStat
{
	DECLINED,
	APPROVED
}EN_transStat;

//structs

typedef struct ST_cardData
{
	unsigned char cardHolderName[25];
	unsigned char primaryAccountNumber[19];
	unsigned char cardExpirationDate[6];
}ST_cardData;


typedef struct ST_terminalData
{
	float transAmount;
	float maxTransAmount;
	unsigned char transactionDate[11];
	}ST_terminalData;


typedef struct ST_serverData
{
	EN_transStat transactionStatus;
		unsigned int receiptReferenceNumber;
	}ST_serverData;


typedef struct ST_accountBalance
{
	unsigned char balance[8];
	unsigned char primaryAccountNumber[19];
}ST_accountBalance;


typedef struct ST_transaction
{
	ST_cardData cardHolderData;
	ST_terminalData transData;
	ST_serverData transResponse;
}ST_transaction;





/*
fuctions implementations
*/

void fillCardData(ST_transaction *transaction) //done
{
ST_cardData *ptr_user;
	
	printf("Please Enter Cardholder Name: ");
	
	gets(ptr_user->cardHolderName);
	
	printf("Please Enter the Primary Account Number: ");
	
	gets(ptr_user->primaryAccountNumber);
	
	printf("Please Enter the Card Expiry Date (month as 01,02,12): ");
	
	scanf("%c,%c",&ptr_user->cardExpirationDate[0],&ptr_user->cardExpirationDate[1]);
	//scanf("%c",&ptr_user->cardExpirationDate[1]);
	
	printf("Please Enter the Card Expiry Date (year): ");
	
	scanf("%c,%c,%c,%c",&ptr_user->cardExpirationDate[2],&ptr_user->cardExpirationDate[3],&ptr_user->cardExpirationDate[4],&ptr_user->cardExpirationDate[5]);
	//scanf("%c",&ptr_user->cardExpirationDate[3]);
	//scanf("%c",&ptr_user->cardExpirationDate[4]);
	//scanf("%c",&ptr_user->cardExpirationDate[5]);	
}
void fillTerminalData(ST_transaction *transaction) //done
{
    ST_terminalData *ptr_atm;
	printf("Please Enter the Terminal Data:\n");
	printf("Please Enter the Transaction Amount:");
	scanf("%f.2",&ptr_atm->transAmount);
	ptr_atm->maxTransAmount = 5000.00;
	//expiry date is already done int fillCardData
	printf("Please Enter the Transaction Date (year): ");
	scanf("%c,%c,%c,%c",&ptr_atm->transactionDate[2],&ptr_atm->transactionDate[3],&ptr_atm->transactionDate[4],&ptr_atm->transactionDate[5]);
	//scanf("%c",&ptr_atm->transactionDate[3]);
	//scanf("%c",&ptr_atm->transactionDate[4]);
	//scanf("%c",&ptr_atm->transactionDate[5]);	
	
}
void checkAmount(ST_transaction *transaction) //done
{
	int check1=1; //to check the transaction amount
	ST_terminalData *ptr_atm;
	printf("Please Enter the Terminal Data:\n");
	
	while(check1=1)
	{
		printf("Please Enter the Transaction Amount:");
		scanf("%f.2",&ptr_atm->transAmount);
		if(ptr_atm->transAmount>5000.00)
		{
			printf("The transaction is declined");
			EN_transStat transactionStatus= DECLINED;
			check1=1;
		}
		else{
			check1=0;
		}
	}
}
void checkExpiryDate(ST_transaction *transaction) //done
{
    ST_cardData *ptr_user;
	ST_terminalData *ptr_atm;

	int compare_index=2; 
	while(compare_index<6)
	{
		if(ptr_atm->transactionDate[compare_index] >= ptr_user->cardExpirationDate[compare_index])
		{
			compare_index++;
		}
		else{
			compare_index=10;
			
			printf("The transaction is declined");
			EN_transStat transactionStatus= DECLINED;
		}
	}
	if(compare_index!=10)
	{
		compare_index=0;
		while(compare_index<3)
	{
		if(ptr_atm->transactionDate[compare_index] >= ptr_user->cardExpirationDate[compare_index])
		{
			compare_index++;
		}
		else{
			compare_index=10;
			
			printf("The transaction is declined");
			EN_transStat transactionStatus= DECLINED;
		}
	}
	}
}

void saveTransactionIntoServer(ST_transaction *transaction) //done
{
	//expiry date is already checked in chekhExpiryDate function
	ST_accountBalance *ptr_balance;
	ST_terminalData *ptr_atm;
	int check2;
	while(check2=1)
	{
		printf("Please Enter the Transaction Amount:");
		scanf("%f.2",&ptr_atm->transAmount);
		if(ptr_atm->transAmount>ptr_balance->balance)
		{
			printf("The transaction is declined");
			EN_transStat transactionStatus= DECLINED;
			check2=1;
		}
		else{
			check2=0;
		printf("The transaction is Approved");
		EN_transStat transactionStatus= APPROVED;
		}
	}
}

void checkBalance(ST_transaction *transaction,ST_accountBalance *ptr_balance)
{
	ST_cardData *ptr_user;
	ST_accountBalance *ptr_balance;
	//ST_accountBalance accounts[10];
	//ptr_balance = &accounts;
	int counter=0,check3=0;
	while(counter>10)
	{
		if(ptr_user->primaryAccountNumber == accounts[counter].balance)
		{
			check3=1;
		}
		else{
			counter++;
		}
	}
	if(check3=0)
	{
		printf("The transaction is declined");
		EN_transStat transactionStatus= DECLINED;
		//done before :checks if the transaction amount > account balance

	}
	else{
		printf("The transaction is Approved");
		EN_transStat transactionStatus= APPROVED;
	}
}
