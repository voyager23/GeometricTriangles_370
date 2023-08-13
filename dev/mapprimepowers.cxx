/*
 * primepowers.cxx
 */
//~ testbed code 
//~ given a vector of std::pair<uint,uint>
//~ determine the possibe denominators, limits and number of configs

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <map>
#include <boost/rational.hpp>

using namespace std;
typedef std::pair<ulong,ulong> PrimePower;
typedef std::vector<PrimePower> vPP;  // describes the prime powers of a factorial
typedef std::map<PrimePower, ulong> mPP;	// map Primepower to count of geometric triangles (progressions)
		//~ // -----
		//~ ulong denom = get<0>(pp);		// defines the denominator
		//~ ulong loops = (get<1>(pp))/2;	// integer divide by 2 gives loop count
		//~ while(loops){
			//~ limit = (ulong)floor(denom * phi);
			//~ count += limit - denom;
			//~ denom *= pp.first;
			//~ --loops;			
		//~ }
		//~ cout << pp.first << "  " << pp.second << "  count:" << count << endl;
		//~ // -----
		
const double phi = 1.61803398874989;	// Golden ratio

int main(int argc, char **argv)
{
	//~ boost::rational<ulong> foo(403,243);
	//~ boost::rational<ulong> bar(4050);
	//~ std::cout << (foo * bar) << endl;
	//~ std::cout << (double)(foo.numerator()) << endl;
	//~ std::cout << (foo.denominator()) << endl;
	//~ return 0;
	
	std::vector<ulong> primes={2,3,5,7,11};
	std::vector<ulong> exp={2,4,6,8,10};
	std::map<PrimePower,ulong> mpp;	// map primepower to sequence count
	ulong count,limit;
	for(ulong &i : primes){
		for(ulong &j : exp){
		count = 0;
		ulong denom = i;	// defines the denominator
		ulong loops = j/2;		// integer divide by 2 gives loop count
		while(loops){
			limit = (ulong)floor(denom * phi);
			count += limit - denom;
			denom *= i;
			--loops;			
		}
		mpp.emplace(make_pair(i,j),count);
		cout <<  "count: " << count << endl;
		// -----			
		}
		cout<<endl;
	}

	for(auto &[k,v] : mpp){
		cout << get<0>(k) << "  " << get<1>(k) << "  " << v << endl;
	}

	return 0;
}

