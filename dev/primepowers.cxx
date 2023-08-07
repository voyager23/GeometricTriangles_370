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

using namespace std;
typedef std::pair<ulong,ulong> PrimePower;
typedef std::vector<PrimePower> vPP;  // describes the prime powers of a factorial
	
int main(int argc, char **argv)
{
	// Setup test data
	const double phi = 1.61803398874989;
	PrimePower p1(2,1);
	PrimePower p2(3,4);
	PrimePower p3(5,2);
	vPP vpp = {p1,p2,p3};
	// input is vector of pair<ulong,ulong> as (prime, power)
	ulong limit;
	for(auto it = vpp.begin(); it != vpp.end(); ++it) {
		ulong count = 0;
		PrimePower pp = *it;
		ulong denom = pp.first;
		ulong power = pp.second;
		do {		
			limit = (ulong)floorl(denom * phi);
			count += limit - denom;
			denom *= pp.first;
			power /= 2;	
		}while(power);
		cout << count << endl;
	}
	return 0;
}

