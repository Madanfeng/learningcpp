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


// 检测联系人是否存在。如股存在返回联系人所在数组位置，否则返回-1.
// abs：通讯录
// name：所要查询的人名
int isExist(Addressbooks * abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        // 找到联系人
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }

    return -1;
}


// 删除联系人
void deletePerson(Addressbooks * abs)
{
    cout << "请输入删除联系人的姓名：";
    string name;
    cin >> name;
    
    int ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人。" << endl;
    }
    else
    {
        // 删除此人
        for (int i = ret; i < abs->m_size-1; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_size--;  // 更新通讯录人员数
        cout << "删除成功！" << endl;
    }

    system("clear");
    
}


// 查找联系人
void findPerson(Addressbooks * abs)
{
    cout << "请输入要查找联系人的姓名：";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人。" << endl;
    }
    else
    {
        // 显示该联系人
        cout << "姓名：" << abs->personArray[ret].m_Name;
        cout << "\t性别：" << (abs->personArray[ret].m_Sex==1 ? "男" : "女");
        cout << "\t电话：" << abs->personArray[ret].m_phone;
        cout << "\t地址：" << abs->personArray[ret].m_Addr << endl;
    }

    cout << "按任意键继续。";
    string s;
    cin >> s;
    system("clear");
    
}


// 修改联系人
void modifyPerson(Addressbooks * abs)
{
    cout << "请输入需要修改的联系人姓名：";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人。" << endl;
    }
    else
    {
        int tag = 0;

        // 姓名
        cout << "是否修改姓名（1-是）：";
        cin >> tag;
        if (tag == 1)
        {
            cout << "请输入修改后的姓名：";
            string name;
            cin >> name;
            abs->personArray[ret].m_Name = name;
            cout << "姓名修改成功！" << endl;
        }
        tag = 0;
        
        // 性别
        cout << "是否修改性别（1-是）：";
        cin >> tag;
        if (tag == 1)
        {
            cout << "请输入修改后的性别（1-男；2-女）：";
            int sex = 0;
            while (true)
            {
                cin >> sex;
                if (sex==1 || sex==2)
                {
                    abs->personArray[ret].m_Sex = sex;
                    cout << "性别修改成功！" << endl;
                    break;
                }
                else
                {
                    cout << "输入有误，请重新输入！" << endl;
                }   
            }
        }
        tag = 0;

        // 电话
        cout << "是否修改联系人电话（1-是）：";
        cin >> tag;
        if (tag == 1)
        {
            cout << "请输入修改后的电话。" << endl;
            string phone;
            cin >> phone;
            abs->personArray[ret].m_phone = phone;
            cout << "电话修改成功" << endl;
        }
        tag = 0;

        // 地址
        cout << "是否修改联系人地址（1-是）：";
        cin >> tag;
        if (tag == 1)
        {
            cout << "请输入修改后的地址: ";
            string addr;
            cin >> addr;
            abs->personArray[ret].m_Addr = addr;
            cout << "地址修改成功。" << endl;
        }
          
    }
    
    cout << "按任意键继续。";
    string s;
    cin >> s;
    system("clear");
    
}


// 清空联系人
void clearBooks(Addressbooks * abs)
{
    cout << "请确定是否彻底清空联系人（1-是）：";
    int tag = 0;
    cin >> tag;
    if (tag == 1)
    {
        abs->m_size = 0;  // 逻辑清空
        cout << "清空联系人成功！" << endl;
    }
    
    cout << "按任意键继续。";
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
            deletePerson(&abs);
            break;
        case 4:  // 查找联系人
            findPerson(&abs);
            break;
        case 5:  // 修改联系人
            modifyPerson(&abs);
            break;
        case 6:  // 清空联系人
            clearBooks(&abs);
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
