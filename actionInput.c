// !!�������� ȣ���� �� 

#include <stdio.h>
#include <stdlib.h>

//�׼� ��ǲ 


int action;									//go==0 or stop==1

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

