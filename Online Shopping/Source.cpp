#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

/*______________________________________________________________________________________________________________________________________
STRUCTS
______________________________________________________________________________________________________________________________________*/

struct shopper{
	string name1;
	long long IDR1;
	string passR1;
	int age1;
	char gender1;
	string address1;
	long long IDL1;
	string passL1;
};

struct editshopper{
	string name;
	long long ID;
	string pass;
	int age;
	char gender;
	string address;
};

struct result{
	string names;
	double prices;
	long long quantities;
	string shop;
};
struct cart{
	string name;
	double price;
	long long quantity;
};

struct product {
	string pname;
	double price;
	long long quantity;
};

struct shop{
	string sname;
	string saddress;
	string category;
};

struct owner{
	string name2;
	long long IDR2;
	string passR2;
	int age2;
	char gender2;
	string address2;
	shop shopdata;
	long long IDL2;
	string passL2;
	product prod;
};

struct editowner{
	string name;
	long long ID;
	string pass;
	int age;
	char gender;
	string address;
	string shopname;
	string shopaddress;
	string category;
	string prodname;
	double prodprice;
	long long prodquantity;
};

/*____________________________________________________________________________________________________________________________
FUNCTIOS & MAIN
____________________________________________________________________________________________________________________________*/

void shopper_register();
bool shopper_loggedin(long long, string);
void  edit_shopper();
void owner_register();
bool owner_loggedin(long long, string);

int main(){
	owner owners;
	shopper clients;
	int choice;
	bool loggedin = 0;
	do{
		cout << "\t \t \t  Welcome to [hssk group] store  \n";
		cout << "\t \t \t *******************************\n";
		cout << endl;
		cout << "\nClient[1]\nOwner [2]\nExit  [3]\n";

		cout << "Choice:- ";
		cin >> choice;
		if (choice == 1){
			cout << "\nRegister [1]\nLogin [2]\nEnter your choice : ";
			cin >> choice;

			if (choice == 1){
				shopper_register();
			}

			else if (choice == 2){
				cout << "\nEnter your ID : ";
				cin >> clients.IDL1;
				cout << "Enter your password : ";
				cin >> clients.passL1;
				shopper_loggedin(clients.IDL1, clients.passL1);
			}
		}


		else if (choice == 2){

			cout << "\nRegister [1]\nLogin [2]\nEnter your choice :  ";
			cin >> choice;

			if (choice == 1){
				owner_register();
			}

			else if (choice == 2){
				cout << "\nEnter your ID : ";
				cin >> owners.IDL2;
				cout << "Enter your password : ";
				cin >> owners.passL2;
				owner_loggedin(owners.IDL2, owners.passL2);
			}

		}

	} while (choice == 1 || choice == 2);
	return 0;
}

/*____________________________________________________________________________________________________________________________
FUNCTIONS
____________________________________________________________________________________________________________________________*/

void shopper_register(){
	shopper clients;
	long long id;
	cout << "\nEnter your name : ";
	cin >> clients.name1;
	do{
		bool exist = 1;
		cout << "Enter Your ID: ";
		cin >> id;
		ifstream client("client.txt");
		while (client >> clients.IDR1 >> clients.passR1 >> clients.name1 >> clients.age1 >> clients.gender1 >> clients.address1){
			if (id == clients.IDR1){
				cout << "This ID already exist ! " << endl;
				exist = 0;
				break;
			}
		}
		if (exist){
			break;
		}
	} while (true);
	clients.IDR1 = id;
	cout << "Enter your Password : ";
	cin >> clients.passR1;
	cout << "Enter your age : ";
	cin >> clients.age1;
	cout << "Gender: 'm' male , 'f' female : ";
	cin >> clients.gender1;
	cout << "Enter your address : ";
	cin >> clients.address1;
	ofstream client("client.txt", ios::app);
	client << clients.IDR1 << " " << clients.passR1 << " " << clients.name1 << " " << clients.age1 << " ";
	client << clients.gender1 << " " << clients.address1 << endl;
	client.close();
}

