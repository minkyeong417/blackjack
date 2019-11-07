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

//함수는 다른파일에 저장
//변수이름은 의미를 알도록 정의 
//card tray object
//형상관리에 몇번 올리기 
//card tray object
int CardTray[N_CARDSET*N_CARD]; //1차원 배열 
int cardIndex = 0;		//tray속 n번째 카드					


//player info
int dollar[N_MAX_USER]={50,50,50,50,50};						//달러 보유 현황 
int n_user;									//유저 명수 


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//현재 카드 보유현황 2차원배열 
int cardSum[N_MAX_USER+1]={0,0,0,0,0,0};					//round별 cardsum. max크기의 1차원배열 
int bet[N_MAX_USER];						//round별 betting 한 금액 
int gameEnd = 0; 							//game end flag

/////////////////////////main///////////////////////////



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	
	srand((unsigned)time(NULL));
	
	configUser();//플레이어 세트 


	mixCardTray();//카드 믹스 



	//Game start --------
	do {//라운드 진행 
		printf("Round %d\n",roundIndex+1);//각 라운드마다~ 
		
		roundIndex++;
		
		betDollar();//나의 베팅 입력 
		
		offerCards(); //카드 나눠주기 & 카드 현황 출력 (딜러는 2번째 카드만) &카드 sum 계 산 
		
		printf("\n------------------ GAME start --------------------------\n");
		
		//player 마다 turn 시작 
		
		int i;
		
		for (i=0;i<n_users;i++) //each player 플레이어 마다 
		{
			if (i==0)
				printf("my turn\n");
			else if (i==n_user)
				printf("server turn\n");
			else
				printf("player %d turn\n",i);
				
			calculateCardSum();
			
			int cardcnt=1;
			
			switch (i)
			
			case 0:{
				
				if (cardSum>21)
				
				
				while (cardSum[i]<21){ //do until the player dies or player says stop
					int action;
				
					printUserCardStatus(i,cardcnt);
				
					printf(" To go: press 0, To stay: press 1 --->");
	
					scanf("%d",&action);
	
					if (action==0){//to go	
						cardcnt++;
						cardhold[i][cardcnt]=pullCard();
					}
				
					else 
						break;
				}
				break;
			}
			
			default {
				while (cardSum[i]<21){ //do until the player dies or player says stop
					printUserCardStatus(i,cardcnt);
					
					if (cardSum[i]>=17)//to stop
						printf("stay\n");
						break;
					else
						cardcnt++;
						printf("go\n");
				}
				
				break;
			}
		}
		
		//result
		checkResult();
	} while (gameEnd == 0);//게임끝날때 까 지 
	
	checkWinner();//승자출력 
	
	
	return 0;
}
