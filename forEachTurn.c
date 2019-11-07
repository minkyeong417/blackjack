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

//각 turn마다 

void doAction(void) { 

	int action;
	
	printf(" To go: press 0, To stay: press 1 --->");
	
	scanf("%d",action);
	
	if (action==0)//to go	
		cardhold[i][]=pullCard();
	
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf(" ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {// 현재 player 카드의 합산 계산 및 승패여부 판단
	
}

int checkResult() {//turn 종료후 결과 출력 승패 원인 출력
	
}

int checkWinner() {
	
}

