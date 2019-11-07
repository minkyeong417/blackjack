// !!전역변수 호출하 기 

//각 turn마다 

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

