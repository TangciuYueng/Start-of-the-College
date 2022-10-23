/* 2151298 ĞÅ11 Ñîëø³¬ */
#include <iostream>
using namespace std;
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			cout << j << "x" << i << "=" << j * i;
			if (i * j < 10)
				cout << "   ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	return 0;
}