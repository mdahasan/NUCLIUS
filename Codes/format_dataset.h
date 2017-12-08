#ifndef FORMAT_DATASET
#define FORMAT_DATASET

#include <cstdlib>
#include "definition.h"

class format_dataset
{
public:
	format_dataset();
	~format_dataset();

	void call_methods();

private:
	VD eigenvalues;
	VD stabilities;

	VD format_eigens();
	VD format_stability();
	
	void print_formatted_dataset(VD &E, VD &S);
};

#endif