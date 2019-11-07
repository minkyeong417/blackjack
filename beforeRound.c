// !!전역변수 호출하 기 

//라운드 돌기 전 

extern int n_user;	

//player settiing
int configUser(void) {
	
	printf("input player number<=5");
	scanf("%d",&n_user);
	
}

//mix the card sets and put in the array
int mixCardTray(void) {
	
	printf("--> card is mixed and put into the tray");
	
	int i,j;
	for(i=0;i<N_CARDSET*N_CARD;i++) { //각 배열요소에 대해서 

		do {
	
		CardTray[i]=rand()%(N_CARDSET*N_CARD);
	
		int plex=1;
		for(j=0;j<i;j++)
		plex*=(CardTray[i]-CardTray[j]);

		}
		while (plex==0);
	}
}

