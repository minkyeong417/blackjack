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
void configUser(void) {
	
	printf("input player number(max:5):");
	scanf("%d",&n_user);
	
}

//mix the card sets and put in the array
void mixCardTray(void) {
	
	printf("--> card is mixed and put into the tray\n\n");
	
	int i,j;
	
	int multiply;
	for (i=0;i<(N_CARDSET*N_CARD);i++)
	{
		do{
			multiply=1;
			CardTray[i]=rand()%(N_CARDSET*N_CARD);
			for(j=0;j<i;j++){
				multiply*=(CardTray[i]-CardTray[j]);
			}
		
		} while(multiply==0);
		
		printf("%d %d\n",i,CardTray[i]);
	}
	
}
	
	


