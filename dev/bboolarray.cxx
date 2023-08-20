/*
 * boolarray.cxx
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
#include <array>
#include <vector>
#include "../inc/toolbox.hxx"

using namespace std;

int main(int argc, char **argv)
{
	const ulong max_perim = 1000000;
	std::vector<ulong> primes;
	SofE(primes,max_perim);
	std::vector<ulong> factors;
	
	const size_t la = 200;	// define array size
	array<bool,la> a = {0};
	ulong n,m,sq;
	
	for(ulong &p : primes){
		sq = p*p;
		if(sq < la){
			do{
				a[sq] = true;
				sq += p;
			}while(sq < la);
		} else {
			break;
		}
	}
	
	for(auto i = 0; i < la; ++i){
		if(a[i]){
			cout << i << " ";
			find_factors(primes, i, factors);
			for(auto& p : factors) cout << p << " ";
			cout << endl;
		}
	}
	return 0;
}

