#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//�����ϵ�˵Ľṹ��
struct Person
{
	//����
	string p_name;
	//�Ա� 1.�� 2.Ů
	int p_sex;
	//����
	int p_age;
	//�绰
	string p_phone;
	//סַ
	string p_addr;
};
//ͨѶ¼�Ľṹ��
struct  Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int p_size;
};


//1.�����ϵ��
void addPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->p_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->p_size].p_name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;

		while (true)
		{
			//���������� 1 ���� 2 �����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->p_size].p_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		
		
		//����
		int age=0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->p_size].p_age = age;

		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->p_size].p_phone = phone;
		
		//סַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->p_size].p_addr = addr;
		
		//����ͨѶ¼����
		abs->p_size++;

		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");//��������
	}
}


//2.��ʾ������ϵ��
void showPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�е������Ƿ�Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->p_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->p_size; i++)
		{
			cout << "������" << abs->personArray[i].p_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].p_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].p_age << "\t";
			cout << "�绰��" << abs->personArray[i].p_phone << "\t";
			cout << "��ַ��" << abs->personArray[i].p_addr << endl;
		}
		
	}
	system("pause");//�밴���������
	system("cls");//��������
}



//�����ϵ���Ƿ���ڣ�������ڷ�����ϵ�����������еľ���λ�ã������ڷ��� -1
//����1 ͨѶ¼ ����2 �Ա�����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->p_size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].p_name == name)
		{
			return i;
		}
	}
	return -1;//�������������û���ҵ�������-1
}


//3.ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "������ɾ����ϵ��������" << endl;

	string name;
	cin >> name;

	//ret == -1  δ�鵽
	//ret != -1  �鵽��
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//���ҵ��ˣ�����ɾ������
		for (int i = ret; i < abs->p_size; i++)
		{
			//����Ǩ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//����ͨѶ¼�е�����
		abs->p_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	//�������������
	system("pause");
	system("cls");
}



//4.����ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ����ϵ���Ƿ����ͨѶ¼��
	int ret = isExist(abs, name);

	//�ҵ���ϵ��
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].p_name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].p_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].p_age << "\t";
		cout << "�绰��" << abs->personArray[ret].p_phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].p_addr << endl;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}

	//�������������
	system("pause");
	system("cls");
}


//5.�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks * abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)//�ҵ�ָ����ϵ��
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].p_name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;

		while (true)
		{
			//���������� 1 ���� 2 �����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].p_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}


		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].p_age = age;

		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[ret].p_phone = phone;

		//סַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[ret].p_addr = addr;

		cout << "�޸ĳɹ���" << endl;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}

	//�������������
	system("pause");
	system("cls");
}


//6.���������ϵ��
void clearPerson(Addressbooks* abs)
{
	cout << "�����Ҫ�����ϵ����" << endl;
	cout << "1 --- ȷ�����" << endl;
	cout << "2 --- ȡ�����" << endl;
	int ret;

	while (true)
	{
		cin >> ret;
		if (ret == 1 || ret == 2)
		{
			break;
		}
		else
		{
			cout << "�����������������" << endl;
		}
	}
	if (ret == 1)
	{
		abs->p_size = 0;//����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
		cout << "ͨѶ¼�����" << endl;
	}
	else
	{
		cout << "��ȡ�����ͨѶ¼" << endl;
	}

	//�������������
	system("pause");
	system("cls");
}


//�˵�����
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****7.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
}



int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ����Ա����
	abs.p_size=0;

	int select=0;  //�����û�����ı���
	
	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1.�����ϵ��
			addPerson(&abs); //���õ�ַ���ݿ����޸�ʵ��
			break;
		case 2://2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4.������ϵ��
			findPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6.�����ϵ��
			clearPerson(&abs);
			break;
		case 7://7.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	


}
