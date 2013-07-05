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
