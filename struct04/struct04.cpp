#include<iostream>
#include<math.h>
#include"bst.h"
using namespace std;

Data a[100001];

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "����-04-21-�����-��-����-����-04\n";
	cout << "������� ����������-node: ";
	int n;
	cin >> n;
	int maxx = -1;
	for (int i = 1; i <= n; ++i) {
		cout << "������� ���������� � " << i << "'th-node: ";
		cin >> a[i].name>> a[i].number;
		maxx = max(maxx, a[i].number);
	}
	cout << "Menu:\n";
	cout << " 1. ���� ���������� � ������ � ������������ �� ��������� ���������� ���� � ������.\n";
	cout << " 2. ���������� ���������� �����, ����� ������� �������� ����� ���� ����.\n";
	cout << " 3. ������� ����, �� ���������� � ������ ����.\n";
	cout << " 4. ������� �����, � ������� ������������ ���������� ����.\n";
	cout << " 5. �������� ����� ������.\n";
	cout << " 6. Print tree.\n";
	cout << " 7. Exit\n";
	Tree Bst;
	CreateTree(Bst);
	int menu;
	while (1) {
		cout << "\n";
		cin >> menu;
		switch (menu) {
		case 1: {
			for (int i = 1; i <= n; ++i) {
				Node* New = new Node;
				New = CreateNode(a[i]);
				AddNode(Bst, New);
			}
			cout << "Success add all node to tree.\n";
			break;
		}
		case 2: {
			int result = FindNodeHadElementMoreThan3(Bst, 0);
			cout << "���������� �����, ����� ������� �������� ����� ���� ����: "<< result  << "\n";
			break;
		}
		case 3: {
			DeleteNode(Bst, 0);
			cout << "Success delete all node(does not contain digits) from tree.\n";
			break;
		}  
		case 4: {
			Node *New = new Node;
			New = FindNode(Bst, maxx);
			cout << "Infors of node have the most digits: " << New->data.name << " " << New->data.number << "\n";
			break;
		}
		case 5: {
			Tree NewBst;
			CreateTree(NewBst);
			CoppyTree(Bst, NewBst);
			cout << "Success coppy tree.\n";
			break;
		}
		case 6: {
			cout << "Print Tree:\n";
			PrintTree(Bst, 0,"root");
			break;
		}
		case 7: {
			return 0;
		}
		}
	}
}