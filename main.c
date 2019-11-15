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

 
//card tray object

int CardTray[N_CARDSET*N_CARD]; 
int cardIndex = -1;					


//player info
int dollar[N_MAX_USER+1]={50,50,50,50,50};						
int n_user;									//scanf


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//
int cardSum[N_MAX_USER+1]={0,0,0,0,0,0};					//cardsum. for each round
int bet[N_MAX_USER];	//betting for each round 
int result[N_MAX_USER+1];	//0 win; 1 lose						 
int gameEnd = 0; 		
int cardcnt[N_MAX_USER+1];
//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)


int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}

///////////////function declaration//////////////
extern void configUser(void);
extern void mixCardTray();
extern void betDollar();
extern void offerCards();
extern void calculateCardSum();
extern void printUserCardStatus(int i,int cardcntt);
extern int pullCard();
extern void checkResult();
extern void checkWinner();
extern void printSum();

/////////////////////////main///////////////////////////



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	
	srand((unsigned)time(NULL));
	
	configUser();//player setting


	mixCardTray();//
	
	//Game start --------
	do {//for each round 
		printf("Round %d>>\n",roundIndex+1);//for each round 
		
		roundIndex++;
		
		betDollar();//betting scanf
		
		offerCards(); //offer card & printpresentcardinformaiton / card sum calculate 
		
		printf("\n------------------ GAME start --------------------------\n");
		
		//turn start for each player
		
		int i;
		
		for (i=0;i<(n_user+1);i++) //for each player 
		{
			if (i==0)
				printf("my turn\n");
			else if (i==n_user)
				printf("server turn\n");
			else
				printf("\nplayer %d turn\n",i);
				
			calculateCardSum();

			int action=1;
			
			
			switch (i) {
			
				case 0:{ //me
						do //do until the player dies or player says stop
						{ 	if (cardSum[0]<21){
						
								printUserCardStatus(i,cardcnt[i]);
								printSum(i);
								printf(" To go: press 0, To stay: press 1 --->");
								
								scanf("%d",&action);
	
								if (action==0){//to go	
									cardhold[i][cardcnt[i]]=pullCard();
									cardcnt[i]++;
									calculateCardSum();
								}
				
								else
									break;
							}
						
							else if (cardSum[0]==21){
								printUserCardStatus(i,cardcnt[i]);
								printSum(i);
								printf("blackjack\n");
								result[0]=0; //win
								break;
							}
						
							else if (cardSum[0]>21){
								printUserCardStatus(i,cardcnt[i]);
								printSum(i);
								printf("lose to overflow\n");
								result[0]=1; //lose
								break;
							}
						
						}
						while (action==0);
						
				}
					break;
					
					
				default: { //others
					while (cardSum[i]<17)//do until the player dies or player says stop
					{
						printUserCardStatus(i,cardcnt[i]);				
						printSum(i);
						cardhold[i][cardcnt[i]]=pullCard();
						cardcnt[i]++;
						calculateCardSum();
						printf("go\n");
						
					}
						
					
					if (cardSum[i]<21){ //to stop
						printUserCardStatus(i,cardcnt[i]);
						printSum(i);
						printf("stay\n\n");

					}
							
					if (cardSum[i]==21){
							printUserCardStatus(i,cardcnt[i]);
							printSum(i);
							printf("blackjack\n\n");
							result[i]=0; //win
					}
						
					if (cardSum[i]>21){
							printUserCardStatus(i,cardcnt[i]);
							printSum(i);
							printf("lose to overflow\n\n");
							result[i]=1;//lose
					}
					
				}
				break;
			}
			
		}
		
		//result
		checkResult();//round result
		for (i=0;i<n_user;i++){
			if (cardIndex>(N_CARDSET*N_CARD)||dollar[i]<=0)
			gameEnd=1;
		}
		
			
	} while (gameEnd == 0);// 
	
	checkWinner();//game result / print winner
	
	
	return 0;
}
