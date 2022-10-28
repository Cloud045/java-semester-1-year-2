#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const int hashing = 1000001;

struct Product {
	int code = 0; //key
	char name[20];
	int price;
	char date[11];
	Product(int code, const char name[], int price, const char date[])
	{
		this->code = code;
		memcpy(this->name, name, sizeof(this->name));
		this->price = price;
		memcpy(this->date, date, sizeof(this->date));
	}
	Product() {}
	Product& operator=(const Product& a)
	{
		this->code = a.code;
		memcpy(this->name, a.name, sizeof(name));
		this->price = a.price;
		memcpy(this->date, a.date, sizeof(date));
		return *this;
	}
};

struct hashelement {
	Product product1;
	int posinfile = INT_MAX;
}ProductList[hashing];


int hashCode(int code) {
	return (code % hashing);
}

int insert(Product product, string nameFile) {
	fstream file(nameFile, ios::out | ios::app);
	int hashIndex = hashCode(product.code);
	while (ProductList[hashIndex].product1.code != 0)
		++hashIndex;
	ProductList[hashIndex].posinfile = file.tellg();
	if (hashIndex < hashing)
		ProductList[hashIndex].product1 = product;
	else return 0;
	file.write((char*)&ProductList[hashIndex].product1, sizeof(ProductList[hashIndex].product1));
	ProductList[hashIndex].posinfile = (int)file.tellg() - (int)sizeof(ProductList[hashIndex].product1);
	file.close();
	return 1;
}
Product search(int code, string nameFile) {
	int i = hashCode(code);
	while (i < hashing && ProductList[i].product1.code != code)
		i++;
	Product product;
	if (ProductList[i].product1.code == code)
	{
		ifstream file(nameFile);
		file.seekg(ProductList[i].posinfile);
		file.read((char*)&product, sizeof(product));
		file.close();
	}
	return product;
}

void deletedFromHeshTable(int code, string nameFile) {
	int i = hashCode(code);
	while (i < hashing && ProductList[i].product1.code != code)
		i++;
	ProductList[i].product1.code = 0;
	vector<Product> products;
	Product product;
	ifstream file(nameFile);
	file.read((char*)&product, sizeof(product));
	while (!file.eof())
	{
		if (product.code != code)
			products.push_back(product);
		file.read((char*)&product, sizeof(product));
	}
	file.close();
	ofstream fileIn(nameFile);
	for (int i = 0; i < products.size(); i++)
		fileIn.write((char*)&products[i], sizeof(products[i]));
	fileIn.close();
}

void display(string nameFile) {
	ifstream file(nameFile);
	Product product;
	file.read((char*)&product, sizeof(product));
	while (!file.eof())
	{
		cout << "Code: " << product.code << ", Name: " << product.name << ", Price: " << product.price << ", Date: " << product.date << endl;
		file.read((char*)&product, sizeof(product));
	}
	file.close();
}

void Menu(string nameFile)
{
	int menu;
	do
	{
		//system("cls");
		cout << "1: Add record." << endl;
		cout << "2: Search record." << endl;
		cout << "3: Delete record." << endl;
		cout << "4: Display table." << endl;
		cout << "Please choose: "; cin >> menu;
		switch (menu)
		{
		default:
			break;
		case 1:
		{
			Product product;
			cout << "Enter code: "; cin >> product.code;
			cout << "Enter name: "; cin >> product.name;
			cout << "Enter price: "; cin >> product.price;
			cout << "Enter date(dd/mm/yyyy): "; cin >> product.date;
			int proverka = insert(product, nameFile);
			if (!proverka) cout << "Error: Table is full!" << endl;
			else cout << "Success!" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			int code;
			cout << "Enter code: "; cin >> code;
			Product product = search(code, nameFile);
			if (product.code == 0) cout << "Record not found!" << endl;
			else
				cout << "Code: " << product.code << ", Name: " << product.name << ", Price: " << product.price << ", Date: " << product.date << endl;
			system("pause");
			break;
		}
		case 3:
		{
			int code;
			cout << "Enter code: "; cin >> code;
			deletedFromHeshTable(code, nameFile);
			cout << "Record is deleted" << '\n';
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Table: " << endl;
			display(nameFile);
			system("pause");
			break;
		}
		}
	} while (menu);
}

int main()
{
	int menu;
	do
	{
		//system("cls");
		cout << "1. Enter data from the keyboard" << endl;
		cout << "2. Available data: " << endl;
		cout << "Please choose: "; cin >> menu;
		switch (menu)
		{
		default:
			break;
		case 1:
		{
			ofstream file("file.dat");
			file.close();
			Menu("file.dat");
			break;
		}
		case 2:
		{
			ofstream file("file.dat");
			file.close();
			insert(*(new Product(12, "1234567890987654342", 10, "12/01/2022")), "file.dat");
			insert(*(new Product(13, "1234567890987654342", 10, "12/01/2022")), "file.dat");
			insert(*(new Product(14, "1234567890987654342", 10, "12/01/2022")), "file.dat");
			insert(*(new Product(15, "1234567890987654342", 10, "12/01/2022")), "file.dat");
			cout << "\nTable in file: " << endl;
			display("file.dat");
			cout << "Find the record with code 14 in the hash table: ";
			Product product = search(14, "file.dat");
			cout << "Code: " << product.code << ", Name: " << product.name << ", Price: " << product.price << ", Date: " << product.date << endl;
			cout << "Delete the record with code 13 in the hash table: ";
			deletedFromHeshTable(13, "file.dat");
			cout << "\nTable in file: " << endl;
			display("file.dat");
			//system("pause");
			break;
		}
		}
	} while (menu);

	return 0;
}