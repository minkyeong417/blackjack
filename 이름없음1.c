#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30
//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	int num;
	num=cardnum%13;
	
	if (num<10)
		return num;
	else
		return 10;
	
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	int num;
	num=cardnum%52;
	
	if (num>=0&&num<=12)
		printf("DIA%d",num+1);
	
	else if (num>=13&&num<=25)
		printf("HRT%d",num-12);
	
	else if (num>=26&&num<=38)
		printf("SPD%d",num-25);
	
	else if (num>=39&&num<=51)	
		printf("CLV%d",num-38);
}


