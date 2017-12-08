#include "dna_stability.h"

dna_stability::dna_stability(VS &R)
{
	reads = R;
}
dna_stability::~dna_stability(){}

void
dna_stability::call_methods()
{
	std::map<string, double> stability = assign_gkl();
	stack_stability(stability);
}

std::map<string, double>
dna_stability::assign_gkl()
{
	stack_step.insert(pair<string, double>("TA", -0.12));
	stack_step.insert(pair<string, double>("TG", -0.78));
	stack_step.insert(pair<string, double>("CA", -0.78));
	stack_step.insert(pair<string, double>("CG", -1.44));
	stack_step.insert(pair<string, double>("AG", -1.29));
	stack_step.insert(pair<string, double>("CT", -1.29));
	stack_step.insert(pair<string, double>("AA", -1.04));
	stack_step.insert(pair<string, double>("TT", -1.04));
	stack_step.insert(pair<string, double>("AT", -1.27));
	stack_step.insert(pair<string, double>("GA", -1.66));
	stack_step.insert(pair<string, double>("TC", -1.66));
	stack_step.insert(pair<string, double>("CC", -1.97));
	stack_step.insert(pair<string, double>("GG", -1.97));
	stack_step.insert(pair<string, double>("AC", -2.04));
	stack_step.insert(pair<string, double>("GT", -2.04));
	stack_step.insert(pair<string, double>("GC", -2.70));

	return stack_step;
}

void
dna_stability::stack_stability(std::map<string, double> &B)
{
	ofstream write;
	write.open("dna-stability.txt", std::ofstream::out);

	cout << "Computing DNA stability..." << endl;

	pair_count.insert(pair<string, long>("TA", 0));
	pair_count.insert(pair<string, long>("TG", 0));
	pair_count.insert(pair<string, long>("CA", 0));
	pair_count.insert(pair<string, long>("CG", 0));
	pair_count.insert(pair<string, long>("AG", 0));
	pair_count.insert(pair<string, long>("CT", 0));
	pair_count.insert(pair<string, long>("AA", 0));
	pair_count.insert(pair<string, long>("TT", 0));
	pair_count.insert(pair<string, long>("AT", 0));
	pair_count.insert(pair<string, long>("GA", 0));
	pair_count.insert(pair<string, long>("TC", 0));
	pair_count.insert(pair<string, long>("CC", 0));
	pair_count.insert(pair<string, long>("GG", 0));
	pair_count.insert(pair<string, long>("AC", 0));
	pair_count.insert(pair<string, long>("GT", 0));
	pair_count.insert(pair<string, long>("GC", 0));

	for(long j = 0; j < reads.size(); j++)
	{
		string read = reads[j];
		long gc_count = 0;

		for(int i = 0; i < read.size(); i++)
		{
			if(read[i] == 'G' || read[i] == 'C')
				gc_count++;

			std::map<string, long>::iterator it;
			string duo = read.substr(i, 2);
			it = pair_count.find(duo);
			if(it != pair_count.end())
				it->second = it->second + 1;
		}

		// computing stability delta G
		string GC[] = {"GG", "CC", "GC", "CG"};
		string AT[] = {"AA", "TT", "AT", "TA"};
		string rest[] = {"GA", "AG", "GT", "TG", "CT", "TC", "CA", "AC"};

		double sum1 = 0, sum2 = 0, sum3 = 0;
		double val;
		long occ;

		for(int i = 0; i < 4; i++)
		{
			std::map<string, double>::iterator dit;
			std::map<string, long>::iterator lit;

			string duo = GC[i];
			dit = B.find(duo);
			if(dit != B.end())
				val = dit->second;

			lit = pair_count.find(duo);
			if(lit != pair_count.end())
				occ = lit->second;

			sum1+= val * occ;
		}

		for(int i = 0; i < 4; i++)
		{
			std::map<string, double>::iterator dit;
			std::map<string, long>::iterator lit;

			string duo = AT[i];
			dit = B.find(duo);
			if(dit != B.end())
				val = dit->second;

			lit = pair_count.find(duo);
			if(lit != pair_count.end())
				occ = lit->second;

			sum2+= val * occ;
		}

		for(int i = 0; i < 8; i++)
		{
			std::map<string, double>::iterator dit;
			std::map<string, long>::iterator lit;

			string duo = rest[i];
			dit = B.find(duo);
			if(dit != B.end())
				val = dit->second;

			lit = pair_count.find(duo);
			if(lit != pair_count.end())
				occ = lit->second;

			sum3+= val * occ;
		}

		double deltaG = (gc_count/2)*(gc_count/2)*
						(sum1 + sum2 - sum3) + 
						(gc_count/2)*(0.5*(sum3) - sum2) + 
						(1/4)*sum2;  

		write << deltaG << endl;
	}

	cout << "DNA stability computation done." << endl;
}