#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int a, b;
	cout << "Input 2 numbers: " << endl;
	cin >> a >> b;
	bitset<32> bs1(a), bs2(b);
	cout << "The value of first variable is:" << bs1 << endl;
	cout << "The value of second variable is: " << bs2 << endl;

	bitset<64> reg;
	for (int i = 0; i < bs1.size(); ++i)
		reg[i] = bs1[i];
	cout << "REGISTER IS NEXT:" << reg << endl;
	cout << "Next steps is:" << endl;
	for (int i = 0; i < 32; ++i)
	{
		int lsb = reg[0];
		reg >>= 1;
		cout << reg << "][" << lsb << endl;
		if (lsb == 1)
		{
			cout << reg << endl;
			cout << "+" << endl;
			cout << bs2 << endl;
			cout << "_________________________________________________________________" << endl;

			bitset<32> a;
			for (int k = 0; k < 32; ++k)
				a[k] = reg[31 + k];

			bitset<32> m("1"), result;
			for (int j = 0; j < 32; ++j)
			{
				bitset<32> const diff(((a >> j)& m).to_ullong() + ((bs2 >> j)& m).to_ullong() + (result >> j).to_ullong());
				result ^= (diff ^ (result >> j)) << j;
			}

			for (int k = 0; k < 32; ++k)
				reg[k + 31] = result[k];
			cout << reg << endl;
		}
	}
	cout << endl << "Result is: " << reg << endl;
	cout << "Multiplication result for " << a << " and " << b << " is " << a * b << endl;
	return 0;
}

