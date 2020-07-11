#include<iostream>
#include<string>

#define MAX 1000   // 注意这里不用加分号
using namespace std;

// 显示菜单界面
void showMenu()
{
    cout << "**************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "**************************" << endl;
}  // 函数定义不需要加分号


// 联系人结构体
struct Person
{
    // 姓名
    string m_Name;
    // 性别 1 男； 2 女
    int m_Sex;
    // 电话
    string m_phone;
    // 地址
    string m_Addr;
};  // 注意结构体定义时需要加分号


// 通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX];
    int m_size;
};


// 添加联系人
void addPerson(Addressbooks * abs)
{
    // 判断通讯录是否已满，如果满了就不再添加
    if(abs->m_size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        // 添加联系人
        // 姓名
        string name;
        cout << "请输入联系人姓名：";
        cin >> name;
        abs->personArray[abs->m_size].m_Name = name;

        // 性别
        int sex = 0;
        cout << "请输入联系人性别（1:男；2:女）：";

        while (true)
        {
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_size].m_Sex = sex;
                break;
            }
            cout << "输入有误，1:男；2:女。请重新输入。" << endl;
        }

        // 电话
        string phone;
        cout << "请输入联系人电话：";
        cin >> phone;
        abs->personArray[abs->m_size].m_phone = phone;

        // 地址
        string address;
        cout << "请输入联系人地址：";
        cin >> address;
        abs->personArray[abs->m_size].m_Addr = address;

        // 更新通讯录人数
        abs->m_size++;

        cout << "添加通讯录成功！" << endl;

        // system("pause");
        
        /*
        注意:
        windows中清屏为： system("cls");
        Mac中清屏为： system("clear");
        */
        system("clear");  // 清屏
        
    }
    
}


// 显示联系人
void showPerson(Addressbooks * abs)
{
    // 判断通讯录人数是否为0， 如果为0， 提示记录为空。
    if(abs->m_size == 0)
    {
        cout << "当前没有联系人信息，可选择 1.添加联系人 。" << endl;
        return;
    }
    else
    {
        cout << "序号\t姓名\t性别\t电话\t地址" << endl;
        for(int i=0; i < abs->m_size; i++)
        {
            cout << i+1 << "\t" << abs->personArray[i].m_Name;
            cout << "\t" << (abs->personArray[i].m_Sex==1 ? "男" : "女");
            cout << "\t" << abs->personArray[i].m_phone;
            cout << "\t" << abs->personArray[i].m_Addr << endl;
        }
    }

    cout << "按任意字母退出。";
    string s;
    cin >> s;
    system("clear");
    
}

int main()
{
    // 创建通讯录结构体
    Addressbooks abs;
    abs.m_size = 0;

    // 用户的选择
    int select = 0;

    while(true)
    {
    // 菜单调用
    showMenu();

    cin >> select;

    switch (select)
    {
        case 1:  // 添加联系人
            addPerson(&abs);  // 需要修改abs，用取地址符
            break;
        case 2:  // 显示联系人
            showPerson(&abs);
            break;
        case 3:  // 删除联系人
            break;
        case 4:  // 查找联系人
            break;
        case 5:  // 修改联系人
            break;
        case 6:  // 清空联系人
            break;
        case 0:  // 退出通讯录
            cout << "欢迎下次使用！" << endl;
            // system("pause");
            return 0;
            break;
        default:
            break;
    }

    }
    
    // system("pause");  // 按任意键继续
    return 0;
}