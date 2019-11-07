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

//�Լ��� �ٸ����Ͽ� ����
//�����̸��� �ǹ̸� �˵��� ���� 
//card tray object
//��������� ��� �ø��� 
//card tray object
int CardTray[N_CARDSET*N_CARD]; //1���� �迭 
int cardIndex = 0;		//tray�� n��° ī��					


//player info
int dollar[N_MAX_USER]={50,50,50,50,50};						//�޷� ���� ��Ȳ 
int n_user;									//���� ��� 


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//���� ī�� ������Ȳ 2�����迭 
int cardSum[N_MAX_USER+1]={0,0,0,0,0,0};					//round�� cardsum. maxũ���� 1�����迭 
int bet[N_MAX_USER];						//round�� betting �� �ݾ� 
int gameEnd = 0; 							//game end flag

/////////////////////////main///////////////////////////



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	
	srand((unsigned)time(NULL));
	
	configUser();//�÷��̾� ��Ʈ 


	mixCardTray();//ī�� �ͽ� 



	//Game start --------
	do {//���� ���� 
		printf("Round %d\n",roundIndex+1);//�� ���帶��~ 
		
		roundIndex++;
		
		betDollar();//���� ���� �Է� 
		
		offerCards(); //ī�� �����ֱ� & ī�� ��Ȳ ��� (������ 2��° ī�常) &ī�� sum �� �� 
		
		printf("\n------------------ GAME start --------------------------\n");
		
		//player ���� turn ���� 
		
		int i;
		
		for (i=0;i<n_users;i++) //each player �÷��̾� ���� 
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
	} while (gameEnd == 0);//���ӳ����� �� �� 
	
	checkWinner();//������� 
	
	
	return 0;
}
