/*

@author: Md Abid Hasan, PhD Candidate
@project: NUCLISUN, A tool to find nucleosomes and linker from DNA sequence. It can also detect
stable and unstabele nucleosomes from sequence information.
@note: C++ implementation

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "kmer_feature.h"
#include "eigenvalues.h"
#include "dna_stability.h"
#include "format_dataset.h"
#include "data_normalization.h"
#include "definition.h"

using namespace std;

void 
printUsage()
{
	cout << endl;
	cout << "NUCLISUN -- ``Finding stable/unstable nucleosomes and linker from DNA sequence'', UCR CSE 2016." << endl;
	cout << "./NUCLISUN -x <fasta>" << endl;
	cout << endl;
	cout << "Definitions of parameters:" << endl;
	cout << "-x <option>, \t Option: 1 -> Nucleosomes and Linker, 2 -> Stalbe and Unstable Nucleosomes" << endl;
	cout << endl;
	cout << "Contact/Help: Md Abid Hasan <mhasa006 at ucr dot edu>" << endl;
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printUsage();
	}

	if(argc < 1 || argc > 5)
	{
		cerr << "Failed to run" << endl;
		printUsage();
	}

	if(argc == 5)
	{
		string option(argv[1]);
		ifstream chr(argv[2]);
		
		long st, sl;

		st = atol(argv[3]);
		sl = atol(argv[4]);
		

		string seq;
		string chromosome = "";
		string CHR="";

		while(getline(chr, seq)) {
		    if(seq[0] == '>')
		    	continue;
		    CHR = CHR + seq;
		}

		// if(CHR.size() > 1000000)
		// {
		// 	cout << "Input lenght more than 40,000bp. Lenght adjusted to 40,000bp." << endl;
		// 	chromosome = CHR.substr(0, 1000000);
		// 	cout << CHR.size() << endl;
		// }
		// else
		// {	
		// 	chromosome = CHR;
		// }

		chromosome = CHR;

		// generating bed file for visualization
		ofstream results("results.bed", ofstream::out); 
		results << "track itemRgb=On" << endl;
		long k = 0;

		// Making reads of lenght NUCLEOSOME_LENGTH from chromosome
		VS reads;
		for(long j = st; j < chromosome.size() - NUCLEOSOME_LENGTH; j+=sl)
		{
			results << "Pf3D7_11_v3" << "\t" << j+1 << "\t" << j+NUCLEOSOME_LENGTH << "\t" << "1_" << k << "\t" << 0 << "\t" << 0 << "\t" << j+1 << "\t" << j+NUCLEOSOME_LENGTH << endl; 
			string read = chromosome.substr(j, NUCLEOSOME_LENGTH);
			reads.push_back(read);
			k++;
		}

		// Generating 3-mer features
		kmer_feature kf(reads);
		kf.call_methods();

		eigenvalues ev;
		ev.call_methods();

		dna_stability ds(reads);
		ds.call_methods();

		format_dataset fd;
		fd.call_methods();

		data_normalization dn;
		dn.call_methods();

		if(option == "-1")
		{
			
		}
		else if(option == "-2")
		{
			
		}
		else{
			cerr << "Failed to run" << endl;
			printUsage();
		}
	}

	return 0;
}