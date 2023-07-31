/*
 * a_soln.cxx
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
#include <iomanip>
#include <numbers>
#include <cmath>
#include <tuple>

using namespace std;

int main(int argc, char **argv)
{
	//const long Foo = 25000000000000;
	long seed, max_seed = 548;
	long limit,m,i,a,b,c,perim;
	const double phi = 1.61803398874989;
	long g_triangles = 0, count;	// Global count, local count
	// Initialise variables
	const long max_perim = 1000000;
	for(seed = 2; seed != max_seed; ++seed) {
		limit = (long)std::floor(seed * phi);
		for(i = 1; i <= limit; ++i) {
			a = seed * seed;
			b = seed * (seed + i);
			c = (seed + i) * (seed + i);
			perim = (a + b + c);
			if(perim <= max_perim) {
				//std::cout<<setw(8)<<i<<setw(8)<<a<<setw(8)<<b<<setw(8)<<c<<setw(8)<<perim<<std::endl;
				// This is the base case for this value of i.
				// Find multiples of the base case for perimeters <= max_perim
				long count = 1;
				g_triangles += 1;
				m = 2;
				do{
					perim = m * (a+b+c);
					if (perim <= max_perim) {
						g_triangles += 1;
						m += 1;
					} else {
						break;
					}
				}while(1);
				//std::cout<<"Found a total of "<<count<<" triangles for this config."<<std::endl;
				//std::cout<<std::endl;				
			} // if perim
		} // for i...
	} // for seed
	std::cout<<g_triangles<<std::endl;
}
