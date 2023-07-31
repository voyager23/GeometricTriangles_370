/*
 * gcdchk.cxx
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
#include <numeric>

int main(int argc, char **argv)
{
	int a,b,c;
	for(a = 100; a != 200; ++a){
		for(b = a +1; b != 200; ++b){
			if (std::gcd(a,b) > 1){
				std::cout<<"a:"<<a<<" b:"<<b<<" gcd:"<<std::gcd(a,b)<<std::endl;
			}
		}
	}
	return 0;
}

