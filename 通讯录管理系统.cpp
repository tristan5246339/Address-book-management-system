#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//设计联系人的结构体
struct Person
{
	//姓名
	string p_name;
	//性别 1.男 2.女
	int p_sex;
	//年龄
	int p_age;
	//电话
	string p_phone;
	//住址
	string p_addr;
};
//通讯录的结构体
struct  Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录的联系人个数
	int p_size;
};


//1.添加联系人
void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->p_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->p_size].p_name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是 1 或者 2 可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->p_size].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		
		//年龄
		int age=0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->p_size].p_age = age;

		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->p_size].p_phone = phone;
		
		//住址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->p_size].p_addr = addr;
		
		//更新通讯录人数
		abs->p_size++;

		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}


//2.显示所有联系人
void showPerson(Addressbooks * abs)
{
	//判断通讯录中的人数是否为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->p_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->p_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].p_name << "\t";
			cout << "性别：" << (abs->personArray[i].p_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].p_age << "\t";
			cout << "电话：" << abs->personArray[i].p_phone << "\t";
			cout << "地址：" << abs->personArray[i].p_addr << endl;
		}
		
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}



//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，不存在返回 -1
//参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->p_size; i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].p_name == name)
		{
			return i;
		}
	}
	return -1;//如果遍历结束都没有找到，返回-1
}


//3.删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入删除联系人姓名：" << endl;

	string name;
	cin >> name;

	//ret == -1  未查到
	//ret != -1  查到了
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//查找到人，进行删除操作
		for (int i = ret; i < abs->p_size; i++)
		{
			//数组迁移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//更新通讯录中的人数
		abs->p_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}



//4.查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定联系人是否存在通讯录中
	int ret = isExist(abs, name);

	//找到联系人
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].p_name << "\t";
		cout << "性别：" << (abs->personArray[ret].p_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].p_age << "\t";
		cout << "电话：" << abs->personArray[ret].p_phone << "\t";
		cout << "地址：" << abs->personArray[ret].p_addr << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}


//5.修改指定联系人信息
void modifyPerson(Addressbooks * abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)//找到指定联系人
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].p_name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是 1 或者 2 可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}


		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].p_age = age;

		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[ret].p_phone = phone;

		//住址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[ret].p_addr = addr;

		cout << "修改成功！" << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}


//6.清空所有联系人
void clearPerson(Addressbooks* abs)
{
	cout << "你真的要清空联系人吗？" << endl;
	cout << "1 --- 确认清空" << endl;
	cout << "2 --- 取消清空" << endl;
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
			cout << "输入错误，请重新输入" << endl;
		}
	}
	if (ret == 1)
	{
		abs->p_size = 0;//将当前记录联系人数量置为0，做逻辑清空操作
		cout << "通讯录已清空" << endl;
	}
	else
	{
		cout << "已取消清空通讯录" << endl;
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}


//菜单界面
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****7.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}



int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前的人员个数
	abs.p_size=0;

	int select=0;  //创建用户输入的变量
	
	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1.添加联系人
			addPerson(&abs); //利用地址传递可以修改实参
			break;
		case 2://2.显示联系人
			showPerson(&abs);
			break;
		case 3://3.删除联系人
			deletePerson(&abs);
			break;
		case 4://4.查找联系人
			findPerson(&abs);
			break;
		case 5://5.修改联系人
			modifyPerson(&abs);
			break;
		case 6://6.清空联系人
			clearPerson(&abs);
			break;
		case 7://7.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	


}
