#include <iostream>
using namespace std;
int odd_or_even (int);
int
main ()
{
  int num;
  cout << "Enter the number\n";
  cin >> num;
  if (odd_or_even (num) == 0)
	{
	  cout << "the number is even" << endl;
	}
  else
	{
	  cout << "the number is odd" << endl;
	}
  return 0;
}

int
odd_or_even (int num)
{
  return num % 2 == 0 ? 0 : 1;
}
