// !!�������� ȣ���� �� 

//���� ���� �� 

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
	for(i=0;i<N_CARDSET*N_CARD;i++) { //�� �迭��ҿ� ���ؼ� 

		do {
	
		CardTray[i]=rand()%(N_CARDSET*N_CARD);
	
		int plex=1;
		for(j=0;j<i;j++)
		plex*=(CardTray[i]-CardTray[j]);

		}
		while (plex==0);
	}
}

