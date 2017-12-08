#include <armadillo>
#include "definition.h"

using namespace arma;

class eigenvalues
{
public:
	eigenvalues();
	~eigenvalues();

	void call_methods();

private:
	std::vector<double> elements;
	void computeEigens();
	
};