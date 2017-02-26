#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Data
{
protected:
	int line = 0;
	string* str;
public:
	Data(int line)
	{
		str = new string[line];
	}
	string* getString()
	{
		return this->str;
	}
	void setString(string str, int line)
	{
		this->str[line] = str;
		this->line++;
	}

	void findString(string str)
	{
		int index, count=0;
		for (int i = 0; i < line; i++)
		{
			index = this->str[i].find(str);
			if (index != -1)
			{
				cout << "Find at line " << (i + 1) << ", " << index << endl;
				count++;
			}
		}

		if (count == 0)
			throw exception("Can't find!");
	}

	void printAll()
	{
		for (int i = 0; i < line; i++)
			cout << str[i] << endl;
	}
};

int main(void)
{
	string str;
	int line = 0;
	ifstream ifs;
	ifs.open("text.txt");
	while (getline(ifs, str))
		line++;
	ifs.close();

	Data data = Data(line);

	ifs.open("text.txt");
	int i = 0;
	while (getline(ifs, str))
	{
		data.setString(str, i);
		i++;
	}
	ifs.close();

	//data.printAll();
	try
	{
		data.findString("google");
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		return -1;
	}

	return 0;
}
