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
 * Downloader.cpp
 *
 *  Created on: Jul 5, 2013
 *      Author: wweber
 */

#include "Downloader.h"
#include <exception>
#include <cstdio>

Downloader::Downloader()
{
	mTubes = WinHttpOpen(L"Mozilla/4.0 (Windows; MSIE 6.0; Windows NT 5.0)",
	WINHTTP_ACCESS_TYPE_NO_PROXY, WINHTTP_NO_PROXY_NAME,
	WINHTTP_NO_PROXY_BYPASS, 0);

	if (!mTubes)
		throw std::exception();
}

Downloader::~Downloader()
{
	if (mTubes)
		WinHttpCloseHandle(mTubes);
}

void Downloader::download(const std::wstring& pUrl,
		const std::string& pFilename)
{
	URL_COMPONENTS urlcomp =
	{ 0 };
	urlcomp.dwStructSize = sizeof(URL_COMPONENTS);
	urlcomp.dwSchemeLength = 1;
	urlcomp.dwHostNameLength = 1;
	urlcomp.dwUrlPathLength = 1;
	urlcomp.dwExtraInfoLength = 1;

	if (!WinHttpCrackUrl(pUrl.c_str(), 0, 0, &urlcomp))
	{
		throw std::exception(); //bad url
	}

	//open output file
	FILE* outfile = fopen(pFilename.c_str(), "w+b"); //windows binary flag
	if (!outfile)
	{
		throw std::exception();
	}

	//something weird happens with the hostname including the path
	WCHAR temp[256] =
	{ 0 };
	memcpy(temp, urlcomp.lpszHostName,
			urlcomp.dwHostNameLength * sizeof(WCHAR));

	//connect
	HINTERNET con = WinHttpConnect(mTubes, temp, urlcomp.nPort, 0);

	if (!con)
	{
		fclose(outfile);
		throw std::exception();
	}

	//make request
	HINTERNET req = WinHttpOpenRequest(con, L"GET", urlcomp.lpszUrlPath, NULL,
	WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
	if (!req)
	{
		fclose(outfile);
		WinHttpCloseHandle(con);
		throw std::exception();
	}

	//send request
	DWORD_PTR junk;
	if (!WinHttpSendRequest(req, NULL, 0, NULL, 0, 0, junk))
	{
		fclose(outfile);
		WinHttpCloseHandle(con);
		WinHttpCloseHandle(req);
		throw std::exception();
	}

	//receive request
	if (!WinHttpReceiveResponse(req, NULL))
	{
		fclose(outfile);
		WinHttpCloseHandle(con);
		WinHttpCloseHandle(req);
		throw std::exception();
	}

	//read
	for (;;)
	{
		DWORD read = 0;
		char data[4096];
		int res = WinHttpReadData(req, data, 4096, &read);

		if (!res || read == 0)
		{
			break;
		}

		//write data
		fwrite(data, sizeof(char), read, outfile);
	}

	//close handles
	WinHttpCloseHandle(req);
	WinHttpCloseHandle(con);
	fclose(outfile);
}
