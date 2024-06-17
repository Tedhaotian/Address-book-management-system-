//ͨѶ¼����ϵͳ
//
#include<iostream>
using namespace std;
#define MAX 1000
//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	int m_Phone;
	string m_Addr;
};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};
//1�������ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˲������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		int sex;
		cout << "�������Ա�(����1����2)��" << endl;
		cout << "1 ���� �� " << endl;
		cout << "2 ���� Ů " << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		cout << "������绰���룺" << endl;
		int phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string add;
		cout << "�������ͥ��ַ��" << endl;
		cin >> add;
		abs->personArray[abs->m_Size].m_Addr = add;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//2����ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ��
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t"
				<< "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺 " << abs->personArray[i].m_Age << "\t"
				<< "�绰:  " << abs->personArray[i].m_Phone << "\t"
				<< "��ַ�� " << abs->personArray[i].m_Addr << endl;
		}

	}
	system("pause");
	system("cls");

}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼ ����2 �Ա�����
int isExist(Addressbooks* abs, string name)
{
	//�ҵ��û����������
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ��ˣ�����������������е��±���
		}

	}
	return -1;//�������������û���ҵ�������-1
}
//3��ɾָ���ĳ���ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//Addressbooks temp = abs[i];
			//abs[i] = abs[i + 1];
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//4������ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{

		cout << "������ " << abs->personArray[ret].m_Name << "\t"
			<< "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t"
			<< "���䣺 " << abs->personArray[ret].m_Age << "\t"
			<< "�绰:  " << abs->personArray[ret].m_Phone << "\t"
			<< "��ַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5���޸�ָ����ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		cout << "�������Ա�(����1����2)��" << endl;
		cout << "1 ���� �� " << endl;
		cout << "2 ���� Ů " << endl;
		int i = 0;
		cin >> i;
		while (true)
		{
			if (i == 1 || i == 2)
			{
				abs->personArray[ret].m_Sex = i;
				break;
			}
			cout << "������������������" << endl;
		}
		cout << "���������䣺 " << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		cout << "������绰:  " << endl;
		int phone;
		cin >> phone;

		abs->personArray[ret].m_Phone = phone;
		cout << "�������ַ�� " << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_Addr = add;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//6�������ϵ��
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

//�˵�����
void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ����ǰͨѶ¼����
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{

		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);//���õ�ַ���ݣ��޸�ʵ��
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			/*	{
					cout << "������ɾ����ϵ�������� " << endl;
					string name;
					cin >> name;
					if (isExist(&abs, name) == -1)
					{
						cout << "���޴���" << endl;
					}
					else
					{
						cout << "�ҵ�����" << endl;
					}
				}*/
			deletePerson(&abs);
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			clearPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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