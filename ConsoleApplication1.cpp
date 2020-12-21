
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;


class Mebel {

	string name;
	int kol;
public:
	Mebel(string name, int kol)
	{
		(*this).name = name;
		(*this).kol = kol;
	}
	void get_print()
	{
		cout <<"�������������: " << (*this).name << " ����������: " <<(*this).kol;
		
	}
};

class Table : virtual public Mebel {
protected:
	int lenth, width;
	int high; string name;
	int kol;
public:
	Table(string name, int kol, int lenth, int width, int high) :Mebel(name, kol)

	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).lenth = lenth;
		(*this).width = width;
		(*this).high = high;


	}
	string get_Table()
	{
		ostringstream full;
		full << "\n������������� �����: " <<(*this).name << " \n���������� ������: " <<(*this).kol << "\n����� �����: " <<(*this).lenth 
			<< "\n ������ �����: " <<(*this).width << " \n������ �����: " <<(*this).high;
		return full.str();
	}

	void get_print()
	{
		Mebel::get_print();
		cout << "\n������������� �����: " <<(*this).name << "\n ���������� ������: " <<(*this).kol << "\n����� �����: " 
			<<(*this).lenth << "\n ������ �����: " <<(*this).width << "\n ������ �����: " <<(*this).high;
	
	}
	
};


class bookcase : virtual public Mebel {
protected:
	string type;
	string material2;
	string name;
	int kol;

public:
	bookcase(string name, int kol, string type, string material2) : Mebel(name, kol)
	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).type = type;
		(*this).material2 = material2;
	}

	void get_print()
	{
		cout << "\n ������������� �����: " <<(*this).name << "\n ����������: " <<(*this).kol << "\n ��� �����: "
			<<(*this).type << "\n �������� : " <<(*this).material2;
	}
	string get_bookcase()
	{
		ostringstream nam;
		nam << "������������� �����: " <<(*this).name << " ���������� ������: " <<(*this).kol << " ��� �����: " <<(*this).type << " �������� : " <<(*this).material2;
		return nam.str();
	}

};

class Design : public Table, public bookcase
{

	string color;
	string ornament;
	string name;

public:Design(string color, string ornament, string name, int kol, int lenth, string type, string material2, int width, int high) :
	bookcase(name, kol, type, material2), Table(name, kol, lenth, width, high), Mebel(name, kol)
{
	(*this).name = name;
	(*this).color = color;
	(*this).ornament = ornament;
}

	
	   void design_prnt()
	   {

		   cout << "\n ����: " <<(*this).color << "\n ������� ���������: " <<(*this).ornament;
	   }
};

void seeCase()
{
	string name; int kol=0; int lenth=0; int width=0; int high=0;
	string type; string material2;
	cout << "������� ���������� � �����\n ";
	cout << "�������������: ";
	cin >> name;
	cout << "����������: "; cin >> kol;
	while (kol < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> kol;
	}

	cout << "��� �����: "; cin >> type;
	cout << "�������� : "; cin >> material2;
	bookcase* st = new bookcase(name, kol, type, material2);
	cout <<(*st).get_bookcase() << endl;
	Mebel *p[2];//����� ����������
	bookcase obj1(name, kol, type, material2);//�������
	p[0] = &obj1; // ������������� ������� ����������

	cout << "����� ";
	p[0]->get_print();

}

void seeTable()
{
	string name; int kol=0; int lenth=0; int width=0; int high=0;
	string type; string material2; string color; string ornament;


	cout << "������� ���������� � �����\n ";
	cout << "�������������: ";
	cin >> name;
	cout << "����������: "; cin >> kol;
	while (kol < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> kol;
	}
	cout << "����� �����: "; cin >> lenth;
	while (lenth < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> lenth;
	}
	cout << "������ �����: "; cin >> width;
	while (width < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> width;
	}
	cout << "������ �����: "; cin >> high;
	while (high < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> high;
	}

	cout << "���� �����: "; cin >> color;
	cout << "������� ��������� (��/���): "; cin >> ornament;
	Design *d;
	Design obj3(color, ornament, name, kol, lenth, type, material2, width, high);
	//Design obj3("red", "no","kk", 300, 3, "kk", "dd", 33, 45);
	d = &obj3;
	Mebel *p[2];//����� ����������
	Table obj2(name, kol, lenth, width, high);
	p[1] = &obj2;

	cout << "����� ";
	p[1]->get_print();
	d->design_prnt();
	Table* stud = new Table(name, kol, lenth, width, high);


	cout <<(*stud).get_Table() << endl;

}

int main() {
	setlocale(LC_ALL, "Russian");

	int input;

	do {
		cout << "\n1. ����\n";
		cout << "2. ����\n";
		cout << "3. Exit\n";
		cout << "��� �����: ";
		cin >> input;


		{
			switch (input) {
			case 1:
				seeTable();
				break;
			case 2:
				seeCase();
				break;
			case 3:
				cout << "����������!\n";
				break;
			default:
				cout << "������\n";
				break;
			}

			cin.get();
		}
	} while (input != 3);


	system("pause>>NUL");
	return 0;
}