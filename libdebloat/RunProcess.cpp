/*
 * RunProcess.cpp
 *
 *  Created on: Jul 4, 2013
 *      Author: wweber
 */
#include "RunProcess.h"

std::string runProcess(const std::string& pCmdline, const std::string& pInput)
{
	//process info
	STARTUPINFO start_info =
	{ 0 };
	PROCESS_INFORMATION proc_info =
	{ 0 };

	SECURITY_ATTRIBUTES sattr =
	{ 0 };
	sattr.bInheritHandle = TRUE;
	sattr.nLength = sizeof(SECURITY_ATTRIBUTES);
	sattr.lpSecurityDescriptor = NULL;

	HANDLE stdout_read;
	HANDLE stdout_write;
	HANDLE stdin_read;
	HANDLE stdin_write;
	CreatePipe(&stdout_read, &stdout_write, &sattr, 1024);
	SetHandleInformation(stdout_read, HANDLE_FLAG_INHERIT, 0);
	CreatePipe(&stdin_read, &stdin_write, &sattr, 1024);
	SetHandleInformation(stdin_write, HANDLE_FLAG_INHERIT, 0);

	start_info.cb = sizeof(STARTUPINFO);
	start_info.dwFlags |= STARTF_USESTDHANDLES;
	start_info.hStdError = stdout_write;
	start_info.hStdOutput = stdout_write;
	start_info.hStdInput = stdin_read;

	//output
	std::string out;

	//TODO: might segfault on pcmdline string
	int res = CreateProcess(NULL, (LPSTR) pCmdline.c_str(), NULL, NULL, TRUE, 0,
	NULL, NULL, &start_info, &proc_info);

	CloseHandle(stdout_write);
	CloseHandle(stdin_read);

	if (res)
	{
		CloseHandle(proc_info.hThread);
		CloseHandle(proc_info.hProcess);

		//write input
		DWORD nWrite;
		int rerr = WriteFile(stdin_write, pInput.c_str(), pInput.size(),
				&nWrite, NULL);

		//read
		for (;;)
		{
			DWORD nRead;
			char buf[128];
			res = 0;
			res = ReadFile(stdout_read, buf, 128, &nRead, NULL);
			if (!res || nRead == 0)
				break;

			//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buf, nRead, &nWrite,
			//NULL);

			out.append(buf, nRead);
		}
	}

	CloseHandle(stdout_read);
	CloseHandle(stdin_write);

	return out;
}

