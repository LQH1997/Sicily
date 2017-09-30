#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define maplenth 12 //地图的竖直长度 
#define mapwidth 12//地图的水平宽度 
int snakelenth = 5;
int maxsnakelenth = maplenth * mapwidth;
void getmovement(void); //读取移动方向 
void gameOver(void); 
int foodxx(int a);//食物的横纵坐标 
int foodyy(int a);
int obstaclexx(int d);//障碍物的横纵坐标 
int obstacleyy(int d);
int score = 0;
int scorei = 0;
char map[maplenth][mapwidth];
char snakebody[50];
int snakelife = 1;
int coordinateOfSnakeBody[maplenth][mapwidth] = {0};
int obstacle[maplenth][mapwidth] = {0};
char moveDirection[1]; //移动都方向 
int headX, headY; //蛇头的横纵坐标 
int bodyX[50] = {1,2,3,4};//蛇身体的横坐标
int bodyY[50] = {1,1,1,1};//蛇身体的纵坐标 
int foodX, foodY;
int obX[10],obY[10]; //障碍物的，可以无视 
int main() {
	int i, a, b, c, d,z=0;
	moveDirection[0] = 'D';
	foodX = foodxx(foodX);
	foodY = foodyy(foodY); //随机创建食物地点 
	coordinateOfSnakeBody[1][1] = 1;
    coordinateOfSnakeBody[1][2] = 1;
	coordinateOfSnakeBody[1][3] = 1;
	coordinateOfSnakeBody[1][4] = 1;
	coordinateOfSnakeBody[1][5] = 2;//初始换蛇头和蛇身体的坐标。头的位置值等于2，身体位置为1 
	printf("press any key to start the game\n");
	printf("please enter W A S D to play the game\n$ is your food!");
	getchar();
	system("cls");
	while(snakelife > 0) { //满足条件之执行循环 
	for(i = 0; i < maplenth; i++) {//就是讲整个map打印出来 
		if(i==0||i==maplenth-1) {
			for(a = 0; a < mapwidth; a++) {
				printf("*");
			}
			printf("\n");
		}                        //打印地图上下边界 
		else {
			for (a = 0; a <mapwidth; a++) {
				if(a==0||a==mapwidth-1) {
					printf("*"); //打印地图的左右边界 
				}
				else {
					if (coordinateOfSnakeBody[i][a] == 1) {
						printf("X");     //打印蛇的身体 
					}
					else  if (coordinateOfSnakeBody[i][a] == 2) {
						printf("H"); 
						headX = a;
						headY = i;  // 打印蛇头，记录蛇头的位置 
					} else if(i == foodY&&a == foodX) printf("$");//打印出食物 
					 else if(obstacle[i][a]==1) {
					 	printf("*");
					 }
				 else printf(" ");//当满足这个坐标既不是蛇的身体，也不是障碍，也不是食物时，打印空白 
				}
			}
			printf("\n");
		}
	}
	getmovement();//读取我们的下一步运动方向，用moveDirection记录读取的方向 
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
if(a[0]=='a') a[0] ='A';//排除大小写的干扰 
if(a[0]=='s') a[0] ='S';
if(a[0]=='d') a[0] ='D';
if(a[0]=='w') a[0] ='W';//如果有键盘输入，就将首字母记录在a[0]中，如果没有输入，a[0]的值不会发生改变，这样对移动方向也不会有影响 
	switch (a[0]) {
		case 'A': if(moveDirection[0] != 'D') { //当蛇的原行驶方向与输入的方向相反时，输入无效 
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
		case 'A': headX -= 1; headY += 0; break;//计算下一步蛇头的坐标 
		}
	for(i = 0; i < snakelenth - 2; i++) {
		bodyX[i] = bodyX[i+1];
		bodyY[i] = bodyY[i+1]; //让蛇身体的后面一节的坐标等于前面一劫的坐标，从而实现蛇的移动 
	}
	bodyX[snakelenth-2] = e;
	bodyY[snakelenth-2] = b;//蛇头后面一截为特殊值，另外记录和改变 
	for(c = 1; c < maplenth-1;c++) {
		for(d = 1; d <mapwidth - 1; d++) {
			coordinateOfSnakeBody[c][d] = 0;
		}
	}//清空蛇身体和头所在数组的值、
	for(i = 0; i < snakelenth - 1; i++) {
		e = bodyX[i];
		b = bodyY[i];
		coordinateOfSnakeBody[b][e] = 1;
	}
	if(coordinateOfSnakeBody[headY][headX] == 1) {
		snakelife -= 1;
	} else if(obstacle[headY][headX] == 1){
		snakelife -= 1;}
	  else coordinateOfSnakeBody[headY][headX] = 2; //重新赋值 
	if(headY==0||headY==maplenth-1) { //判断是否撞墙 
		snakelife -= 1;
	} else if(headX==0||headX==mapwidth-1) {//判断是否撞墙
		snakelife -= 1;
	}
	scorebefore = score;//无视就好 
	if(headY == foodY&&headX == foodX) { //检测是否吃到食物 
		snakelenth++;
		score += 1;
		foodX = foodxx(foodX);
		foodY = foodyy(foodY); //产生食物的位置 
	}
	while(coordinateOfSnakeBody[foodY][foodX]== 1|| coordinateOfSnakeBody[foodY][foodX] == 2) {
		foodX = foodxx(foodX);
		foodY = foodyy(foodY);//如果食物产生在蛇的身体的位置，就重新生成食物的位置 
	}
	if(score==scorebefore + 1) { //这是障碍物的产生，可以无视 
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

