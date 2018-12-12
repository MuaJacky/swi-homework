字符游戏————贪吃蛇
=

经过查看很多前辈做的贪吃蛇经验，我自己仿照的做了几个，首先根据

教程的贪吃蛇头写的：
![snake-head](https://github.com/MuaJacky/swi-homework/raw/gh-pages/lab13/snake-head.jpg)


然后根据框架有贪吃蛇main函数：
![snake-main](https://github.com/MuaJacky/swi-homework/raw/gh-pages/lab13/snake-main.png)

然后根据main函数，snake_move函数也出来了:   

    void snake_move (int x, int y) {
    system("cls");
    int i; 
    if(snakeX[0] + x == moneyX && snakeY[0] + y == moneyY) 				//判断是否吃到食物 ,如是便使蛇伸长 
        snake_eat() ;						
    else 
        map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = ' ';	//如果没有吃到食物,把蛇的最后一段删除 
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

最后如果吃到了食物，就应该有snake_eat:

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


以上便是贪吃蛇的主要函数.


然后根据智能蛇的AI原理：曼哈顿距离有AI蛇

main函数：

    int main() {
        put_money(); 	
        char ch = wherego();//默认向右走 
        
        output();
        while(1) {
            Sleep(200);
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
            ch = wherego();
            if (judge() == 0)
            {
                gameover();
                return 0;
            }
        }
        return 0;
    }

wherego()寻找食物函数:

    char wherego() { 
        int k=0, i; 
        int a = snakeX[0]; 
        int b = snakeY[0]; 
        int distence[4] = {0, 0, 0, 0}; 
        distence[0] = abs(moneyX - (a-1)) + abs(moneyY - b); 
        distence[1] = abs(moneyX - (a+1)) + abs(moneyY - b); 
        distence[2] = abs(moneyX - a) + abs(moneyY - (b - 1));
        distence[3] = abs(moneyX - a) + abs(moneyY - (b + 1)); 

        if(map[b][a-1] == '*' || map[b][a-1] == 'X') {
            distence[0] = 9999;} 
        if(map[b][a+1] == '*' || map[b][a+1] == 'X') {
            distence[1] = 9999;} 
        if(map[b-1][a] == '*' || map[b-1][a] == 'X') {
            distence[2] = 9999;} 
        if(map[b+1][a] == '*' || map[b+1][a] == 'X') {
            distence[3] = 9999;} 

        int min = distence[0]; 
        for( i = 0; i < 4; i++) { 
            if(distence[i] < min) { 
                min = distence[i]; 
                k = i;
            } 
        } 

        return movable[k]; 
    }

最后展示一下我的成果:
![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/lab13/snake-AI.gif)