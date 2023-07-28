/*
 * analyse.cxx
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
#include <numbers>
#include <cmath>

int main(int argc, char **argv)
{
	int n,i,a,b,c;
	
	int g_triangles = 0;
	
	for(n = 2; n <= 18 ; ++n) {
		i = 1;
		int count = 0;
		while((n*n - n*i - i*i) > 0){
			a = n*n;
			b = a*(n+i)/n;
			c = b*(n+i)/n;	
			std::cout << "n:" << n << "	i:" << i;
			std::cout << " a:" << a << " b:" << b << " c:" << c;
			std::cout << " perim:" << a+b+c << std::endl;
			i++;
			g_triangles += 1;
			count += 1;
		}
		std::cout << "Count: " << count << "G_triangles: " << g_triangles << std::endl;
		std::cout << "limit(n+i):" << floor(n * std::numbers::phi_v<double>) << std::endl << std::endl;
	}
	std::cout << "G_triangles: " << g_triangles << std::endl;
	return 0;
}

