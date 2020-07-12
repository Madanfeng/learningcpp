#include<iostream>
using namespace std;

// 注意：不要返回局部变量的地址！！！

int* func(int b) // 形参数据也会放在栈区
{
    int a = 10;  // 局部变量  存放在栈区，栈区的数据在函数执行后自动释放
    return &a;
}

int main()
{
    int b = 10;
    int * p = func(b);
    cout << *p << endl;   // 第一次打印正确的数字，因为编译器做了保留
    cout << *p << endl;   // 第二次这个数字就不再保留

    return 0;
}
