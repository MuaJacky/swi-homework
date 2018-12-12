#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define SNAKE_MAX_LENGTH 50 
#define SNAKE_HEAD 'H' 
#define SNAKE_BODY 'X' 
#define BLANK_CELL ' ' 
#define SNAKE_FOOD '$' 
#define WALL_CELL '*'

//全局变量：初始状态表 
int food = 0;
//定义开始时食物数量为0 
int x = 0, y = 0;
//定义食物的坐标（x，y） 
int snakex[SNAKE_MAX_LENGTH] = { 5, 4, 3, 2, 1 };
//蛇身的横坐标 
int snakey[SNAKE_MAX_LENGTH] = { 1, 1, 1, 1, 1 };
//蛇身的纵坐标 
int lastX = 1, lastY = 1;
//表示蛇尾部的坐标 
int snakeLength = 5;
//定义初始长度，在该变量完成蛇长的变化
int moneyX,moneyY;

void snake_move (int, int);     //蛇移动函数 
void put_money (void);          //下放食物 
void output (void);             //输出数组 
void gameover (void);           //打印提示游戏结束 
void snake_eat (void);      //吃到食物后蛇的伸长 
int judge (void);               //判断游戏是否结束 
char changeUpper (char);        //将字母全部转为大写 
char wherego(void);

char map[12][13] =
    {"************",
    "*XXXXH     *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "************"};
//蛇身的各个位置,[0]是头 
int snakeX[SNAKE_MAX_LENGTH] = {5, 4, 3, 2, 1}; 
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};

int main() {
    char ch;//默认向右走 
    put_money();    
    output();
    while(1) {
        ch = changeUpper(ch);
        switch(ch) {
            case 'A': 
                snake_move (-1, 0);
                break;
            case 'S':
                snake_move (0, 1);
                break;
            case 'D':
                snake_move (1, 0);
                break; 
            case 'W':
                snake_move (0, -1);
                break;
            }
        while(!kbhit())
        {
            Sleep(200);
        }   
        if(kbhit())
            ch = getch();
        if(judge() == 0){
            gameover();
            break;
        }
    }
}

void put_money (void) {
    //随机设置食物位置 
    moneyX = rand () % 9;
    moneyY = rand () % 9;
    //判断位置是否为空 
    if (map[moneyY][moneyX] == ' ') {
        map[moneyY][moneyX]='$';
    }
    else    //不为空重新调用 
        put_money ();       
}


void snake_move (int x, int y) {
    system("cls");
    int i; 
    if(snakeX[0] + x == moneyX && snakeY[0] + y == moneyY)              //判断是否吃到食物 ,如是便使蛇伸长 
        snake_eat() ;                       
    else 
        map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = ' ';    //如果没有吃到食物,把蛇的最后一段删除 
    //蛇的向前走,蛇身的后面一段继承前面一段的位置 
    for(i = snakeLength - 1; i > 0; i --) {                              
        snakeX[i] = snakeX[i - 1];      
        snakeY[i] = snakeY[i - 1];
        map[snakeY[i]][snakeX[i]] = 'X';
    }
    snakeX[0] += x;
    snakeY[0] += y;
    map[snakeY[0]][snakeX[0]] = 'H';
    //输出数组 
    output ();
}


void snake_eat (void) {
    put_money ();//蛇吃到食物后重置食物位置
    //小于最长长度 
    if (snakeLength < SNAKE_MAX_LENGTH) { 
        snakeY[snakeLength] = snakeY[snakeLength-1];
        snakeX[snakeLength] = snakeX[snakeLength-1];
        snakeLength ++ ;
    } 
    else 
        map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] = ' '; //大于最长长度 
}

int judge(){
    int i;
    //碰到框架游戏结束 
    if(snakeX[0] == 0||snakeX[0] == 11||snakeY[0] == 0||snakeY[0] == 11)
        return 0;
    //头碰到自己游戏结束 
    for(i=1;i<snakeLength;i++) {
        if(snakeX[0] == snakeX[i]&&snakeY[0]==snakeY[i])
                return 0;
    }
    return 1;
}

void output()
{
    for (int i = 0; i < 12; ++i)
    {
        printf("%s\n",map[i]);
    }
}

char changeUpper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 'a' - 'A';
    }
    return c;
}

void gameover()
{
    printf("Game Over!\n");
}