/*____________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________*/

void  edit_shopper(){
	editshopper shoppers[100];
	int i = 0;
	shopper clients;
	cout << "\nEnter your ID again : ";
	cin >> clients.IDL1;
	ifstream client("client.txt");
	while (client >> clients.IDR1 >> clients.passR1 >> clients.name1 >> clients.age1 >> clients.gender1 >> clients.address1){
		if (clients.IDL1 == clients.IDR1){
			cout << "\nEnter your new Name : ";
			cin >> shoppers[i].name;
			cout << "Enter your new ID : ";
			cin >> shoppers[i].ID;
			cout << "Enter your new Password : ";
			cin >> shoppers[i].pass;
			cout << "Enter your new age : ";
			cin >> shoppers[i].age;
			cout << "Gemder ( 'm' male / 'f' female ) : ";
			cin >> shoppers[i].gender;
			cout << "Enter your new address : ";
			cin >> shoppers[i].address;
		}
		else {
			shoppers[i].ID = clients.IDR1;
			shoppers[i].pass = clients.passR1;
			shoppers[i].name = clients.name1;
			shoppers[i].age = clients.age1;
			shoppers[i].gender = clients.gender1;
			shoppers[i].address = clients.address1;
		}
		i++;
	}
	ofstream cl("client.txt", ios::trunc);
	cl.close();
	for (int j = 0; j < i; j++){
		ofstream client("client.txt", ios::app);
		client << shoppers[j].ID << " " << shoppers[j].pass << " " << shoppers[j].name << " " << shoppers[j].age;
		client << " " << shoppers[j].gender << " " << shoppers[j].address << endl;
	}
	client.close();
}

/*______________________________________________________________________________________________________________________________
______________________________________________________________________________________________________________________________*/

