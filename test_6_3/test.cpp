#include <iostream>
using namespace std;

class Group
{
public:
	Group()
	{
		stud0 = "李作炳";
		stud1 = "李肖阳";
		stud2 = "丁璐璐";
		stud3 = "孙志博";
		stud4 = "李威霖";
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
		return "返回值有误";
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
