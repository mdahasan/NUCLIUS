#include "eigenvalues.h"

eigenvalues::eigenvalues(){}
eigenvalues::~eigenvalues(){}

void
eigenvalues::call_methods()
{
	computeEigens();
}

void
eigenvalues::computeEigens()
{
	ifstream tmers("3-mer.txt");
	ofstream eigens("3-mer-eigens.txt");
	double freq;
	double base;
	cx_vec eigval;

	cout << "Generating Eigenvalues for 3-mer frequency matrix..." << endl;

	while(tmers >> freq)
	{	
		elements.push_back(freq);
		if(elements.size() == 16)
		{
			mat A(4,4);

			int j = 0;
			int k = 0;
			for(int i = 0; i < elements.size(); i++)
			{
				A(j, k) = elements[i];
				k++;
				if(k == 4)
				{
					j++;
					k = 0;
				}
			}

			eigval = eig_gen(A);
			eigens << max(eigval) << endl;
			A.clear();
			elements.clear();
		}
	}

	cout << "Eigenvalue generation done." << endl;
}