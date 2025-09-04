#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include "HashTable.h"
#include "SList.h"

HashTable::HashTable(int kol)
{
	q = kol;
	mas = new SList[q];
}

HashTable::~HashTable()
{
	if (!mas)
	{
		delete[]mas;
	}
}

int HashTable::hashfunc(const char* str)
{
	int l = strlen(str);
	int f = 0;
	for (int i = 0; i < l; i++)
	{
		f = (f * 31 + str[i]) % q;
	}
	return f;
}

void HashTable::add(const char* str)
{
	if (!str) return;
	int ind = hashfunc(str);
	mas[ind].push(str);
}

void HashTable::alljoin()
{
	for (int i = 1; i < q; i++)
	{
		mas[0].join(mas[i]);
		mas[0].uniqstr += mas[i].uniqstr;
	}
}

void HashTable::printUniqSTR()
{
	if (mas && mas[0].head)
	{
		mas[0].print();
	}
	else
	{
		std::cout << "No unique strings found\n";
	}
}

int HashTable::totalCompare()
{
	int total = 0;
	for (int i = 0; i < q; i++)
	{
		total += mas[i].compare;
	}
	return total;
}

int HashTable::totalUniq()
{
	if (mas && mas[0].head)
	{
		return mas[0].uniqstr;
	}
	return 0;
}