#include <iostream>
using namespace std;

class Group
{
public:
	Group()
	{
		stud0 = "������";
		stud1 = "��Ф��";
		stud2 = "����";
		stud3 = "��־��";
		stud4 = "������";
	}
	string OptionStu(size_t i)
	{
		switch(i)
		{
			case 0:return stud0;
			case 1:return stud1;
			case 2:return stud2;
			case 3:return stud3;
			case 4:return stud4;
		}
		return "����ֵ����";
	}
private:
	string stud0;
	string stud1;
	string stud2;
	string stud3;
	string stud4;
};
int main()
{
	srand((unsigned int)time(NULL));
	Group group;
	size_t option = rand() % 5;
	cout << group.OptionStu(option) << endl;
	return 0;
}
