#include<stdio.h>
int AND(int x,int y){

	//AND�Q�[�g
	int answer;


	switch(x){
	case 0:
		if(y==0){
			answer = 0;
		}else{
			answer = 0;
		}
		break;

	case 1:
		if(y==0){
			answer = 0;
		}else{
			answer = 1;
		}
		break;

	default:
		printf("Error!0��1�����\n");
		break;
	}

	return answer;
}

	
