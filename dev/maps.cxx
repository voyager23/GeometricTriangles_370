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

using namespace std;

int main(int argc, char **argv)
{
	// Source data
	vector<ulong> primes = {2,3,5,7,11,13,17,19};
	vector<ulong> exp = {2,4,6,8,10,12};
	// Containers
	map<ulong, vector<ulong>> datamap;
	for(ulong p : primes){
		datamap.emplace(p,vector<ulong>{});
	}
	
	// Test code
	auto r = datamap.find(19);
	
	if (r != datamap.end()){
		cout << r->first << endl;
	}
	
	int foo = 0;
	
	return 0;
}

