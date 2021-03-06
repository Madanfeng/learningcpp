# C++ 核心编程

## 1_内存分区模型  
>c++程序在执行时，将内存划分为4个区域  
>>1. 代码区：存放函数体的二进制代码，由操作系统进行管  
>>2. 全局区：存放全局变量和静态变量以及常数  
>>3. 栈区：  由编译器自动分配释放，存放函数的参数值，局部变量等  
>>4. 堆区：  由程序员分配和释放，若程序员不释放，程序结束时由操作系统收回

>**内存四区的意思：**  
>>不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程


### 1_1 程序运行前  
>在程序编译后，生成exe可执行文件，为执行该程序前分为两个区域  

>**代码区:**  
存放CPU执行的机器指令  
代码区是 **共享** 的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可  
代码区是 **只读** 的，使其只读的原因是防止程序意外地修改了指令  

>**全局区：**  
_全局变量_ 和 _静态变量_ 存在在此  
全局区还包含了 _常量区_ ，字符串常量和其他常量也存放在此  
_该区域的数据在程序结束后由操作系统释放_  


### 1_2 程序运行后  
>**栈区：**  
>>由编译器自动分配释放，存放 _函数的参数值_ ，_局部变量_ 等。  

>>注意：**不要返回局部变量的地址**，栈区开辟的数据由编译器自动释放  

>**堆区：**  
>>由程序员分配释放，若程序员不释放，程序结束时由操作系统收回  
>>在C++中主要用 **new** 在堆区开辟内存

### 1_3 **new** 操作符  
>C++利用 new 操作符在堆区开辟数据  
>堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 **delete**  
>语法： `new 数据类型`  
>利用new创建的数据，会返回该数据对应的类型的指针