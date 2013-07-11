/*
 * This file is part of WinDeBloat.
 * 
 * WinDeBloat is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * WinDeBloat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with WinDeBloat.  If not, see <http://www.gnu.org/licenses/>. 
 */

/*
 * RunProcess.h
 *
 *  Created on: Jul 4, 2013
 *      Author: wweber
 */

#ifndef RUNPROCESS_H_
#define RUNPROCESS_H_

#include <Windows.h>
#include <string>

/**
 * @file
 * Contains the utility function runProcess
 */

/**
 * Run a process, redirecting its input and output into this program.
 * Blocks until the program's stdout closes.
 * @param pCmdline The full command line to run.
 * @param pInput The input to send to the child's stdin
 * @return The full output of the child's stdout
 */
std::string runProcess(const std::string& pCmdline, const std::string& pInput);

#endif /* RUNPROCESS_H_ */
