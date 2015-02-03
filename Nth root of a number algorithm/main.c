#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/*
// Using 1/n in pow() function
int  main()
{
   int x;
   scanf("%d",&x);

   int n;
   scanf("%d",&n);

   int result = pow(x,1.0/n);
   printf("%d",result);

}

*/

//using generic code
inline double abs_(double x) { return x >= 0 ? x : -x; }
double pow_(double x, int e)
{
	double ret = 1;
	for (ret = 1; e; x *= x, e >>= 1)
		if ((e & 1)) ret *= x;
	return ret;
}

double root(double a, int n)
{
	double d, x = 1;
	if (!a) return 0;
	if (n < 1 || (a < 0 && !(n&1))) return 0./0.; /* NaN */

	do {	d = (a / pow_(x, n - 1) - x) / n;
		x+= d;
	} while (abs_(d) >= abs_(x) * (DBL_EPSILON * 10));

	return x;
}

int main()
{
	double x = 82;
	printf("root(%g, 4) = %g\n", x, root(x, 4));
	printf("%d",(int)root(x,4));
	return 0;
}
