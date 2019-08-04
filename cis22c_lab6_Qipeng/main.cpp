#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iterator>
#include<algorithm>


using namespace std;
const int TABLE_SIZE = 200;
class HashEntry
{
public:
	int key;
	string value;
	HashEntry(int key, string value)
	{
		this->key;
		this->value;
	}

};
class HashMap
{
private:
	HashEntry **table;
public:
	HashMap()
	{
		table = new HashEntry *[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	}
	/**
	*The Hash function.
	*/
	int HashFunc(int n)
	{
		int sum = 0;

		// Loop to do sum while 
		// sum is not less than 
		// or equal to 9 
		while (n > 0 || sum > 9)
		{
			if (n == 0)
			{
				n = sum;
				sum = 0;
			}
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
	void Insert(int key, string value)
	{
		int hash = HashFunc(key);
		while (table[hash] != NULL && table[hash]->key != key)
		{
			hash = HashFunc(hash + 1);

		}if (table[hash] != NULL)
		{
			delete table[hash];
			table[hash] = new HashEntry(key, value);
		}
	}
	/**
	*Search for an element
	*/
	string search(int key)
	{
		int hash = HashFunc(key);
		while (table[hash] != NULL && table[hash]->key != key)
		{
			hash = HashFunc(hash + 1);
		}
		if (table[hash] == NULL)
			return "No records";
		else
			return table[hash]->value;
	}
	~HashMap()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] !=NULL)
			{
				delete table[i];
				delete[] table;
			}

		}
	}


};



int main()
{
	HashMap hash;
	int key;
	int choice;
	int count = 0;
	string name2[50];
	std::string date[50];
	short loop1 = 0;
	short loop2=0;
	string line1;
	unsigned int line_no= 0;
	std::ifstream myfile("bst_testfile.txt");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{		
			getline(myfile, line1);
			//name[loop1] = line1;
			//loop1++;
			++line_no;
			/**if (line_no %2 == 0)
			{
				date[loop2] = line1;
				loop2++;
			}
			else
			{
				name[loop1] = line1;
				loop1++;

			}
			cout << name[loop1] << endl;
			++line_no;	**/
			if (line_no % 2==0)
			{
				//int k=0;
				std::string date[50] = { line1 };
				/**for (int i = 0; i < sizeof(name); i++)
				{
					string ns = name[i];
					ns.erase(std::remove(ns.begin(), ns.end(), '-'), ns.end());
					std::istringstream iss(ns);
					iss >> k;
					cin.ignore();
					cin.ignore();
					return k;

				}
				int keyarr[sizeof(name)] = { k };**/
				cout << endl;
				copy(date, date + sizeof(date) / sizeof(date[0]), ostream_iterator<string>(cout));
				cout << endl;
				cout << endl;
			}
			if(line_no % 2 == 1)
			{
				
				string name[50] = { line1 };
				
				
				//cout << endl;
				copy(name, name + sizeof(name) / sizeof(name[0]), ostream_iterator<string>(cout));
				
			}
	
		}
		myfile.close();
	}
	else
	{
		cout << "Cannot find the file specified"<<endl;
		for (int i = 0; i < sizeof(name2); i++)
		{
			cout << "Values:" << endl;
			cout << name2[i] << endl;

		}
		system("PAUSE");	
	}
	cout << "\nNumber of lines in file: "<<line_no << endl;
	cout << "Please press Enter" << endl;
	/**
	int n;
	string ns = "1949-12-10";
	string nss;
	ns.erase(std::remove(ns.begin(), ns.end(), '-'), ns.end());
	std::istringstream iss(ns);
	iss >> n;
	cout << digSum(n);
	cin.ignore();
	cin.ignore();
	return 0;
	**/
	cin.ignore();
	cout << "Press enter again to Enter main menu" << endl;
	cin.ignore();
	system("cls");
	
	while (1)
	{
		cout << "n----------------------" << endl;
		cout << "Operations on Hash Table" << endl;
		cout << "n----------------------" << endl;
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			
			for (int i = 0; i < sizeof(name2); i++)
			{
				cout << name2[i] << endl;
				//key = 0;
				//hash.Insert(key, name[i]);
			}
		case 2:
			cout << "Enter birthday without delimiters of the element to be searched: ";
			cin >> key;
			//int key=convertKey(key);
			hash.search(key);
			break;
		case 3:
			exit(1);
		default:
			break;
		}
	}
	return 0;
}
