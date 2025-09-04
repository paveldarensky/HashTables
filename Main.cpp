#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include "SList.h"
#include "HashTable.h"
#include <random>

int GenInt(int a, int b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(a, b);
	return dis(gen);
}


char* GenStr(int lenstr)
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	//static const char alphanum[] =
	//	"ABCDE";

	char* res = new char[lenstr + 1];

	for (int i = 0; i < lenstr; i++)
	{
		res[i] = alphanum[GenInt(0, sizeof(alphanum) - 2)];
	}
	res[lenstr] = '\0';

	return res;
}

void main()
{
	int n, len, q;
	std::cout << "Enter n, len, q: ";
	std::cin >> n >> len >> q;
	std::cout << "\n";

	HashTable hashtable(q);

	std::cout << "Start strings:\n";
	char** masSTR = new char* [n];
	for (int i = 0; i < n; i++)
	{
		masSTR[i] = GenStr(len);
		std::cout << masSTR[i] << "\n";
		hashtable.add(masSTR[i]);
	}

	hashtable.alljoin();

	std::cout << "\nUnique strings:\n";
	hashtable.printUniqSTR();
	std::cout << "\nTotal compare: " << hashtable.totalCompare() << "\n" << "Unique strings count: " << hashtable.totalUniq() << "\n";


	for (int i = 0; i < n; i++)
	{
		delete[] masSTR[i];
	}
	delete[]masSTR;
}