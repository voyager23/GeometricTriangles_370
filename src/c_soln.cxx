/*
 * c_soln.cxx
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
#include <utility>
#include <vector>
#include <cmath>
#include <map>
#include "../inc/toolbox.hxx"

// Outline
	//~ start
		//~ setup vector of primes <= 10^6 - see SofE
		//~ setup map of PrimePower,count - see mapprimepowers
		//~ Variables n = 1; total = 0;
		//~ while(true)
			//~ count = 0
			//~ count geometric sequences for n
			//~ check perimeters
			//~ add valid to count
			//~ if count == 0 break???????
			//~ n += 1
			//~ total += count
			//~ loop
		//~ print total
	//~ stop
//

int main(int argc, char **argv)
{
	const ulong maxPerim = 1000000;
	
	return 0;
}

