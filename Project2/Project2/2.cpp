#include <iostream>
using namespace std;	
#include <string>
#include<ctime>
#include "swap1.h"
#include "swap2.h"
#include"BubbleSort.h"	
#include "PrintArray.h"	
void test01(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void test02(int* a, int* b)
{
	int temp = *a;
	* a = *b;
	*b = temp;
}
void test03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
/*����
int* func()
{
	int* p = new int(10);
	return p;
}*/
/*ջ��
int * func()
{
	int a = 10;
	return &a;
}*/
/*ȫ����
int a = 10;
int b = 20;
const int g = 20;
const int h = 20;*/
/*
struct Hero {
	string name;
	int age ;
	string sex;
};

void bubblesort(Hero arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j].age > arr[j + 1].age) {
				Hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printInfo(Hero arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "������" << arr[i].name << "\t������" << arr[i].age << "\t�Ա���" <<arr[i].sex<< endl;
	}
}*/


/*�ɼ�����
struct Student {
	string name;
	int score;
};
struct Teacher {
	string name;
	struct Student Sarray[5];
};

void allocatespace(Teacher Tarray[], int len) {
	string nameSeed = "ABCDE";
	
	for (int i = 0; i < len; i++) {
		Tarray[i].name = "Teacher_";
		Tarray[i].name += nameSeed[i];
		for (int j = 0; j < 5; j++) {
			int random = rand() % 61 + 40;
			Tarray[i].Sarray[j].name = "Student_";
			Tarray[i].Sarray[j].name += nameSeed[j];
			Tarray[i].Sarray[j].score = random;
		}
	}
}
void printInfo(Teacher Tarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "��ʦ��������:" << Tarray[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\tѧ����������:" << Tarray[i].Sarray[j].name << "  �ɼ���:" << Tarray[i].Sarray[j].score << endl;
		}
	}
}

*/



		


/*Ƕ�׽ṹ����ṹ��ָ��	��const
struct student {
	string name;
	int age;
	int score;
};




struct Student {
	string name;
	int age;
	int score;
};

struct Teacher {
	int number;
	int age;
	string name;
	struct Student stu1;
	struct Student stu2;	
};


void printstudent1(struct Student stu) {
	stu.age = 28;
	cout << "�Ӻ����� ������" << stu.name << "\t������" << stu.age << "\t�ɼ���" << stu.score << endl;
}
void printstudent2(struct Student* stu) {
	stu->age = 30;
	cout << "�Ӻ����� ������" << stu->name << "\t������" << stu->age << "\t�ɼ���" << stu->score << endl;
}

void stuinfor(const struct student *stu) {	
	cout << "������" << stu->name << "\t������" << stu->age << "\t�ɼ���" << stu->score << endl;	
}*/

//#define day 7 �곣������
	int main(){
	/*1.1����
	int a = 18;

		cout<< "��èè�����������" << a << endl;
		*/
		/*1.2����
		*constint day = 7; //const���峣��
		//int day = 16; //���󣬳������ܱ��޸�
		cout << "һ����" << day << "��" << endl;

		*/
		/*��.��������
		2.1����
		short num1 = 10;
		int num2 = 10;
		long num3 = 10;
		long long num4 = 10;
		cout << "num1��" << num1 << endl;
		cout << "num2��" << num2 << endl;
		cout << "num3��" << num3 << endl;
		cout << "num4��" << num4 << endl;
		*/
		/* 2.2sizeof�ؼ���
	���ڿ��ڴ��С
	short num1 = 10;
	cout << "num1��ռ���ڴ�ռ���" << sizeof(num1) << endl;
	long long num2 = 29;
	cout << "num2��ռ�Ŀռ���" << sizeof(num2) << endl;*/
	/*2.3ʵ��
	float money1 = 80.29f;
	double money2 = 98.62;
	double sum = money1 + money2;
	cout << "��ʣ" << sum << "��" << endl;
	cout << "float��ռ���ڴ���" << sizeof(money1) << endl;
	cout << "double��ռ���ڴ���" << sizeof(money2) << endl;*/
	/*2.3.2��ѧ������
	float num1 = 3e3;//3*10^3
	cout << "num1����" << num1 << endl;
	float num2 = 3e-4;
	cout << "num����" << num2 << endl;*/
	/*2.4�ַ���
	char ch1 = 'a';
	cout << ch1 << endl;
	cout << sizeof(char) << endl;
	��ѯASCII��
	cout << int(ch1) << endl;*/
	/*2.5ת���ַ�
	cout << "��������C++���š�\n���ߣ�����\n�۸�59.9Ԫ\n��ע���Ƽ��Ķ��½ڣ�\"��һ��\",\"������\""<<endl;
	cout << "ѧ��\t����\t�ɼ�" << endl;
	cout << "001\tС��\t92" << endl;
	cout << "002\tС��\t98" << endl;*/
	/*2.6�ַ�����
	string str1 = "hello world";
	cout << str1 << endl;
	char str2[] = "hello world";
	cout << str2 << endl;*/

	/*2.7bool��
	bool flag = true;
	cout << flag << endl;
	flag = false;
	cout << flag << endl;
	cout << sizeof(flag) << endl;*/

	/*2.8��������
	cout << "������a��ֵ" << endl;
	int a = 0;
	cin >> a;//<<���������>>��ȡ�����
	cout << "a��ֵΪ" << a << endl;

	char f[] = " hello world";
	cin >> f;
	cout << "��èè�����˵" << f << endl;*/

	/*3.1�����
	float a1 = 1.2f;
	float a2 = 0.6f;
	cout << a1 / a2 << endl;*/

	/*ȡģ
	int b1 = 10;
	int b2 = 20;
	cout << b1 % b2 << endl;//С������ȡģ����*/

	/*3.2�����Լ�
	int a = 10;
	int b = a++ * 10;
	cout << b << endl;
	cout << b<< endl;

	int c = 10;
	int d = 10;
	cout << c++ * d << endl;//���ú�ӣ���ʱc=11
	cout << ++c * d << endl;//�ȼӺ���*/

	/*3.3�߼������
	int a = 3; int b = 4;
	cout << a == b << endl///<<����������ȼ�����==������Ϊ��cout<<a)==b<<endl;

	cout << (3 != 4) << endl;
	cout << (3 <= 2) << endl;*/
	/*
	int a = 10; int c = 0;
	int b = 10;
	cout << !a << endl;     //�ǡ���ȡ��
	cout << (a && b )<< endl;     //�롪��ͬʱΪ���Ϊ��
	cout << (a || c) << endl;   */  //�򡪡�ֻ����һ��Ϊ���Ϊ��

	/*�������̽ṹ
	* 4.1˳��ṹ
	int score = 85;
	cout << "���������ĳɼ�:" << endl;
	cin >> score;
	if (score > 90) {
		cout << "�����ķǳ���" << endl;
	}
	else if (score > 80 && score < 90) {
		cout << "�����Ļ�����" << endl;
	}
	else if (score > 70 && score < 80) {
		cout << "����Ҫ����" << endl;
	}
	else {
		cout << "����ҪŬ��ѧϰŶ" << endl;}*/

		/*Ƕ��if���
		cout << "������һ������" << endl;
		int num = 0;
		cin >> num;
		if (num >= 100 && num <= 999) {
			cout << "���������һ����λ��" << endl;
			if ((num % 10) == (num / 10 % 10)) {
				cout << "���������λ���ĸ�λ��ʮλ���" << endl;
			}
		}
			else {
				cout << "�ⲻ��һ����λ��" << endl;
			}*/
			/*С�������
				int a = 0;
				int b = 0;
				int c = 0;
				cout << "������С��a������:" << endl;
				cin >> a;
				cout << "������С��b������:" << endl;
				cin >> b;
				cout << "������С��c������:" << endl;
				cin >> c;
				if (a > b && b > c) {
					cout << "С��a����" << endl;
				}
				if (a > c && c > b) {
					cout << "С��a����" << endl;
				}
				if (b > a && a > c) {
					cout << "С��b����" << endl;
				}
				if (b > c && c > a) {
					cout << "С��b����" << endl;
				}
				if (c > a && a > b) {
					cout << "С��b����" << endl;
				}
				if (c > b && b > a) {
					cout << "С��b����" << endl;
				}*/

				/*
				int a = 0;
				int b = 0;
				int c = 0;
				cout << "������С��a������:" << endl;
				cin >> a;
				cout << "������С��b������:" << endl;
				cin >> b;
				cout << "������С��c������:" << endl;
				cin >> c;
				if (a > b) {
					if (a > c) { cout << "С��a����"<<endl; }
					else { cout << "С��c����" << endl; }
				}
				else {
					if (b > c) { cout << "С��b����" << endl; }
					else { cout << "С��c����"<< endl; }
				}
				*/

				/*4.1.2��Ŀ�����
				int a = 10;
				int b = 93;
				int c;
				c = (a > b ? a : b);
				cout << "c��" << c << endl;

				//���ڸ�ֵ
				(a > b ? a : b) = 5;
				cout << "a��" << a << endl << "b��" << b << endl << "c��" << c << endl;*/

				/*4.1��֧�ṹ
				int month;
				cout << "�������·�:" << endl;
				cin >> month;
				switch (month) {
				case 3:
				case 4:
				case 5:
					cout << "���쵽����" << endl;
					break;
				case 6:
				case 7:
				case 8:
					cout << "��������" << endl;
					break;
				case 9:
				case 10:
				case 11:
					cout << "��������" << endl;
					break;
				case 12:
				case 1:
				case 2:
					cout << "���쵽��" << endl;
					break;
				default:
					cout << "����������1-12�·�������һ����" << endl;
						break;
				}*/


				/*4.2whileѭ��
				int num = 0;
				while (num < 10) {
					cout << num << endl;
					num++;
				}*/


				/*������
				srand(time(0));//�������������
				int num = rand() % 100;
				cout << "���һ������" << endl;
				int val=0;
				while (val != num) {
				cin >> val;
					if (val < num) { cout << "��µ��е�С��"<<endl;}
					if (val > num) { cout << "��µ��е����" << endl; }
				}
				cout << "��ϲ��¶���" << endl;*/

				/*do while���
				int num = 0;
				do {
					cout << num << endl;
					num++;
				} while (num < 10);*/

				/*ʧ��
				int num = 100;
				do {
				int a = num / 100;
				int b = num / 10 % 10;
				int c = num % 10;
				int sum = a * a * a + b * b * b + c * c * c;
				num++;
				} while (num<1000);
				if (num ==sum) { cout << "��һ��ˮ�ɻ�����" << num << endl; };
				num++;*/

				/*ˮ�ɻ���
				int num = 100;
				do{
					int a = num / 100;
					int b = num / 10 % 10;
					int c = num % 10;
					int sum = a * a * a + b * b * b + c * c * c;
					if (sum == num) { cout << "��һ��ˮ�ɻ�����" << num << endl; };
					num++;
				} while (num < 1000);*/
				/*4.3forѭ��������С��Ϸ
				for (int i = 1; i <= 100; i++) {
					if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7) {
						cout << "��" << endl;
					}
					else {
						cout << i << endl;
					}
				}*/
				/*4.4Ƕ��ѭ��
			for (int i = 1; i < 10; i++){
				for (int j = 1; j < 10; j++){
					cout << "*" << "\t";

				}
				cout << endl;
			}
			*/
			/*�˷���
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= i; j++) {
					cout << j << "*" << i << "=" << i * j << "\t";
				}
				cout << endl;
			}	*/

			/*
			for (int i = 1; i <= 100; i++) {
				for (int j = 1; j <= i; j++) {
					cout << j << "*" << i << "=" << i * j << "\t";
				}
				cout << endl;
			}*/

			/*break���
			int num = 1;
			int sum=0;
			while (sum < 50) {
				sum += num;
				num++;
					if (sum > 50) {
						cout << "���һ����" << num-1 << endl;
						cout << "sum��" << sum << endl;

					}

			}*/

			/*continue��䣨�Ѿ����߼��Ż���
			int num = 1;
			while (num <= 20) {
				if (num % 4 == 0) { num++; continue; }
				if (num % 3 == 0) {
					cout << "3�ı���" << num << endl;
					num++;
				}
				else {
					cout << num << endl;
					num++;
				}



			}*/

			/*goto ���
				int num = 1;
			FLAG:
				cout << "����������" << endl;
				string password;
				cin >> password;
				if (num < 3) {
				if (password == "123456") {
					cout << "������ȷ����ӭʹ�ñ�ϵͳ" << endl;
					return 0;
				}

				else {
					cout << "�����������������" << endl;
					num++;
					goto FLAG;

				}
			}
				else{
					cout << "�������������࣬�˺�������������ϵ����Ա" << endl;
				}

				*/



				/*��.����
				5.1һά����Ķ���
				int sum = 0;
				int arr1[] = { 5,2,9,1,7,3 };
				int minVal = arr1[0];
				for (int i = 0; i < 6; i++) {
					cout << arr1[i] << endl;
					sum += arr1[i];
					if (arr1[i] < minVal) {
						minVal = arr1[i];
					}
						}
					cout << "sum��" << sum << endl;
					cout << "�����е���Сֵ��" << minVal << endl;	*/

					/*5.2������
					int arr1[] = { 1,3,6,8,0,3 };
					cout << "arr1�ĵ�ַ��" << int(arr1)<< endl;
					cout << "arr1[0]�ĵ�ַ��" << int( & arr1[0]) << endl;
					cout << "arr1[1]�ĵ�ַ��" <<int( & arr1[1]) << endl;
					cout << "arr1���ڴ���" << sizeof(arr1) << endl;
					cout << "arr1��Ԫ�ظ�����" << sizeof(arr1) / sizeof(arr1)[0] << endl;*/

					/*С�������
					int arr1[5] = { 300,350,200,400,250 };
					int maxVal = arr1[0];
					for (int i = 0; i < 5; i++) {
						if (arr1[i] > maxVal) {
							maxVal = arr1[i];
						}
					}
					cout << "���ص�С��������" << maxVal << endl;	*/

					/*���鵹���㷨
					int arr1[5] = { 1,5,2,8,4 };
					for (int I = 0; I < 5; I++) {
						cout << "����arr1��Ԫ����" << arr1[I] << "\t";
					}

					int start = 0;
					int end = sizeof(arr1) / sizeof(arr1[0]) - 1;
					long temp = 0;
					while (start < end) {
						temp = arr1[start];
						arr1 [start]= arr1[end];
						arr1[end] = temp;
							start++;
							end--;


					}
					for(int j=0;j<5;j++){
						cout << "����arr1��Ԫ����" <<arr1[j] << "\t";
					}*/

					/***********ð������
						int arr1[] = { 0,3,8,2,9,5,4,7,6 ,1 };
						int temp;
						for (int i = 0; i < 9; i++) {
							for (int j = 0; j < 10 - i - 1; j++) {
								if (arr1[j] > arr1[j + 1]) {
									temp = arr1[j];
									arr1[j] = arr1[j + 1];
									arr1[j + 1] = temp;
								}
							}
						}
						cout << "������������" << endl;
						for (int k = 0; k < 10; k++) {
							cout << arr1[k] << "\t";
						}
					*/



/*��ά����
int arr[2][3] = { { 1,2,3 },{ 4, 5, 6 } };
for (int i = 0; i < 2; i++) {//����ÿһ��
	for (int j = 0; j < 3; j++) {//����ÿһ��
		cout << arr[i][j] << " ";//�� ����ǿ�ɶ���
	}cout << endl;//ÿ�н��л���
}*/


/*�ɼ�ͳ��
string names[] = { "����","����","����" };
int arr1[3][3] = { {100,100,100},{90,50,100},{60,70,80} };
	
for (int i = 0; i < 3; i++) {
	int sum = 0;
	for (int j = 0; j < 3; j++) {
		sum += arr1[i][j];
	}cout << names[i]<<"�ĳɼ���" << sum << endl;
}*/

/*�����Ķ��������
int a = 100;
int b = 102;
int c = add(a, b);
cout << c << endl;*/

/*6.5ֵ����
int a = 10;
int b = 20;
swap(a, b);
cout << a <<" " <<b << endl;*/

/*6.6����������
int c=uiu(a, b);
  cout << "c��" << c << endl;
int a = 12l;
int b = 983;
int c = max(a, b); 
cout << "���ֵ��" << c << endl;*/

/*7.1ָ��Ķ���
int a = 10;
int* p = &a;
cout << "*p��" << *p << endl;	
cout << p << endl;
cout << &a << endl;*/


/*7.2ָ����ڴ��С
int a = 10;
int* p;
p = &a;
cout << "ָ����ռ�ڴ���" << sizeof(int*) << endl;*/

/*7.3��ָ��
int* p = NULL;*/

/*7.4Ұָ��
int* p = (int*)0x1100;
cout << *p << endl;*/

/*ָ�������
int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
int* p = arr;
cout << "arr��һ��Ԫ����" << *p << endl;
cout << "arr�е�Ԫ����" << endl;
for (int i = 0; i < 10; i++) {
	cout << *p << endl;
	p++;
}*/

/*������ָ��
int a = 10;
int b = 20;
cout << "��ʼʱa,b,��ֵ�ֱ���" << a << "\t" << b << endl;
swap1(a, b);
cout << "ֵ���ݺ�a,b,��ֵ�ֱ���" << a << "\t" << b << endl;
swap2(&a, &b);
cout << "��ַ���ݺ�a,b,��ֵ�ֱ���" << a << "\t" << b << endl;*/

/*ָ�뺯��������
int arr[] = { 6,3,7,0,1,8,2,9,5,4 };
int n = sizeof(arr) / sizeof(arr[1]);
BubbleSort(arr, n);
PrintArray(arr, n);*/


/*8.1�ṹ��
struct Student {
	string name;
	int age;
	int score;
};

struct Student s1 = { "����",18,97 };
struct Student s2;
s2.name = "����";
s2.age = 21;
s2.score = 99;
struct Student s3 = { "����",22,93 };
cout << "������" << s1.name << "������" << s1.age << "������" << s1.score << endl;
cout << "������" << s2.name << "������" << s2.age << "������" << s2.score << endl;
cout << "������" << s3.name << "������" << s3.age << "������" << s3.score << endl;*/


/*�ṹ������
struct Student stuarray[] = {
	{"����",18,100},
{ "����", 87, 65 },{"����",54,54} };

for (int i = 0; i < 3; i++) {
	cout << "����" << stuarray[i].name << "\t����" << stuarray[i].age << "\t����" << stuarray[i].score << endl;
}*/

/*�ṹ��ָ��
struct Student s = { "����",18,198 };
Student* p1 = &s;
p1->score=80;
cout << "����" <<p1->name << "\t����" << p1->age << "\t����" << p1->score << endl;*/

/*�ṹ��Ƕ�׽ṹ��
struct Teacher t1;
t1.number = 1000;
t1.age = 43;
t1.name = "����ʦ";
t1.stu1.age = 18;
t1.stu1.name = "����";
t1.stu1.score = 99;
t1.stu2.age = 19;
t1.stu2.name = "����";
t1.stu2.score = 98;
cout << "������" << t1.number << "\t������" << t1.name << "\t������" << t1.age << endl;	
cout << "ѧ��1��������" << t1.stu1.name << "\t������" << t1.stu1.age << "\t�ɼ���" << t1.stu1.score << endl;	
cout << "ѧ��2��������" << t1.stu2.name << "\t������" << t1.stu2.age << "\t�ɼ���" << t1.stu2.score << endl;	*/


/*�ṹ���ֵ�������ַ����
struct Student s1 = { "����",18,97 };
printstudent1(s1);
cout << "�������� ������" << s1.name << "\t������" << s1.age << "\t�ɼ���" << s1.score << endl;	
printstudent2(&s1);	
cout << "�������� ������" << s1.name << "\t������" << s1.age << "\t�ɼ���" << s1.score << endl;	*/


/*
student stu = { "����",18,95 };
stuinfor(&stu);	*/


/*�ɼ�����ϵͳ
srand(time(0));
struct Teacher Tarray[3];	
int len = sizeof(Tarray) / sizeof(Tarray[0]);
allocatespace(Tarray, len);
printInfo(Tarray, len);*/



/*Ӣ�۴�ӡ
struct Hero arr[5]{
	{"����",23,"��" },
	{ "����",22,"��" },
	{ "�ŷ�",20,"��" },
	{ "����",21,"��" },
	{ "����",19,"Ů" } };
printInfo(arr, 5); cout<<endl;
int len = sizeof(arr) / sizeof(arr[0]);	
bubblesort(arr, len);
printInfo(arr, len);*/

/*ȫ����
int c = 10;
int d = 10;
static int e = 10;
static int f = 10;
const int i = 10;
const int j = 10;
cout << "ȫ�ֱ���a�ĵ�ַ��" << int( & a) << endl;
cout << "ȫ�ֱ���b�ĵ�ַ��" << int( & b) << endl;
cout << "�ֲ�����c�ĵ�ַ��" << int( & c) << endl;
cout << "�ֲ�����d�ĵ�ַ��" << int( & d) << endl;
cout << "��̬����e�ĵ�ַ��" <<int( & e) << endl;
cout << "��̬����f�ĵ�ַ��" << int( & f ) << endl;
cout << "const����g�ĵ�ַ��" << int( & g) << endl;
cout << "const����h�ĵ�ַ��" << int( & h) << endl;
cout << "const�����ֲ�i�ĵ�ַ��" << int( & i) << endl;
cout << "const�����ֲ�j�ĵ�ַ��" << int( & j) << endl;
cout << "�ַ��������ĵ�ַ��" << int( & "hello world") << endl;*/

/*1.1ջ��
int* p = func();
cout << *p << endl;//����ָ��	
cout << *p << endl;*/


/*
int* p = func();
cout <<* p << endl;
cout << p << endl;
delete p;
cout << *p << endl;
*/


/*new�����
int* arr = new int[10];
for (int i = 0; i < 10; i++)
{
	arr[i] = i + 100;
}
for (int i = 0; i < 10; i++)
{
	cout << arr[i] << endl;
}
delete[] arr;*/

/*2.1���õĻ���ʹ��
int a = 10;
int& b = a; 
cout << "a��" <<a<< endl;
cout << "b��" <<b<< endl;
b = 20;
cout << "a��" <<a<< endl;
cout << "b��" <<b<< endl;*/


/*2.2���õ�ע������
int a = 10;
int& b = a;
int c = 20;
b = c;
cout << a << b << c << endl;*/
/*2.3���ô���
int a = 10;
int b = 20;
test01(a, b);
cout << "test01��a��bΪ" << a << '\t' << b << endl;
test02(&a, &b);
cout << "test01��a��bΪ" << a << '\t' << b << endl;
test03(a, b);
cout << "test01��a��bΪ" << a << '\t' << b << endl;*/












	return 0;

}
