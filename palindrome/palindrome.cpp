#include <iostream>
#include <cstring>
#include "queue.h"
#include "stack.h"
using namespace std;

static Stack schar;
static Queue qchar;

void PushAll(char* str, int size)
{
	for (int i = 0; i < size; i++)
	{
		schar.Push(str[i]);
	}
	
	schar.DisplayStack();
}

void EnqueueAll(char* str, int size)
{
	for (int i = 0; i < size; i++)
	{
		qchar.Enqueue(str[i]);
	}

	qchar.DisplayQueue();
}

bool palindrome()
{
	while (!schar.IsEmpty()||!qchar.IsEmpty())
	{
		if (schar.Pop()!= qchar.Dequeue())
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	cout << "Please enter the word:" << endl;
	
	char *cstr;
	string str;
	cin >> str;

	cstr = new char[str.size() + 1];
	strcpy(cstr, str.c_str());

	cout << cstr << endl;
	cout << str.size() << endl;
	
	PushAll(cstr, str.size());
    EnqueueAll(cstr, str.size());

	
	if (palindrome())
	{
		cout << "It is a palindrome word." << endl;
	}
	else
	{
		cout << "It is NOT a palindrome word." << endl;
	}


	system("pause");
	return 0;
}
