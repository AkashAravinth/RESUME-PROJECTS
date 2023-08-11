#pragma once
#include <vector>;
#include<iostream>;
#include<string>;
using namespace std;
class block
{
public:
	string id, name, validity, act_type, cardtype;
	int act_no;
	block* next;
	block(string id, string name, string validity, string act_type, string cardtype, int act_no)
	{
		this->id = id;
		this->name = name;
		this->validity = validity;
		this->act_type = act_type;
		this->act_no = act_no;
	}
	~block()
	{
		if (next != nullptr)
		{
			delete next;
		}
	}

};
class hash_prog
{
	block** tab;
	int ts;
public:
	hash_prog(int ts)
	{
		this->ts = ts;
		tab = new block * [this->ts];
		for (int i = 0; i < this->ts; i++)
		{
			tab[i] = nullptr;
		}
	}
	int hashfunc(string& key)
	{
		int in = 0, pow = 1, key_s = key.size();
		for (int i = 0; i < key_s; i++)
		{
			in += pow * key[i];
			pow *= 26;
		}
		return in % ts;


	}
	void insert(string id, int act_no, string name, string validity, string act_type, string cardtype)
	{
		bool check_pres = search(id);
		if (!check_pres)
		{
			int in = hashfunc(id);
			block* newnode = new block(id, name, validity, act_type, cardtype, act_no);
			if (tab[in] != nullptr)
			{
				block* temp;
				temp = tab[in];
				tab[in] = newnode;
				newnode->next = temp;
			}
			else
			{
				tab[in] = newnode;
				newnode->next = nullptr;
			}
			cout << "SUCCESS\n";

		}
		else
		{
			cout << "CAN'T STORE, ARLREADY PRESENT\n";
		}

	}
	bool search(string id)
	{
		for (int i = 0; i < ts; i++)
		{
			block* temp = tab[i];
			while (temp != nullptr)
			{
				if (id == temp->id)
				{
					return 1;
				}
				temp = temp->next;
			}
		}
		return 0;

	}
	void erase(string id)
	{
		bool set = 0;
		//check if it is present already
		bool check_pres = search(id);
		if (check_pres)
		{
			for (int i = 0; i < ts; i++)
			{
				block* temp = tab[i];
				block* temp_bef = tab[i];
				while (temp != nullptr)
				{
					if (id == temp->id)
					{
						if (temp == temp_bef)
						{
							tab[i] = nullptr;
							delete temp;
							set = 1;
							cout << "SUCCESS\n";
							break;
						}
						else
						{
							temp_bef->next = temp->next;
							temp->next = nullptr;
							delete temp;
							set = 1;
							cout << "SUCCESS\n";
							break;
						}
					}
					temp_bef = temp;
					temp = temp->next;
				}
				if (set)
				{
					break;
				}

			}
		}
		else
		{
			cout << "DATA NOT PRESENT\n";
		}

	}
	void print_complete()
	{
		for (int i = 0; i < ts; i++)
		{
			block* temp = tab[i];
			while (temp != nullptr)
			{
				cout << temp->id << "," << temp->name;
				temp = temp->next;
			}
			//name, string validity, string act_type, string cardtype, int act_no
			cout << "\n";
		}
	}
	void print(string id)
	{
		for (int i = 0; i < ts; i++)
		{
			block* temp = tab[i];
			while (temp != nullptr)
			{
				if (id == temp->id)
				{
					cout << "ID:" << temp->id << "\nNAME:" << temp->name << "\nACT No.:" << temp->act_no << "\nVALIDITY:" << temp->validity << "\nTYPE:" << temp->act_type << "\nCARD TYPE:" << temp->cardtype<<"\n";
				}
				temp = temp->next;
			}
		}
	}

};

