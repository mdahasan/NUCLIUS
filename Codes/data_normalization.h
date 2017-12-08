#ifndef DATA_NORMALIZATION
#define DATA_NORMALIZATION

#include <cmath>
#include <numeric>
#include "definition.h"

class data_normalization
{
public:
	data_normalization();
	~data_normalization();
	
	void call_methods();

private:

	void normalization();
};

#endif