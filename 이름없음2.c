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

//card array controllers -----------------------------


//mix the card sets and put in the array
int mixCardTray(void) {
	
	printf("--> card is mixed and put into the tray");
	
	int x[52];
	int i,j;
	for(i=0;i<52;i++) {

	do{
	
	x[i]=rand()%52;

	}
	while ();
	}
}


}

//get one card from the tray
int pullCard(void) {
	int i;
	i=1+rand()%52;
	return i;
}

