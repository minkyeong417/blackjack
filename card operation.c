// !!전역변수 호출하 기 

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

extern int CardTray[N_CARDSET*N_CARD]; //1차원 배열 
extern int cardIndex;		//tray속 n번째 카드	
extern int n_user;
extern int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];
extern int cardSum[N_MAX_USER+1];

//get one card from the tray(0~51)
int pullCard(void) {
	return CardTray[cardIndex]%52;
	cardIndex++;
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	int num;
	num=cardnum%52;
	
	if (num>=0&&num<=12) {
		
		if (num%13<10)
		printf("DIA%d",num%13+1);
		
		else if (num%13==10)
		printf("DIAJack");
		
		else if (num%13==11)
		printf("DIAQueen");
		
		else if (num%13==12)
		printf("DIAKing");
	}
	
	else if (num>=13&&num<=25) {
		
		if (num%13<10)
		printf("HRT%d",num%13+1);
		
		else if(num%13==10)
		printf("HRTJack");
		
		else if (num%13==11)
		printf("HRTQueen");
		
		else if (num%13==12)
		printf("HRTKing");
	}
	
	else if (num>=26&&num<=38) {
		
		if (num%13<10)
		printf("SPD%d",num%13+1);
		
		else if(num%13==10)
		printf("SPDJack");
		
		else if (num%13==11)
		printf("SPDQueen");
		
		else if (num%13==12)
		printf("SPDKing");
	}
	
	else if (num>=39&&num<=51)	{
		
		if (num%13<10)
		printf("CLV%d",num%13+1);
		
		else if(num%13==10)
		printf("CLVJack");
		
		else if (num%13==11)
		printf("CLVQueen");
		
		else if (num%13==12)
		printf("CLVKing");
	}
}

//calculate the actual card number in the blackjack game
void calculateCardSum(){
	int i,j;
	
	for (i=0;i<n_user+1;i++){
		for (j=0;j<=N_MAX_CARDHOLD;j++){
			switch (cardhold[i][j]%13){
			
			case 0:
				{
				if ((cardSum[i]+=11)>21)
					cardSum[i]+=1;
				else
					cardSum[i]+=11;
				break;
				}
				
			case 10:
				cardSum[i]+=10;
				break;
			
			case 11:
				cardSum[i]+=10;
				break;
				
			case 12:
				cardSum[i]+=10;
				break;
					
			default:
				cardSum[i]+=cardhold[i][j]%13;
				break;
			}
		}
	}
}

int getCardNum(int cardnum) {
	
	int num;
	
	num=cardnum%13;
	
	if (num<10)
		return num;
	else
		return 10;
	}

