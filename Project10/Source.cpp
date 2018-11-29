#include <iostream>
#include <string>
using namespace std;

class Coffee
{
private:
	static int IDGenerator;
	int ID;
	string name;
	string type;
	string orgin;
	double rating;
public:
	Coffee();
	void getEntry();
	friend ostream& operator<<(ostream &o, Coffee& i);
	~Coffee()
	{

	}
};

int Coffee::IDGenerator = 1;

class CoffeeList
{
private: 
	int numItems;
	Coffee iList[100];
public:
	CoffeeList();
	void addItem();
	bool check(string);
	void showList();
};

Coffee::Coffee()
{
	ID = IDGenerator++;
	name = "";
	type = "";
	orgin = "";
	rating = 0; 
}

ostream& operator<<(ostream &o, Coffee& i)
{
	o << "ID: " << i.ID << endl;
	o << "name " << i.name << endl;
	o << "Type: " << i.type << endl;
	o << "Orgin: " << i.orgin << endl;
	o << "Rating: " << i.rating << endl;

	return o;
}

void Coffee::getEntry()
{
	cout << "Enter name of coffee " << endl;
	getline(cin, name);
	cout << "Enter type of coffee" << endl;
	getline(cin, type);
	cout << "Enter orgin of coffee" << endl;
	getline(cin, orgin);
	cout << "Enter rating of coffee" << endl;
	cin >> rating;
	cin.ignore();
	cin.clear();

}

CoffeeList::CoffeeList()
{
	numItems = 0;
}

bool CoffeeList::check(string)
{
	
}
void CoffeeList::addItem()
{
	iList[numItems].getEntry();
	numItems++; // counts the total number of items 
}

void CoffeeList::showList()
{
	for (int i = 0; i < numItems; i++)
		cout << iList[i] << endl;
}

int main()
{
	CoffeeList listA;
	int enter = 1;
	while (enter == 1)
	{
		listA.addItem();
		cout << "press 1 if you would like to add an entry" << endl;
		cin >> enter;
		cin.ignore();
		cin.clear();
	}
	listA.showList();


	system("PAUSE");
}
