#include <math.h>
#include <iostream>

#ifndef NO_DEBUG_LOG
#define DBLOG(x) std::cout << x;
#endif
#ifdef NO_DEBUG_LOG
#define DBLOG(x) 
#endif

long double root2(long double rootValue, double precision)
{
	/*input value to find root of. precision value, a double between 0 and 1 being the precision of how far your result may be off, max offset = 1 + division, min offset = 1 / max offset; */
	long double currentValue = rootValue;
	long double bisectValue;
	bool isgood = false;
	float rMax, rMin;
	rMax = 1 + precision;
	rMin = 1 / rMax;

	if (rootValue < 0)
	{
		DBLOG("root under 0");
		return NAN;
	}

	else
	{

		bisectValue = currentValue;
		while (!isgood)
		{
			if (currentValue * currentValue == rootValue)
			{
				isgood = 1;
			}
			else if ((currentValue * currentValue / rootValue < rMax) && (currentValue * currentValue / rootValue > rMin))
			{
				isgood = 1;
			}

			else if (currentValue * currentValue < rootValue)
			{
				currentValue += 0.5 * bisectValue;
			}
			else if (currentValue * currentValue > rootValue)
			{
				currentValue -= 0.5 * bisectValue;
			}
			bisectValue *= 0.5;
		}
	}
	return currentValue;
}
