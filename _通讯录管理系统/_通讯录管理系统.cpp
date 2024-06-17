//通讯录管理系统
//
#include<iostream>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	int m_Phone;
	string m_Addr;
};
//设计通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};
//1、添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满，如果满了不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		int sex;
		cout << "请输入性别(输入1或者2)：" << endl;
		cout << "1 —— 男 " << endl;
		cout << "2 —— 女 " << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		cout << "请输入电话号码：" << endl;
		int phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string add;
		cout << "请输入家庭地址：" << endl;
		cin >> add;
		abs->personArray[abs->m_Size].m_Addr = add;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//2、显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为零
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t"
				<< "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"
				<< "年龄： " << abs->personArray[i].m_Age << "\t"
				<< "电话:  " << abs->personArray[i].m_Phone << "\t"
				<< "地址： " << abs->personArray[i].m_Addr << endl;
		}

	}
	system("pause");
	system("cls");

}
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks* abs, string name)
{
	//找到用户输入的姓名
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到了，返回这个人在数组中的下标编号
		}

	}
	return -1;//如果遍历结束都没有找到，返回-1
}
//3、删指定的除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//Addressbooks temp = abs[i];
			//abs[i] = abs[i + 1];
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//4、查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//找到联系人
	{

		cout << "姓名： " << abs->personArray[ret].m_Name << "\t"
			<< "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t"
			<< "年龄： " << abs->personArray[ret].m_Age << "\t"
			<< "电话:  " << abs->personArray[ret].m_Phone << "\t"
			<< "地址： " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5、修改指定联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//找到联系人
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		cout << "请输入性别(输入1或者2)：" << endl;
		cout << "1 —— 男 " << endl;
		cout << "2 —— 女 " << endl;
		int i = 0;
		cin >> i;
		while (true)
		{
			if (i == 1 || i == 2)
			{
				abs->personArray[ret].m_Sex = i;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "请输入年龄： " << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		cout << "请输入电话:  " << endl;
		int phone;
		cin >> phone;

		abs->personArray[ret].m_Phone = phone;
		cout << "请输入地址： " << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_Addr = add;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//6、清空联系人
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

//菜单界面
void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化当前通讯录人数
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{

		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			addPerson(&abs);//利用地址传递，修改实参
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			/*	{
					cout << "请输入删除联系人姓名： " << endl;
					string name;
					cin >> name;
					if (isExist(&abs, name) == -1)
					{
						cout << "查无此人" << endl;
					}
					else
					{
						cout << "找到此人" << endl;
					}
				}*/
			deletePerson(&abs);
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			clearPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}