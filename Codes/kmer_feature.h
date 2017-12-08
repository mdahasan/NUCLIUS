#ifndef KMER_FEATURE
#define KMER_FEATURE

#include <iomanip>
#include "definition.h"

class kmer_feature
{
public:
	kmer_feature(VS &R);
	~kmer_feature();

	void call_methods();

private:
	VS reads;
	
	std::map<string, long> base_kmers;
	std::map<string, long> codons;

	std::map<string, long> codon_map();
	void codon_count(VS &reads, std::map<string, long> C);
	
};

#endif