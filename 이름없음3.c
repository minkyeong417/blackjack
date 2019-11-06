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

//playing game functions -----------------------------

extern int n_user;	

//player settiing
int configUser(void) {
	
	printf("input player number<=5");
	scanf("%d",&n_user);
	
}


//betting
void betDollar(void) {
	int i=1;
	int j;
	
	printf("-------------ROUND %d (cardIndex:0)----------------\n",i);
	printf("your betting (total:$50) :");
	scanf("%d",&bet[0]);
	
	for (j=1;j<n_user;j++){
	
	bet[j]=1+rand()%5;
	printf("player%d bets $%d (out of $50)\n",j,bet[j]);
	
	}

	
}

void presentdollar(){
	int i;
	for (i=0;i<n_user,i++){
	
	dollar[i]-=bet[i];
	
	}
	
}

//offering initial 2 cards
void offerCards(void) {
	int i;
	printf("card offering:\n");
	//1. give two card for each players
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
		
		if (i==0) {
			printf("you:");
			printCard(cardhold[0][0]);
			printCard(cardhold[0][1]);
			printf("\n");
		}
		
		else {
			printf("player%d:",i);
			printCard(cardhold[i][0]);
			printCard(cardhold[i][1]);
			printf("\n");
		}	
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}



void doAction(void) { 
	if (action==0)//to go	
		cardhold[i][]=pullCard();
	
	
	
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {// 현재 player 카드의 합산 계산 및 승패여부 판단
	
}

int checkResult() {//turn 종료후 결과 출력 승패 원인 출력
	
}

int checkWinner() {
	
}

