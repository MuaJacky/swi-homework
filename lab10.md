用python做线代高数题
==

高数
--

（教材：北大版高等数学第二版上册）    
python做符号运算需要载入sympy库，sym是符号（symbol）前3个英文字母，py是Python的前两个字母，需要注意的是python2和python3的语法有所不同  
在命令操作行>>>输入from sympy import *    

1. 求极限   Page 52 4.2   

    ![极限](https://github.com/MuaJacky/swi-homework/raw/master/lab10/jixian.jpg)

    - x趋近于0时求关于x的表达式的极限，先要定义x或者说给x赋值,操作如下：
    - >x=Symbol(‘x’)
    - 然后可以进行求极限操作,格式如下：
    - >limit(表达式，变量，趋近值）
    - 具体操作见图 

    ![极限示意图](https://github.com/MuaJacky/swi-homework/raw/master/lab10/jixian1.jpg)  

    答案是0，结果正确
- 附：当x趋近于无穷时趋近值为oo（字母o，不是数字0）

2. 泰勒展开 Page 200 2.1   

    ![泰勒](https://github.com/MuaJacky/swi-homework/raw/master/lab10/taile.jpg)

    我们可以使用pprint（）函数打印出方便阅读的展开式
泰勒展开格式如下：

    >series.(表达式，变量名，指定展开点，展开阶数）   

    具体操作如下：   

    ![](https://github.com/MuaJacky/swi-homework/raw/master/lab10/taile1.jpg)

    结果正确   

    附：自然常数e用大写的E来表示   


线代
--
（教材：线性代数及其应用第三版英文版）
做线性代数需要导入Numpy库，载入操作如下： 
> import numpy as np

1. 解方程组并求dot验证： Page 55 16   

    ![方程](https://github.com/MuaJacky/swi-homework/raw/master/lab10/fangcheng.jpg)

    具体操作如下：

    ![方程操作](https://github.com/MuaJacky/swi-homework/raw/master/lab10/fangcheng1.jpg)


2. 求逆矩阵  Page 127 31

    ![逆矩阵](https://github.com/MuaJacky/swi-homework/raw/master/lab10/juzhen.jpg)

    注意：要求出一个矩阵的行列式不为0才可计算他的逆矩阵   

    操作如下:

    ![逆矩阵操作](https://github.com/MuaJacky/swi-homework/raw/master/lab10/juzhen1.jpg)

    结果正确
