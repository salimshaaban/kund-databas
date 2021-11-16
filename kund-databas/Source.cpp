#include <iostream>
#include <vector>
#include <string>
#include<numeric>
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
		cout <<"Enter updated name: (Currently: "<< cList[customerID].cName<<"): ";
		getline(cin >> ws, cList[customerID].cName);
		cout << "Enter updated city: (Currently: " << cList[customerID].cCity << "): ";
		cin >> cList[customerID].cCity;
		cout << "Enter updated state: (Currently: " << cList[customerID].cState << "): ";
		cin >> cList[customerID].cState;
		cout << "Enter updated last visit: (Currently: " << cList[customerID].cLast_visit << "): ";
		cin >> cList[customerID].cLast_visit;
		cout << "Enter updated totalt sales: (Currently: " << cList[customerID].cTotal_sales << "): ";
		cin >> cList[customerID].cTotal_sales;
		cout << "Customer " << customerID << " updated." << endl;

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
			cout << "ID: " << tCustomers.cList[i].cID+1 << endl;
		    cout << "Name: " << tCustomers.cList[i].cName << endl;
			cout << "City: " << tCustomers.cList[i].cCity << endl;
			cout << "State: "<< tCustomers.cList[i].cState << endl;
			cout << "Last visit: " << tCustomers.cList[i].cLast_visit << endl;
			cout << "Total sales: "<< tCustomers.cList[i].cTotal_sales<<"$" << endl;
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
			int cUpdate;
			cout << "Enter customer ID to update: ";
			cin >> cUpdate;
			if (cUpdate <= tCustomers.cList.size())
			{
				tCustomers.updateCustomer(cUpdate-1);
			}
			else
			{
				cout << "No customer ID " << cUpdate << " exists" << endl;
			}
			break;
		}
		case 3:
		{

			break;

		}
		case 4:
		{
			int deleteID;
			char sureDelete;
			cout << "Enter customer ID to delete: ";
			cin >> deleteID;
			if (deleteID <= tCustomers.cList.size())
			{
				cout << "Customer " << deleteID << " found with following info: " << endl;
				cout << "Name: " << tCustomers.cList[deleteID-1].cName << endl;
				cout << "City: " << tCustomers.cList[deleteID-1].cCity << endl;
				cout << "State: " << tCustomers.cList[deleteID-1].cState << endl;
				cout << "Last visit: " << tCustomers.cList[deleteID-1].cLast_visit << endl;
				cout << "Total sales: " << tCustomers.cList[deleteID-1].cTotal_sales << endl;
				cout << "Are you sure you want to delete this customer? (y or n)";
				cin >> sureDelete;
				if (sureDelete == 'y')
				{
					cout << "Customer deleted." << endl;
					tCustomers.deleteCustomer(deleteID - 1);
				}
				else if(sureDelete=='n')
				{
					cout << "Customer not deleted." << endl;
				}
			}
			else
			{
				cout << "No customer ID " << deleteID << " exists" << endl;
			}
			
			break;
		}
		case 5:
		{
			int companySales=0;

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
	return 0;
}