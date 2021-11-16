#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct dataBase
{

	void createCustomer(string name, string city, string state, int last_visit, int total_sales)
	{
		tCustomers.cName = name;
		tCustomers.cCity = city;
		tCustomers.cState = state;
		tCustomers.cLast_visit = last_visit;
		tCustomers.cTotal_sales = total_sales;
		tCustomers.cID = cList.size();
		cList.push_back(tCustomers);
		cout << cID << endl;
	}

	void interface();
	
	void options(int customerID)
	{

	}

	void updateCustomer(int customerID)
	{

	}

	void deleteCustomer(int customerID)
	{

		cList.erase(cList.begin()+customerID);
	}

	void show_cus(int customerID)
	{

	}

	int cID;
	string cName;
	string cCity;
	string cState;
	int cLast_visit;
	int cTotal_sales;
	//format_date();
	vector <dataBase> cList;

}tCustomers;

void welcome()
{
	bool menu = true;
	
	cout << "Salim Customer Management System" << endl;

	//CODE BLOCK
	while (menu)
	{

		cout << "Showing all customers" << endl;

		for (int i = 0; i < tCustomers.cList.size(); i++)
		{
				cout << tCustomers.cList[i].cName << endl;
				cout << tCustomers.cList[i].cCity << endl;
				cout << tCustomers.cList[i].cState << endl;
				cout << tCustomers.cList[i].cLast_visit << endl;
				cout << tCustomers.cList[i].cTotal_sales << endl;
		}

		cout << "What would you like to do?\n1 - Add Customer\n2 - Update Customer\n"
			<< "3 - Show Customers Table\n4 - Delete Customer\n5 - Show Total Sales\n6 - Exit Program"
			<< endl;
		int whatToDo;
		cin >> whatToDo;

		switch (whatToDo)
		{
		case 1:
		{
			string Name;
			string City;
			string State;
			int Last_visit;
			int Totalt_sales;
			cout << "Enter Customer first and last name: ";
			getline(cin >> ws, Name);
			cout << "Enter Customer City: ";
			cin >> City;
			cout << "Enter Customer state: ";
			cin >> State;
			cout << "Enter Customer's last visit (YYYYMMDD): ";
			cin >> Last_visit;
			cout << "Enter Customer total sales: ";
			cin >> Totalt_sales;
			tCustomers.createCustomer(Name, City, State, Last_visit, Totalt_sales);
			break;

		}
		case 2:
		{

			break;

		}
		case 3:
		{

			break;

		}
		case 4:
		{
			int deleteID;
			cout << "Enter customer ID to delete: ";
			cin >> deleteID;
			tCustomers.deleteCustomer(deleteID-1);
			break;

		}
		case 5:
		{

			break;

		}
		case 6:
		{
			menu = false;
			break;
		}
		default:

			break;
		}
	}
	
}

int main()
{
	welcome();
	cout << tCustomers.cID << endl;
	return 0;
}