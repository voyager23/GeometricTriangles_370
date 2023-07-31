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
	long limit,m,i, perim;
	const double phi = 1.61803398874989;
	long g_triangles = 0, count;	// Global count, local count
	// Initialise variables
	const long max_perim = 1000000;
	for(seed = 12; seed != 13; ++seed) {
		limit = (long)std::floor(seed * phi);
		for(i = 1; i <= limit; ++i) {
			a = seed * seed;
			b = seed * (seed + i);
			c = (seed + i) * (seed + i);
			perim = (a + b + c);
		}
	}	
}
