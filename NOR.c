#include<stdio.h>
int NOR(int x,int y){

	//NOR�Q�[�g
	int answer;



	switch(x){
	case 0:
		if(y==0){
			answer = 1;
		}else{
			answer = 0;
		}
		break;

	case 1:
		if(y==0){
			answer = 0;
		}else{
			answer = 0;
		}
		break;

	default:
		printf("Error!0��1�����\n");
		break;
	}

	return answer;
}

	
