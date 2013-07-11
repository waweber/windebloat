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
 * Downloader.h
 *
 *  Created on: Jul 5, 2013
 *      Author: wweber
 */

#ifndef DOWNLOADER_H_
#define DOWNLOADER_H_

#include <Windows.h>
#include <winhttp.h>
#include <string>

/**
 * Class that uses WinHttp to download a file from the internet.
 */
class Downloader
{
public:
	Downloader();
	virtual ~Downloader();

	/**
	 * Download a file and save it to the local filesystem.
	 * This function blocks until the download is complete.
	 * An exception will be thrown if the download fails.
	 * @param pUrl The URL to download
	 * @param pFilename The name of the file to write to.
	 */
	void download(const std::wstring& pUrl, const std::string& pFilename);

protected:
	HINTERNET mTubes;
};

#endif /* DOWNLOADER_H_ */
