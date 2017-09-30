#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define maplenth 12 //��ͼ����ֱ���� 
#define mapwidth 12//��ͼ��ˮƽ��� 
int snakelenth = 5;
int maxsnakelenth = maplenth * mapwidth;
void getmovement(void); //��ȡ�ƶ����� 
void gameOver(void); 
int foodxx(int a);//ʳ��ĺ������� 
int foodyy(int a);
int obstaclexx(int d);//�ϰ���ĺ������� 
int obstacleyy(int d);
int score = 0;
int scorei = 0;
char map[maplenth][mapwidth];
char snakebody[50];
int snakelife = 1;
int coordinateOfSnakeBody[maplenth][mapwidth] = {0};
int obstacle[maplenth][mapwidth] = {0};
char moveDirection[1]; //�ƶ������� 
int headX, headY; //��ͷ�ĺ������� 
int bodyX[50] = {1,2,3,4};//������ĺ�����
int bodyY[50] = {1,1,1,1};//������������� 
int foodX, foodY;
int obX[10],obY[10]; //�ϰ���ģ��������� 
int main() {
	int i, a, b, c, d,z=0;
	moveDirection[0] = 'D';
	foodX = foodxx(foodX);
	foodY = foodyy(foodY); //�������ʳ��ص� 
	coordinateOfSnakeBody[1][1] = 1;
    coordinateOfSnakeBody[1][2] = 1;
	coordinateOfSnakeBody[1][3] = 1;
	coordinateOfSnakeBody[1][4] = 1;
	coordinateOfSnakeBody[1][5] = 2;//��ʼ����ͷ������������ꡣͷ��λ��ֵ����2������λ��Ϊ1 
	printf("press any key to start the game\n");
	printf("please enter W A S D to play the game\n$ is your food!");
	getchar();
	system("cls");
	while(snakelife > 0) { //��������ִ֮��ѭ�� 
	for(i = 0; i < maplenth; i++) {//���ǽ�����map��ӡ���� 
		if(i==0||i==maplenth-1) {
			for(a = 0; a < mapwidth; a++) {
				printf("*");
			}
			printf("\n");
		}                        //��ӡ��ͼ���±߽� 
		else {
			for (a = 0; a <mapwidth; a++) {
				if(a==0||a==mapwidth-1) {
					printf("*"); //��ӡ��ͼ�����ұ߽� 
				}
				else {
					if (coordinateOfSnakeBody[i][a] == 1) {
						printf("X");     //��ӡ�ߵ����� 
					}
					else  if (coordinateOfSnakeBody[i][a] == 2) {
						printf("H"); 
						headX = a;
						headY = i;  // ��ӡ��ͷ����¼��ͷ��λ�� 
					} else if(i == foodY&&a == foodX) printf("$");//��ӡ��ʳ�� 
					 else if(obstacle[i][a]==1) {
					 	printf("*");
					 }
				 else printf(" ");//�������������Ȳ����ߵ����壬Ҳ�����ϰ���Ҳ����ʳ��ʱ����ӡ�հ� 
				}
			}
			printf("\n");
		}
	}
	getmovement();//��ȡ���ǵ���һ���˶�������moveDirection��¼��ȡ�ķ��� 
	Sleep(300-score);
	system("cls");
}
gameOver();
}

