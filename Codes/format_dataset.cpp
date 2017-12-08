#include "format_dataset.h"

format_dataset::format_dataset(){}
format_dataset::~format_dataset(){}

void
format_dataset::call_methods()
{
	cout << "Start formatting test data..." << endl;
	VD eigens = format_eigens();
	VD stabs = format_stability();

	print_formatted_dataset(eigens, stabs);
}

VD
format_dataset::format_eigens()
{
	string input;
	string eig;
	
	std::string::size_type sz;
	

	ifstream file("3-mer-eigens.txt");

	if(file.is_open())
	{
		while(getline(file, input))
		{
			eig = "";
			for(int i = 0; i < input.size(); i++)
			{
				if(input[i] == ',')break;
				else if(input[i] == '(')continue;
				else
				{
					eig = eig + input[i];
					
				}
			}
			// double eg = std::stod(eig, &sz);
			double eg = atof(eig.c_str());
			eigenvalues.push_back(eg);
		}
	}
	return eigenvalues;
}

VD 
format_dataset::format_stability()
{
	double stab;

	ifstream file("dna-stability.txt");

	if(file.is_open())
	{
		while(file >> stab)
		{
			stabilities.push_back(stab);
		}
	}
	return stabilities;
}

void
format_dataset::print_formatted_dataset(VD &E, VD &S)
{
	ofstream write("test_data", std::ofstream::out);
	long k = 0;
	int i = 1;
	// write << "+1 ";
	for(long j = 0; j <= E.size(); j++)
	{
		if((j % 4) == 0 && j > 0){
			// write << i << ":" << S[k] << endl;
			write << S[k] << endl;
			k++;
			i = 1;
			// if(k != S.size()) write << "+1:";
		}
		if(k == S.size())break;
		// write << i << ":" << E[j] << " ";
		write << E[j] << " ";
		i++;
	}

	cout << "Data formatting done." << endl;
}
