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
	long n,i,a,b,c,z;
	long g_triangles = 0, count;	// Global count, local count
	// Initialise variables
	// bool full_check = false;
	const long max_perim = 1000000;
	n = 12;	
	do{
 		//~ calc limit and hence a,b,c & perimeter at n+limit
		// find limit for n.
		z = (long)floor(n * std::numbers::phi_v<double>);
		cout << setw(15) << n << " ";
		// calc a,b,c for the limit value
		// common_ratio is z/n
		a = n*n;
		b = a*z/n;
		c = b*z/n;
		if ((a+b+c)<=max_perim){
			count = z - n;
			g_triangles += count;
		} else {
			count = 0;	// count valid triangles
			i = 1;
			do{
				a = n*n;
				b = a*(n+i)/n;
				c = b*(n+i)/n;
				if ((a+b+c) <= max_perim)
					count += 1;
				i += 1;
			} while((a+b+c)<=max_perim);
			g_triangles += count;			
		} // else...
		n += 1;
		cout << setw(15) << g_triangles << endl;
	} while (count > 0);
	cout << "Max perimeter:" << max_perim << " G_Triangles:" << g_triangles << endl;
	return 0;
}

