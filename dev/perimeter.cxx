/*
 * perimeter.cxx
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
	bool full_check = false;
	const int max_perim = 1000;
	
	n = 11;
	do {
		// find limit for n.
		z = (int)floor(n * std::numbers::phi_v<double>);
		cout << setw(6) << n;
		// calc a,b,c for the limit value
		// common_ratio is z/n
		a = n*n;
		b = a*z/n;
		c = b*z/n;
		auto t = make_tuple(a,b,c);
		auto p = a+b+c;
		cout << setw(6) << z << setw(6) << a;
		cout << setw(6) << b;
		cout << setw(6) << c;
		cout << setw(6) << p << endl;
		if(p > max_perim) full_check = true;
		++n;
	} while(!(full_check));
	
	return 0;
}

