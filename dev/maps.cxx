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
#include "../inc/toolbox.hxx"

using namespace std;
// Typedefs
typedef map<ulong,vector<ulong>> DataMap;	

void prt_map_vector(DataMap);
void prt_map_vector(DataMap mpp){
	for(const auto& k : mpp){
		cout<<k.first<<" - ";
		for(const auto& v : k.second){
			cout<<v<<" ";
		}
		cout<<endl;
	}
}


#define NO_OP int foo = 0

int main(int argc, char **argv)
{

	// Source data
	const ulong maxPerim = 1000000;
	const double phi = 1.61803398874989;
	vector<ulong> primes = {2,3,5,7,11,13,17,19,23,29,31};
	vector<ulong> exp = {2,4,6,8,10,12,14,16,18,20};
	// Containers
	DataMap datamap;
	DataMap countmap;
	DataMap maxperimmap;
	
	// Load vectors
	datamap.clear();
	maxperimmap.clear();
	for(auto i : primes){
		vector<ulong> tmp = {};
		vector<ulong> tmp2 = {};
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
	NO_OP;
	cout<<endl<<"Individual totals."<<endl;
	prt_map_vector(datamap);
	
	// derive a new data map with cumulative totals
	countmap.clear();
	for(const auto& k : datamap){
		ulong seq_count = 0;
		vector<ulong> tmp = {};			
		for(auto v : k.second){
			v += seq_count;
			seq_count = v;
			tmp.push_back(seq_count);
		}
		countmap.emplace(k.first,tmp);
	}
	cout<<endl;
	cout<<"Cumulative totals."<<endl;
	prt_map_vector(countmap);
	
	// Note: the max perimeter can only be determined when the sequence start value {scale factor} is known.
	// For a max perimeter of 10^6, 190,988 <= scale factor <= 333,333
	// largest prime required is approx 250,000
	
	// for each object number:
	//		get prime factors
	//		discard exp < 2
	//		set local_count = 0
	//		for each primepower pair:
	//			local_count += cumulative total from countmap
	//			using common ratio from max_limit/denominator find perim
	//			while (limit >= denom)and(perim > max):
	//				local_count -= 1
	//				limit -= 1;
	//			# end while
	//			global_count += local_count
	//		# end for each primepower
	//	# end for each object number
	//	
	
	return 0;
}

