#include<stdio.h>
#include<string.h>

int NOT(int x);
int AND(int x,int y);
int OR(int x,int y);
int NAND(int x,int y);
int NOR(int x,int y);

struct NODE1{
	char nodename[10];
	int num;
};

int main(void){

	FILE *fp;
	struct NODE1 NODE[30];
	char read[100]={'\0'},readcopy1[100]={'\0'},Ronrisiki1[100]={'\0'};
	char sq1[100]={'\0'};
	char *sp,*sq,*ret,*readcopy,*Ronrisiki;
	int i=0,j=0,Igyousuu,Ngyousuu,Ogyousuu;
	int a=0,b=0,c=0,d=0,last=0,NG=0;

	fp = fopen("s27_gate_noscan.txt","r");

	if(fp == NULL){
		printf("ファイルをオープンできませんでした。\n");
		return 1;
	}else{
		printf("ファイルをオープンしました。\n");
	}

	//構造体の中身を初期化
	for(i=0;i<30;i++){
		for(j=0;j<10;j++){
		NODE[i].nodename[j] = '\0';
		NODE[i].num = 0;
		}
	}

	i=0;
    
	while(fgets(read,100,fp) != NULL){

		//INPUT:,NODE:,OUTPUT:が何行目にあるかの確認
		if(!strcmp(read, "INPUT:\n")){
			Igyousuu = i+1;
		}
			if(!strcmp(read, "NODE:\n")){
			Ngyousuu = i+1;
		}
			if(!strcmp(read, "OUTPUT:\n")){
			Ogyousuu = i+1;
		}
		i++;
	}

	//INPUTのノード名と論理値を構造体NODEに格納
	i=0;
	fseek( fp, 8, SEEK_SET );
	while(fgets(read,100,fp) != NULL){
		if(!strcmp(read,"\n")){
			break;
		}
		for(j=0;read[j]!='\n';j++){
			NODE[i].nodename[j] = read[j];
		}
		printf("%sの論理値は:",&NODE[i].nodename);
		scanf("%d",&NODE[i].num);

		if(NODE[i].num!=0 && NODE[i].num!=1){
		printf("Error,0か1を入力\n");
		return(-1);
		}

		printf("\n");

		i++;
	}


	//INPUTのノード名と論理演算子の右側のノード名を比較して一致したら論理演算
	fseek( fp, 8, SEEK_SET );
	while(NODE[Ogyousuu-6].nodename[0]=='\0'){
		fseek( fp, 8, SEEK_SET );

	while(fgets(read,100,fp) != NULL){

		readcopy = readcopy1;
		readcopy = strcpy(readcopy,read);
		//NODE配列の要素数をカウント
		last=0;
		for(j=0;NODE[j].nodename[0]!='\0';j++){
			last++;
		}

	//ファイルから読み込んだ文字列に空白がある場合の処理
		if(strstr(read," ")!=NULL){
			sp = strstr(read," ");

	//配列の中身を一つずつずらす
			for(j=0;sp[j]!='\0';j++){
				sp[j] = sp[j+1];
			}
			Ronrisiki = Ronrisiki1;
			Ronrisiki = strcpy(Ronrisiki,sp);
			sp = strstr(sp," ");
			for(j=0;sp[j]!='\0';j++){
				sp[j]=sp[j+1];
				if(sp[j]=='\n'){
					sp[j]=0;
				}
			}
	//さらに空白がある場合の処理
			if(strstr(sp," ")!=NULL){
				sq = sq1;
			  sq = strcpy(sq,sp);
			  sp = strstr(sp," ");
			  for(j=0;sp[j]!='\0';j++){
				sp[j]=sp[j+1];
			  }

			  //空白が何番目にあるかを検索
			  ret = strstr(sq," ");
			  for(j=ret-sq;sq[j]!='\0';j++){
				  sq[j]=0;
			  }
			  //構造体NODE.nodenameと論理演算子の右側を比較
			  c=0,d=0;
			  for(j=0;NODE[j].nodename[0]!='\0';j++){
				  if(strcmp(NODE[j].nodename,sq)==0){
					  a=1;
				  }else if(a!=1){
					  c++;
				  }
				  if(strcmp(NODE[j].nodename,sp)==0){
					  b=1;
				  }else if(b!=1){
					  d++;
				  }
				  if(a==1 && b==1){
					  ret = strstr(Ronrisiki," ");
					  for(j=ret-Ronrisiki;Ronrisiki[j]!='\0';j++){
						  Ronrisiki[j]=0;
					  }
					  if(strcmp(Ronrisiki,"AND")==0){
						  //printf("AND演算\n");
						  //構造体にデータを追加する前に、既に同じデータがないか調べる。

						  ret = strstr(readcopy," ");
						  for(j=ret-readcopy;readcopy[j]!='\0';j++){
							  readcopy[j]=0;
						  }
						  for(i=0;NODE[i].nodename[0]!='\0';i++){
							  if(strcmp(NODE[i].nodename,readcopy)==0){
								  NG=1;
								  break;
							  }else{
								  NG=0;
							  }
						  }
						  if(NG==0){
						  NODE[last].num = AND(NODE[c].num,NODE[d].num);
						  strcpy(NODE[last].nodename,readcopy);
						  printf("NODE[%d]にnodename:%s,num:%dを追加(AND)\n",last,NODE[last].nodename,NODE[last].num);
						  }

					  }else if(strcmp(Ronrisiki,"OR")==0){
						  //printf("OR演算\n");
						  //構造体にデータを追加する前に、既に同じデータがないか調べる。
						  
						  ret = strstr(readcopy," ");
						  for(j=ret-readcopy;readcopy[j]!='\0';j++){
							  readcopy[j]=0;
						  }
						  for(i=0;NODE[i].nodename[0]!='\0';i++){
							  if(strcmp(NODE[i].nodename,readcopy)==0){
								  NG=1;
								  break;
							  }else{
								  NG=0;
							  }
						  }
						  if(NG==0){
						  NODE[last].num = OR(NODE[c].num,NODE[d].num);
						  strcpy(NODE[last].nodename,readcopy);
						  printf("NODE[%d]にnodename:%s,num:%dを追加(OR)\n",last,NODE[last].nodename,NODE[last].num);
						  }

					  }else if(strcmp(Ronrisiki,"NAND")==0){
						  //printf("NAND演算\n");
						  //構造体にデータを追加する前に、既に同じデータがないか調べる。

						  ret = strstr(readcopy," ");
						  for(j=ret-readcopy;readcopy[j]!='\0';j++){
							  readcopy[j]=0;
						  }
						  for(i=0;NODE[i].nodename[0]!='\0';i++){
							  if(strcmp(NODE[i].nodename,readcopy)==0){
								  NG=1;
								  break;
							  }else{
								  NG=0;
							  }
						  }
						  if(NG==0){
						  NODE[last].num = NAND(NODE[c].num,NODE[d].num);
						  strcpy(NODE[last].nodename,readcopy);
						  printf("NODE[%d]にnodename:%s,num:%dを追加(NAND)\n",last,NODE[last].nodename,NODE[last].num);
						  }

					  }else if(strcmp(Ronrisiki,"NOR")==0){
						  //printf("NOR演算\n");
						  //構造体にデータを追加する前に、既に同じデータがないか調べる。


						  ret = strstr(readcopy," ");
						  for(j=ret-readcopy;readcopy[j]!='\0';j++){
							  readcopy[j]=0;
						  }
						  for(i=0;NODE[i].nodename[0]!='\0';i++){
							  if(strcmp(NODE[i].nodename,readcopy)==0){
								  NG=1;
								  break;
							  }else{
								  NG=0;
							  }
						  }
						  if(NG==0){
						  NODE[last].num = NOR(NODE[c].num,NODE[d].num);
						  strcpy(NODE[last].nodename,readcopy);
						  printf("NODE[%d]にnodename:%s,num:%dを追加(NOR)\n",last,NODE[last].nodename,NODE[last].num);
						  }

					  }

					  break;
				  }else{
					  //printf("不一致！\n");
				  }
			  }
			  a=0;
			  b=0;

			}else{
				for(j=0;NODE[j].nodename[0]!='\0';j++){
					//一致した場合の処理
				  if(strcmp(NODE[j].nodename,sp)==0){
					  //構造体にデータを追加する前に、既に同じデータがないか調べる。
					 
					 ret = strstr(readcopy," ");
					 for(i=ret-readcopy;readcopy[i]!='\0';i++){
						 readcopy[i]=0;
					 }
					 for(i=0;NODE[i].nodename[0]!='\0';i++){
							  if(strcmp(NODE[i].nodename,readcopy)==0){
								  NG=1;
								  break;
							  }else{
								  NG=0;
							  }
						  }
					 if(NG==0){
					 NODE[last].num = NOT(NODE[j].num);
					 strcpy(NODE[last].nodename,readcopy);
					 printf("NODE[%d]にnodename:%s,num:%dを追加(NOT)\n",last,NODE[last].nodename,NODE[last].num);
					 }
					  break;
				  }else{
					  //printf("不一致！！\n");
				  }
				}
			}
		}
	}
	}

	printf("OUTPUT:\n");
	fseek( fp, (Ogyousuu-1)*sizeof(int), SEEK_SET );
	i=0;
		while(fgets(read,100,fp) != NULL){
			if(strcmp(read,"OUTPUT:\n")==0){

				while(fgets(read,100,fp) != NULL){
					//構造体からOUTPUTのノード名が一致する文字列を探し、一致した文字列の論理値を表示する
					for(i=0;read[i]!='\0';i++){
						if(read[i]=='\n'){
							read[i]=0;
						}

					}

				      for(j=0;NODE[j].nodename[0]!='\0';j++){
						  if(strcmp(NODE[j].nodename,read)==0){
							  printf("%s:%d\n",NODE[j].nodename,NODE[j].num);
							  break;
						  }
					  }
				}
				break;
			}
		}

	fclose(fp);
	printf("ファイルをクローズしました\n");

	return 0;
}

	
