#include<stdio.h>
int NOT(int x){


	int answer=0;
	//NOT�Q�[�g

	switch(x){
	case 0:
		answer = 1;
		break;

	case 1:
		answer = 0;
		break;

	default:
		printf("Error!0��1�����\n");
		break;
	}

	return answer;
}

	
