#ifndef DNA_STABILITY
#define DNA_STABILITY

#include "definition.h"

class dna_stability
{
public:
	dna_stability(VS &R);
	~dna_stability();
	
	void call_methods();

private:
	VS reads;
	
	std::map<string, double> stack_step;
	std::map<string, long> pair_count;

	std::map<string, double> assign_gkl();
	void stack_stability(std::map<string, double> &S);
};

#endif