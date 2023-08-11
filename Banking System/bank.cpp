#include <vector>;
#include<iostream>;
#include<string>;
#include"hash_prog.h";
using namespace std;
int main()
{
	string id,name,validity,act_type,cardtype;
	bool presence;
	int choose, act_no,home;
	hash_prog h(5);
here:
	cout << "HOME:\n";
	cout << "VALID ID SIZE:10 \n CHOOSE: \n 1.SEARCH \n 2.CREATE \n 3.DELETE\n";
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "ENTER ID\n";
		cin >> id;
		if (sizeof(id)/4 == 10)
		{
			presence = h.search(id);
			if (presence)
			{
				h.print(id);
				home = 0;
			again:
				cout << "PRESS 1. FOR HOME\n";
				cin >> home;
				//clear screen statement
				if (home == 1)
				{
					goto here;
				}
				else
				{
					goto again;
				}
			}
			else
			{
				cout << "DATA DOES NOT EXIST\n";
				home = 0;
			again1:
				cout << "PRESS 1. FOR HOME\n";
				cin >> home;
				//clear screen statement
				if (home == 1)
				{
					goto here;
				}
				else
				{
					goto again1;
				}
			}
		}
		else
		{
			cout << "INVALID ID SIZE\n";
			goto here;
		}
		//break;
	case 2:
		cout << "ENTER ID:\n";
		cin >> id;
		if (sizeof(id)/4== 10)
		{
			cout << "ENTER NAME:\n";
			cin >> name;
			cout << "ENTER ACT No.:\n";
			cin >> act_no;
			cout << "ENTER VALIDITY:\n";
			cin >> validity;
			cout << "ENTER ACT TYPE:\n";
			cin >> act_type;
			cout << "ENTER CARD TYPE:\n";
			cin >> cardtype;
			h.insert(id, act_no, name, validity, act_type, cardtype);
			home = 0;
		again2:
			cout << "PRESS 1. FOR HOME\n";
			cin >> home;
			//clear screen statement
			if (home == 1)
			{
				goto here;
			}
			else
			{
				goto again2;
			}
		}
		else
		{
			cout << "INVALID ID SIZE\n";
			goto here;
		}
		break;
	case 3:
		cout << "ENTER ID\n";
		cin >> id;
		if (sizeof(id)/4== 10)
		{
			h.erase(id);
			home = 0;
		again3:
			cout << "PRESS 1. FOR HOME\n";
			cin >> home;
			//clear screen statement
			if (home == 1)
			{
				goto here;
			}
			else
			{
				goto again3;
			}
		}
		else
		{
			cout << "INVALID ID SIZE\n";
			goto here;
		}
		//break;
	default:
		cout << "ENTERED NON EXISTING OPTION\n REDIRECTING TO HOME\n";
		goto here;
	}
}