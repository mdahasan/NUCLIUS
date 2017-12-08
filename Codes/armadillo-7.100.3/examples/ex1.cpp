#include<iostream>
#include<vector>
#include<armadillo>
#include<fstream>

using namespace std;
using namespace arma;

int main()
{
	ifstream fopen("3-mer.txt");
	vector<double> elements;
	//mat A(4,4);
	double freq;
	int count = 0;
	while(fopen >> freq){
	cout << freq << endl;
		//elements.push_back(freq);
		elements.push_back(freq);
		//count++;
		if(elements.size() == 16){
			cout << elements.size() << endl;
			//count = 0;
			mat A(4,4);
			int j = 0;
			int k = 0;
			for(int i = 0; i < elements.size(); i++)
			{
				cout << elements[i] << endl;
				A(j, k) = elements[i];
				k++;
				if(k == 4)
				{
					j++;
					k = 0;
				}
				
			}
			A.print();
			cx_vec eigval = eig_gen(A);
			for(int i = 0; i < eigval.size(); i++)
			{
				cout << eigval[i] << endl;
			}
			cout << max(eigval) << endl;
			elements.clear();
			A.clear();
		}
		//else{	
		//	elements.push_back(freq);
		//	count++;
		//}

	}
	//mat A = randu<mat>(4,4);
	//cx_vec eigval=eig_gen(A);

	//cout << eigval.size() << endl;
	//for(int i = 0; i< eigval.size(); i++)
	//{
	//	cout << eigval[i] << endl;
	//}
	return 0;
}
