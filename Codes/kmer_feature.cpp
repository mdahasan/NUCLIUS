#include "kmer_feature.h"

string cmid[] = {"A", "T", "C", "G"};

kmer_feature::kmer_feature(VS &R)
{
	reads = R;
}
kmer_feature::~kmer_feature(){}

void
kmer_feature::call_methods()
{
	std::map<string, long> base_codon = codon_map();
	codon_count(reads, base_codon);
}

// A table containing all 3-mers with initial count = 0

std::map<string, long>
kmer_feature::codon_map()
{
	string codon = "";

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				if(i == 0)codon = codon + 'A';
				else if(i == 1)codon = codon + 'T';
				else if(i == 2)codon = codon + 'C';
				else if(i == 3)codon = codon + 'G';

				if(j == 0)codon = codon + 'A';
				else if(j == 1)codon = codon + 'T';
				else if(j == 2)codon = codon + 'C';
				else if(j == 3)codon = codon + 'G';

				if(k == 0)codon = codon + 'A';
				else if(k == 1)codon = codon + 'T';
				else if(k == 2)codon = codon + 'C';
				else if(k == 3)codon = codon + 'G';	

				codons.insert(pair<string, long>(codon, 0));
				codon = "";
			}
		}
	}
	return codons;
}

// Count the frequency of each 3-mer in every read window of the chromosome

void
kmer_feature::codon_count(VS &reads, std::map<string, long> C)
{
	ofstream write;
	write.open("3-mer.txt", std::ofstream::out);
	cout << "Starting 3-mer frequency analysis..." << endl;

	for(long j = 0; j < reads.size(); j++)
	{
		string read = reads[j];

		for(int i = 0; i < read.size(); i++)
		{
			std::map<string, long>::iterator it;
			string kmer = read.substr(i, 3);
			it = C.find(kmer);
			if(it != C.end())
				it->second = it->second + 1;
		}

		for(int l = 0; l < 4; l++)
		{
			// write << (l + 1) << ".0" << " ";
			for(int i = 0; i < 4; i++)
			{
				for(int k = 0; k < 4; k++)
				{
					string threes = cmid[l];

					if(i == 0)threes = 'A' + threes;
					else if(i == 1)threes = 'T' + threes;
					else if(i == 2)threes = 'C' + threes;
					else if(i == 3)threes = 'G' + threes;

					if(k == 0)threes = threes + 'A';
					else if(k == 1)threes = threes + 'T';
					else if(k == 2)threes = threes + 'C';
					else if(k == 3)threes = threes + 'G';

					std::map<string, long>::iterator it;
					it = C.find(threes);
					if(it != C.end())
					{
						write << (it->second) << ".0" << " ";
					}
				}
			}
			write << endl;
		}
		std::map<string, long>::iterator mapiter;
			for(mapiter = C.begin(); mapiter != C.end(); mapiter++)
				mapiter->second = 0;
	}
	cout << "3-mer frequency analysis done." << endl;
}