#include <iostream>
#include "group.h"
using namespace std;
int main()
{
	const int m = 10;
	const int n = 50;
	int Group[m][n];
	
	readgroupnull(Group, m, n);
	readgroup(Group, m, n);
	print_without_null(Group, m, n);
	countgroup(Group, m, n);

	system("pause");
	return 0;
}