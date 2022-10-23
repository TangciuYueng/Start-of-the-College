/* 2151298 ĞÅ11 Ñîëø³¬*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{

	double n=0, m=1;
	double x=1;
	while (fabs(2 * x * x * x - 9 * x * x + 12 * x - 3) >= 1e-6) {
		x = (m + n) * 0.5;
		if (2 * x * x * x - 9 * x * x + 12 * x - 3 > 0)
			m = x;
		else
			n = x;
	}
	cout << setiosflags(ios::fixed) << setprecision(3)<< "x=" << n << endl;
	return 0;
}