bool shopper_loggedin(long long ID, string pass){
	int choice;
	int i = 0, j = 0;
	string shopname;
	bool loggedin = 0;
	bool found = 0;
	result results[100];
	cart carts[100];
	shopper clients;
	owner owners;
	ifstream client("client.txt");
	while (client >> clients.IDR1 >> clients.passR1 >> clients.name1 >> clients.age1 >> clients.gender1 >> clients.address1){
		if (ID == clients.IDR1 && pass == clients.passR1){
			loggedin = 1;
			break;
		}
	}
	client.close();
	if (loggedin){
		char search[50];
		double receipt = 0;
		cout << "\nLogin successfully <3 \n";
		cout << "\nSearch [1] \nEdit data [2]" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		if (choice == 1)
		{
			do{
				cout << "\n1 - Sport \t\t 2 - Electronics\n\n3 - Clothes \t\t 4 - Cars" << endl;
				cout << "\nMake your choice : ";
				cin >> choice;
				if (choice == 1){
					cout << "\nSearch (use small letters only ) : ";
					cin >> search;
					ifstream Sport("Sport.txt");
					cout << "\n***********************RESULTS************************" << endl;
					while (Sport >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
						if (search == owners.prod.pname){
							cout << "\n" << i + 1 << " - " << owners.prod.pname << " " << owners.prod.price << " ";
							cout << owners.prod.quantity << " " << shopname << endl;
							results[i].names = owners.prod.pname;
							results[i].prices = owners.prod.price;
							results[i].quantities = owners.prod.quantity;
							results[i].shop = shopname;
							found = 1;
							i++;


						}
					}
					cout << endl;
					if (found == 0){
						cout << "\nNot Found D':" << endl;
					}
				}
				else if (choice == 2){
					cout << "\nSearch (use small letters only ) : ";
					cin >> search;
					ifstream Electronics("Electronics.txt");
					cout << "\n***********************RESULTS************************" << endl;
					while (Electronics >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
						if (search == owners.prod.pname){
							cout << "\n" << i + 1 << " - " << owners.prod.pname << " " << owners.prod.price << " ";
							cout << owners.prod.quantity << " " << shopname << endl;
							results[i].names = owners.prod.pname;
							results[i].prices = owners.prod.price;
							results[i].quantities = owners.prod.quantity;
							results[i].shop = shopname;
							found = 1;
							i++;

						}
					}
					cout << endl;
					if (found == 0){
						cout << "\nNot Found D':" << endl;
					}
				}
				else if (choice == 3){
					cout << "\nSearch (use small letters only ) : ";
					cin >> search;
					ifstream Clothes("Clothes.txt");
					cout << "\n***********************RESULTS************************" << endl;
					while (Clothes >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
						if (search == owners.prod.pname){
							cout << "\n" << i + 1 << " - " << owners.prod.pname << " " << owners.prod.price << " ";
							cout << owners.prod.quantity << " " << shopname << endl;
							results[i].names = owners.prod.pname;
							results[i].prices = owners.prod.price;
							results[i].quantities = owners.prod.quantity;
							results[i].shop = shopname;
							found = 1;
							i++;

						}
					}
					cout << endl;
					if (found == 0){
						cout << "\nNot Found D':" << endl;
					}
				}
				else if (choice == 4){
					cout << "\nSearch (use small letters only ) : ";
					cin >> search;
					ifstream Cars("Cars.txt");
					cout << "\n***********************RESULTS************************" << endl;
					while (Cars >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
						if (search == owners.prod.pname){
							cout << "\n" << i + 1 << " - " << owners.prod.pname << " " << owners.prod.price << " ";
							cout << owners.prod.quantity << " " << shopname << endl;
							results[i].names = owners.prod.pname;
							results[i].prices = owners.prod.price;
							results[i].quantities = owners.prod.quantity;
							results[i].shop = shopname;
							found = 1;
							i++;
						}
					}
					cout << endl;
					if (found == 0){
						cout << "\nNot Found D':" << endl;
					}
				}
				if (found){

					cout << "choose the product you want to add to cart : ";
					cin >> choice;
					carts[j].name = results[choice - 1].names;
					carts[j].price = results[choice - 1].prices;
					cout << "Enter the quantity you want :" << "\t";
					cin >> carts[j].quantity;

					j++;
				}
				cout << "Do you want to add another product to the cart (1:YES / 2 : NO ) : ";
				cin >> choice;

			} while (choice != 2);
			cout << " your cart:" << "\t" << endl;

			for (int i = 0; i<j; i++)
			{
				cout << carts[i].name << "\t" << carts[i].price << "\t" << carts[i].quantity << "\t";
				receipt += carts[i].price*carts[i].quantity;
			}

			cout << endl;
			cout << "*************The Total Price is =**********" << endl;
			cout << receipt << "LE" << endl;
			cout << endl;
			cout << "Thank you !" << endl;


		}
		else{
			edit_shopper();
		}
	}
	else {
		cout << "\n\aInvalid ID or password D': " << endl;
	}
	return false;
}

/*______________________________________________________________________________________________________________________________________
_______________________________________________________________________________________________________________________________________*/

