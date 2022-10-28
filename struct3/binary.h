#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct subject
{
	int key;
	char group[10];
	int lession;
	int week;
	int day;
	char class_type[30];
	char classroom[4];
};
void toBinary(string filename)
{
	ifstream fin(filename);
	ofstream fout("output_" + filename, ios::binary);
	subject* sub = new subject;
	string input;
	getline(fin, input);
	sub->key = stoi(input);
	fin.getline(sub->group, 10);
	getline(fin, input);
	sub->lession = stoi(input);
	getline(fin, input);
	sub->week = stoi(input);
	getline(fin, input);
	sub->day = stoi(input);
	fin.getline(sub->class_type, 30);
	fin.getline(sub->classroom, 4);
	fout.write((char*)sub, sizeof(subject));
	while (!fin.eof())
	{
		getline(fin, input);
		sub->key = stoi(input);
		fin.getline(sub->group, 10);
		getline(fin, input);
		sub->lession = stoi(input);
		getline(fin, input);
		sub->week = stoi(input);
		getline(fin, input);
		sub->day = stoi(input);
		fin.getline(sub->class_type, 30);
		fin.getline(sub->classroom, 4);
		fout.write((char*)sub, sizeof(subject));
	}
}
subject* read_file(string filename, int key)
{
	ifstream fin(filename, ios::binary);
	subject* sub = new subject;
	fin.read((char*)sub, sizeof(subject));
	while (sub->key != key)
	{
		fin.seekg(sizeof(subject));
		fin.read((char*)sub, sizeof(subject));
	}
	return sub;
}
void toText(string filename)
{
	ifstream fin(filename, ios::binary);
	ofstream fout("output_" + filename);
	subject* sub = new subject;
	fin.read((char*)sub, sizeof(subject));
	fout << sub->group << endl;
	fout << sub->lession << endl;
	fout << sub->week << endl;
	fout << sub->day << endl;
	fout << sub->class_type << endl;
	fout << sub->classroom << endl;
	while (!fin.eof())
	{
		fin.read((char*)sub, sizeof(subject));
		fout << sub->group << endl;
		fout << sub->lession << endl;
		fout << sub->week << endl;
		fout << sub->day << endl;
		fout << sub->class_type << endl;
		fout << sub->classroom << endl;
	}
}
void cout_subject(string filename)
{
	ifstream fin(filename, ios::binary);
	subject* sub = new subject;
	fin.read((char*)sub, sizeof(subject));
	cout << sub->group << endl;
	cout << sub->lession << endl;
	cout << sub->week << endl;
	cout << sub->day << endl;
	cout << sub->class_type << endl;
	cout << sub->classroom << endl;
	while (!fin.eof())
	{
		fin.seekg(sizeof(subject));
		fin.read((char*)sub, sizeof(subject));
		cout << sub->group << endl;
		cout << sub->lession << endl;
		cout << sub->week << endl;
		cout << sub->day << endl;
		cout << sub->class_type << endl;
		cout << sub->classroom << endl;
	}
}
subject* read_s(int n, string filename)
{
	ifstream fin(filename, ios::binary);
	subject* sub = new subject;
	fin.read((char*)sub, sizeof(subject));
	for (int i = 0; i < n; i++)
	{
		fin.seekg(sizeof(subject));
		fin.read((char*)sub, sizeof(subject));
	}
	return sub;
}
void delete_key(int key, string filename)
{
	ifstream fin(filename, ios::binary);
	ofstream fout("temp.dat", ios::binary);
	subject* sub = new subject;
	while (!fin.eof())
	{
		fin.read((char*)sub, sizeof(subject));
		if (sub->key != key)
		{
			fout.write((char*)sub, sizeof(subject));
		}
	}
	char* filename1 = new char[filename.size() + 1];
	memcpy(filename1, filename.c_str(), filename.size() + 1);
	remove(filename1);
	rename("temp.dat", filename1);
}
void timetable(int key, char group[10], int lession, int week, int day, char class_type[30], char classroom[4])
{
	subject* sub = new subject;
	sub->key = key;
	memcpy(sub->group, group, 10);
	sub->lession = lession;
	sub->week = week;
	sub->day = day;
	memcpy(sub->class_type, class_type, 30);
	memcpy(sub->classroom, classroom, 4);
}