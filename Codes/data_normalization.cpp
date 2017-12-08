#include "data_normalization.h"

data_normalization::data_normalization(){}
data_normalization::~data_normalization(){}

void
data_normalization::call_methods()
{
	normalization();
}

void
data_normalization::normalization()
{
	ifstream file("test_data");
	ofstream output;
	output.open("norm_test_data");

	VL container;
	double a, t, c, g;
	double s;

	double sum = 0;
	double mean, sq_sum, stdev;

	int k;

	cout << "Normalizing testing dataset..." << endl;

	while(file >> a >> t >> c >> g >> s)
	{
		k = 1;

		container.push_back(a);
		container.push_back(t);
		container.push_back(c);
		container.push_back(g);

		container.push_back(s);

		sum = std::accumulate(container.begin(), container.end(), 0.0);
		mean = sum / container.size();
		sq_sum = std::inner_product(container.begin(), container.end(), container.begin(), 0.0);
		stdev = std::sqrt(sq_sum/container.size() - (mean*mean));

		output << "+1 ";
		if(((a-mean)/stdev) != 0){output << k << ":" << ((a-mean)/stdev) << " "; k++;}
		if(((t-mean)/stdev) !=0 ){output << k << ":" << ((t-mean)/stdev) << " "; k++;}
		if(((c-mean)/stdev) !=0 ){output << k << ":" << ((c-mean)/stdev) << " "; k++;}
		if(((g-mean)/stdev) !=0 ){output << k << ":" << ((g-mean)/stdev) << " "; k++;}
		if(((s-mean)/stdev) !=0 ){output << k << ":" << ((s-mean)/stdev) << " "; k++;}
		output << endl;

			   // << ((a-mean)/stdev) << " " << ((t-mean)/stdev) << " "
			   // << ((c-mean)/stdev) << " " << ((g-mean)/stdev) << " "
			   // << ((s-mean)/stdev) << endl;

		// container.clear();
	}

	cout << "Dataset normalization done." << endl;
}