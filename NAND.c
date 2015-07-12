#include<stdio.h>
int NAND(int x,int y){

	//NANDƒQ[ƒg
	int answer;


	switch(x){
	case 0:
		if(y==0){
			answer = 1;
		}else{
			answer = 1;
		}
		break;

	case 1:
		if(y==0){
			answer = 1;
		}else{
			answer = 0;
		}
		break;

	default:
		printf("Error!0‚©1‚ğ“ü—Í\n");
		break;
	}

	return answer;
}

	
