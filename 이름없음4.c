// !!전역변수 호출하 기 

#include <stdio.h>
#include <stdlib.h>

///y와 x의 배열요소가 모두 다르면 plex==0 



int x[10];
	int i;
	for (i=0;i<10;i++)
		x[i]=rand()%10;
	int y=5;
	int plex=1;
	for(i=0;i<10;i++)
	plex*=(y-x[i]);

	if (plex==0) //y와 x[i]는 동일하다.  
	return 0;

