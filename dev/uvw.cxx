/*
 * uvw.cxx
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

int main(int argc, char **argv)
{
	ulong u,u2,v,w;
	double s;
	
	for(w = 1; w != 156; ++w){
		u2 = w*(156-w);
		s = std::sqrt(u2);
		u = (ulong)std::floor(s);
		if ((u*u)==u2){
			std::cout<<"u2:"<<u2<<"  w:"<<w<<std::endl;
		}
		
	}
	
	return 0;
}

