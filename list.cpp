/*
 * main.cpp
 *
 *  Created on: 19/ago/2011
 *      Author: alessandro
 */
#include <iostream>
#include <string.h>

using namespace std;

class nodo{
public:
	nodo *next;
	char str[30];
	nodo();
};

class lista{
private:
	nodo *start;
	int elem;

public:
	lista();
	void insert(char *str);
	void print();

};

class stack:public lista{
	public:
	   void push(char *str);
	   stack() {st=NULL;}
	   void pop();
	   void print();
	   nodo * st;
};

nodo::nodo()
{
	str[0]='\0';
	next=NULL;
}

lista::lista()
{
	start=NULL;
	elem=0;
}

void lista::insert(char *str)
{
	nodo *temp=new nodo();
	nodo *p;
	strcpy(temp->str,str);

	if(start==NULL)
	{
      start=temp;
	}
	else
	{
		for(p=start;p->next;p=p->next);
		p->next=temp;

	}
	elem++;
}

void lista::print()
{
	nodo *p;
	for(p=start;p;p=p->next)
	{
		cout<<p->str<<endl;
	}
}

void stack::push(char *str)
{
	nodo *temp;
	
	temp=new nodo();
	strcpy(temp->str,str);
	
	temp->next=st;
	st=temp;
}
void stack::print()
{
	nodo *p;
	for(p=st;p;p=p->next)
	{
		cout<<p->str<<endl;
	}
}
void stack::pop()
{
	nodo *temp;
	temp=st;
	st=temp->next;
	delete temp;
}
int main()
{
	lista l;
	stack s;
	l.insert("paolo");
	l.insert("pellizzoni");
	
	l.print();
	
	cout<<endl;
	
	s.push("asd");
	s.push("lol");
	
	s.print();
	
	s.pop();
	
	cout<<endl;
	
	s.print();
	
	cin.get();
	return 0;
}
