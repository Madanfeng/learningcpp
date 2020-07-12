#include<iostream>
using namespace std;

// new的基本语法
int * func()
{
    // 在堆区创建整型数据
    // new返回是 该数据类型的指针
    int * p = new int(10);
    return p;
}    

void test01()
{
    int * p = func();
    cout  << *p << endl;
    cout  << *p << endl;
    // 堆区的数据由程序员开辟，程序员释放
    // 利用 delete 释放
    delete p;
    // coout << *p << endl;    // 运行该命令会出错
}


// 在堆区用new开辟数组
void test02()
{
    // 创建10个整型数组, 在堆区
    int * arr = new int[10];  // 10代表数组有10个元素
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    
    // 释放堆区数组
    // 释放数组的时候， 需要加[]
    delete[] arr;
    
}

int main()
{

    test01();

    test02();

    return 0;
}