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
	
	int i,j;
	for(i=0;i<N_CARDSET*N_CARD;i++) { //각 배열요소에 대해서 

		do {
	
		CardTray[i]=rand()%(N_CARDSET*N_CARD);
	
		int plex=1;
		for(j=0;j<i;j++)
		plex*=(CardTray[i]-CardTray[j]);

		}
		while (plex==0);
	}
}


}

//get one card from the tray
int pullCard(void) {
	return CardTray[cardIndex];
	cardIndex++;
}

