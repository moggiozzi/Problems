// ������� 6 ���� ������ 1,2,3,4,5 � 6 �������. �� ������ ���� ��������� ����� � �������,
// �� �������, ��������, ����������. �� ����� ���������� ����� ����������� �� �������� ����� ����� ��������,
// ���� �� ����� �������� ����������� (�� �����, ����� ������)?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum ComparisonResult{ LESS, EQUAL, GREAT };
struct Comparison
{
	ComparisonResult result;
	vector<int> left;
	vector<int> right;
};

bool checkComparison(vector<int> &permutation, Comparison &comparison)
{
	int lSum = 0;
	int rSum = 0;
	for(int i=0;i<comparison.left.size();i++)
		lSum+=permutation[comparison.left[i]];
	for(int i=0;i<comparison.right.size();i++)
		rSum+=permutation[comparison.right[i]];
	if ((comparison.result == LESS && lSum < rSum) ||
		(comparison.result == EQUAL && lSum == rSum) ||
		(comparison.result == GREAT && lSum > rSum) )
		return true;
	return false;
}

void printP(vector<int> &v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	cout<<endl;
}
// ��������� ��������� ������������ � ������������������ �������
bool nextP(vector<int> &v)
{
	for(int i=v.size()-1;i>0;i--)
	{
		if(v[i]>v[i-1])
		{
			for(int j=v.size()-1;j>i-1;j--)
			{
				if(v[j]>v[i-1])
				{
					swap(v[i-1],v[j]);
					break;
				}
			}
			sort(v.begin()+i,v.end());
			return true;
		}
	}
	return false;
}

void readComparison(Comparison & c)
{
	// \ todo
	//printf("������� ����� : 1 2 = 3 ��� 2 < 3 ��� 1 3 > 2\n");
}

int main()
{
	std::vector<int> v;
	int n = 6;
	for(int i=1;i<=n;i++)
		v.push_back(i);
	Comparison c1;
	c1.left.push_back(1); c1.left.push_back(2); c1.left.push_back(4);
	c1.right.push_back(3); c1.right.push_back(5);
	c1.result = EQUAL;
	Comparison c2;
	c2.left.push_back(0); c2.left.push_back(2); c2.left.push_back(3);
	c2.right.push_back(1); c2.right.push_back(5);
	c2.result = EQUAL;
	if(checkComparison(v,c1) && checkComparison(v,c2))
		printP(v);
	while(nextP(v))
	{
		if(checkComparison(v,c1) && checkComparison(v,c2))
			printP(v);
	}
	return 0;
}