
#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			4
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

extern int dollar[N_MAX_USER+1];
extern int bet[N_MAX_USER];
extern int n_user;	
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];
extern int cardSum[N_MAX_USER+1];
extern int cardIndex;
extern int pullCard(); 
extern int cardcnt[N_MAX_USER];

//before turn start

//betting
void betDollar(void) {
	
	printf("your betting (total:%d) :",dollar[0]);
	scanf("%d",&bet[0]);
	
	int i;
	
	for (i=1;i<n_user;i++){
	
		bet[i]=1+rand()%N_MAX_BET;
		printf("\nplayer%d bets $%d (out of %d)\n\n",i,bet[i],dollar[i]);
	}
	
	int j;
	
}

//offering initial 2 cards
void offerCards(void) {
	
	printf("card offering>>\n");
	
	//1. give two cards
	
	int i,j;

	for (i=0;i<n_user+1;i++){
		for (j=0;j<2;j++){
		cardhold[i][j] = pullCard();
		}
	}
	
	//2. print card state
	
	printf("server:X ");
	printCard(cardhold[n_user][1]);
	printf("\n");
		
		
	printf("you:");
	printCard(cardhold[0][0]);
	printf(" ");
	printCard(cardhold[0][1]);
	printf("\n");
	
	for (i=1;i<n_user;i++){
		printf("player %d:",i);
		printCard(cardhold[i][0]);
		printf(" ");
		printCard(cardhold[i][1]);
		printf("\n");
	}
	
	for (i=0;i<n_user+1;i++)
		cardcnt[i]+=2;
		
}


