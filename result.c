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

extern int cardSum[N_MAX_USER+1];	
extern int result[N_MAX_USER+1];//1 lose to overflow; 2 blackjack;
extern int dollar[N_MAX_USER+1];
extern int CardTray[N_CARDSET*N_CARD];
extern int n_user;
extern int bet[];

void checkResult(){
	int i;
	
	for(i=0;i<n_user;i++){
		if (i!=0)
		printf("player %d result: ",i);
		else
		printf("your result: ");
		
		if (result[i]==2)
		
			printf("blackjack\n");
		
		else if (result[i]==1)
		
			printf("lose due to overflow\n");
		
		else {
			
			if (result[n_user]==2) {
				dollar[i]-=bet[i];
				printf("lose\n");
				
			}
			
			else if (result[n_user]==1){
				printf("win\n");
				dollar[i]+=bet[i];
				
			}
			else {
				if (cardSum[i]<cardSum[n_user]){
					dollar[i]-=bet[i];
					printf("lose\n");
				}
			
				else if (cardSum[i]>=cardSum[n_user]){
					dollar[i]+=bet[i];
					printf("win\n");
				}	
			}
			
		
		}
		
		printf("[Sum:%d]",cardSum[i]);
		printf(" current dollar state:$%d\n\n",dollar[i]);	
	}
	
}

void checkWinner(){
	int i,j;
	
	for (i=0;i<n_user;i++){
		int k=1;	
		
		for (j=0;j<n_user;j++){
			if (dollar[i]<dollar[j])
				k*=0;
		}
		
		if (k==1){
			if(i==0)
			printf("winner: you");
			
			else
			printf("winner: player %d",i);
		}
	}
		
}
		

