#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <iostream>
#include <stdio.h>
#include "SList.h"

class HashTable
{
	int q;
	SList* mas;

public:
	HashTable(int kol);
	~HashTable();
	int hashfunc(const char* str);
	void add(const char* str);
	void alljoin();
	void printUniqSTR();
	int totalCompare();
	int totalUniq();
};
