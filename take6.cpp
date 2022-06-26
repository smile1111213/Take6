#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <windows.h>
#define MAX 500
#pragma GCC diagnostic ignored "-Wwrite-strings"

void EnterAgain();
void Explanation();   
void GameScene1(int *num1,int num2[][6],int *playerscore,char *playername);
void GameScene2(int *num1,int num2[][6],int *playerscore,int *putcard,int player_play,int bot1_play,int bot2_play,int bot3_play,char *playername);
void GameScene3(int *num1,int num2[][6],int *playerscore,int *putcard,char *playername);
void GameScene4(int *num1,int num2[][6],int *playerscore,int *putcard,char *playername);
void GameScene5(int *num1,int num2[][6],int *playerscore,int *putcard,char *playername);
void StartScene();
void Count();
void BubbleSort(int *array);
void BubbleSort2(int *array);
void BubbleSort3(int *array);
void shuffle(int *arr, int n, int low, int up);
int BotPlayCard(int *bot,int table[][6],int handcard, int first);		//�O�uBOT 
int BotPlayCard_2(int *bot,int table[][6],int handcard, int first);		//�E�iBOT 
void givebullhead();
void storealltable(int alltable[][6] ,int row , int card);
int countbullhead(int alltable[][6] ,int row);
void fold(int alltable[][6] ,int row ,int card);
void Tocountfold(int alltable[][6] , int *disting ,int playerscore[]);
int Aichoise(int alltable[][6] );
void aftercard(int player_play,int bot1_play,int bot2_play,int bot3_play, int playerscore[],int alltable[][6], int order,int *disting);
void musiceat();
void musicstart();
void music();
void music2();


typedef struct node{
	int number;
	int bullhead;
} Card;

