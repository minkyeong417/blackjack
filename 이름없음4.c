// !!�������� ȣ���� �� 

#include <stdio.h>
#include <stdlib.h>

///y�� x�� �迭��Ұ� ��� �ٸ��� plex==0 



int x[10];
	int i;
	for (i=0;i<10;i++)
		x[i]=rand()%10;
	int y=5;
	int plex=1;
	for(i=0;i<10;i++)
	plex*=(y-x[i]);

	if (plex==0) //y�� x[i]�� �����ϴ�.  
	return 0;

