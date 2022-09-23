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
// Contact Details: github.microscopy@zeiss.com
// 
//******************************************************************************

#pragma once

#include <cstdint>

class CHeapAllocator
{
public:
	void*	Allocate(std::uint64_t size);
	void	Free(void* ptr);
};

class CSharedPtrAllocator
{
private:
	std::shared_ptr<const void> shp;
public:
	explicit CSharedPtrAllocator(std::shared_ptr<const void> shp) :shp(shp) {}

	void*	Allocate(std::uint64_t size) { return const_cast<void*>(this->shp.get()); }
	void	Free(void* ptr) { this->shp.reset(); }
};
