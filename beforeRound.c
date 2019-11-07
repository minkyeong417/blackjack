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

extern int CardTray[N_CARDSET*N_CARD]; //1차원 배열 

//라운드 돌기 전 

extern int n_user;	

//player setting
int configUser(void) {
	
	printf("input player number(max:5):");
	scanf("%d",&n_user);
	
}

//mix the card sets and put in the array
int mixCardTray(void) {
	
	printf("--> card is mixed and put into the tray\n");
	
	int i,j;
	
	for(i=0;i<N_CARDSET*N_CARD;i++) { //각 배열요소에 대해서 

		do {
	
			CardTray[i]=rand()%(N_CARDSET*N_CARD);
	
			int multiply=1;
		
			for(j=0;j<i;j++)
				multiply*=(CardTray[i]-CardTray[j]);

		}
		while (multiply==0);
	}
}

