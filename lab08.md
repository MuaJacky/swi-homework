什么是“自顶向下，逐步求精”的思想方法？
==

    Top-down design
      A top-down approach (also known as stepwise design and in some cases used as a synonym of decomposition) is essentially the breaking down of a system to gain insight into its compositional sub-systems in a reverse engineering fashion.

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/lab08/up_to_down.jpg)

“自顶向下，逐步求精”举例（描述洗衣机控制程序）
==

![](https://github.com/MuaJacky/swi-homework/raw/gh-pages/lab08/xiyiji.jpg)


使用伪代码分解“正常洗衣”程序的大步骤。   

    Choose mood : input volume and time

    water_in_switch(open)  
    keep open until water_volume reach volume  then close  

    set time1 = time_counter();   
    keep close until     
    wait(time) = 1

    motor_run(left);
    motor_run(left);
    motor_run(left);
    motor_run(right);
    motor_run(right);
    motor_run(right);

    keep water_out_switch(open) until  
    water_volume = 0 

    end

进一步用基本操作、控制语句（IF、 FOR、 WHILE等）、变量与表达式，写出每 个步骤的伪代码

    READ volume,time
            REPEAT

            water_in_switch(open)

        UNTILL water_volume = volume 
        time1 = time_counter()  
        REPEAT

            water_in_volume(close)

        UNTILL    wait(time) = 1
        set times = 0
        REPEAT
            motor_run(left)
            motor_run(right)
        until(++times = 3)
        WHILE(water_volume > 0)
        water_out_switch(open)
        ENDWHILE
        water_out_switch(close)
        FOR(wait(time) = 0 )

            motor_run(left)
            motor_run(right)

        ENDFOR
        
        end

提取一些共性功能模块（函数），简化“正常洗衣”程序，使程序 变得更利于人类理解和修改维护。

water_in_switch(volume){   
    if  water_volume < volume then open   
    else close
}

water_out_switch()
{    
    if  water_volume > 0 then open    
    else  close   
}

wait(time)
{    
    if  time1 == time return 1  
    else return 0   
}