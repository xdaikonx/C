#include<stdio.h>
int OR(int x,int y){

	//ORゲート
	int answer;


	switch(x){
	case 0:
		if(y==0){
			answer = 0;
		}else{
			answer = 1;
		}
		break;

	case 1:
		if(y==0){
			answer = 1;
		}else{
			answer = 1;
		}
		break;

	default:
		printf("Error!0か1を入力\n");
		break;
	}

	return answer;
}

	