Card card[105];//��104�i�P 
char *name[4];
int main(void){
	
	int enter, flag = 0;
	int up = 104, low = 1;
	int n = 44, i, j , t;
	int arr[44];	
	int player[10];//���a����P 
	int bot1[10], bot2[10], bot3[10], table[4][6] = {0};//�T�ӹq������P�εP���W��24�i�P 
	int player_play,bot1_play,bot2_play,bot3_play;
	int putcard[4]={0};
	int handcard = 10;	//��P��
	int tmp_handcard; 
	int playerscore[4] = {66, 66, 66, 66};
	int finalscore[4] = {0};
	int last_table[4];
	int disting = 0;
	int first = 0;
	char playername[5];
	
	givebullhead();
	srand(time(NULL));
	
	shuffle(arr, n, low, up);//�o�P 
	handcard = 10;
	//�qarr[44]�����P��player�B3��BOT�Btable 
	for(i = 0; i<44; i++){		
		if(i < 10){
			player[i] = arr[i];
		}
		else if(10 <= i && i < 20){
			bot1[i-10] = arr[i]; 
		}
		else if(20 <= i && i < 30){
			bot2[i-20] = arr[i];
		}
		else if(30 <= i && i < 40){
			bot3[i-30] = arr[i];
		}
		else
			table[i-40][0] = arr[i];
	}
	//�Ѥp�ƨ�j 
	BubbleSort(player);
	BubbleSort(bot1);
	BubbleSort(bot2);
	BubbleSort(bot3);
	
	first = 1;
	
	StartScene(); 
	music();
    scanf("%d",&enter);
    while(1){
		if(enter == 1){//�i�J�C��
			system("cls");
			break;
		}
		else if(enter == 2){//�ݹC������ 
			system("cls");
			Explanation();
			system("cls");
			break;
		}
		else if(enter == 3){//�^��D�e�� 
			system("cls");
			StartScene();
			scanf("%d",&enter); 
		}
		else{
			system("cls");
			EnterAgain();
			scanf("%d",&enter);		 	
		}
	}
	printf("�п�J�A���W�r(�̦h5�Ӧr�u��^��):\n");
	scanf("%5s",playername);
	system("cls");
	Count();
	system("pause");
	system("cls");
	while(playerscore[0] > 0 && playerscore[1] > 0 && playerscore[2] > 0 && playerscore[3] > 0){
		while(playerscore[0] > 0 && playerscore[1] > 0 && playerscore[2] > 0 && playerscore[3] > 0){
			GameScene1(player,table,playerscore,playername);
			printf("�п�J�A�n�X���P: ");
			musicstart();
			scanf("%d",&player_play);
			while(flag == 0){
				for(t = 0 ; t < 10 ; t++){
					if(player_play == player[t]){
						flag++;
						break;
					}	
				}
				if(flag ==0){
					printf("�бq�A����P����@�i!�A��J�@��:");
					scanf("%d",&player_play);
				}	
			}
			flag = 0;
			bot1_play = BotPlayCard(bot1,table,handcard,first);
			bot2_play = BotPlayCard_2(bot2,table,handcard,first);
			if(rand() % 3 == 0)
				bot3_play = BotPlayCard_2(bot3,table,handcard,first);
			else
				bot3_play = BotPlayCard(bot3,table,handcard,first);
				
				
			system("cls");
		
			//�X�P��P�Ѧ��i���e���� 
			for(i = 0; player[i]!=0; i++)
				if(player_play == player[i])
					j = i;
				
			for(i = j; i<handcard; i++){
				player[i] = player[i+1];
			}
			player[handcard-1] = 0;
		
			handcard--;
		
		
			GameScene2(player,table,playerscore,putcard,player_play,bot1_play,bot2_play,bot3_play,playername);	
			Sleep(1200);
			aftercard(player_play, bot1_play, bot2_play,bot3_play, playerscore, table, 0,&disting);
			system("cls");
			GameScene3(player,table,playerscore,putcard,playername);
			Tocountfold(table, &disting ,playerscore);		
			system("cls");
		
		
		
			GameScene3(player,table,playerscore,putcard,playername);
			Sleep(1200);
			aftercard(player_play,bot1_play,bot2_play,bot3_play, playerscore  ,table,1,&disting);
			system("cls");
			GameScene4(player,table,playerscore,putcard,playername);
			Tocountfold(table, &disting ,playerscore);
			system("cls");
	
		
		
			GameScene4(player,table,playerscore,putcard,playername);
			Sleep(1200);
			aftercard(player_play,bot1_play,bot2_play,bot3_play, playerscore  ,table,2,&disting);
			system("cls");
			GameScene5(player,table,playerscore,putcard,playername);
			Tocountfold(table, &disting ,playerscore);
			system("cls");

		
		
			GameScene5(player,table,playerscore,putcard,playername);
			Sleep(1200);
			aftercard(player_play,bot1_play,bot2_play,bot3_play, playerscore ,table,3,&disting);
			system("cls");
			GameScene1(player,table,playerscore,playername);
			Tocountfold(table, &disting ,playerscore);
			system("cls");
			if(player[1] == 0)
				break;
		}
		while(playerscore[0] > 0 && playerscore[1] > 0 && playerscore[2] > 0 && playerscore[3] > 0){
			bot1_play = BotPlayCard(bot1,table,handcard,first);
			bot2_play = BotPlayCard_2(bot2,table,handcard,first);
			bot3_play = BotPlayCard(bot3,table,handcard,first);
		
		
			system("cls");
			
			player_play = player[0];
			
			//�X�P��P�Ѧ��i���e���� 
			for(i = 0; player[i]!=0; i++)
				if(player_play == player[i])
					j = i;
				
			for(i = j; i<handcard; i++){
				player[i] = player[i+1];
			}
			player[handcard-1] = 0;
		
			handcard--;
		
		
			GameScene2(player,table,playerscore,putcard,player_play,bot1_play,bot2_play,bot3_play,playername);	
			Sleep(1200);
			aftercard(player_play, bot1_play, bot2_play,bot3_play, playerscore, table, 0,&disting);
			system("cls");
			GameScene3(player,table,playerscore,putcard,playername);
			Tocountfold(table, &disting ,playerscore);		
			system("cls");
		
		
		
			GameScene3(player,table,playerscore,putcard,playername);
			Sleep(1200);
			aftercard(player_play,bot1_play,bot2_play,bot3_play, playerscore  ,table,1,&disting);
			system("cls");
			GameScene4(player,table,playerscore,putcard,playername);
			Tocountfold(table, &disting ,playerscore);
			system("cls");
	
		
		
			GameScene4(player,table,playerscore,putcard,playername);
			Sleep(1200);
			aftercard(player_play,bot1_play,bot2_play,bot3_play, playerscore  ,table,2,&disting);
			system("cls");
			GameScene5(player,table,playerscore,putcard,playername);
			Tocountfold(table, &disting ,playerscore);
			system("cls");

		
		
			GameScene5(player,table,playerscore,putcard,playername);
			Sleep(1200);
			aftercard(player_play,bot1_play,bot2_play,bot3_play, playerscore ,table,3,&disting);
			system("cls");
			GameScene1(player,table,playerscore,playername);
			Tocountfold(table, &disting ,playerscore);
			system("cls");
			break;
		}
		shuffle(arr, n, low, up);//�o�P 
		handcard = 10;
		for(i = 0; i < 4;i++){
			for(j = 1 ;j < 6;j++)
				table[i][j] = 0;
		}		
		//�qarr[44]�����P��player�B3��BOT�Btable 
		for(i = 0; i<44; i++){		
			if(i < 10){
				player[i] = arr[i];
			}
			else if(10 <= i && i < 20){
				bot1[i-10] = arr[i]; 
			}
			else if(20 <= i && i < 30){
				bot2[i-20] = arr[i];
			}	
			else if(30 <= i && i < 40){
				bot3[i-30] = arr[i];
			}
			else
				table[i-40][0] = arr[i];
		}
		//�Ѥp�ƨ�j 
		BubbleSort(player);
		BubbleSort(bot1);
		BubbleSort(bot2);
		BubbleSort(bot3);
		system("cls");
	}
	
	for(i = 0 ; i < 4 ; i++)
		finalscore[i] = playerscore[i];

	BubbleSort3(finalscore);
	
	for(i = 0 ; i < 4 ; i++){
		if(i == 0){
			if(finalscore[i] == playerscore[0])
				printf("�a�x:%5s\n",playername);
			else if(finalscore[i] == playerscore[1])
				printf("�a�x:James\n");
			else if(finalscore[i] == playerscore[2])
				printf("�a�x:Curry\n");
			else if(finalscore[i] == playerscore[3])
				printf("�a�x:Judge\n");	
		}
		else if(i == 1){
			if(finalscore[i] == playerscore[0])
				printf("�ȭx:%5s\n",playername);
			else if(finalscore[i] == playerscore[1])
				printf("�ȭx:James\n");
			else if(finalscore[i] == playerscore[2])
				printf("�ȭx:Curry\n");
			else if(finalscore[i] == playerscore[3])
				printf("�ȭx:Judge\n");
		}
		else if(i == 2){
			if(finalscore[i] == playerscore[0])
				printf("�u�x:%5s\n",playername);
			else if(finalscore[i] == playerscore[1])
				printf("�u�x:James\n");
			else if(finalscore[i] == playerscore[2])
				printf("�u�x:Curry\n");
			else if(finalscore[i] == playerscore[3])
				printf("�u�x:Judge\n");
		}
		else if(i == 3){
			if(finalscore[i] == playerscore[0])
				printf("�[�o��!�h�h�m��:%5s\n",playername);
			else if(finalscore[i] == playerscore[1])
				printf("�[�o��!�h�h�m��:James\n");
			else if(finalscore[i] == playerscore[2])
				printf("�[�o��!�h�h�m��:Curry\n");
			else if(finalscore[i] == playerscore[3])
				printf("�[�o��!�h�h�m��:Judge\n");
		}
	}
	music2();	  

}
void EnterAgain(){
	char *b[21];
	int h,k;
	b[0] = "                _________________________________________________   ";
	b[1] = "               �x                                                �x "; 
	b[2] = "               �x          *      **** ******   ***********      �x ";
	b[3] = "               �x      *   *             *           *           �x "; 
	b[4] = "               �x     *    *      **** ******        *           �x ";
	b[5] = "               �x    **********   *  * *    *        *           �x ";
	b[6] = "               �x   *     *       *  * ******        *           �x "; 
	b[7] = "               �x  *      *       *  * *    *   ***********      �x ";
	b[8] = "               �x     *********   *  * ******        *           �x ";
	b[9] = "               �x         *       **** *    *        *           �x ";
	b[10] = "               �x         *       *  * ******        *           �x ";
	b[11] = "               �x         *        **   *  *         *           �x ";
	b[12] = "               �x         *       **** *    *   ***********      �x ";
	b[13] = "               �x                                                �x ";
	b[14] = "               �x             Welcome to the game!               �x ";
	b[15] = "               �x                                                �x "; 
	b[16] = "               �x          Failed!Please enter again!            �x ";
	b[17] = "               �x                                                �x ";
	b[18] = "               �x                                                �x ";
	b[19] = "               �x                                                �x ";
	b[20] = "               �|------------------------------------------------�} ";
   	for(h = 1 ; h < 4 ; h++)
		putchar('\n');
	for(k = 0 ; k <21 ; k++)
		printf("%s\n",b[k]);
}
void Explanation(){
	FILE *fptr1;
	char str1[MAX], explan;
	int bytes1;
	

	fptr1 = fopen("Explanation.txt", "r");
	

	bytes1 = fread(str1, sizeof(char), MAX, fptr1);
	str1[bytes1] = '\0';
	if(feof(fptr1)){
		printf("%s", str1);
	}
	fclose(fptr1);
	system("pause");
} 
void GameScene1(int *num1,int num2[][6],int *playerscore,char *playername){
	int first ;
	char *c[38];
	char star1[]="*";
	char star2[]="**";
	char star3[]="***";
	char star4[]="****";
	char space1[]=" ";
	char space2[]="  ";
	char space3[]="   ";
	char space4[]="    ";
	char *str[10],*str1[10];
	char *str2[6] = {"    ","    ","    ","    ","    ","    "};
	char *str3[6] = {"   ","   ","   ","   ","   ","   "};
	char *str4[6] = {"    ","    ","    ","    ","    ","    "};
	char *str5[6] = {"   ","   ","   ","   ","   ","   "};
	char *str6[6] = {"    ","    ","    ","    ","    ","    "};
	char *str7[6] = {"   ","   ","   ","   ","   ","   "};
	char *str8[6] = {"    ","    ","    ","    ","    ","    "};
	char *str9[6] = {"   ","   ","   ","   ","   ","   "};
	size_t i,r,q,u;	
	
	c[0] = " ____________________________________________________________________________ ";
	c[1] = "|                                  %10s������: %2d / James������: %2d    |";
	c[2] = "|      �ڪ���P                         Curry������: %2d / Judge������: %2d    |";
	c[3] = "|____________________________________________________________________________|";
	c[4] = "| %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s |      |";
    c[5] = "| %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  |      |";
    c[6] = "| %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  |      |";
    c[7] = "|      |      |      |      |      |      |      |      |      |      |      |";
    c[8] = "|______|______|______|______|______|______|______|______|______|______|      |";
	c[9] = "|____________________________________________________________________________|";
	c[10] = "|                           �п�@�i�P���X                                   |";
	c[11] = "|____________________________________________________________________________|";
	c[12] = "|__________________________________   ______                                 |";
	c[13] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[14] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[15] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[16] = "|      |      |      |      |      | |      |                                |";
	c[17] = "|______|______|______|______|______| |______|                                |";
	c[18] = "|__________________________________   ______                                 |";  
	c[19] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[20] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[21] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[22] = "|      |      |      |      |      | |      |                                |";
	c[23] = "|______|______|______|______|______| |______|                                |";
	c[24] = "|__________________________________   ______                                 |";
	c[25] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[26] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[27] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[28] = "|      |      |      |      |      | |      |                                |";
	c[29] = "|______|______|______|______|______| |______|                                |";
	c[30] = "|__________________________________   ______                                 |";
	c[31] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[32] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[33] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[34] = "|      |      |      |      |      | |      |                                |";
	c[35] = "|______|______|______|______|______| |______|                                |";
	c[36] = "|                                                                            |";
	c[37] = "|____________________________________________________________________________|";
	

	
	for(q = 0 ; q <38 ; q++){
		if(q == 1){
			printf(c[q],playername,playerscore[0],playerscore[1]);
			puts("");
		}
		else if(q == 2){
			printf(c[q],playerscore[2],playerscore[3]);
			puts("");
		}
		else if(q == 4){
			for(r = 0 ; r < 10 ; r++){
				if(num1[r] == 5  || num1[r] == 15 || num1[r] == 25 ||
					num1[r] == 35 || num1[r] == 45 || num1[r] == 65 ||
					num1[r] == 75 || num1[r] == 85 || num1[r] == 95){
					str[r] = star2;
					str1[r] = space3;
				}
				else if(num1[r] == 10  || num1[r] == 20 || num1[r] == 30 ||
				        num1[r] == 40 || num1[r] == 50 || num1[r] == 60 ||
				        num1[r] == 70 || num1[r] == 80 || num1[r] == 90){
				        str[r] = star3;
						str1[r] = space3;    	
				}
				else if(num1[r] == 11  || num1[r] == 22 || num1[r] == 33 ||
				        num1[r] == 44 || num1[r] == 66 || num1[r] == 77 ||
				        num1[r] == 88 || num1[r] == 99){
					    str[r] = star3;
						str1[r] = star2;    	
				}
				else if(num1[r] == 55){
						str[r] = star4;
						str1[r] = star3;
				}
				else if(num1[r] == 0){
						str[r] = space4;
						str1[r] = space3;
				}
				else{
					str[r] = star1;
					str1[r] = space3;
				}
			}
			printf(c[q],str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7]
			      ,str[8],str[9]);	
			puts("");	
		}
		else if(q == 5){				
			printf(c[q],str1[0],str1[1],str1[2],str1[3],str1[4],str1[5],str1[6],str1[7]
					,str1[8],str1[9]);
			puts("");				    
		}			
		else if(q == 6){
			if(num1[9] == 0){
				first = 1;
				i = 9;
				for(r = 8 ; r >= 0 ; r--){
					if(num1[r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 9 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num1[0],num1[1],num1[2]
					 	  		,num1[3],num1[4],num1[5],num1[6]
				      	  		,num1[7],num1[8],num1[9]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num1[0],num1[1],num1[2]
					   ,num1[3],num1[4],num1[5],num1[6]
				       ,num1[7],num1[8],num1[9]);	
			puts("");
		}
		else if(q == 13){
			for(u = 0 ; u < 6 ; u++){
				if(num2[0][u] == 5  || num2[0][u] == 15 || num2[0][u] == 25 ||
				   	num2[0][u] == 35 || num2[0][u] == 45 || num2[0][u] == 65 ||
				   	num2[0][u] == 75 || num2[0][u] == 85 || num2[0][u] == 95){
				   	str2[u] = star2;
				   	str3[u] = space3;
				}
				else if(num2[0][u] == 10  || num2[0][u] == 20 || num2[0][u] == 30 ||
				    	num2[0][u] == 40 || num2[0][u] == 50 || num2[0][u] == 60 ||
				    	num2[0][u] == 70 || num2[0][u] == 80 || num2[0][u] == 90){
						str2[u] = star3;
						str3[u] = space3;    	
				}
				else if(num2[0][u] == 11  || num2[0][u] == 22 || num2[0][u] == 33 ||
				    	num2[0][u] == 44 || num2[0][u] == 66 || num2[0][u] == 77 ||					    	
						num2[0][u] == 88 || num2[0][u] == 99){
						str2[u] = star3;
						str3[u] = star2;    	
				}
				else if(num2[0][u] == 55){
						str2[u] = star4;							
						str3[u] = star3;
				}
				else if(num2[0][u] == 0){
						str2[u] = space4;
						str3[u] = space3;
				}
				else{
					str2[u] = star1;
					str3[u] = space3;				
				}
			}
			printf(c[q],str2[0],str2[1],str2[2],str2[3],str2[4],str2[5]);
			puts("");
		}
		else if(q == 14){					        					   
			printf(c[q],str3[0],str3[1],str3[2],str3[3],str3[4],str3[5]);
			puts("");
		}
		else if(q == 15){
			if(num2[0][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[0][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);				
			puts("");
		}
		else if(q == 19){
			for(u = 0 ; u < 6 ; u++){
				if(num2[1][u] == 5  || num2[1][u] == 15 || num2[1][u] == 25 ||
				   num2[1][u] == 35 || num2[1][u] == 45 || num2[1][u] == 65 ||
				   num2[1][u] == 75 || num2[1][u] == 85 || num2[1][u] == 95){
				   str4[u] = star2;
				   str5[u] = space3;
				}
				else if(num2[1][u] == 10  || num2[1][u] == 20 || num2[1][u] == 30 ||
					    num2[1][u] == 40 || num2[1][u] == 50 || num2[1][u] == 60 ||
					    num2[1][u] == 70 || num2[1][u] == 80 || num2[1][u] == 90){
						str4[u] = star3; 
						str5[u] = space3;   	
				}
				else if(num2[1][u] == 11  || num2[1][u] == 22 || num2[1][u] == 33 ||
					    num2[1][u] == 44 || num2[1][u] == 66 || num2[1][u] == 77 ||
					    num2[1][u] == 88 || num2[1][u] == 99){
						str4[u] = star3;
						str5[u] = star2;  	
				}
				else if(num2[1][u] == 55){
						str4[u] = star4;
						str5[u] = star3;
				}
				else if(num2[1][u] == 0){
						str4[u] = space4;
						str5[u] = space3;	
				}				
				else{
						str4[u] = star1;
						str5[u] = space3;
				}
			} 
			printf(c[q],str4[0],str4[1],str4[2],str4[3],str4[4],str4[5]);
			puts("");
		}
		else if(q == 20){				        					   
			printf(c[q],str5[0],str5[1],str5[2],str5[3],str5[4],str5[5]);
			puts("");
		}				
        else if(q == 21){
        	if(num2[1][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[1][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5]);
			puts("");
		}
		else if(q == 25){
			for(u = 0 ; u < 6 ; u++){
				if(num2[2][u] == 5  || num2[2][u] == 15 || num2[2][u] == 25 ||
				   	num2[2][u] == 35 || num2[2][u] == 45 || num2[2][u] == 65 ||
				   	num2[2][u] == 75 || num2[2][u] == 85 || num2[2][u] == 95){
				   	str6[u] = star2;
				   	str7[u] = space3;
				}
				else if(num2[2][u] == 10  || num2[2][u] == 20 || num2[2][u] == 30 ||
					    num2[2][u] == 40 || num2[2][u] == 50 || num2[2][u] == 60 ||
					    num2[2][u] == 70 || num2[2][u] == 80 || num2[2][u] == 90){
						str6[u] = star3; 
						str7[u] = space3;   	
				}
				else if(num2[2][u] == 11  || num2[2][u] == 22 || num2[2][u] == 33 ||
					   	num2[2][u] == 44 || num2[2][u] == 66 || num2[2][u] == 77 ||
					    num2[2][u] == 88 || num2[2][u] == 99){
						str6[u] = star3; 
						str7[u]= star2;   	
				}
				else if(num2[2][u] == 55){
						str6[u] = star4;
						str7[u] = star3;
				}
				else if(num2[2][u] == 0){
						str6[u] = space4;
						str7[u] = space3;
				}
				else{
					str6[u] = star1;
					str7[u] = space3;	
				}
			} 
			printf(c[q],str6[0],str6[1],str6[2],str6[3],str6[4],str6[5]);
		    puts("");
		}
		else if(q == 26){
			printf(c[q],str7[0],str7[1],str7[2],str7[3],str7[4],str7[5]);
		    puts("");		
		}	
		else if(q == 27){
			if(num2[2][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[2][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
			puts("");
		}
		else if(q == 31){
			for(u = 0 ; u < 6 ; u++){
				if(num2[3][u] == 5  || num2[3][u] == 15 || num2[3][u] == 25 ||
			   	   num2[3][u] == 35 || num2[3][u] == 45 || num2[3][u] == 65 ||
			   	   num2[3][u] == 75 || num2[3][u] == 85 || num2[3][u] == 95){
			   	   str8[u] = star2;
			   	   str9[u] = space3;
				}
				else if(num2[3][u] == 10  || num2[3][u] == 20 || num2[3][u] == 30 ||
				   		num2[3][u] == 40 || num2[3][u] == 50 || num2[3][u] == 60 ||
				    	num2[3][u] == 70 || num2[3][u] == 80 || num2[3][u] == 90){
						str8[u] = star3; 
						str9[u] = space3;   	
				}
				else if(num2[3][u] == 11  || num2[3][u] == 22 || num2[3][u] == 33 ||
				    	num2[3][u] == 44 || num2[3][u] == 66 || num2[3][u] == 77 ||
				    	num2[3][u] == 88 || num2[3][u] == 99){
						str8[u] = star3;
						str9[u] = star2;  	
				}
				else if(num2[3][u] == 55){
						str8[u] = star4;
						str9[u] = star3;
				}
				else if(num2[3][u] == 0){
						str8[u] = space4;
						str9[u] = space3;
				}
				else{
					str8[u] = star1;
					str9[u] = space3;
				}
			} 
			printf(c[q],str8[0],str8[1],str8[2],str8[3],str8[4],str8[5]);
		    puts("");
		}
		else if(q == 32){
			printf(c[q],str9[0],str9[1],str9[2],str9[3],str9[4],str9[5]);
		    puts("");
		}
		else if(q == 33){
			if(num2[3][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[3][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
			puts("");
		}						
	    else
	    	printf("%s\n",c[q]);	
	}	
}
void GameScene2(int *num1,int num2[][6],int *playerscore,int *putcard,int player_play,int bot1_play,int bot2_play,int bot3_play,char *playername){
	int first;
	int tmp_putcard[4];
	char *c[38];
	char star1[]="*";
	char star2[]="**";
	char star3[]="***";
	char star4[]="****";
	char space1[]=" ";
	char space2[]="  ";
	char space3[]="   ";
	char space4[]="    ";
	char *str[10],*str1[10];
	char *str2[6] = {"    ","    ","    ","    ","    ","    "};
	char *str3[6] = {"   ","   ","   ","   ","   ","   "};
	char *str4[6] = {"    ","    ","    ","    ","    ","    "};
	char *str5[6] = {"   ","   ","   ","   ","   ","   "};
	char *str6[6] = {"    ","    ","    ","    ","    ","    "};
	char *str7[6] = {"   ","   ","   ","   ","   ","   "};
	char *str8[6] = {"    ","    ","    ","    ","    ","    "};
	char *str9[6] = {"   ","   ","   ","   ","   ","   "};
	char *str10[4] = {"    ","    ","    ","    "};
	char *str11[4] = {"   ","   ","   ","   "};
	size_t i,r,h,q,u;			
	c[0] = " ____________________________________________________________________________ ";
	c[1] = "|                                  %10s������: %2d / James������: %2d    |";
	c[2] = "|      �ڪ���P                         Curry������: %2d / Judge������: %2d    |";
	c[3] = "|____________________________________________________________________________|";
	c[4] = "| %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s |      |";
    c[5] = "| %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  |      |";
    c[6] = "| %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  |      |";
    c[7] = "|      |      |      |      |      |      |      |      |      |      |      |";
    c[8] = "|______|______|______|______|______|______|______|______|______|______|      |";
	c[9] = "|____________________________________________________________________________|";
	c[10] = "|                           �п�@�i�P���X                                   |";
	c[11] = "|____________________________________________________________________________|";
	c[12] = "|__________________________________   ______                                 |";
	c[13] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[14] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[15] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[16] = "|      |      |      |      |      | |      |                                |";
	c[17] = "|______|______|______|______|______| |______|                                |";
	c[18] = "|__________________________________   ______                                 |";  
	c[19] = "| %4s | %4s | %4s | %4s | %4s | | %4s |     %5s  %5s  %5s  %5s |";
	c[20] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |    ___________________________ |";
	c[21] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |   | %4s | %4s | %4s | %4s ||";
	c[22] = "|      |      |      |      |      | |      |   | %3s  | %3s  | %3s  | %3s  ||";
	c[23] = "|______|______|______|______|______| |______|   | %3d  | %3d  | %3d  | %3d  ||";
	c[24] = "|__________________________________   ______    |      |      |      |      ||";
	c[25] = "| %4s | %4s | %4s | %4s | %4s | | %4s |   |______|______|______|______||";
	c[26] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[27] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[28] = "|      |      |      |      |      | |      |                                |";
	c[29] = "|______|______|______|______|______| |______|                                |";
	c[30] = "|__________________________________   ______                                 |";
	c[31] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[32] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[33] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[34] = "|      |      |      |      |      | |      |                                |";
	c[35] = "|______|______|______|______|______| |______|                                |";
	c[36] = "|                                                                            |";
	c[37] = "|____________________________________________________________________________|";
	
	putcard[0] = player_play ;
	putcard[1] = bot1_play ;
	putcard[2] = bot2_play ;
	putcard[3] = bot3_play ;
	
	for(i = 0 ; i < 4 ; i++)
		tmp_putcard[i] = putcard[i];
	
	BubbleSort2(putcard);
	
	for(i = 0 ; i < 4 ; i++){
		if(i == 0){
			if(tmp_putcard[i] == putcard[0])
				name[0] = playername;
			else if(tmp_putcard[i] == putcard[1])
				name[1] = playername;
			else if(tmp_putcard[i] == putcard[2])
				name[2] = playername;
			else if(tmp_putcard[i] == putcard[3])
				name[3] = playername;
		}
		else if(i == 1){
			if(tmp_putcard[i] == putcard[0])
				name[0] = "James";
			else if(tmp_putcard[i] == putcard[1])
				name[1] = "James";
			else if(tmp_putcard[i] == putcard[2])
				name[2] = "James";
			else if(tmp_putcard[i] == putcard[3])
				name[3] = "James";
		}
		else if(i == 2){
			if(tmp_putcard[i] == putcard[0])
				name[0] = "Curry";
			else if(tmp_putcard[i] == putcard[1])
				name[1] = "Curry";
			else if(tmp_putcard[i] == putcard[2])
				name[2] = "Curry";
			else if(tmp_putcard[i] == putcard[3])
				name[3] = "Curry";
		}
		else if(i == 3){
			if(tmp_putcard[i] == putcard[0])
				name[0] = "Judge";
			else if(tmp_putcard[i] == putcard[1])
				name[1] = "Judge";
			else if(tmp_putcard[i] == putcard[2])
				name[2] = "Judge";
			else if(tmp_putcard[i] == putcard[3])
				name[3] = "Judge";
		}
	}	  
	 	 
	for(q = 0 ; q <38 ; q++){
		if(q == 1){
			printf(c[q],playername,playerscore[0],playerscore[1]);
			puts("");
		}
		else if(q == 2){
			printf(c[q],playerscore[2],playerscore[3]);
			puts("");
		}
		else if(q == 4){
			for(r = 0 ; r < 10 ; r++){
				if(num1[r] == 5  || num1[r] == 15 || num1[r] == 25 ||
					num1[r] == 35 || num1[r] == 45 || num1[r] == 65 ||
					num1[r] == 75 || num1[r] == 85 || num1[r] == 95){
					str[r] = star2;
					str1[r] = space3;
				}
				else if(num1[r] == 10  || num1[r] == 20 || num1[r] == 30 ||
				        num1[r] == 40 || num1[r] == 50 || num1[r] == 60 ||
				        num1[r] == 70 || num1[r] == 80 || num1[r] == 90){
				        str[r] = star3;
						str1[r] = space3;    	
				}
				else if(num1[r] == 11  || num1[r] == 22 || num1[r] == 33 ||
				        num1[r] == 44 || num1[r] == 66 || num1[r] == 77 ||
				        num1[r] == 88 || num1[r] == 99){
					    str[r] = star3;
						str1[r] = star2;    	
				}
				else if(num1[r] == 55){
						str[r] = star4;
						str1[r] = star3;
				}
				else if(num1[r] == 0){
						str[r] = space4;
						str1[r] = space3;
				} 
				else{
					str[r] = star1;
					str1[r] = space3;
				}
			}
			printf(c[q],str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7]
			      ,str[8],str[9]);	
			puts("");	
		}
		else if(q == 5){				
			printf(c[q],str1[0],str1[1],str1[2],str1[3],str1[4],str1[5],str1[6],str1[7]
					,str1[8],str1[9]);
			puts("");				    
		}			
		else if(q == 6){
			if(num1[9] == 0){
				first = 1;
				i = 9;
				for(r = 8 ; r >= 0 ; r--){
					if(num1[r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 9 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num1[0],num1[1],num1[2]
					 	  		,num1[3],num1[4],num1[5],num1[6]
				      	  		,num1[7],num1[8],num1[9]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num1[0],num1[1],num1[2]
					   ,num1[3],num1[4],num1[5],num1[6]
				       ,num1[7],num1[8],num1[9]);	
			puts("");
		}
		else if(q == 13){
			for(u = 0 ; u < 6 ; u++){
				if(num2[0][u] == 5  || num2[0][u] == 15 || num2[0][u] == 25 ||
				   	num2[0][u] == 35 || num2[0][u] == 45 || num2[0][u] == 65 ||
				   	num2[0][u] == 75 || num2[0][u] == 85 || num2[0][u] == 95){
				   	str2[u] = star2;
				   	str3[u] = space3;
				}
				else if(num2[0][u] == 10  || num2[0][u] == 20 || num2[0][u] == 30 ||
				    	num2[0][u] == 40 || num2[0][u] == 50 || num2[0][u] == 60 ||
				    	num2[0][u] == 70 || num2[0][u] == 80 || num2[0][u] == 90){
						str2[u] = star3;
						str3[u] = space3;    	
				}
				else if(num2[0][u] == 11  || num2[0][u] == 22 || num2[0][u] == 33 ||
				    	num2[0][u] == 44 || num2[0][u] == 66 || num2[0][u] == 77 ||					    	
						num2[0][u] == 88 || num2[0][u] == 99){
						str2[u] = star3;
						str3[u] = star2;    	
				}
				else if(num2[0][u] == 55){
						str2[u] = star4;							
						str3[u] = star3;
				}
				else if(num2[0][u] == 0){
						str2[u] = space4;
						str3[u] = space3;
				}
				else{
					str2[u] = star1;
					str3[u] = space3;				
				}
			}
			printf(c[q],str2[0],str2[1],str2[2],str2[3],str2[4],str2[5]);
			puts("");
		}
		else if(q == 14){					        					   
			printf(c[q],str3[0],str3[1],str3[2],str3[3],str3[4],str3[5]);
			puts("");
		}
		else if(q == 15){
			if(num2[0][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[0][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);				
			puts("");
		}
		else if(q == 19){
			for(u = 0 ; u < 6 ; u++){
				if(num2[1][u] == 5  || num2[1][u] == 15 || num2[1][u] == 25 ||
				   num2[1][u] == 35 || num2[1][u] == 45 || num2[1][u] == 65 ||
				   num2[1][u] == 75 || num2[1][u] == 85 || num2[1][u] == 95){
				   str4[u] = star2;
				   str5[u] = space3;
				}
				else if(num2[1][u] == 10  || num2[1][u] == 20 || num2[1][u] == 30 ||
					    num2[1][u] == 40 || num2[1][u] == 50 || num2[1][u] == 60 ||
					    num2[1][u] == 70 || num2[1][u] == 80 || num2[1][u] == 90){
						str4[u] = star3; 
						str5[u] = space3;   	
				}
				else if(num2[1][u] == 11  || num2[1][u] == 22 || num2[1][u] == 33 ||
					    num2[1][u] == 44 || num2[1][u] == 66 || num2[1][u] == 77 ||
					    num2[1][u] == 88 || num2[1][u] == 99){
						str4[u] = star3;
						str5[u] = star2;  	
				}
				else if(num2[1][u] == 55){
						str4[u] = star4;
						str5[u] = star3;
				}
				else if(num2[1][u] == 0){
						str4[u] = space4;
						str5[u] = space3;	
				}				
				else{
						str4[u] = star1;
						str5[u] = space3;
				}
			} 
			printf(c[q],str4[0],str4[1],str4[2],str4[3],str4[4],str4[5],name[0],name[1],name[2],name[3]);
			puts("");
		}
		else if(q == 20){				        					   
			printf(c[q],str5[0],str5[1],str5[2],str5[3],str5[4],str5[5]);
			puts("");
		}				
        else if(q == 21){      	
            for(h = 0 ; h < 4 ; h++){
				if(putcard[h] == 5  || putcard[h] == 15 || putcard[h] == 25 ||
					putcard[h] == 35 || putcard[h] == 45 || putcard[h] == 65 ||
					putcard[h] == 75 || putcard[h] == 85 || putcard[h] == 95){
					str10[h] = star2;
					str11[h] = space3;
				}
				else if(putcard[h] == 10 || putcard[h] == 20 || putcard[h] == 30 ||
					    putcard[h] == 40 || putcard[h] == 50 || putcard[h] == 60 ||
					    putcard[h] == 70 || putcard[h] == 80 || putcard[h] == 90){
						str10[h] = star3;
						str11[h] = space3;    	
				}
				else if(putcard[h] == 11 || putcard[h] == 22 || putcard[h] == 33 ||
					    putcard[h] == 44 || putcard[h] == 66 || putcard[h] == 77 ||
					    putcard[h] == 88 || putcard[h] == 99){
					    str10[h] = star3;
						str11[h] = star2;    	
				}
				else if(putcard[h] == 55){
					str10[h] = star4;
					str11[h] = star3;
				}
				else{
					str10[h] = star1;
					str11[h] = space3;
				}
			}
			if(num2[1][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[1][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[0],str10[1],str10[2],str10[3]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[0],str10[1],str10[2],str10[3]);
			puts("");
		}
		else if(q == 22){
			printf(c[q],str11[0],str11[1],str11[2],str11[3]);
			puts("");
		}
		else if(q == 23){
			printf(c[q],putcard[0],putcard[1],putcard[2],putcard[3]);
			puts("");
		}
		else if(q == 25){
				for(u = 0 ; u < 6 ; u++){
				if(num2[2][u] == 5  || num2[2][u] == 15 || num2[2][u] == 25 ||
				   num2[2][u] == 35 || num2[2][u] == 45 || num2[2][u] == 65 ||
				   num2[2][u] == 75 || num2[2][u] == 85 || num2[2][u] == 95){
				   str6[u] = star2;
				   str7[u] = space3;
				}
				else if(num2[2][u] == 10  || num2[2][u] == 20 || num2[2][u] == 30 ||
					    num2[2][u] == 40 || num2[2][u] == 50 || num2[2][u] == 60 ||
					    num2[2][u] == 70 || num2[2][u] == 80 || num2[2][u] == 90){
						str6[u] = star3; 
						str7[u] = space3;   	
				}
				else if(num2[2][u] == 11  || num2[2][u] == 22 || num2[2][u] == 33 ||
					    num2[2][u] == 44 || num2[2][u] == 66 || num2[2][u] == 77 ||
					    num2[2][u] == 88 || num2[2][u] == 99){
						str6[u] = star3;
						str7[u] = star2;  	
				}
				else if(num2[2][u] == 55){
						str6[u] = star4;
						str7[u] = star3;
				}
				else if(num2[2][u] == 0){
						str6[u] = space4;
						str7[u] = space3;	
				}				
				else{
						str6[u] = star1;
						str7[u] = space3;
				}
			} 
			printf(c[q],str6[0],str6[1],str6[2],str6[3],str6[4],str6[5]);
		    puts("");
		}
		else if(q == 26){
			printf(c[q],str7[0],str7[1],str7[2],str7[3],str7[4],str7[5]);
		    puts("");		
		}	
		else if(q == 27){
			if(num2[2][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[2][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
			puts("");
		}
		else if(q == 31){
			for(u = 0 ; u < 6 ; u++){
				if(num2[3][u] == 5  || num2[3][u] == 15 || num2[3][u] == 25 ||
			   	   num2[3][u] == 35 || num2[3][u] == 45 || num2[3][u] == 65 ||
			   	   num2[3][u] == 75 || num2[3][u] == 85 || num2[3][u] == 95){
			   	   str8[u] = star2;
			   	   str9[u] = space3;
				}
				else if(num2[3][u] == 10  || num2[3][u] == 20 || num2[3][u] == 30 ||
				   		num2[3][u] == 40 || num2[3][u] == 50 || num2[3][u] == 60 ||
				    	num2[3][u] == 70 || num2[3][u] == 80 || num2[3][u] == 90){
						str8[u] = star3; 
						str9[u] = space3;   	
				}
				else if(num2[3][u] == 11  || num2[3][u] == 22 || num2[3][u] == 33 ||
				    	num2[3][u] == 44 || num2[3][u] == 66 || num2[3][u] == 77 ||
				    	num2[3][u] == 88 || num2[3][u] == 99){
						str8[u] = star3;
						str9[u] = star2;  	
				}
				else if(num2[3][u] == 55){
						str8[u] = star4;
						str9[u] = star3;
				}
				else if(num2[3][u] == 0){
						str8[u] = space4;
						str9[u] = space3;
				}
				else{
					str8[u] = star1;
					str9[u] = space3;
				}
			} 
			printf(c[q],str8[0],str8[1],str8[2],str8[3],str8[4],str8[5]);
		    puts("");
		}
		else if(q == 32){
			printf(c[q],str9[0],str9[1],str9[2],str9[3],str9[4],str9[5]);
		    puts("");
		}
		else if(q == 33){
			if(num2[3][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[3][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
			puts("");
		}						
	    else
	    	printf("%s\n",c[q]);	
	}	
}
void GameScene3(int *num1,int num2[][6],int *playerscore,int *putcard,char *playername){
	int first;
	int tmp_putcard[4];
	char *c[38];
	char star1[]="*";
	char star2[]="**";
	char star3[]="***";
	char star4[]="****";
	char space1[]=" ";
	char space2[]="  ";
	char space3[]="   ";
	char space4[]="    ";
	char *str[10],*str1[10];
	char *str2[6] = {"    ","    ","    ","    ","    ","    "};
	char *str3[6] = {"   ","   ","   ","   ","   ","   "};
	char *str4[6] = {"    ","    ","    ","    ","    ","    "};
	char *str5[6] = {"   ","   ","   ","   ","   ","   "};
	char *str6[6] = {"    ","    ","    ","    ","    ","    "};
	char *str7[6] = {"   ","   ","   ","   ","   ","   "};
	char *str8[6] = {"    ","    ","    ","    ","    ","    "};
	char *str9[6] = {"   ","   ","   ","   ","   ","   "};
	char *str10[4] = {"    ","    ","    ","    "};
	char *str11[4] = {"   ","   ","   ","   "};
	size_t i,r,h,q,u;			
	c[0] = " ____________________________________________________________________________ ";
	c[1] = "|                                  %10s������: %2d / James������: %2d    |";
	c[2] = "|      �ڪ���P                         Curry������: %2d / Judge������: %2d    |";
	c[3] = "|____________________________________________________________________________|";
	c[4] = "| %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s |      |";
    c[5] = "| %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  |      |";
    c[6] = "| %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  |      |";
    c[7] = "|      |      |      |      |      |      |      |      |      |      |      |";
    c[8] = "|______|______|______|______|______|______|______|______|______|______|      |";
	c[9] = "|____________________________________________________________________________|";
	c[10] = "|                           �п�@�i�P���X                                   |";
	c[11] = "|____________________________________________________________________________|";
	c[12] = "|__________________________________   ______                                 |";
	c[13] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[14] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[15] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[16] = "|      |      |      |      |      | |      |                                |";
	c[17] = "|______|______|______|______|______| |______|                                |";
	c[18] = "|__________________________________   ______                                 |";  
	c[19] = "| %4s | %4s | %4s | %4s | %4s | | %4s |            %5s  %5s  %5s |";
	c[20] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |           ____________________ |";
	c[21] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |          | %4s | %4s | %4s ||";
	c[22] = "|      |      |      |      |      | |      |          | %3s  | %3s  | %3s  ||";
	c[23] = "|______|______|______|______|______| |______|          | %3d  | %3d  | %3d  ||";
	c[24] = "|__________________________________   ______           |      |      |      ||";
	c[25] = "| %4s | %4s | %4s | %4s | %4s | | %4s |          |______|______|______||";
	c[26] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[27] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[28] = "|      |      |      |      |      | |      |                                |";
	c[29] = "|______|______|______|______|______| |______|                                |";
	c[30] = "|__________________________________   ______                                 |";
	c[31] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[32] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[33] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[34] = "|      |      |      |      |      | |      |                                |";
	c[35] = "|______|______|______|______|______| |______|                                |";
	c[36] = "|                                                                            |";
	c[37] = "|____________________________________________________________________________|";
	for(q = 0 ; q <38 ; q++){
		if(q == 1){
			printf(c[q],playername,playerscore[0],playerscore[1]);
			puts("");
		}
		else if(q == 2){
			printf(c[q],playerscore[2],playerscore[3]);
			puts("");
		}
		else if(q == 4){
			for(r = 0 ; r < 10 ; r++){
				if(num1[r] == 5  || num1[r] == 15 || num1[r] == 25 ||
					num1[r] == 35 || num1[r] == 45 || num1[r] == 65 ||
					num1[r] == 75 || num1[r] == 85 || num1[r] == 95){
					str[r] = star2;
					str1[r] = space3;
				}
				else if(num1[r] == 10  || num1[r] == 20 || num1[r] == 30 ||
				        num1[r] == 40 || num1[r] == 50 || num1[r] == 60 ||
				        num1[r] == 70 || num1[r] == 80 || num1[r] == 90){
				        str[r] = star3;
						str1[r] = space3;    	
				}
				else if(num1[r] == 11  || num1[r] == 22 || num1[r] == 33 ||
				        num1[r] == 44 || num1[r] == 66 || num1[r] == 77 ||
				        num1[r] == 88 || num1[r] == 99){
					    str[r] = star3;
						str1[r] = star2;    	
				}
				else if(num1[r] == 55){
						str[r] = star4;
						str1[r] = star3;
				}
				else if(num1[r] == 0){
						str[r] = space4;
						str1[r] = space3;
				} 
				else{
					str[r] = star1;
					str1[r] = space3;
				}
			}
			printf(c[q],str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7]
			      ,str[8],str[9]);	
			puts("");	
		}
		else if(q == 5){				
			printf(c[q],str1[0],str1[1],str1[2],str1[3],str1[4],str1[5],str1[6],str1[7]
					,str1[8],str1[9]);
			puts("");				    
		}			
		else if(q == 6){
			if(num1[9] == 0){
				first = 1;
				i = 9;
				for(r = 8 ; r >= 0 ; r--){
					if(num1[r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 9 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num1[0],num1[1],num1[2]
					 	  		,num1[3],num1[4],num1[5],num1[6]
				      	  		,num1[7],num1[8],num1[9]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num1[0],num1[1],num1[2]
					   ,num1[3],num1[4],num1[5],num1[6]
				       ,num1[7],num1[8],num1[9]);	
			puts("");
		}
		else if(q == 13){
			for(u = 0 ; u < 6 ; u++){
				if(num2[0][u] == 5  || num2[0][u] == 15 || num2[0][u] == 25 ||
				   	num2[0][u] == 35 || num2[0][u] == 45 || num2[0][u] == 65 ||
				   	num2[0][u] == 75 || num2[0][u] == 85 || num2[0][u] == 95){
				   	str2[u] = star2;
				   	str3[u] = space3;
				}
				else if(num2[0][u] == 10  || num2[0][u] == 20 || num2[0][u] == 30 ||
				    	num2[0][u] == 40 || num2[0][u] == 50 || num2[0][u] == 60 ||
				    	num2[0][u] == 70 || num2[0][u] == 80 || num2[0][u] == 90){
						str2[u] = star3;
						str3[u] = space3;    	
				}
				else if(num2[0][u] == 11  || num2[0][u] == 22 || num2[0][u] == 33 ||
				    	num2[0][u] == 44 || num2[0][u] == 66 || num2[0][u] == 77 ||					    	
						num2[0][u] == 88 || num2[0][u] == 99){
						str2[u] = star3;
						str3[u] = star2;    	
				}
				else if(num2[0][u] == 55){
						str2[u] = star4;							
						str3[u] = star3;
				}
				else if(num2[0][u] == 0){
						str2[u] = space4;
						str3[u] = space3;
				}
				else{
					str2[u] = star1;
					str3[u] = space3;				
				}
			}
			printf(c[q],str2[0],str2[1],str2[2],str2[3],str2[4],str2[5]);
			puts("");
		}
		else if(q == 14){					        					   
			printf(c[q],str3[0],str3[1],str3[2],str3[3],str3[4],str3[5]);
			puts("");
		}
		else if(q == 15){
			if(num2[0][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[0][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);				
			puts("");
		}
		else if(q == 19){
			for(u = 0 ; u < 6 ; u++){
				if(num2[1][u] == 5  || num2[1][u] == 15 || num2[1][u] == 25 ||
				   num2[1][u] == 35 || num2[1][u] == 45 || num2[1][u] == 65 ||
				   num2[1][u] == 75 || num2[1][u] == 85 || num2[1][u] == 95){
				   str4[u] = star2;
				   str5[u] = space3;
				}
				else if(num2[1][u] == 10  || num2[1][u] == 20 || num2[1][u] == 30 ||
					    num2[1][u] == 40 || num2[1][u] == 50 || num2[1][u] == 60 ||
					    num2[1][u] == 70 || num2[1][u] == 80 || num2[1][u] == 90){
						str4[u] = star3; 
						str5[u] = space3;   	
				}
				else if(num2[1][u] == 11  || num2[1][u] == 22 || num2[1][u] == 33 ||
					    num2[1][u] == 44 || num2[1][u] == 66 || num2[1][u] == 77 ||
					    num2[1][u] == 88 || num2[1][u] == 99){
						str4[u] = star3;
						str5[u] = star2;  	
				}
				else if(num2[1][u] == 55){
						str4[u] = star4;
						str5[u] = star3;
				}
				else if(num2[1][u] == 0){
						str4[u] = space4;
						str5[u] = space3;	
				}				
				else{
						str4[u] = star1;
						str5[u] = space3;
				}
			} 
			printf(c[q],str4[0],str4[1],str4[2],str4[3],str4[4],str4[5],name[1],name[2],name[3]);
			puts("");
		}
		else if(q == 20){				        					   
			printf(c[q],str5[0],str5[1],str5[2],str5[3],str5[4],str5[5]);
			puts("");
		}				
        else if(q == 21){
            for(h = 1 ; h < 4 ; h++){
				if(putcard[h] == 5  || putcard[h] == 15 || putcard[h] == 25 ||
					putcard[h] == 35 || putcard[h] == 45 || putcard[h] == 65 ||
					putcard[h] == 75 || putcard[h] == 85 || putcard[h] == 95){
					str10[h] = star2;
					str11[h] = space3;
				}
				else if(putcard[h] == 10 || putcard[h] == 20 || putcard[h] == 30 ||
					    putcard[h] == 40 || putcard[h] == 50 || putcard[h] == 60 ||
					    putcard[h] == 70 || putcard[h] == 80 || putcard[h] == 90){
						str10[h] = star3;
						str11[h] = space3;    	
				}
				else if(putcard[h] == 11 || putcard[h] == 22 || putcard[h] == 33 ||
					    putcard[h] == 44 || putcard[h] == 66 || putcard[h] == 77 ||
					    putcard[h] == 88 || putcard[h] == 99){
					    str10[h] = star3;
						str11[h] = star2;    	
				}
				else if(putcard[h] == 55){
					str10[h] = star4;
					str11[h] = star3;
				}
				else{
					str10[h] = star1;
					str11[h] = space3;
				}
			}
			if(num2[1][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[1][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[1],str10[2],str10[3]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[1],str10[2],str10[3]);
			puts("");
		}
		else if(q == 22){
			printf(c[q],str11[1],str11[2],str11[3]);
			puts("");
		}
		else if(q == 23){
			printf(c[q],putcard[1],putcard[2],putcard[3]);
			puts("");
		}
		else if(q == 25){
				for(u = 0 ; u < 6 ; u++){
				if(num2[2][u] == 5  || num2[2][u] == 15 || num2[2][u] == 25 ||
				   num2[2][u] == 35 || num2[2][u] == 45 || num2[2][u] == 65 ||
				   num2[2][u] == 75 || num2[2][u] == 85 || num2[2][u] == 95){
				   str6[u] = star2;
				   str7[u] = space3;
				}
				else if(num2[2][u] == 10  || num2[2][u] == 20 || num2[2][u] == 30 ||
					    num2[2][u] == 40 || num2[2][u] == 50 || num2[2][u] == 60 ||
					    num2[2][u] == 70 || num2[2][u] == 80 || num2[2][u] == 90){
						str6[u] = star3; 
						str7[u] = space3;   	
				}
				else if(num2[2][u] == 11  || num2[2][u] == 22 || num2[2][u] == 33 ||
					    num2[2][u] == 44 || num2[2][u] == 66 || num2[2][u] == 77 ||
					    num2[2][u] == 88 || num2[2][u] == 99){
						str6[u] = star3;
						str7[u] = star2;  	
				}
				else if(num2[2][u] == 55){
						str6[u] = star4;
						str7[u] = star3;
				}
				else if(num2[2][u] == 0){
						str6[u] = space4;
						str7[u] = space3;	
				}				
				else{
						str6[u] = star1;
						str7[u] = space3;
				}
			} 
			printf(c[q],str6[0],str6[1],str6[2],str6[3],str6[4],str6[5]);
		    puts("");
		}
		else if(q == 26){
			printf(c[q],str7[0],str7[1],str7[2],str7[3],str7[4],str7[5]);
		    puts("");		
		}	
		else if(q == 27){
			if(num2[2][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[2][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
			puts("");
		}
		else if(q == 31){
			for(u = 0 ; u < 6 ; u++){
				if(num2[3][u] == 5  || num2[3][u] == 15 || num2[3][u] == 25 ||
			   	   num2[3][u] == 35 || num2[3][u] == 45 || num2[3][u] == 65 ||
			   	   num2[3][u] == 75 || num2[3][u] == 85 || num2[3][u] == 95){
			   	   str8[u] = star2;
			   	   str9[u] = space3;
				}
				else if(num2[3][u] == 10  || num2[3][u] == 20 || num2[3][u] == 30 ||
				   		num2[3][u] == 40 || num2[3][u] == 50 || num2[3][u] == 60 ||
				    	num2[3][u] == 70 || num2[3][u] == 80 || num2[3][u] == 90){
						str8[u] = star3; 
						str9[u] = space3;   	
				}
				else if(num2[3][u] == 11  || num2[3][u] == 22 || num2[3][u] == 33 ||
				    	num2[3][u] == 44 || num2[3][u] == 66 || num2[3][u] == 77 ||
				    	num2[3][u] == 88 || num2[3][u] == 99){
						str8[u] = star3;
						str9[u] = star2;  	
				}
				else if(num2[3][u] == 55){
						str8[u] = star4;
						str9[u] = star3;
				}
				else if(num2[3][u] == 0){
						str8[u] = space4;
						str9[u] = space3;
				}
				else{
					str8[u] = star1;
					str9[u] = space3;
				}
			} 
			printf(c[q],str8[0],str8[1],str8[2],str8[3],str8[4],str8[5]);
		    puts("");
		}
		else if(q == 32){
			printf(c[q],str9[0],str9[1],str9[2],str9[3],str9[4],str9[5]);
		    puts("");
		}
		else if(q == 33){
			if(num2[3][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[3][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
			puts("");
		}						
	    else
	    	printf("%s\n",c[q]);	
	}	
}
void GameScene4(int *num1,int num2[][6],int *playerscore,int *putcard,char *playername){
	int first;
	char *c[38];
	char star1[]="*";
	char star2[]="**";
	char star3[]="***";
	char star4[]="****";
	char space1[]=" ";
	char space2[]="  ";
	char space3[]="   ";
	char space4[]="    ";
	char *str[10],*str1[10];
	char *str2[6] = {"    ","    ","    ","    ","    ","    "};
	char *str3[6] = {"   ","   ","   ","   ","   ","   "};
	char *str4[6] = {"    ","    ","    ","    ","    ","    "};
	char *str5[6] = {"   ","   ","   ","   ","   ","   "};
	char *str6[6] = {"    ","    ","    ","    ","    ","    "};
	char *str7[6] = {"   ","   ","   ","   ","   ","   "};
	char *str8[6] = {"    ","    ","    ","    ","    ","    "};
	char *str9[6] = {"   ","   ","   ","   ","   ","   "};
	char *str10[4] = {"    ","    ","    ","    "};
	char *str11[4] = {"   ","   ","   ","   "};
	size_t i,r,h,q,u;			
	c[0] = " ____________________________________________________________________________ ";
	c[1] = "|                                  %10s������: %2d / James������: %2d    |";
	c[2] = "|      �ڪ���P                         Curry������: %2d / Judge������: %2d    |";
	c[3] = "|____________________________________________________________________________|";
	c[4] = "| %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s |      |";
    c[5] = "| %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  |      |";
    c[6] = "| %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  |      |";
    c[7] = "|      |      |      |      |      |      |      |      |      |      |      |";
    c[8] = "|______|______|______|______|______|______|______|______|______|______|      |";
	c[9] = "|____________________________________________________________________________|";
	c[10] = "|                           �п�@�i�P���X                                   |";
	c[11] = "|____________________________________________________________________________|";
	c[12] = "|__________________________________   ______                                 |";
	c[13] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[14] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[15] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[16] = "|      |      |      |      |      | |      |                                |";
	c[17] = "|______|______|______|______|______| |______|                                |";
	c[18] = "|__________________________________   ______                                 |";  
	c[19] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                   %5s  %5s |";
	c[20] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                  _____________ |";
	c[21] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                 | %4s | %4s ||";
	c[22] = "|      |      |      |      |      | |      |                 | %3s  | %3s  ||";
	c[23] = "|______|______|______|______|______| |______|                 | %3d  | %3d  ||";
	c[24] = "|__________________________________   ______                  |      |      ||";
	c[25] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                 |______|______||";
	c[26] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[27] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[28] = "|      |      |      |      |      | |      |                                |";
	c[29] = "|______|______|______|______|______| |______|                                |";
	c[30] = "|__________________________________   ______                                 |";
	c[31] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[32] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[33] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[34] = "|      |      |      |      |      | |      |                                |";
	c[35] = "|______|______|______|______|______| |______|                                |";
	c[36] = "|                                                                            |";
	c[37] = "|____________________________________________________________________________|";
	for(q = 0 ; q <38 ; q++){
		if(q == 1){
			printf(c[q],playername,playerscore[0],playerscore[1]);
			puts("");
		}
		else if(q == 2){
			printf(c[q],playerscore[2],playerscore[3]);
			puts("");
		}
		else if(q == 4){
			for(r = 0 ; r < 10 ; r++){
				if(num1[r] == 5  || num1[r] == 15 || num1[r] == 25 ||
					num1[r] == 35 || num1[r] == 45 || num1[r] == 65 ||
					num1[r] == 75 || num1[r] == 85 || num1[r] == 95){
					str[r] = star2;
					str1[r] = space3;
				}
				else if(num1[r] == 10  || num1[r] == 20 || num1[r] == 30 ||
				        num1[r] == 40 || num1[r] == 50 || num1[r] == 60 ||
				        num1[r] == 70 || num1[r] == 80 || num1[r] == 90){
				        str[r] = star3;
						str1[r] = space3;    	
				}
				else if(num1[r] == 11  || num1[r] == 22 || num1[r] == 33 ||
				        num1[r] == 44 || num1[r] == 66 || num1[r] == 77 ||
				        num1[r] == 88 || num1[r] == 99){
					    str[r] = star3;
						str1[r] = star2;    	
				}
				else if(num1[r] == 55){
						str[r] = star4;
						str1[r] = star3;
				}
				else if(num1[r] == 0){
						str[r] = space4;
						str1[r] = space3;
				} 
				else{
					str[r] = star1;
					str1[r] = space3;
				}
			}
			printf(c[q],str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7]
			      ,str[8],str[9]);	
			puts("");	
		}
		else if(q == 5){				
			printf(c[q],str1[0],str1[1],str1[2],str1[3],str1[4],str1[5],str1[6],str1[7]
					,str1[8],str1[9]);
			puts("");				    
		}			
		else if(q == 6){
			if(num1[9] == 0){
				first = 1;
				i = 9;
				for(r = 8 ; r >= 0 ; r--){
					if(num1[r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 9 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num1[0],num1[1],num1[2]
					 	  		,num1[3],num1[4],num1[5],num1[6]
				      	  		,num1[7],num1[8],num1[9]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num1[0],num1[1],num1[2]
					   ,num1[3],num1[4],num1[5],num1[6]
				       ,num1[7],num1[8],num1[9]);	
			puts("");
		}
		else if(q == 13){
			for(u = 0 ; u < 6 ; u++){
				if(num2[0][u] == 5  || num2[0][u] == 15 || num2[0][u] == 25 ||
				   	num2[0][u] == 35 || num2[0][u] == 45 || num2[0][u] == 65 ||
				   	num2[0][u] == 75 || num2[0][u] == 85 || num2[0][u] == 95){
				   	str2[u] = star2;
				   	str3[u] = space3;
				}
				else if(num2[0][u] == 10  || num2[0][u] == 20 || num2[0][u] == 30 ||
				    	num2[0][u] == 40 || num2[0][u] == 50 || num2[0][u] == 60 ||
				    	num2[0][u] == 70 || num2[0][u] == 80 || num2[0][u] == 90){
						str2[u] = star3;
						str3[u] = space3;    	
				}
				else if(num2[0][u] == 11  || num2[0][u] == 22 || num2[0][u] == 33 ||
				    	num2[0][u] == 44 || num2[0][u] == 66 || num2[0][u] == 77 ||					    	
						num2[0][u] == 88 || num2[0][u] == 99){
						str2[u] = star3;
						str3[u] = star2;    	
				}
				else if(num2[0][u] == 55){
						str2[u] = star4;							
						str3[u] = star3;
				}
				else if(num2[0][u] == 0){
						str2[u] = space4;
						str3[u] = space3;
				}
				else{
					str2[u] = star1;
					str3[u] = space3;				
				}
			}
			printf(c[q],str2[0],str2[1],str2[2],str2[3],str2[4],str2[5]);
			puts("");
		}
		else if(q == 14){					        					   
			printf(c[q],str3[0],str3[1],str3[2],str3[3],str3[4],str3[5]);
			puts("");
		}
		else if(q == 15){
			if(num2[0][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[0][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);				
			puts("");
		}
		else if(q == 19){
			for(u = 0 ; u < 6 ; u++){
				if(num2[1][u] == 5  || num2[1][u] == 15 || num2[1][u] == 25 ||
				   num2[1][u] == 35 || num2[1][u] == 45 || num2[1][u] == 65 ||
				   num2[1][u] == 75 || num2[1][u] == 85 || num2[1][u] == 95){
				   str4[u] = star2;
				   str5[u] = space3;
				}
				else if(num2[1][u] == 10  || num2[1][u] == 20 || num2[1][u] == 30 ||
					    num2[1][u] == 40 || num2[1][u] == 50 || num2[1][u] == 60 ||
					    num2[1][u] == 70 || num2[1][u] == 80 || num2[1][u] == 90){
						str4[u] = star3; 
						str5[u] = space3;   	
				}
				else if(num2[1][u] == 11  || num2[1][u] == 22 || num2[1][u] == 33 ||
					    num2[1][u] == 44 || num2[1][u] == 66 || num2[1][u] == 77 ||
					    num2[1][u] == 88 || num2[1][u] == 99){
						str4[u] = star3;
						str5[u] = star2;  	
				}
				else if(num2[1][u] == 55){
						str4[u] = star4;
						str5[u] = star3;
				}
				else if(num2[1][u] == 0){
						str4[u] = space4;
						str5[u] = space3;	
				}				
				else{
						str4[u] = star1;
						str5[u] = space3;
				}
			} 
			printf(c[q],str4[0],str4[1],str4[2],str4[3],str4[4],str4[5],name[2],name[3]);
			puts("");
		}
		else if(q == 20){				        					   
			printf(c[q],str5[0],str5[1],str5[2],str5[3],str5[4],str5[5]);
			puts("");
		}				
        else if(q == 21){
            for(h = 2 ; h < 4 ; h++){
				if(putcard[h] == 5  || putcard[h] == 15 || putcard[h] == 25 ||
					putcard[h] == 35 || putcard[h] == 45 || putcard[h] == 65 ||
					putcard[h] == 75 || putcard[h] == 85 || putcard[h] == 95){
					str10[h] = star2;
					str11[h] = space3;
				}
				else if(putcard[h] == 10 || putcard[h] == 20 || putcard[h] == 30 ||
					    putcard[h] == 40 || putcard[h] == 50 || putcard[h] == 60 ||
					    putcard[h] == 70 || putcard[h] == 80 || putcard[h] == 90){
						str10[h] = star3;
						str11[h] = space3;    	
				}
				else if(putcard[h] == 11 || putcard[h] == 22 || putcard[h] == 33 ||
					    putcard[h] == 44 || putcard[h] == 66 || putcard[h] == 77 ||
					    putcard[h] == 88 || putcard[h] == 99){
					    str10[h] = star3;
						str11[h] = star2;    	
				}
				else if(putcard[h] == 55){
					str10[h] = star4;
					str11[h] = star3;
				}
				else{
					str10[h] = star1;
					str11[h] = space3;
				}
			}
			if(num2[1][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[1][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[2],str10[3]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[2],str10[3]);
			puts("");
		}
		else if(q == 22){
			printf(c[q],str11[2],str11[3]);
			puts("");
		}
		else if(q == 23){
			printf(c[q],putcard[2],putcard[3]);
			puts("");
		}
		else if(q == 25){
				for(u = 0 ; u < 6 ; u++){
				if(num2[2][u] == 5  || num2[2][u] == 15 || num2[2][u] == 25 ||
				   num2[2][u] == 35 || num2[2][u] == 45 || num2[2][u] == 65 ||
				   num2[2][u] == 75 || num2[2][u] == 85 || num2[2][u] == 95){
				   str6[u] = star2;
				   str7[u] = space3;
				}
				else if(num2[2][u] == 10  || num2[2][u] == 20 || num2[2][u] == 30 ||
					    num2[2][u] == 40 || num2[2][u] == 50 || num2[2][u] == 60 ||
					    num2[2][u] == 70 || num2[2][u] == 80 || num2[2][u] == 90){
						str6[u] = star3; 
						str7[u] = space3;   	
				}
				else if(num2[2][u] == 11  || num2[2][u] == 22 || num2[2][u] == 33 ||
					    num2[2][u] == 44 || num2[2][u] == 66 || num2[2][u] == 77 ||
					    num2[2][u] == 88 || num2[2][u] == 99){
						str6[u] = star3;
						str7[u] = star2;  	
				}
				else if(num2[2][u] == 55){
						str6[u] = star4;
						str7[u] = star3;
				}
				else if(num2[2][u] == 0){
						str6[u] = space4;
						str7[u] = space3;	
				}				
				else{
						str6[u] = star1;
						str7[u] = space3;
				}
			} 
			printf(c[q],str6[0],str6[1],str6[2],str6[3],str6[4],str6[5]);
		    puts("");
		}
		else if(q == 26){
			printf(c[q],str7[0],str7[1],str7[2],str7[3],str7[4],str7[5]);
		    puts("");		
		}	
		else if(q == 27){
			if(num2[2][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[2][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
			puts("");
		}
		else if(q == 31){
			for(u = 0 ; u < 6 ; u++){
				if(num2[3][u] == 5  || num2[3][u] == 15 || num2[3][u] == 25 ||
			   	   num2[3][u] == 35 || num2[3][u] == 45 || num2[3][u] == 65 ||
			   	   num2[3][u] == 75 || num2[3][u] == 85 || num2[3][u] == 95){
			   	   str8[u] = star2;
			   	   str9[u] = space3;
				}
				else if(num2[3][u] == 10  || num2[3][u] == 20 || num2[3][u] == 30 ||
				   		num2[3][u] == 40 || num2[3][u] == 50 || num2[3][u] == 60 ||
				    	num2[3][u] == 70 || num2[3][u] == 80 || num2[3][u] == 90){
						str8[u] = star3; 
						str9[u] = space3;   	
				}
				else if(num2[3][u] == 11  || num2[3][u] == 22 || num2[3][u] == 33 ||
				    	num2[3][u] == 44 || num2[3][u] == 66 || num2[3][u] == 77 ||
				    	num2[3][u] == 88 || num2[3][u] == 99){
						str8[u] = star3;
						str9[u] = star2;  	
				}
				else if(num2[3][u] == 55){
						str8[u] = star4;
						str9[u] = star3;
				}
				else if(num2[3][u] == 0){
						str8[u] = space4;
						str9[u] = space3;
				}
				else{
					str8[u] = star1;
					str9[u] = space3;
				}
			} 
			printf(c[q],str8[0],str8[1],str8[2],str8[3],str8[4],str8[5]);
		    puts("");
		}
		else if(q == 32){
			printf(c[q],str9[0],str9[1],str9[2],str9[3],str9[4],str9[5]);
		    puts("");
		}
		else if(q == 33){
			if(num2[3][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[3][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
			puts("");
		}						
	    else
	    	printf("%s\n",c[q]);	
	}
}
void GameScene5(int *num1,int num2[][6],int *playerscore,int *putcard,char *playername){
	int first;
	char *c[38];
	char star1[]="*";
	char star2[]="**";
	char star3[]="***";
	char star4[]="****";
	char space1[]=" ";
	char space2[]="  ";
	char space3[]="   ";
	char space4[]="    ";
	char *str[10],*str1[10];
	char *str2[6] = {"    ","    ","    ","    ","    ","    "};
	char *str3[6] = {"   ","   ","   ","   ","   ","   "};
	char *str4[6] = {"    ","    ","    ","    ","    ","    "};
	char *str5[6] = {"   ","   ","   ","   ","   ","   "};
	char *str6[6] = {"    ","    ","    ","    ","    ","    "};
	char *str7[6] = {"   ","   ","   ","   ","   ","   "};
	char *str8[6] = {"    ","    ","    ","    ","    ","    "};
	char *str9[6] = {"   ","   ","   ","   ","   ","   "};
	char *str10[4] = {"    ","    ","    ","    "};
	char *str11[4] = {"   ","   ","   ","   "};
	size_t i,r,h,q,u;			
	c[0] = " ____________________________________________________________________________ ";
	c[1] = "|                                  %10s������: %2d / James������: %2d    |";
	c[2] = "|      �ڪ���P                         Curry������: %2d / Judge������: %2d    |";
	c[3] = "|____________________________________________________________________________|";
	c[4] = "| %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s | %4s |      |";
    c[5] = "| %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  | %3s  |      |";
    c[6] = "| %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  | %3d  |      |";
    c[7] = "|      |      |      |      |      |      |      |      |      |      |      |";
    c[8] = "|______|______|______|______|______|______|______|______|______|______|      |";
	c[9] = "|____________________________________________________________________________|";
	c[10] = "|                           �п�@�i�P���X                                   |";
	c[11] = "|____________________________________________________________________________|";
	c[12] = "|__________________________________   ______                                 |";
	c[13] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[14] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[15] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[16] = "|      |      |      |      |      | |      |                                |";
	c[17] = "|______|______|______|______|______| |______|                                |";
	c[18] = "|__________________________________   ______                                 |";  
	c[19] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                          %5s |";
	c[20] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                         ______ |";
	c[21] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                        | %4s ||";
	c[22] = "|      |      |      |      |      | |      |                        | %3s  ||";
	c[23] = "|______|______|______|______|______| |______|                        | %3d  ||";
	c[24] = "|__________________________________   ______                         |      ||";
	c[25] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                        |______||";
	c[26] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[27] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[28] = "|      |      |      |      |      | |      |                                |";
	c[29] = "|______|______|______|______|______| |______|                                |";
	c[30] = "|__________________________________   ______                                 |";
	c[31] = "| %4s | %4s | %4s | %4s | %4s | | %4s |                                |";
	c[32] = "| %3s  | %3s  | %3s  | %3s  | %3s  | | %3s  |                                |";
	c[33] = "| %3d  | %3d  | %3d  | %3d  | %3d  | | %3d  |                                |";
	c[34] = "|      |      |      |      |      | |      |                                |";
	c[35] = "|______|______|______|______|______| |______|                                |";
	c[36] = "|                                                                            |";
	c[37] = "|____________________________________________________________________________|";
	for(q = 0 ; q <38 ; q++){
		if(q == 1){
			printf(c[q],playername,playerscore[0],playerscore[1]);
			puts("");
		}
		else if(q == 2){
			printf(c[q],playerscore[2],playerscore[3]);
			puts("");
		}
		else if(q == 4){
			for(r = 0 ; r < 10 ; r++){
				if(num1[r] == 5  || num1[r] == 15 || num1[r] == 25 ||
					num1[r] == 35 || num1[r] == 45 || num1[r] == 65 ||
					num1[r] == 75 || num1[r] == 85 || num1[r] == 95){
					str[r] = star2;
					str1[r] = space3;
				}
				else if(num1[r] == 10  || num1[r] == 20 || num1[r] == 30 ||
				        num1[r] == 40 || num1[r] == 50 || num1[r] == 60 ||
				        num1[r] == 70 || num1[r] == 80 || num1[r] == 90){
				        str[r] = star3;
						str1[r] = space3;    	
				}
				else if(num1[r] == 11  || num1[r] == 22 || num1[r] == 33 ||
				        num1[r] == 44 || num1[r] == 66 || num1[r] == 77 ||
				        num1[r] == 88 || num1[r] == 99){
					    str[r] = star3;
						str1[r] = star2;    	
				}
				else if(num1[r] == 55){
						str[r] = star4;
						str1[r] = star3;
				}
				else if(num1[r] == 0){
						str[r] = space4;
						str1[r] = space3;
				} 
				else{
					str[r] = star1;
					str1[r] = space3;
				}
			}
			printf(c[q],str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7]
			      ,str[8],str[9]);	
			puts("");	
		}
		else if(q == 5){				
			printf(c[q],str1[0],str1[1],str1[2],str1[3],str1[4],str1[5],str1[6],str1[7]
					,str1[8],str1[9]);
			puts("");				    
		}			
		else if(q == 6){
			if(num1[9] == 0){
				first = 1;
				i = 9;
				for(r = 8 ; r >= 0 ; r--){
					if(num1[r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 9 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num1[0],num1[1],num1[2]
					 	  		,num1[3],num1[4],num1[5],num1[6]
				      	  		,num1[7],num1[8],num1[9]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num1[0],num1[1],num1[2]
					   ,num1[3],num1[4],num1[5],num1[6]
				       ,num1[7],num1[8],num1[9]);	
			puts("");
		}
		else if(q == 13){
			for(u = 0 ; u < 6 ; u++){
				if(num2[0][u] == 5  || num2[0][u] == 15 || num2[0][u] == 25 ||
				   	num2[0][u] == 35 || num2[0][u] == 45 || num2[0][u] == 65 ||
				   	num2[0][u] == 75 || num2[0][u] == 85 || num2[0][u] == 95){
				   	str2[u] = star2;
				   	str3[u] = space3;
				}
				else if(num2[0][u] == 10  || num2[0][u] == 20 || num2[0][u] == 30 ||
				    	num2[0][u] == 40 || num2[0][u] == 50 || num2[0][u] == 60 ||
				    	num2[0][u] == 70 || num2[0][u] == 80 || num2[0][u] == 90){
						str2[u] = star3;
						str3[u] = space3;    	
				}
				else if(num2[0][u] == 11  || num2[0][u] == 22 || num2[0][u] == 33 ||
				    	num2[0][u] == 44 || num2[0][u] == 66 || num2[0][u] == 77 ||					    	
						num2[0][u] == 88 || num2[0][u] == 99){
						str2[u] = star3;
						str3[u] = star2;    	
				}
				else if(num2[0][u] == 55){
						str2[u] = star4;							
						str3[u] = star3;
				}
				else if(num2[0][u] == 0){
						str2[u] = space4;
						str3[u] = space3;
				}
				else{
					str2[u] = star1;
					str3[u] = space3;				
				}
			}
			printf(c[q],str2[0],str2[1],str2[2],str2[3],str2[4],str2[5]);
			puts("");
		}
		else if(q == 14){					        					   
			printf(c[q],str3[0],str3[1],str3[2],str3[3],str3[4],str3[5]);
			puts("");
		}
		else if(q == 15){
			if(num2[0][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[0][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else
				printf(c[q],num2[0][0],num2[0][1],num2[0][2],num2[0][3],num2[0][4],num2[0][5]);				
			puts("");
		}
		else if(q == 19){
			for(u = 0 ; u < 6 ; u++){
				if(num2[1][u] == 5  || num2[1][u] == 15 || num2[1][u] == 25 ||
				   num2[1][u] == 35 || num2[1][u] == 45 || num2[1][u] == 65 ||
				   num2[1][u] == 75 || num2[1][u] == 85 || num2[1][u] == 95){
				   str4[u] = star2;
				   str5[u] = space3;
				}
				else if(num2[1][u] == 10  || num2[1][u] == 20 || num2[1][u] == 30 ||
					    num2[1][u] == 40 || num2[1][u] == 50 || num2[1][u] == 60 ||
					    num2[1][u] == 70 || num2[1][u] == 80 || num2[1][u] == 90){
						str4[u] = star3; 
						str5[u] = space3;   	
				}
				else if(num2[1][u] == 11  || num2[1][u] == 22 || num2[1][u] == 33 ||
					    num2[1][u] == 44 || num2[1][u] == 66 || num2[1][u] == 77 ||
					    num2[1][u] == 88 || num2[1][u] == 99){
						str4[u] = star3;
						str5[u] = star2;  	
				}
				else if(num2[1][u] == 55){
						str4[u] = star4;
						str5[u] = star3;
				}
				else if(num2[1][u] == 0){
						str4[u] = space4;
						str5[u] = space3;	
				}				
				else{
						str4[u] = star1;
						str5[u] = space3;
				}
			} 
			printf(c[q],str4[0],str4[1],str4[2],str4[3],str4[4],str4[5],name[3]);
			puts("");
		}
		else if(q == 20){				        					   
			printf(c[q],str5[0],str5[1],str5[2],str5[3],str5[4],str5[5]);
			puts("");
		}				
        else if(q == 21){
            for(h = 3 ; h < 4 ; h++){
				if(putcard[h] == 5  || putcard[h] == 15 || putcard[h] == 25 ||
					putcard[h] == 35 || putcard[h] == 45 || putcard[h] == 65 ||
					putcard[h] == 75 || putcard[h] == 85 || putcard[h] == 95){
					str10[h] = star2;
					str11[h] = space3;
				}
				else if(putcard[h] == 10 || putcard[h] == 20 || putcard[h] == 30 ||
					    putcard[h] == 40 || putcard[h] == 50 || putcard[h] == 60 ||
					    putcard[h] == 70 || putcard[h] == 80 || putcard[h] == 90){
						str10[h] = star3;
						str11[h] = space3;    	
				}
				else if(putcard[h] == 11 || putcard[h] == 22 || putcard[h] == 33 ||
					    putcard[h] == 44 || putcard[h] == 66 || putcard[h] == 77 ||
					    putcard[h] == 88 || putcard[h] == 99){
					    str10[h] = star3;
						str11[h] = star2;    	
				}
				else if(putcard[h] == 55){
					str10[h] = star4;
					str11[h] = star3;
				}
				else{
					str10[h] = star1;
					str11[h] = space3;
				}
			}
			if(num2[1][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[1][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[3]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[1][0],num2[1][1],num2[1][2],num2[1][3],num2[1][4],num2[1][5],str10[3]);
			puts("");
		}
		else if(q == 22){
			printf(c[q],str11[3]);
			puts("");
		}
		else if(q == 23){
			printf(c[q],putcard[3]);
			puts("");
		}
		else if(q == 25){
				for(u = 0 ; u < 6 ; u++){
				if(num2[2][u] == 5  || num2[2][u] == 15 || num2[2][u] == 25 ||
				   num2[2][u] == 35 || num2[2][u] == 45 || num2[2][u] == 65 ||
				   num2[2][u] == 75 || num2[2][u] == 85 || num2[2][u] == 95){
				   str6[u] = star2;
				   str7[u] = space3;
				}
				else if(num2[2][u] == 10  || num2[2][u] == 20 || num2[2][u] == 30 ||
					    num2[2][u] == 40 || num2[2][u] == 50 || num2[2][u] == 60 ||
					    num2[2][u] == 70 || num2[2][u] == 80 || num2[2][u] == 90){
						str6[u] = star3; 
						str7[u] = space3;   	
				}
				else if(num2[2][u] == 11  || num2[2][u] == 22 || num2[2][u] == 33 ||
					    num2[2][u] == 44 || num2[2][u] == 66 || num2[2][u] == 77 ||
					    num2[2][u] == 88 || num2[2][u] == 99){
						str6[u] = star3;
						str7[u] = star2;  	
				}
				else if(num2[2][u] == 55){
						str6[u] = star4;
						str7[u] = star3;
				}
				else if(num2[2][u] == 0){
						str6[u] = space4;
						str7[u] = space3;	
				}				
				else{
						str6[u] = star1;
						str7[u] = space3;
				}
			} 
			printf(c[q],str6[0],str6[1],str6[2],str6[3],str6[4],str6[5]);
		    puts("");
		}
		else if(q == 26){
			printf(c[q],str7[0],str7[1],str7[2],str7[3],str7[4],str7[5]);
		    puts("");		
		}	
		else if(q == 27){
			if(num2[2][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[2][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[2][0],num2[2][1],num2[2][2],num2[2][3],num2[2][4],num2[2][5]);
			puts("");
		}
		else if(q == 31){
			for(u = 0 ; u < 6 ; u++){
				if(num2[3][u] == 5  || num2[3][u] == 15 || num2[3][u] == 25 ||
			   	   num2[3][u] == 35 || num2[3][u] == 45 || num2[3][u] == 65 ||
			   	   num2[3][u] == 75 || num2[3][u] == 85 || num2[3][u] == 95){
			   	   str8[u] = star2;
			   	   str9[u] = space3;
				}
				else if(num2[3][u] == 10  || num2[3][u] == 20 || num2[3][u] == 30 ||
				   		num2[3][u] == 40 || num2[3][u] == 50 || num2[3][u] == 60 ||
				    	num2[3][u] == 70 || num2[3][u] == 80 || num2[3][u] == 90){
						str8[u] = star3; 
						str9[u] = space3;   	
				}
				else if(num2[3][u] == 11  || num2[3][u] == 22 || num2[3][u] == 33 ||
				    	num2[3][u] == 44 || num2[3][u] == 66 || num2[3][u] == 77 ||
				    	num2[3][u] == 88 || num2[3][u] == 99){
						str8[u] = star3;
						str9[u] = star2;  	
				}
				else if(num2[3][u] == 55){
						str8[u] = star4;
						str9[u] = star3;
				}
				else if(num2[3][u] == 0){
						str8[u] = space4;
						str9[u] = space3;
				}
				else{
					str8[u] = star1;
					str9[u] = space3;
				}
			} 
			printf(c[q],str8[0],str8[1],str8[2],str8[3],str8[4],str8[5]);
		    puts("");
		}
		else if(q == 32){
			printf(c[q],str9[0],str9[1],str9[2],str9[3],str9[4],str9[5]);
		    puts("");
		}
		else if(q == 33){
			if(num2[3][5] == 0){
				first = 1;
				i = 5;
				for(r = 4 ; r >= 0 ; r--){
					if(num2[3][r] == 0){
						i = r;
					}
					else 
						break;
				}
				for(r = 5 ; r >= i ; r--){
			    	if(first == 1){
						printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
				    	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b   ");
				    	first++;
					}
					else if(first == 2){
						printf("\b\b\b\b\b\b\b\b\b\b\b\b   ");
						first++;
					}
					else{
				    	printf("\b\b\b\b\b\b\b\b\b\b   ");
					}						
				}
			}
			else				
				printf(c[q],num2[3][0],num2[3][1],num2[3][2],num2[3][3],num2[3][4],num2[3][5]);
			puts("");
		}						
	    else
	    	printf("%s\n",c[q]);	
	}
}
void StartScene(){
	char *a[21];
	int i,j;

	a[0] = "                _________________________________________________   ";
	a[1] = "               �x                                                �x "; 
	a[2] = "               �x          *      **** ******   ***********      �x ";
	a[3] = "               �x      *   *             *           *           �x "; 
	a[4] = "               �x     *    *      **** ******        *           �x ";
	a[5] = "               �x    **********   *  * *    *        *           �x ";
	a[6] = "               �x   *     *       *  * ******        *           �x "; 
	a[7] = "               �x  *      *       *  * *    *   ***********      �x ";
	a[8] = "               �x     *********   *  * ******        *           �x ";
	a[9] = "               �x         *       **** *    *        *           �x ";
	a[10] = "               �x         *       *  * ******        *           �x ";
	a[11] = "               �x         *        **   *  *         *           �x ";
	a[12] = "               �x         *       **** *    *   ***********      �x ";
	a[13] = "               �x                                                �x ";
	a[14] = "               �x             Welcome to the game!               �x ";
	a[15] = "               �x                                                �x "; 
	a[16] = "               �x          Press 1 to enter the game.            �x ";
	a[17] = "               �x       Press 2 to watch the explanation.        �x ";
	a[18] = "               �x            Pess 3 to return here.              �x ";
	a[19] = "               �x                                                �x ";
	a[20] = "               �|------------------------------------------------�} ";
	for(i = 1 ; i < 4 ; i++)
		putchar('\n');
	for(j = 0 ; j <21 ; j++)
		printf("%s\n",a[j]);
}
void Count(){
	FILE *hPtr;
	char str[150];
	
	hPtr = fopen("Count.txt","r");
	
	printf("�H�U���C���I�ƪ����t:\n");
	
	if (!hPtr) {
        printf("�ɮ׶}�ҥ���...\n");
        exit(1);
    }
    while (fgets(str, 150, hPtr) != NULL) {
        printf(str);
    }
    printf("\n");	
}

void BubbleSort2(int *array){
	int pass;
	int hold;
	size_t i;
	
	for(pass = 1 ; pass < 4 ; pass++)
		for(i = 0; i < 3; i++)
			if(array[i] > array[i+1]){
				hold = array[i];
				array[i] = array[i+1];
				array[i+1] = hold;		
		}
}
void BubbleSort3(int *array){
		int pass;
	int hold;
	size_t i;
	
	for(pass = 1 ; pass < 4 ; pass++)
		for(i = 0; i < 3; i++)
			if(array[i] < array[i+1]){
				hold = array[i];
				array[i] = array[i+1];
				array[i+1] = hold;		
		}
}
void BubbleSort(int *array){
	int pass;
	int hold;
	size_t i;
	
	for(pass = 1 ; pass < 10 ; pass++)
		for(i = 0; i < 9; i++)
			if(array[i] > array[i+1]){
				hold = array[i];
				array[i] = array[i+1];
				array[i+1] = hold;		
		}
}
void shuffle(int *arr, int n, int low, int up){
	int i, pos1, pos2, tmp;
	int sum_poker = up - low + 1;
	
	int *Poker = (int*) malloc(sum_poker * sizeof(int) );
	for(i = 0; i < sum_poker; i++)
		Poker[i] = i + low;
	
	//�}�l�~�P	
	for(i = 0; i < sum_poker; i++){
		pos1 = (int)(rand() / (RAND_MAX+1.0) * sum_poker);
        pos2 = (int)(rand() / (RAND_MAX+1.0) * sum_poker);
        
        tmp = Poker[pos1];
        Poker[pos1] = Poker[pos2];
		Poker[pos2] = tmp;
	}
	
	//�~���P�A�e��n�i��arr
	for(i = 0; i < n; i++)
		arr[i] = Poker[i];
	free(Poker); 
}
int BotPlayCard(int *bot,int table[][6],int handcard, int first){	// (bot[], table[])
	int m,n,z;
	int less_row;		//�ĴX"�C"�ֵ̤P 
	int tmp_show,tmp_table;		// �Ȧs�A����P�A�Ȧs�i���W�Ҧb�̫᪺���|�i�P 
	int test = 1;
	int test2 = 0;
	int differ = 103;		//�n�X���P�P���b��e���P���Ʀr�t�ȡA�b table[tmp_row][tmp_col] �P tmp_bot_play ���̤p�t�� 
	int tmp_col , tmp_row;		//�P�ĴX�C��differ, �� 
	int not0_col, not0_row;		//�Ȯɦs�ĴX�C�B��O�̫�@�i�P 
	int tmp_bot_play;			//���i��P��differ 
	int play = 0;    //�X���i�P 
	int tmp_m;
	int tmp_handcard;
	int i, j;
	
	if(first == 0){
		//��̤p�t��
		for(i = 0; i < 4; i++){
			if(table[i][4] == 0){
				for(j = 3; j>=0; j--){
					if(table[i][j] != 0){
						not0_col = i;
						not0_row = j;
						break;
					}
				}
				for(m = 0; m<10; m++){	
					if(bot[m] > table[not0_col][not0_row]){
						if(bot[m] - table[not0_col][not0_row] < differ){
							differ = bot[m] - table[not0_col][not0_row];
							tmp_col = not0_col;
							tmp_row = not0_row;
							tmp_m = m;
							tmp_bot_play = bot[tmp_m];
							test = 0;
						}
						break;
					} 
				}
			}	
		}
		
		if(test == 0){
			if(tmp_row == 0){		//��=0 �u���@�i�P 
				play = tmp_bot_play;
			}
			else if(tmp_row == 1){
				play = tmp_bot_play;
			}
			else if(tmp_row == 2){
				if(differ <= 15){
					play = tmp_bot_play;
				}
			}
			else if(tmp_row == 3){
				if(differ < 3){
					play = tmp_bot_play;
				}
			}
			else
				test = 1;
		}
	}
		
	
	if(test == 1){
		while(test2 == 0){
			for(i = 0 ; i < 4 ; i++){	//1.�P��=4�����L�t��2�H����						
				if(table[i][3] != 0){					//�ĥ|�i!=0�� 
					for(j = 0 ; j < handcard ; j++){				
						if(table[i][4] == 0){			//�Ĥ��i=0�� 
							if(bot[j] > table[i][3] && bot[j] - table[i][3] < 2){
								play = bot[j];
								test2++;
								break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0 ; i < 4 ; i++){	//2.�P��=4�����L�t��3�H����						
				if(table[i][3] != 0){					//�ĥ|�i!=0�� 
					for(j = 0 ; j < handcard ; j++){				
						if(table[i][4] == 0){			//�Ĥ��i=0�� 
							if(bot[j] > table[i][3] && bot[j] - table[i][3] < 3){
								play = bot[j];
								test2++;
								break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//3.�P��=3�����L�t��3�H����							
				if(table[i][2] != 0){				
					for(j = 0; j < handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 3){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//4.�P��=3�����L�t��5�H����							
				if(table[i][2] != 0){				
					for(j = 0; j < handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 5){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//5.��P��=2�����L�t��5�H����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][1] && bot[j] - table[i][1] < 5){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//6.��P��=2�����L�t��10�H����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][1] && bot[j] - table[i][1] < 10){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//7.��P��=1�����L�t��5�H����					
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 5){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//8.��P��=1�����L�t��10�H����					
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 10){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//9.��P��=1�����L�t��15�H����					
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 15){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//10.��P��=1�����L�t��20�H����					
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 20){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//11.��P��=1�����L�t��25�H����
				
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 25){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//12.�P�ƬO1����	 				
				for(j = 0; j<handcard; j++){				
					if(table[i][1] == 0){		
						if(bot[j] > table[i][0]){
							play = bot[j];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;	
			}
			if(test2 != 0)
				break;

			for(i = 0; i<4; i++){	//13.��P��=2�����L�t��15�H����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][1] && bot[j] - table[i][1] < 15){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//14.�P��=3�����L�t��8�H����					
				if(table[i][2] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 8){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//15.�P��=3�����L�t��12�H����				
				if(table[i][2] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 12){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//16.��P��=2�����L�t��20�H����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][1] && bot[j] - table[i][1] < 20){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//17.�P��=2����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][0]){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//18.�P�ƬO3�t��<14					
				if(table[i][2] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 14){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//19.�P�ƬO3�t��<17					
				if(table[i][2] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 17){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;	
				
			for(i = 0; i<4; i++){	//20.�P�ƬO3�t��<20					
				if(table[i][2] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 20){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//21.��P��=4�����L�t��5�H����					
				if(table[i][3] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][4] == 0){		
							if(bot[j] > table[i][1] && bot[j] - table[i][1] < 20){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			
			if(test2 == 0)
				break;	
		}
	}



	if(play == 0){		//22.�p�G�̤j��P - table[i][3] < 6						
		for(i = 0; i<4; i++){
			if(table[i][3] != 0 && table[i][4] == 0){
				if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] < 6){
					play = bot[handcard -1];
					break;
				}
			}
		}
	}
	
	if(play == 0){		//23.�p�G�̤j��P - table[i][3] < 10						
		for(i = 0; i<4; i++){
			if(table[i][3] != 0 && table[i][4] == 0){
				if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] < 10){
					play = bot[handcard -1];
					break;
				}
			}
		}
	}
	
	if(play == 0){		//24.�p�G�̤j��P - table[i][3] > 35						
		for(i = 0; i<4; i++){
			if(table[i][3] != 0 && table[i][4] == 0){
				if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] > 35){
					play = bot[handcard -1];
					break;
				}
			}
		}
	}
	
	if(play == 0){		//25.�p�G�̤j��P - table[i][3] > 25						
		for(i = 0; i<4; i++){
			if(table[i][3] != 0 && table[i][4] == 0){
				if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] > 25){
					play = bot[handcard -1];
					break;
				}
			}
		}
	}
	
	if(play == 0){		//26.�p�G�̤j��P - table[i][4] > 30						
		for(i = 0; i<4; i++){
			if(table[i][4] != 0){
				if(bot[handcard -1] > table[i][4] && bot[handcard -1] - table[i][4] > 30){
					play = bot[handcard -1];
					break;
				}
			}
		}
	}
	
	if(play == 0){		//27.�p�G�̤j��P - table[i][4] > 20						
		for(i = 0; i<4; i++){
			if(table[i][4] != 0){
				if(bot[handcard -1] > table[i][4] && bot[handcard -1] - table[i][4] > 20){
					play = bot[handcard -1];
					break;
				}
			}
		}
	}
	
	
	if(play == 0)		//28.�X�̤p��					
		play = bot[0];
	
	//�X�P��P�Ѧ��i���e���� 
	for(i = 0; bot[i]!=0; i++)
		if(play == bot[i]){
			j = i;
			break;
		}		
			
	for(i = j; i<handcard ; i++){
		bot[i] = bot[i+1];
	}
	bot[handcard-1] = 0;

	return play;	
}
int BotPlayCard_2(int *bot,int table[][6],int handcard, int first){	// (bot[], table[])
	int m,n,z;
	int less_row;		//�ĴX"�C"�ֵ̤P 
	int tmp_show,tmp_table;		// �Ȧs�A����P�A�Ȧs�i���W�Ҧb�̫᪺���|�i�P 
	int test = 1;
	int test2 = 0;
	int differ = 103;		//�n�X���P�P���b��e���P���Ʀr�t�ȡA�b table[tmp_row][tmp_col] �P tmp_bot_play ���̤p�t�� 
	int tmp_col , tmp_row;		//�P�ĴX�C��differ, �� 
	int not0_col, not0_row;		//�Ȯɦs�ĴX�C�B��O�̫�@�i�P 
	int tmp_bot_play;			//���i��P��differ 
	int play = 0;    //�X���i�P 
	int tmp_m;
	int tmp_handcard;
	int i, j;
	
	if(first == 0){
		for(i = 0; i<4; i++){
			if(bot[3] > table[i][0]){
				play = bot[3];
				test = 0;
				break;
			}
		}
		for(i = 0; i<4; i++){
			if(bot[6] > table[i][0]){
				play = bot[6];
				test = 0;
				break;
			}
		}
	}
		

	if(test == 1){
		while(test2 == 0){
			for(i = 0 ; i < 4 ; i++){	//1.�P��=4�����L�t��2�H����						
				if(table[i][3] != 0){					//�ĥ|�i!=0�� 
					for(j = 0 ; j < handcard ; j++){				
						if(table[i][4] == 0){			//�Ĥ��i=0�� 
							if(bot[j] > table[i][3] && bot[j] - table[i][3] < 2){
								play = bot[j];
								test2++;
								break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0 ; i < 4 ; i++){	//2.�P��=4�����L�t��3�H����						
				if(table[i][3] != 0){					//�ĥ|�i!=0�� 
					for(j = 0 ; j < handcard ; j++){				
						if(table[i][4] == 0){			//�Ĥ��i=0�� 
							if(bot[j] > table[i][3] && bot[j] - table[i][3] < 3){
								play = bot[j];
								test2++;
								break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0 ; i < 4 ; i++){	//3.�P��=4�����L�t��5�H����						
				if(table[i][3] != 0){					//�ĥ|�i!=0�� 
					for(j = 0 ; j < handcard ; j++){				
						if(table[i][4] == 0){			//�Ĥ��i=0�� 
							if(bot[j] > table[i][3] && bot[j] - table[i][3] < 5){
								play = bot[j];
								test2++;
								break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//4.�P��=3�����L�t��3�H����							
				if(table[i][2] != 0){				
					for(j = 0; j < handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 3){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//5.�P��=3�����L�t��6�H����							
				if(table[i][2] != 0){				
					for(j = 0; j < handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 6){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//6.�P��=3�����L�t��8�H����							
				if(table[i][2] != 0){				
					for(j = 0; j < handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 8){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//7.�P��=3�����L�t��10�H����							
				if(table[i][2] != 0){				
					for(j = 0; j < handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 10){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//8.�P��=3�����L�t��13�H����							
				if(table[i][2] != 0){				
					for(j = 0; j < handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][2] && bot[j] - table[i][2] < 13){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			if(play == 0){		//9.�p�G�̤j��P - table[i][3] < 8						
				for(i = 0; i<4; i++){
					if(table[i][3] != 0 && table[i][4] == 0){
						if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] < 8){
							play = bot[handcard -1];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;
			}
			
			if(play == 0){		//10.�p�G�̤j��P - table[i][3] < 12						
				for(i = 0; i<4; i++){
					if(table[i][3] != 0 && table[i][4] == 0){
						if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] < 12){
							play = bot[handcard -1];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;
			}
			
			for(i = 0; i<4; i++){	//11.��P��=2�����L�t��10�H����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][1] && bot[j] - table[i][1] < 10){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//12.��P��=2�����L�t��20�H����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][1] && bot[j] - table[i][1] < 20){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
			
			for(i = 0; i<4; i++){	//13.��P��=1�����L�t��5�H����					
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 5){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;

			for(i = 0; i<4; i++){	//14.��P��=1�����L�t��15�H����					
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 15){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
	
			for(i = 0; i<4; i++){	//15.��P��=1�����L�t��25�H����
				if(table[i][0] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][1] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 25){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;	

			for(i = 0; i<4; i++){	//16.�P�ƬO1����	 				
				for(j = 0; j<handcard; j++){				
					if(table[i][1] == 0){		
						if(bot[j] > table[i][0]){
							play = bot[j];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;	
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//17.�P�ƬO3�t��<20					
				if(table[i][2] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][0] && bot[j] - table[i][0] < 20){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;	
			
			for(i = 0; i<4; i++){	//18.�P��=3����					
				if(table[i][2] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][3] == 0){		
							if(bot[j] > table[i][0]){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;
				
			for(i = 0; i<4; i++){	//19.�P��=2����					
				if(table[i][1] != 0){				
					for(j = 0; j<handcard; j++){				
						if(table[i][2] == 0){		
							if(bot[j] > table[i][0]){
								play = bot[j];
								test2++;
							break;
							}
						}
					}
					if(test2 != 0)
						break;
				}		
			}
			if(test2 != 0)
				break;	
				
			if(play == 0){		//20.�p�G�̤j��P - table[i][3] > 35						
				for(i = 0; i<4; i++){
					if(table[i][3] != 0 && table[i][4] == 0){
						if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] > 35){
							play = bot[handcard -1];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;
			}
			
			if(play == 0){		//21.�p�G�̤j��P - table[i][3] > 25						
				for(i = 0; i<4; i++){
					if(table[i][3] != 0 && table[i][4] == 0){
						if(bot[handcard -1] > table[i][3] && bot[handcard -1] - table[i][3] > 25){
							play = bot[handcard -1];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;
			}
			
			if(play == 0){		//22.�p�G�̤j��P - table[i][4] > 30						
				for(i = 0; i<4; i++){
					if(table[i][4] != 0){
						if(bot[handcard -1] > table[i][4] && bot[handcard -1] - table[i][4] > 30){
							play = bot[handcard -1];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;
			}
			
			if(play == 0){		//23.�p�G�̤j��P - table[i][4] > 20						
				for(i = 0; i<4; i++){
					if(table[i][4] != 0){
						if(bot[handcard -1] > table[i][4] && bot[handcard -1] - table[i][4] > 20){
							play = bot[handcard -1];
							test2++;
							break;
						}
					}
				}
				if(test2 != 0)
					break;
			}
			
			if(test2 == 0)
				break;	
		}
	}
	
	if(play == 0)		//24.�X�̤p��					
		play = bot[0];
	
	//�X�P��P�Ѧ��i���e���� 
	for(i = 0; bot[i]!=0; i++)
		if(play == bot[i]){
			j = i;
			break;
		}		
			
	for(i = j; i<handcard ; i++){
		bot[i] = bot[i+1];
	}
	bot[handcard-1] = 0;

	return play;	
}

void givebullhead(){// �w�q�X�C�i�P�����Y�� �A card[1]�� card [104]���C���P�� 
	int i ;
	
	card[0].number = 0;//�S���o�i�P 
	card[0].bullhead = 0;
	
	for(i = 1 ;i <= 104 ;i++){
		if(i%5 == 0 && i%10 != 0){//�����ƵP 2���Y 
			card[i].bullhead = 2;
		}
		else if(i%10 == 0){//�Q���ƵP 3���Y 
			card[i].bullhead = 3;
		}
		else if(i%11 == 0){//�Q�@���ƵP 5���Y 
			card[i].bullhead = 5;
		}
		else{//��l�� 1���Y 
			card[i].bullhead = 1;
		}
	}
	card[55].bullhead = 7;//55���P 7���Y 
}


void storealltable(int alltable[][6] ,int row , int card){//�x�s�ثe�ୱ�W�Ҧ����P �G���}�C[4]*[6]  
	int i;
	for(i = 0 ;i<6 ;i++){
		if(alltable[row][i] == 0){//��X���檺�P���ĴX�C 
			break;
		}
	}
	alltable[row][i] = card;
}

 
int countbullhead(int alltable[][6] ,int row){//�ƭn�j�Y�@�y���C�����Y���`�M 
	int i ,thisbullhead = 0;
	for(i = 0 ;i<5 ;i++){
		thisbullhead += card[ alltable[row][i] ].bullhead;
	}
	return thisbullhead;
}

void fold(int alltable[][6] ,int row ,int card){//��j�Y�@�y�����P���_�� 
	int i ;
	for(i = 0;i<6;i++){ //��C�k�s 
		alltable[row][i] = 0;
	}
	alltable[row][0] = card;  //���X���Ʃ�b��C�Ĥ@�i 
} 

int Aichoise(int alltable[][6] ){	//�q�����a��X���Y�Ƴ̤֦C 
	int i,j,choise = 0;
	int smallest = 28 ,rowtotal = 0;//smallest 	���i�঳37  ,rowtotal ����C���Y���`�M 
	for(i = 0 ;i<4 ;i++){
		rowtotal = 0;
		for(j = 0 ;j <5 ;j++){
			rowtotal += card[alltable[i][j]].bullhead;
		}
		if(smallest > rowtotal){
			smallest = rowtotal;
			choise = i+1;
		}
	}
	return choise;
}

void Tocountfold(int alltable[][6] , int *disting ,int playerscore[]){
	int i, head;
	for(i = 0 ;i<4 ;i++){
		if(alltable[i][5] != 0){
			Sleep(1200);
			head = countbullhead(alltable, i ); // �p��n�Y�����Y�� 
			playerscore[*disting - 1] = playerscore[*disting - 1] -head ; //���a���Ʀ����Y�������Y�� 
			musiceat();
			fold(alltable ,i ,alltable[i][5]); //��Y�����P�q�P���W���� 
		}
	}		
}

void aftercard(int player_play,int bot1_play,int bot2_play,int bot3_play, int playerscore[] ,int alltable[][6] ,int order,int *disting){
	typedef struct node{
		int number ;
		int player ;
	} Node;
	
	Node put[4];
	Node temp;
	
	int test;
	int i = 0,j = 0;
	int differ = 0,smallest = 0,dot = 0 ,row = 0;
	int head = 0;//�������� 
	int after[4] = {player_play ,bot1_play ,bot2_play ,bot3_play};
	int choise = 0;
	int table[4];
	
	for(i = 0 ;i<4 ;i++){//��X�C�@�C���̫�@�i�P 
		for(j = 0 ;j<6 ;j++){
			if(alltable[i][j] == 0){
				table[i] = alltable[i][j-1];
				break;
			}
		}
	}
	
	for(i = 0 ;i<4 ;i++){//�аO�X�P�� 
		put[i].number = after[i];
		put[i].player = i+1;
	}
	
	for(j = 0; j<3; j++){//Bubblesort
		for(i = 0 ;i<3 ;i++){
			if(put[i].number > put[i+1].number){
				temp = put[i];
				put[i] = put[i+1];
				put[i+1] = temp;
			}
		}
	}
	
	

	smallest = 104;//�t�@�w�p��104
	dot = 0; 
	for(j = 0 ;j<4 ;j++){//��X�t�̤p��
		differ = put[order].number - table[j];
		if(differ < 0){//�t���I�� 
			dot++;
		}
		else if(differ > 0 && smallest > differ){ 
			smallest = differ ;
			row = j;
		}
	}
	
	if(dot == 4){//  dot == 4 ,�N��X���P�̤p,�����Y�P 
		if(put[order].player == 1){//�ڥX�� 
			printf("�п�ܭn�Y�o�C : (��J 1~4) ");
			scanf("%d",&choise);
		}
		else{
			choise = Aichoise(alltable);
		}
		while(choise>4 || choise<1){//�T�{choise�b1~4 
			printf("�п�ܭn�Y�o�C : (��J 1~4) ");
			scanf("%d",&choise);
		}
		switch(choise){
			case 1:
				table[0] = put[order].number; //���C�̫᪺�P��s���X���P 
				alltable[choise-1][5] =  put[order].number;
				Sleep(1200);
				head = countbullhead(alltable, choise-1 ); // �p��n�Y�����Y�� 
				playerscore[put[order].player - 1] = playerscore[put[order].player - 1] -head ; //���a���Ʀ����Y�������Y�� 
				musiceat();
				fold(alltable ,choise-1 ,put[order].number); //��Y�����P�q�P���W���� 
				break;
			case 2:
				table[1] = put[order].number;
				alltable[choise-1][5] =  put[order].number;
				Sleep(1200);
				head = countbullhead(alltable, choise-1);
				playerscore[put[order].player - 1] = playerscore[put[order].player - 1] -head ;
				musiceat();
				fold(alltable ,choise-1 ,put[order].number);
				break;
			case 3:
				table[2] = put[order].number;
				alltable[choise-1][5] =  put[order].number;
				Sleep(1200);
				head = countbullhead(alltable, choise-1);
				playerscore[put[order].player - 1] = playerscore[put[order].player - 1] -head ;
				musiceat();
				fold(alltable ,choise-1 ,put[order].number );
				break;
			case 4:
				table[3] = put[order].number;
				alltable[choise-1][5] =  put[order].number;
				Sleep(1200);
				head = countbullhead(alltable, choise-1);
				playerscore[put[order].player - 1] = playerscore[put[order].player - 1] -head ;
				musiceat();
				fold(alltable ,choise-1 ,put[order].number);
				break;
			default :
				printf("�X���F ");
				scanf("%d",&choise);
				break;
		}
	}
	else {//��itable 
		
		table[row] = put[order].number;//���C�̫᪺�P��s���X���P 
		storealltable(alltable ,row ,put[order].number);//��ƥX���W 
		if(alltable[row][5] != 0){//�j�Y�@�y 
			*disting = put[order].player;
		}
			
	}	
}

void musiceat()
{
     //�����W�v(�̦������A�i�H�ۤv�y�L�վ�@�U) 
    //Do:523
    //Re:587
    //Mi:659
    //Fa:698 
    //So: 784 
    //La: 880 
    //Si: 988 
    //Do: 1060 
    //Re: 1185 
    //Mi: 1300 
    int row;
    int voice[2] = 	{784,1060} ; 
    //����ɶ�(1���b�� 2���b�� 300������ɶ�) 
    int tempo[2] = 	{1,1}; 
    for(row=0; row < 2 ; row++)
    {
   
        Beep(voice[row],tempo[row]*200);           
		
    } 
}  

void musicstart()
{
     //�����W�v(�̦������A�i�H�ۤv�y�L�վ�@�U) 
    //Do:523
    //Re:587
    //Mi:659
    //Fa:698 
    //So: 784 
    //La: 880 
    //Si: 988 
    //Do: 1060 
    //Re: 1185 
    //Mi: 1300 
    int row;
    int voice[2] = 	{1060,784} ; 
    //����ɶ�(1���b�� 2���b�� 300������ɶ�) 
    int tempo[2] = 	{1,1}; 
    for(row=0; row<2 ; row++)
    {
   
        Beep(voice[row],tempo[row]*200);           
		
    } 
} 

void music()
{
     //�����W�v(�̦������A�i�H�ۤv�y�L�վ�@�U) 
    //Do:523
    //Re:587
    //Mi:659
    //Fa:698 
    //So: 784 
    //La: 880 
    //Si: 988 
    //Do: 1060 
    //Re: 1185 
    //Mi: 1300 
    int row;
    int voice[50] = 	{988,784,880,740,784,659,740,587,
						988,784,880,740,784,740,659,587,} ; 
    //����ɶ�(1���b�� 2���b�� 300������ɶ�) 
    int tempo[50] = 	{2,1,2,2,2,2,2,3,
						2,1,2,2,2,2,2,3,}; 
    for(row=0; row<16 ; row++)
    {
   
        Beep(voice[row],tempo[row]*200);           
		
    } 
}  

void music2()
{
     //�����W�v(�̦������A�i�H�ۤv�y�L�վ�@�U) 
    //Do:523
    //Re:587
    //Mi:659
    //Fa:698 
    //So: 784 
    //La: 880 
    //Si: 988 
    //Do: 1060 
    //Re: 1185 
    //Mi: 1300 
    int row;
    int voice[50] = 	{659,659,659,740,784,880,740,587,587,
						494,659,740,784,880,
						988,988,1185,1109,880,880,988,988,1185,1109,880,988} ; 
    //����ɶ�(1���b�� 2���b�� 300������ɶ�) 
    int tempo[50] = 	{3,1,1,1,1,1,3,1,3,
						1,4,4,4,4,
						1,1,1,2,1,1,2,1,1,2,2,3}; 
    for(row=0; row<27 ; row++)
    {
   
        Beep(voice[row],tempo[row]*200);           
		
    } 
   
}   
