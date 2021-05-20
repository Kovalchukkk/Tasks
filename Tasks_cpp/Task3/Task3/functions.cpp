#include <iostream>
using namespace std;

void readgroupnull(int group[10][50], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			group[i][j] = 0;
		}
	}
}

void readgroup(int group[10][50], int m, int n)
{
	int number_of_groups;
	int count_in_group;
	do {
		cout << "How many groups?(1-10) ";
		cin >> number_of_groups;
	} while (number_of_groups < 2 || number_of_groups > 9);
	
	for (int i = 0; i < number_of_groups; i++)
	{

		count_in_group = 0;
		do {
			cout << "How many numbers in group " << i + 1 << "?(3-50) ";
			cin >> count_in_group;
		} while (count_in_group < 4 || count_in_group > 50);

		for (int j = 0; j < count_in_group; j++)
		{
			cout << "Enter a group[" << i + 1 << "]" << "[" << j + 1 << "]" << "=" << "\t";
			cin >> group[i][j];
		}
	}
}

void countgroup(int group[10][50], int m, int n)
{
	int countplus, countminus, sumplus, summinus;
	for (int i = 0; i < m; i++)
	{
		countplus = 0, countminus = 0, sumplus = 0, summinus = 0;
		for (int j = 0; j < n; j++)
		{
			if (group[i][j] > 0)
			{
				countplus += 1;
				while (group[i][j] != 0)
				{
					sumplus += group[i][j] % 10;
					group[i][j] /= 10;
				}
			}

			else if (group[i][j] < 0)
			{
				countminus += 1;
				while (group[i][j] != 0)
				{
					summinus += abs(group[i][j] % 10);
					group[i][j] /= 10;
				}
			}
		}
		if (countplus > countminus)
			cout << "A count of positive number in group " << i + 1 << " is bigger than negative= " << '\t' << countplus << '\t' << "Sum of digits= " << '\t' << sumplus << endl;

		else if (countplus < countminus)
			cout << "A count of negative number in group " << i + 1 << " is bigger than positive= " << '\t' << countminus << '\t' << "Sum of digits= " << '\t' << summinus << endl;
	}
}

void printgroup(int group[10][50], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << group[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void print_without_null(int group[10][50], int m, int n)
{
	cout << "Group: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (group[i][j] != 0)
				cout << group[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}