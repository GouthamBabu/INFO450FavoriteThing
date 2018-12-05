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
	void getName();
	void getType();
	void getOrgin();
	void getRating();
	void delName();
	void delType();
	void delOrgin();
	void delRating();
	string findName();
	friend ostream& operator<<(ostream &o, Coffee& i);
	~Coffee()
	{

	}
	//getters and setters
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
	void delItem();
	string listName();
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

string Coffee::findName()
{
	return name;
}

void Coffee::getName()
{
	cout << "Enter name of coffee " << endl;
	getline(cin, name);
}
void Coffee::getType()
{
	cout << "Enter type of coffee" << endl;
	getline(cin, type);
}
void Coffee::getOrgin()
{
	cout << "Enter orgin of coffee" << endl;
	getline(cin, orgin);
}
void Coffee::getRating()
{
	cout << "Enter rating of coffee" << endl;
	cin >> rating;
}


void Coffee::delName()
{
	name = "";
}
void Coffee::delType()
{
	type = "";
}
void Coffee::delOrgin()
{
	orgin = "";
}
void Coffee::delRating()
{
	rating = 0; 
}


CoffeeList::CoffeeList()
{
	numItems = 0;
}


string CoffeeList::listName()
{
	return iList[(numItems-1)].findName();
}


bool CoffeeList::check(string name) //checks for duplicate entry
{
	for (int i = 1; i < numItems; i++)
	{
		if (iList[i-1].findName() == name)
			return 1;
	}
	return 0;
}
void CoffeeList::addItem()
{

	iList[numItems].getName();
	iList[numItems].getType();
	iList[numItems].getOrgin();
	iList[numItems].getRating();
	cin.ignore();
	cin.clear();
	numItems++; // counts the total number of items 
}

void CoffeeList::delItem()
{
	numItems--;
	iList[(numItems)].delName();
	iList[(numItems)].delType();
	iList[(numItems)].delOrgin();
	iList[(numItems)].delRating();
}

void CoffeeList::showList()
{
	for (int i = 0; i < numItems; i++)
		cout << iList[i] << endl;
}


int main()
{
	cout << "     Welcome to Favorite Things Database for COFFEE!!" << endl;
	cout << "You can use this to keep a list of different types of coffee" << endl;
	CoffeeList listA;
	int enter = 1;
	while (enter == 1) // allows the user to keep entering
	{
		listA.addItem(); //get entry
		string name; 
		name =listA.listName(); // this variable gets the name of the coffee from the entry that the user just made
		bool alreadyThere = 0; // this variable helps keep track if there is repeated entires
		alreadyThere = listA.check(name); // this calls the function to check for repeated entries  
		if (alreadyThere == 1)
		{
			cout << "that coffee already exists in the list. YOUR ENTRY HAS BEEN DELETED. Pleast try again." << endl;
			listA.delItem(); //deletes repeated entry
		}
		cout << "press 1 if you would like to add an entry" << endl;
		cin >> enter;
		cin.ignore();
		cin.clear();
	}

	listA.showList();

	system("PAUSE");
}
