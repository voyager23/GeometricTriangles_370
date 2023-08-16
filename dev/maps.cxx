/*
 * maps.cxx
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
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void prt_map_vector(map<ulong, vector<ulong>>);
void prt_map_vector(map<ulong, vector<ulong>> mpp){
	for(const auto& k : mpp){
		cout<<k.first<<" - ";
		for(const auto& v : k.second){
			cout<<v<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char **argv)
{
	// Source data
	const ulong maxPerim = 1000000;
	const double phi = 1.61803398874989;
	vector<ulong> primes = {2,3,5,7,11,13,17,19};
	vector<ulong> exp = {2,4,6,8,10,12};
	// Containers
	map<ulong, vector<ulong>> datamap;
	
	// Load vectors
	for(auto i : primes){
		vector<ulong> tmp = {};
		for(auto j : exp){
			ulong den = i;
			ulong pwr = j - 2;
			while(pwr>0){
				den *= i;
				pwr -= 2;
			}
			ulong limit = (ulong)floor(den * phi);
			ulong count = limit - den + 1;
			tmp.push_back(count);			
		}
		datamap.emplace(i,tmp);
	}
	
	int foo = 0;	// NO_OP
	
	prt_map_vector(datamap);
	
	return 0;
}

