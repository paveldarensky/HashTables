#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <iostream>
#include <stdio.h>

struct ListElem
{
	char* data;
	ListElem* next;
};

class SList
{
public:
	ListElem* head, * tail;
	int compare, uniqstr;

public:
	SList();
	~SList();
	bool check(const char* str);
	void push(const char* str);
	void join(SList& other);
	void print();
};