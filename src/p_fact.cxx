/*
 * p_fact.cxx
 * 
 * Copyright 2023 mike <mike@pop-os>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * Answer:  1491274
 * Solution: 861805
 */

#include <iostream>
#include <iomanip>
#include <numbers>
#include <cmath>
#include <tuple>
#include <map>
#include <vector>
#include <set>

#include "../inc/toolbox.hxx"

using namespace std;

int main(int argc, char **argv)
{
	const double phi = 1.61803398874989;
    std::vector<ul> primes;
	PfactOfN pfn;	// vector of std::pair< (uint)prime, (uint)power> 
    SofE(primes,1000);
    cout << "highest prime: " << primes.back() << endl;
    for(unsigned a = 2; a < primes.back(); ++a) {
		generate_descriptors(primes, a, pfn);
		cout << a << ": ";
		prt_pfofn(pfn);
		NL;
		// for each entry in pfn return a list of denominators
		// e.g {2,2} {3,3},{5,4} => (2,3,5,25)
		//		for each denominator calc. the limiting denominator i.e floor(d * phi)
		//			e.g 25 * phi = 40.45 => 40 - 25 = 15 possible sequences
			
	}
    cout << "highest prime: " << primes.back() << endl;

}
