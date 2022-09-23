//******************************************************************************
// 
// libCZI is a reader and writer for the CZI fileformat written in C++
// Copyright (C) 2017 Carl Zeiss Microscopy GmbH
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
// 
// To obtain a commercial version please contact Zeiss Microscopy GmbH.
// 
//******************************************************************************

#pragma once

#include "CziStructs.h"

class CFileHeaderSegmentData
{
private:
	int verMajor, verMinor;
	GUID fileGuid;
	std::uint64_t subBlockDirectoryPosition;
	std::uint64_t attachmentDirectoryPosition;
	std::uint64_t metadataPosition;
public:
	CFileHeaderSegmentData()
		:verMajor(-1),
		verMinor(-1),
		fileGuid({ 0, 0, 0, { 0,0,0,0,0,0,0,0 } }),
		subBlockDirectoryPosition((std::numeric_limits<decltype(subBlockDirectoryPosition)>::max)()),
		attachmentDirectoryPosition((std::numeric_limits<decltype(subBlockDirectoryPosition)>::max)()),
		metadataPosition((std::numeric_limits<decltype(subBlockDirectoryPosition)>::max)())
	{
		
	}

	CFileHeaderSegmentData(const FileHeaderSegmentData* hdrSegmentData) :
		verMajor(hdrSegmentData->Major),
		verMinor(hdrSegmentData->Minor),
		fileGuid(hdrSegmentData->FileGuid),
		subBlockDirectoryPosition(hdrSegmentData->SubBlockDirectoryPosition),
		attachmentDirectoryPosition(hdrSegmentData->AttachmentDirectoryPosition),
		metadataPosition(hdrSegmentData->MetadataPosition)
	{}

	void GetVersion(int* ptrMajor, int* ptrMinor) const
	{
		if (ptrMajor != nullptr) { *ptrMajor = this->verMajor; }
		if (ptrMinor != nullptr) { *ptrMinor = this->verMinor; }
	}

	std::uint64_t GetSubBlockDirectoryPosition() const { return this->subBlockDirectoryPosition; }
	std::uint64_t GetAttachmentDirectoryPosition() const { return this->attachmentDirectoryPosition; }
	std::uint64_t GetMetadataPosition() const { return this->metadataPosition; }
	GUID GetFileGuid()const { return this->fileGuid; }

	bool GetIsSubBlockDirectoryPositionValid()const
	{
		return  this->subBlockDirectoryPosition != (std::numeric_limits<decltype(subBlockDirectoryPosition)>::max)() && this->subBlockDirectoryPosition != 0;
	}

	bool GetIsAttachmentDirectoryPositionValid()const
	{
		return  this->attachmentDirectoryPosition != (std::numeric_limits<decltype(attachmentDirectoryPosition)>::max)() && this->attachmentDirectoryPosition != 0;
	}

	bool GetIsMetadataPositionPositionValid()const
	{
		return  this->metadataPosition != (std::numeric_limits<decltype(metadataPosition)>::max)() && this->metadataPosition != 0;
	}
};
