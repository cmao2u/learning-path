#include <iostream>
using namespace std;
#define MAX 1000 //通讯录最大容量	

void showMenu() {
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}
struct Person
{
	string name;
	string number;
	int sex;
	int age;
	string address;
};
struct addressbooks
{
	Person personArray[MAX]; //通讯录中保存的联系人数组
	int size;     //通讯录中当前人员的个数
};
void addPerson(addressbooks* adb)
{
	if (adb->size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	string name;
	cout << "请输入姓名" << endl;
	cin >> name;
	adb->personArray[adb->size].name = name;
	string number;
	cout << "请输入电话号码" << endl;
	cin >> number;
	adb->personArray[adb->size].number = number;
FLAG:
	int sex;

	cout << "请输入性别" << endl;

	cout << "1---男" << endl;
	cout << "2---女" << endl;
	cin >> sex;
	if (sex == 1 || sex == 2)
	{
		adb->personArray[adb->size].sex = sex;
	}
	else
	{
		cout << "沃尔玛塑料袋，给我重新输入：" << endl;
		goto FLAG;
	}
	int age;
	cout << "请输入年龄" << endl;
FLAG2:
	cin >> age;
	if (age < 0 || age > 150)
	{
		cout << "你开啥玩笑,给我重新输:" << endl;
		goto FLAG2;
	}
	adb->personArray[adb->size].age = age;
	string address;
	cout << "请输入地址" << endl;
	cin >> address;
	adb->personArray[adb->size].address = address;
	adb->size++;
	cout << "添加成功" << endl;
	cout << "当前通讯录人数为：" << adb->size << endl;
	system("pause");
	system("cls");
}
void showperson(addressbooks* adb)
{
	if (adb->size == 0) {
		cout << "通讯录内没有联系人" << endl;
	}
	else
	{
		for (int i = 0; i < adb->size; i++)
		{
			cout << "姓名:" << adb->personArray[i].name << '\t';
			cout << "电话:" << adb->personArray[i].number << '\t';
			cout << "性别:" << (adb->personArray[i].sex == 1 ? "男" : "女") << '\t';
			cout << "年龄:" << adb->personArray[i].age << '\t';
			cout << "住址:" << adb->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
int findperson(addressbooks* adb, string name)
{
	for (int i = 0; i < adb->size; i++)
	{
		if (adb->personArray[i].name == name)
		{
			return i;
		}

	}
	return -1;
}
void deleteperson(addressbooks* adb, string name)
{

	cout << "请输入删除人名字" << endl;
	cin >> name;
	int ret = findperson(adb, name);
	if (ret != -1)
	{
		for (int i = ret; i < adb->size; i++)
		{
			adb->personArray[i] = adb->personArray[i + 1];
		}
		adb->size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人 " << endl;
	}
	system("pause");
	system("cls");
}
void Findperson(addressbooks* adb)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = findperson(adb, name);
	if (ret != -1)
	{
		cout << "姓名:" << adb->personArray[ret].name << '\t';
		cout << "电话:" << adb->personArray[ret].number << '\t';
		cout << "性别:" << (adb->personArray[ret].sex == 1 ? "男" : "女") << '\t';
		cout << "年龄:" << adb->personArray[ret].age << '\t';
		cout << "住址:" << adb->personArray[ret].address << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* adb)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = findperson(adb, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		adb->personArray[ret].name = name;
		string number;
		cout << "请输入电话号码" << endl;
		cin >> number;
		adb->personArray[ret].number = number;
	FLAG:
		int sex;

		cout << "请输入性别" << endl;

		cout << "1---男" << endl;
		cout << "2---女" << endl;
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			adb->personArray[ret].sex = sex;
		}
		else
		{
			cout << "沃尔玛塑料袋，给我重新输入：" << endl;
			goto FLAG;
		}
		int age;
		cout << "请输入年龄" << endl;
	FLAG2:
		cin >> age;
		if (age < 0 || age > 150)
		{
			cout << "你开啥玩笑,给我重新输:" << endl;
			goto FLAG2;
		}
		adb->personArray[ret].age = age;
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		adb->personArray[ret].address = address;
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
}

void clearperson(addressbooks* adb)
{
	adb->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select = 0;
	struct addressbooks adb; // 将adb的声明和初始化移到循环外部，避免每次循环都重新实例化
	adb.size = 0;
	while (1)
	{
		showMenu();
		cin >> select;
		if (cin.fail())// 如果输入失败，清除错误状态并忽略错误的输入
		{
			cin.clear(); // 清除错误状态
			cin.ignore(10000, '\n'); // 清除错误的输入，直到换行符
			cout << "输入错误，请输入数字！" << endl;
			continue; // 重新显示菜单
		}
		switch (select)
		{
		case 1:        //添加联系人
			addPerson(&adb);
			break;
		case 2:        //显示联系人
			showperson(&adb);
			break;
		case 3:        //删除联系人
		{
			string name;
			deleteperson(&adb, name);
			break;
		}
		case 4:        //查找联系人
		{
			Findperson(&adb);
			break;
		}
		case 5:        //修改联系人  
			modifyperson(&adb);
			break;
		case 6:        //清空联系人
			clearperson(&adb);
			break;
		case 0:        //退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
		default:
			cout << "请输入有效数字" << endl;
			break;
		}
	}
	return 0;
}