void owner_register(){
	owner owners;
	int choice;
	long long id;
	cout << "\nEnter your name : ";
	cin >> owners.name2;
	do{
		bool exist = 1;
		cout << "Enter Your ID: ";
		cin >> id;
		ifstream owner("owner.txt");
		while (owner >> owners.IDR2 >> owners.passR2 >> owners.name2 >> owners.age2 >> owners.gender2 >> owners.address2 >> owners.shopdata.category >> owners.shopdata.saddress >> owners.shopdata.sname){
			if (id == owners.IDR2){
				cout << "This ID already exist ! " << endl;
				exist = 0;
				break;
			}
		}
		if (exist){
			break;
		}
	} while (true);
	owners.IDR2 = id;
	cout << "Enter your Password : ";
	cin >> owners.passR2;
	cout << "Enter your age : ";
	cin >> owners.age2;
	cout << "Gender: 'm' male , 'f' female : ";
	cin >> owners.gender2;
	cout << "Enter your address : ";
	cin >> owners.address2;
	cout << "1 - Sport \t\t 2 - Electronics\n\n3 - Clothes \t\t 4 - Cars" << endl;
	cout << "Choose your Shop category : ";
	cin >> choice;
	switch (choice){
	case 1:
		owners.shopdata.category = "Sport";
		break;
	case 2:
		owners.shopdata.category = "Electronics";
		break;
	case 3:
		owners.shopdata.category = "Clothes";
		break;
	case 4:
		owners.shopdata.category = "Cars";
	}
	cout << "Eneter Shop name : ";
	cin >> owners.shopdata.sname;
	cout << "Enter Shop address : ";
	cin >> owners.shopdata.saddress;
	ofstream owner("owner.txt", ios::app);
	owner << owners.IDR2 << " " << owners.passR2 << " " << owners.name2 << " " << owners.age2 << " ";
	owner << owners.gender2 << " " << owners.address2 << " " << owners.shopdata.category << " ";
	owner << owners.shopdata.saddress << " " << owners.shopdata.sname << endl;
	owner.close();
}

/*_________________________________________________________________________________________________________________________________________________________________________________________________________
_________________________________________________________________________________________________________________________________________________________________________________________________________*/

void edit_owner(){
	editowner owners2[100];
	owner owners;
	int i = 0;
	int choice;
	cout << "\nEnter your ID again : ";
	cin >> owners.IDL2;
	ifstream owner("owner.txt");
	while (owner >> owners.IDR2 >> owners.passR2 >> owners.name2 >> owners.age2 >> owners.gender2 >> owners.address2 >> owners.shopdata.category >> owners.shopdata.saddress >> owners.shopdata.sname){
		if (owners.IDL2 == owners.IDR2){
			cout << "\nEnter your new Name : ";
			cin >> owners2[i].name;
			cout << "Enter your new ID : ";
			cin >> owners2[i].ID;
			cout << "Enter your new Password : ";
			cin >> owners2[i].pass;
			cout << "Enter your new age : ";
			cin >> owners2[i].age;
			cout << "Gender ( 'm' male / 'f' female ) : ";
			cin >> owners2[i].gender;
			cout << "Enter your new address : ";
			cin >> owners2[i].address;
			cout << "1 - Sport \t\t 2 - Electronics\n\n3 - Clothes \t\t 4 - Cars" << endl;
			cout << "Choose your Shop category : ";
			cin >> choice;
			switch (choice){
			case 1:
				owners2[i].category = "Sport";
				break;
			case 2:
				owners2[i].category = "Electronics";
				break;
			case 3:
				owners2[i].category = "Clothes";
				break;
			case 4:
				owners2[i].category = "Cars";
			}
			cout << "Eneter Shop name : ";
			cin >> owners2[i].shopname;
			cout << "Enter Shop address : ";
			cin >> owners2[i].shopaddress;
		}
		else {
			owners2[i].ID = owners.IDR2;
			owners2[i].pass = owners.passR2;
			owners2[i].name = owners.name2;
			owners2[i].age = owners.age2;
			owners2[i].gender = owners.gender2;
			owners2[i].address = owners.address2;
			owners2[i].category = owners.shopdata.category;
			owners2[i].shopname = owners.shopdata.sname;
			owners2[i].shopaddress = owners.shopdata.saddress;
		}
		i++;
	}
	ofstream own("owner.txt", ios::trunc);
	own.close();
	for (int j = 0; j < i; j++){
		ofstream owner("owner.txt", ios::app);
		owner << owners2[j].ID << " " << owners2[j].pass << " " << owners2[j].name << " " << owners2[j].age;
		owner << " " << owners2[j].gender << " " << owners2[j].address << " " << owners2[j].category << " ";
		owner << owners2[j].shopaddress << " " << owners2[j].shopname << endl;
	}
	owner.close();
}

/*________________________________________________________________________________________________________________________________________________________________________________________________________
________________________________________________________________________________________________________________________________________________________________________________________________________*/

