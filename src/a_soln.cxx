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
	int n,i,a,b,c,z;
	int g_triangles = 0, count;	// Global count, local count
	// Initialise variables
	bool full_check = false;
	const int max_perim = 1000;
	n = 2;
	
	do{
 		//~ calc limit and hence a,b,c & perimeter at n+limit
 		//~ if perimeter <= max_perimeter {
			//~ count = limit - n
			//~ g_triangles += count
		//~ } else {
			//~ count = 0	// count valid triangles
			//~ i = 1
			//~ do{
				//~ a = n*n
				//~ b = a*(n+i)/n
				//~ c = b*(n+i)/n
				//~ if (a+b+c)<=max_perim
					//~ count += 1
			//~ } while((a+b+c)<=max_perim)
			//~ g_triangles += count
		//~ }
	} while count > 0
	return 0;
}

