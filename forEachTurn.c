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

extern int roundIndex;
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];

//for each turn


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	
	for (i=0;i<cardcnt+1;i++)
		printCard(cardhold[user][i]);
	printf(" ::: ");
}