bool owner_loggedin(long long ID, string pass){
	int choice;
	int j = 0;
	string shopname;
	string shopname2;
	string product;
	bool loggedin = 0;
	owner owners;
	editowner owners2[100];
	ifstream owner("owner.txt");
	while (owner >> owners.IDR2 >> owners.passR2 >> owners.name2 >> owners.age2 >> owners.gender2 >> owners.address2 >> owners.shopdata.category >> owners.shopdata.saddress >> owners.shopdata.sname){
		if (ID == owners.IDR2 && pass == owners.passR2){
			loggedin = true;
			shopname = owners.shopdata.sname;
			break;
		}
	}

	if (loggedin){
		cout << "\nLogin successfully <3 \n";
		cout << "\n1 - Add Product \n2 - Remove Product \n3 - Edit data \n4 - View Shop products " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		if (choice == 1){
			cout << "1 - Sport \t\t 2 - Electronics\n\n3 - Clothes \t\t 4 - Cars" << endl;
			cout << "Choose your product category : ";
			cin >> choice;
			if (choice == 1){
				cout << "Enter product name : ";
				cin >> owners.prod.pname;
				cout << "Enter product price : ";
				cin >> owners.prod.price;
				cout << "Enter product quantity : ";
				cin >> owners.prod.quantity;
				ofstream sport("Sport.txt", ios::app);
				sport << shopname << " " << owners.prod.pname << " " << owners.prod.price << " " << owners.prod.quantity << " " << shopname << endl;
				sport.close();
			}
			else if (choice == 2){
				cout << "Enter product name : ";
				cin >> owners.prod.pname;
				cout << "Enter product price : ";
				cin >> owners.prod.price;
				cout << "Enter product quantity : ";
				cin >> owners.prod.quantity;
				ofstream Electronics("Electronics.txt", ios::app);
				Electronics << shopname << " " << owners.prod.pname << " " << owners.prod.price << " " << owners.prod.quantity << " " << shopname << endl;
				Electronics.close();
			}
			else if (choice == 3){
				cout << "Enter product name : ";
				cin >> owners.prod.pname;
				cout << "Enter product price : ";
				cin >> owners.prod.price;
				cout << "Enter product quantity : ";
				cin >> owners.prod.quantity;
				ofstream Clothes("Clothes.txt", ios::app);
				Clothes << shopname << " " << owners.prod.pname << " " << owners.prod.price << " " << owners.prod.quantity << " " << shopname << endl;
				Clothes.close();
			}
			else{
				cout << "Enter product name : ";
				cin >> owners.prod.pname;
				cout << "Enter product price : ";
				cin >> owners.prod.price;
				cout << "Enter product quantity : ";
				cin >> owners.prod.quantity;
				ofstream Cars("Cars.txt ", ios::app);
				Cars << shopname << " " << owners.prod.pname << " " << owners.prod.price << " " << owners.prod.quantity << " " << shopname << endl;
				Cars.close();
			}
		}
		else if (choice == 2){
			cout << "1 - Sport \t\t 2 - Electronics\n\n3 - Clothes \t\t 4 - Cars" << endl;
			cout << "Choose the category of the product you want to remove : ";
			cin >> choice;
			cout << "Enter the name of the product you want to remove : ";
			cin >> product;
			cout << "Enter the name of your shop : ";
			cin >> shopname2;
			if (choice == 1){
				ifstream sport("Sport.txt");
				while (sport >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
					if (shopname2 == shopname&&product == owners.prod.pname){
						continue;
					}
					else{
						owners2[j].shopname = shopname;
						owners2[j].prodname = owners.prod.pname;
						owners2[j].prodprice = owners.prod.price;
						owners2[j].prodquantity = owners.prod.quantity;
					}
					j++;
				}
				ofstream Sp("Sport.txt", ios::trunc);
				Sp.close();
				for (int i = 0; i < j; i++){
					ofstream sport("Sport.txt", ios::app);
					sport << owners2[i].shopname << " " << owners2[i].prodname << " " << owners2[i].prodprice << " ";
					sport << owners2[i].prodquantity << " " << owners2[i].shopname << endl;
				}
				sport.close();
			}
			else if (choice == 2){
				ifstream Electronics("Electronics.txt");
				while (Electronics >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
					if (shopname2 == shopname&&product == owners.prod.pname){
						continue;
					}
					else{
						owners2[j].shopname = shopname;
						owners2[j].prodname = owners.prod.pname;
						owners2[j].prodprice = owners.prod.price;
						owners2[j].prodquantity = owners.prod.quantity;
					}
					j++;
				}
				ofstream electro("Electronics.txt", ios::trunc);
				electro.close();
				for (int i = 0; i < j; i++){
					ofstream Electronics("Electronics.txt", ios::app);
					Electronics << owners2[i].shopname << " " << owners2[i].prodname << " " << owners2[i].prodprice << " ";
					Electronics << owners2[i].prodquantity << " " << owners2[i].shopname << endl;
				}
				Electronics.close();
			}
			else if (choice == 3){

				ifstream Clothes("Clothes.txt");
				while (Clothes >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
					if (shopname2 == shopname&&product == owners.prod.pname){
						continue;
					}
					else{
						owners2[j].shopname = shopname;
						owners2[j].prodname = owners.prod.pname;
						owners2[j].prodprice = owners.prod.price;
						owners2[j].prodquantity = owners.prod.quantity;
					}
					j++;
				}
				ofstream clo("Clothes.txt", ios::trunc);
				clo.close();
				for (int i = 0; i < j; i++){
					ofstream Clothes("Clothes.txt", ios::app);
					Clothes << owners2[i].shopname << " " << owners2[i].prodname << " " << owners2[i].prodprice << " ";
					Clothes << owners2[i].prodquantity << " " << owners2[i].shopname << endl;
				}
				Clothes.close();
			}
			else{
				ifstream Cars("Cars.txt ", ios::app);
				while (Cars >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
					if (shopname2 == shopname&&product == owners.prod.pname){
						continue;
					}
					else{
						owners2[j].shopname = shopname;
						owners2[j].prodname = owners.prod.pname;
						owners2[j].prodprice = owners.prod.price;
						owners2[j].prodquantity = owners.prod.quantity;
					}
					j++;
				}
			}
			ofstream car("Cars.txt", ios::trunc);
			car.close();
			ofstream Cars("Cars.txt", ios::app);
			for (int i = 0; i < j; i++){
				Cars << owners2[i].shopname << " " << owners2[i].prodname << " " << owners2[i].prodprice << " ";
				Cars << owners2[i].prodquantity << " " << owners2[i].shopname << endl;
			}
			Cars.close();
		}

		else if (choice == 3){
			edit_owner();
		}

		else {
			string name;
			cout << "Enter shop name " << endl;
			cin >> name;
			ifstream Sport("Sport.txt ");
			while (Sport >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
				if (name == shopname){
					cout << owners.prod.pname << " , " << owners.prod.price << " , " << owners.prod.quantity << endl;
				}
			}
			ifstream Clothes("Clothes.txt ");
			while (Clothes >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
				if (name == shopname){
					cout << owners.prod.pname << " , " << owners.prod.price << " , " << owners.prod.quantity << endl;
				}
			}
			ifstream Cars("Cars.txt ");
			while (Cars >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
				if (name == shopname){
					cout << owners.prod.pname << " , " << owners.prod.price << " , " << owners.prod.quantity << endl;
				}
			}
			ifstream Electronics("Electronics.txt ");
			while (Electronics >> shopname >> owners.prod.pname >> owners.prod.price >> owners.prod.quantity >> shopname){
				if (name == shopname){
					cout << owners.prod.pname << " , " << owners.prod.price << " , " << owners.prod.quantity << endl;
				}
			}
		}
	}
	else{
		cout << "\n\aInvalid ID or password D': \n";
	}
	return false;
}