void getmovement(void) {
	char a[20];
	int i,b,e,c,d;
	int scorebefore;
	e = headX;
	b = headY;
if(kbhit()) {
	a[0] = getch();
}
if(a[0]=='a') a[0] ='A';//�ų���Сд�ĸ��� 
if(a[0]=='s') a[0] ='S';
if(a[0]=='d') a[0] ='D';
if(a[0]=='w') a[0] ='W';//����м������룬�ͽ�����ĸ��¼��a[0]�У����û�����룬a[0]��ֵ���ᷢ���ı䣬�������ƶ�����Ҳ������Ӱ�� 
	switch (a[0]) {
		case 'A': if(moveDirection[0] != 'D') { //���ߵ�ԭ��ʻ����������ķ����෴ʱ��������Ч 
			moveDirection[0] = a[0];
		} break;
		case 'S':if(moveDirection[0] != 'W') {
			moveDirection[0] = a[0];
		} break;
		case 'D':if(moveDirection[0] != 'A') {
			moveDirection[0] = a[0];
		} break;
		case 'W':if(moveDirection[0] != 'S') {
			moveDirection[0] = a[0];
		} break;
	}
	switch(moveDirection[0]) {
		case 'W': headY -= 1; headX += 0; break;
		case 'S': headY += 1; headX += 0; break;
		case 'D': headX += 1; headY += 0; break;
		case 'A': headX -= 1; headY += 0; break;//������һ����ͷ������ 
		}
	for(i = 0; i < snakelenth - 2; i++) {
		bodyX[i] = bodyX[i+1];
		bodyY[i] = bodyY[i+1]; //��������ĺ���һ�ڵ��������ǰ��һ�ٵ����꣬�Ӷ�ʵ���ߵ��ƶ� 
	}
	bodyX[snakelenth-2] = e;
	bodyY[snakelenth-2] = b;//��ͷ����һ��Ϊ����ֵ�������¼�͸ı� 
	for(c = 1; c < maplenth-1;c++) {
		for(d = 1; d <mapwidth - 1; d++) {
			coordinateOfSnakeBody[c][d] = 0;
		}
	}//����������ͷ���������ֵ��
	for(i = 0; i < snakelenth - 1; i++) {
		e = bodyX[i];
		b = bodyY[i];
		coordinateOfSnakeBody[b][e] = 1;
	}
	if(coordinateOfSnakeBody[headY][headX] == 1) {
		snakelife -= 1;
	} else if(obstacle[headY][headX] == 1){
		snakelife -= 1;}
	  else coordinateOfSnakeBody[headY][headX] = 2; //���¸�ֵ 
	if(headY==0||headY==maplenth-1) { //�ж��Ƿ�ײǽ 
		snakelife -= 1;
	} else if(headX==0||headX==mapwidth-1) {//�ж��Ƿ�ײǽ
		snakelife -= 1;
	}
	scorebefore = score;//���Ӿͺ� 
	if(headY == foodY&&headX == foodX) { //����Ƿ�Ե�ʳ�� 
		snakelenth++;
		score += 1;
		foodX = foodxx(foodX);
		foodY = foodyy(foodY); //����ʳ���λ�� 
	}
	while(coordinateOfSnakeBody[foodY][foodX]== 1|| coordinateOfSnakeBody[foodY][foodX] == 2) {
		foodX = foodxx(foodX);
		foodY = foodyy(foodY);//���ʳ��������ߵ������λ�ã�����������ʳ���λ�� 
	}
	if(score==scorebefore + 1) { //�����ϰ���Ĳ������������� 
	/*for(i = 0; i <score; i++) {
		obX[i] = obstaclexx(obX[i]);
		obY[i] = obstacleyy(obY[i]);
		obstacle[obY[i]][obX[i]] = 1;
		while(obX[i]==foodX&&obY[i]==foodY) {
		obstacle[obY[i]][obX[i]] = 0;
		obX[i] = obstaclexx(obX[i]);
		obY[i] = obstacleyy(obY[i]);
		obstacle[obY[i]][obX[i]] = 1;
		}
	} */
}
}

void gameOver(void) {
	printf("Game Over\nYou Silly B\nYour Score is %d\n",score);
	system("pause");
}
int foodyy(int x) {
	srand(time(0));
	int y;
	y = rand()%(maplenth-2);
	y += 1;
	return y;
}
int foodxx(int x) {
	srand(time(0));
	int y;
	y = rand()%(mapwidth-2);
	y += 1;
	return y;
}
int obstaclexx(int d) {
	srand(d+2);
	int y;
	y = rand()%(mapwidth-2);
	y += 1;
	return y;
}
int obstacleyy(int d) {
	srand(d+3);
	int y;
	y = rand()%(maplenth-2);
	y += 1;
	return y;
}

