#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include <cstring>
#include "SList.h"

SList::SList()
{
	head = tail = nullptr;
	compare = uniqstr = 0;
}

SList::~SList()
{
	ListElem *ptr;
	while (head != nullptr)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}
	tail = nullptr;
}

bool SList::check(const char* str)
{
	ListElem* current = head;
	while (current)
	{
		compare++;
		if (strcmp(current->data, str) == 0)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

void SList::push(const char* str)
{
	if (!check(str))
	{
		uniqstr++;
		ListElem* newEl = new ListElem;
		newEl->data = new char[strlen(str) + 1];
		strcpy(newEl->data, str);
		newEl->next = nullptr;
		if (!head)
		{
			head = tail = newEl;
		}
		else
		{
			tail->next = newEl;
			tail = newEl;
		}
	}
}

void SList::join(SList& other)
{
	if (!other.head) return;
	if (!head) { head = other.head; tail = other.tail; }
	else { tail->next = other.head; tail = other.tail; }
	other.head = other.tail = nullptr;
}

void SList::print()
{
	ListElem* current;
	current = head;
	while (current)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
}