#include <math.h>

#define NO_DEBUG_LOG

#ifndef NO_DEBUG_LOG
#define DBLOG(x) std::cout << x;
#endif
#ifdef NO_DEBUG_LOG
#define DBLOG(x) 
#endif

long double root2(long double rootValue, double precision)
{
	/*input value to find root of. precision value, a double between 0 and 1 being the precision of how far your result may be off, this is calculated by division*/
	long double currentValue = rootValue;
	long double bisectValue;
	bool isgood;

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
			else if ((currentValue * currentValue / rootValue < 1 + precision) && (currentValue * currentValue / rootValue > 1 - precision))
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
