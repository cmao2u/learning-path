#include <iostream>
using namespace std;
#define MAX 1000 //ͨѶ¼�������	

void showMenu() {
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
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
	Person personArray[MAX]; //ͨѶ¼�б������ϵ������
	int size;     //ͨѶ¼�е�ǰ��Ա�ĸ���
};
void addPerson(addressbooks* adb)
{
	if (adb->size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	string name;
	cout << "����������" << endl;
	cin >> name;
	adb->personArray[adb->size].name = name;
	string number;
	cout << "������绰����" << endl;
	cin >> number;
	adb->personArray[adb->size].number = number;
FLAG:
	int sex;

	cout << "�������Ա�" << endl;

	cout << "1---��" << endl;
	cout << "2---Ů" << endl;
	cin >> sex;
	if (sex == 1 || sex == 2)
	{
		adb->personArray[adb->size].sex = sex;
	}
	else
	{
		cout << "�ֶ������ϴ��������������룺" << endl;
		goto FLAG;
	}
	int age;
	cout << "����������" << endl;
FLAG2:
	cin >> age;
	if (age < 0 || age > 150)
	{
		cout << "�㿪ɶ��Ц,����������:" << endl;
		goto FLAG2;
	}
	adb->personArray[adb->size].age = age;
	string address;
	cout << "�������ַ" << endl;
	cin >> address;
	adb->personArray[adb->size].address = address;
	adb->size++;
	cout << "��ӳɹ�" << endl;
	cout << "��ǰͨѶ¼����Ϊ��" << adb->size << endl;
	system("pause");
	system("cls");
}
void showperson(addressbooks* adb)
{
	if (adb->size == 0) {
		cout << "ͨѶ¼��û����ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i < adb->size; i++)
		{
			cout << "����:" << adb->personArray[i].name << '\t';
			cout << "�绰:" << adb->personArray[i].number << '\t';
			cout << "�Ա�:" << (adb->personArray[i].sex == 1 ? "��" : "Ů") << '\t';
			cout << "����:" << adb->personArray[i].age << '\t';
			cout << "סַ:" << adb->personArray[i].address << endl;
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

	cout << "������ɾ��������" << endl;
	cin >> name;
	int ret = findperson(adb, name);
	if (ret != -1)
	{
		for (int i = ret; i < adb->size; i++)
		{
			adb->personArray[i] = adb->personArray[i + 1];
		}
		adb->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴��� " << endl;
	}
	system("pause");
	system("cls");
}
void Findperson(addressbooks* adb)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = findperson(adb, name);
	if (ret != -1)
	{
		cout << "����:" << adb->personArray[ret].name << '\t';
		cout << "�绰:" << adb->personArray[ret].number << '\t';
		cout << "�Ա�:" << (adb->personArray[ret].sex == 1 ? "��" : "Ů") << '\t';
		cout << "����:" << adb->personArray[ret].age << '\t';
		cout << "סַ:" << adb->personArray[ret].address << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(addressbooks* adb)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = findperson(adb, name);
	if (ret != -1)
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		adb->personArray[ret].name = name;
		string number;
		cout << "������绰����" << endl;
		cin >> number;
		adb->personArray[ret].number = number;
	FLAG:
		int sex;

		cout << "�������Ա�" << endl;

		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			adb->personArray[ret].sex = sex;
		}
		else
		{
			cout << "�ֶ������ϴ��������������룺" << endl;
			goto FLAG;
		}
		int age;
		cout << "����������" << endl;
	FLAG2:
		cin >> age;
		if (age < 0 || age > 150)
		{
			cout << "�㿪ɶ��Ц,����������:" << endl;
			goto FLAG2;
		}
		adb->personArray[ret].age = age;
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		adb->personArray[ret].address = address;
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void clearperson(addressbooks* adb)
{
	adb->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select = 0;
	struct addressbooks adb; // ��adb�������ͳ�ʼ���Ƶ�ѭ���ⲿ������ÿ��ѭ��������ʵ����
	adb.size = 0;
	while (1)
	{
		showMenu();
		cin >> select;
		if (cin.fail())// �������ʧ�ܣ��������״̬�����Դ��������
		{
			cin.clear(); // �������״̬
			cin.ignore(10000, '\n'); // �����������룬ֱ�����з�
			cout << "����������������֣�" << endl;
			continue; // ������ʾ�˵�
		}
		switch (select)
		{
		case 1:        //�����ϵ��
			addPerson(&adb);
			break;
		case 2:        //��ʾ��ϵ��
			showperson(&adb);
			break;
		case 3:        //ɾ����ϵ��
		{
			string name;
			deleteperson(&adb, name);
			break;
		}
		case 4:        //������ϵ��
		{
			Findperson(&adb);
			break;
		}
		case 5:        //�޸���ϵ��  
			modifyperson(&adb);
			break;
		case 6:        //�����ϵ��
			clearperson(&adb);
			break;
		case 0:        //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		default:
			cout << "��������Ч����" << endl;
			break;
		}
	}
	return 0;
}