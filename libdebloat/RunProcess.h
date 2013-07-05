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
