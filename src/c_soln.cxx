/*
 * c_soln.cxx
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
 * 
 * 
 */


#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <map>
#include "../inc/toolbox.hxx"
#include <boost/rational.hpp>
// ULONG_MAX 18,446,744,073,709,551,615   {18*10^18}
using namespace std;

// Outline
	//~ start
		//~ setup vector of primes <= 10^6 - see SofE
		//~ setup map of PrimePower,count - see mapprimepowers
		//~ Variables n = 1; total = 0;
		//~ while(true)
			//~ count = 0
			//~ count geometric sequences for n
			//~ check perimeters
			//~ add valid to count
			//~ if count == 0 break???????
			//~ n += 1
			//~ total += count
			//~ loop
		//~ print total
	//~ stop
//

#define NO_OP bool __NO_OP__=false

int main(int argc, char **argv)
{
	std::cout << sizeof(ulong) << endl;
	std::cout << sizeof(long long) << endl;
	std::cout << ULONG_MAX << endl;
	
	exit(0);
	const ulong maxPerim = 1000000;
	const double phi = 1.61803398874989;
    std::vector<ul> primes;
	PfactN pfn;	// vector of std::pair< (uint)prime, (uint)power> 
    SofE(primes,7);
		// cout << "highest prime: " << primes.back() << endl;
	std::vector<ulong> exp={2,4,6,8,10,12,14};
	std::map<PrimePower,ulong> mpp;	// map primepower to sequence count
    ulong count, limit; 
    
    // Version 2: primepower map
    for(ulong &i : primes) {
		for(ulong &j : exp) {
			ulong denom = i;
			ulong power = j;
			power -= 2;
			while(power > 0){
				denom *= i;
				power -= 2;
			}
			limit = (ulong)floor(denom * phi);
			count = limit - denom + 1;
			mpp.emplace(make_pair(i,j),count);
		}
	}
    
    NO_OP;
    
    //~ // setup primepower map
	//~ for(ulong &i : primes){
		//~ for(ulong &j : exp){
			//~ count = 0;
			//~ ulong denom = i;		// defines the denominator
			//~ ulong loops = j/2;		// integer divide by 2 gives loop count
			//~ while(loops){
				//~ limit = (ulong)floor(denom * phi);
				//~ count += (limit - denom);
				//~ denom *= i;
				//~ --loops;			
			//~ }
			//~ mpp.emplace(make_pair(i,j),count);
		//~ }
		//~ NO_OP;
	//~ }
	
	// scan forward from n=4 to find total sequences
	
	const ulong DBN = 1620;	// DEBUG CONSTANT
	
	ulong n = DBN, local, global = 0;
	while(true){
		local = 0;
		// get prime powers for n
		generate_descriptors(primes, n, pfn);	// std::pair<prime,power>
		// ignore powers < 2
		// for each prime power
		for(auto &i : pfn){
			std::pair<ulong,ulong> temp = i;
			if(std::get<1>(temp) < 2) continue;
			if(std::get<1>(temp) % 2 == 1) temp.second -= 1;
			
			//		look up in map
			auto j = mpp.find(temp);
			if(j != mpp.end()) {
				local = 0;
				cout << "found" << endl;
				while(temp.second > 1){
					local += j->second;
					temp.second -= 1;
					// find new value temp
				}
				local += j->second;
			}
			//		if found 
			//			add to local count
			//		else
			else 
				cout << "Not found" << endl;
			//			calc result
			//			add to map
			//			add to local count
			//	next n
		}
		global += local;
		if(++n > DBN) break;	
	}
	cout << global << endl;

    	
	return 0;
}

