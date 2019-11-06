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
	
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	if (cardnum>=1&&cardnum<=13)
		printf("DIA%d",cardnum);
	else if (cardnum>=14&&cardnum<=26)
		printf("HRT%d",cardnum-13);
	else if (cardnum>=27&&cardnum<=39)
		printf("SPD%d",cardnum-26);
	else if (cardnum>=40&&cardnum<=52)	
		printf("CLV%d",cardnum-39);
}


