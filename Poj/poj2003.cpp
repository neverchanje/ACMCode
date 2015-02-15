#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

#define reassign() str[0]="",str[1]="",str[2]=""

struct node
{
	string name;
	vector<node*> ch;
	node* pa;

	static node* create(const string& nm)
	{
		node* nd = new node();
		nd->pa = NULL;
		nd->name = nm;
		return nd;
	}
};
node *root;
map<string, node*> table;

void remove(node* p)
{
	table.erase(p->name);
	while(p->ch.size())
	{
		p->name = p->ch[0]->name;
		table[p->name] = p;
		p = p->ch[0];
	}
	node* pa = p->pa;
	for(int i=0; i<pa->ch.size(); i++)
		if(pa->ch[i] == p)
		{
			pa->ch.erase(pa->ch.begin() + i);
			break;
		}
}

void printdown(const node* p, int rank)
{
	for(int i=0; i<rank; i++) putchar('+');
	cout<<p->name<<endl;
	for(int i=0; i<p->ch.size(); i++)
	{
		printdown(p->ch[i], rank+1);
	}
}

void split(string* str, const string& cmd)
{
	int k = 0;
	for(int i=0; i<cmd.length(); i++)
	{
		if(cmd[i]!=' ')
			str[k].push_back(cmd[i]);
		else
			k++;
	}
}

int main() 
{
//	freopen("a.txt", "r", stdin);
	string cmd;
	string str[3] = {"", "", ""};

	getline(cin, cmd);
	root = node::create(cmd);
	table[cmd] = root;

	while(getline(cin, cmd))
	{		
		if(cmd == "print")
		{
			printdown(root, 0);
			puts("------------------------------------------------------------");
		}
		else
		{
			split(str ,cmd);

			if(str[2] != "") //hire
			{
				node* parent = table[str[0]];
				node* child = node::create(str[2]);
				table[str[2]] = child;
				parent->ch.push_back(child);
				child->pa = parent;
			}
			else //fire
			{
				node* cur = table[str[1]];
				remove(cur);
			}
			reassign();
		}
	}

	return 0;
}