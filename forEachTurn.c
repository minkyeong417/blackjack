// !!�������� ȣ���� �� 

//�� turn���� 

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
int calcStepResult() {// ���� player ī���� �ջ� ��� �� ���п��� �Ǵ�
	
}

int checkResult() {//turn ������ ��� ��� ���� ���� ���
	
}

int checkWinner() {
	
}

