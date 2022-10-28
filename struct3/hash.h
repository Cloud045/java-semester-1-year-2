//#pragma once
//#include <vector>
//#include <algorithm> 
//
//using namespace std;
//
//int hashing;
//vector<int> hashList;
//
//struct Product {
//	int code;
//	string name;
//	int price;
//	string date;
//	Product(int code, string name, int price, string date) {
//		this->code = code;
//		this->name = name;
//		this->price = price;
//		this->date = date;
//	}
//};
//
//struct typeItem {
//	Product product;
//	bool openORclose = true; //свободна ли ячейка
//	bool deletedORnot = false; //не удалялось 
//};
//
//struct HeshTable
//{
//	int L = 19;
//	typeItem* T;
//	void createHeshTable() {
//		T = new typeItem[L];
//	}
//};
//
//int hashCode(int code,int Has) {
//	return (code % Has);
//}
//
//int insertInHeshTable(Product product, HeshTable& t) {
//	int i = hashCode(product.code, t.L);
//	//разрешение коллизии
//	while (i < t.L && t.T[i].openORclose == false)
//		i ++;
//	if (i < t.L) {
//		t.T[i].product = product;
//		t.T[i].openORclose = false;
//		return 0;
//	}
//	else return 1; //таблица заполнена полностью
//}
//
//void outTable(HeshTable& t) {
//	for (int i = 0; i < t.L; i++)
//		cout << "n: " << i << " Code: " << t.T[i].product.code << " Name: " << t.T[i].product.name << "Price: " << t.T[i].product.price << " Date: " << t.T[i].product.price << " Open?: " << t.T[i].openORclose << " Delete?: " << t.T[i].deletedORnot << '\n';
//}
//
//int search(HeshTable& t, int code) {
//	int i = hashCode(code, t.L);
//	while (i < t.L && t.T[i].product.code != code && ((t.T[i].openORclose == false && t.T[i].deletedORnot == false) || t.T[i].openORclose == true && t.T[i].deletedORnot == true))
//		i ++;
//	if (t.T[i].openORclose == true && t.T[i].deletedORnot == false) {
//		return -1;
//	}
//	return i;
//}
//
//int deletedFromHeshTable(HeshTable& t, int code) {
//	int i = search(t, code);
//	if (i != -1) { //такой хаписи в таблице нет
//		t.T[i].deletedORnot = true;
//		t.T[i].openORclose = true;
//		return 0;
//	}
//	return -1;
//}
//
//void Menu(HeshTable T)
//{
//	int menu;
//	do
//	{
//		system("cls");
//		cout << "1: Add record." << endl;
//		cout << "2: Search record." << endl;
//		cout << "3: Delete record." << endl;
//		cout << "4: Display table." << endl;
//		cout << "Please choose: "; cin >> menu;
//		switch (menu)
//		{
//		default:
//			break;
//		case 1:
//		{
//			Product product;
//			int offset;
//			cout << "Enter code: "; cin >> product.code;
//			cout << "Enter name: "; cin >> product.name;
//			cout << "Enter price: "; cin >> product.price;
//			cout << "Enter date: "; cin >> product.date;
//			cout << "Enter offset: "; cin >> offset;
//			int proverka = insertInHeshTable(product, T);
//			if (proverka) cout << "Error: Table is full!" << endl;
//			else cout << "Success!" << endl;
//			system("pause");
//			break;
//		}
//		case 2:
//		{
//			int code;
//			cout << "Enter code: "; cin >> code;
//			int i = search(T, code);
//			typeItem r;
//			if (i != -1)
//			{
//				r = T.T[i];
//				cout << " Code: " << r.product.code << " Name: " << r.product.name << "Price: " << r.product.price << " Date: " << r.product.price << " Open?: " << r.openORclose << " Delete?: " << r.deletedORnot << '\n';
//			}
//			else cout << "Error: Record is not found!" << endl;
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			int code;
//			cout << "Enter code: "; cin >> code;
//			int i = deletedFromHeshTable(T, code);
//			if (!i) cout << "Record is deleted" << '\n';
//			else
//				cout << "Error: Record is not found!" << '\n';
//			system("pause");
//			break;
//		}
//		case 4:
//		{
//			cout << "Table: " << endl;
//			outTable(T);
//			system("pause");
//			break;
//		}
//		}
//	} while (menu);
//}

//struct Product* search(int code) {
//	int hashIndex = hashCode(code, hashing);
//
//	while (ProductList[hashIndex] != NULL) {
//		if (ProductList[hashIndex]->code == code)
//			return ProductList[hashIndex];
//		++hashIndex;
//		hashIndex %= hashing;
//	}
//	return NULL;
//}
//
//void insert() {
//	struct Product* item = (struct Product*)malloc(sizeof(struct Product));
//	cout << "Information of new product: ";
//	cin >> item->code >> item->name >> item->price >> item->date;
//
//	int hashIndex = hashCode(item->code, hashing);
//	while (ProductList[hashIndex] != NULL) {
//		++hashIndex;
//		hashIndex %= hashing;
//	}
//	hashList.push_back(hashIndex);
//	ProductList[hashIndex] = item;
//}
//
//struct Product* delProduct(int code) {
//	int hashIndex = hashCode(code, hashing);
//	while (ProductList[hashIndex] != NULL) {
//
//		if (ProductList[hashIndex]->code == code) {
//			vector<int>::iterator it;
//			it = find(hashList.begin(), hashList.end(), hashIndex);
//			hashList.erase(it);
//			struct Product* temp = ProductList[hashIndex];
//			ProductList[hashIndex] = NULL;
//			return temp;
//		}
//		++hashIndex;
//		hashIndex %= hashing;
//	}
//	return NULL;
//}

//void rehashing(int newhash) {
//	vector<int> newhashList;
//	Product** newProductList = new Product * [10000001];
//	for (int i = 0; i < 1000000; ++i) newProductList[i] = NULL;
//	while (!hashList.empty()) {
//		int it = hashList.back();
//		int code = ProductList[it]->code;
//
//		int hashIndex = hashCode(code, newhash);
//		while (newProductList[hashIndex] != NULL) {
//			++hashIndex;
//			hashIndex %= hashing;
//		}
//		newhashList.push_back(hashIndex);
//		newProductList[hashIndex] = ProductList[it];
//		hashList.pop_back();
//	}
//	for (int i = 0; i < 1000000; ++i) ProductList[i] = newProductList[i];
//	for (int i = 0; i < newhashList.size(); ++i) {
//		hashList.push_back(newhashList[i]);
//	}
//	hashing = newhash;
//	cout << "Success rehashing!!!\n";
//}

