# libCZI
[![CMake](https://github.com/FelixS90/libCZIrw_Demo/actions/workflows/cmake.yml/badge.svg?branch=main&event=push)](https://github.com/FelixS90/libCZIrw_Demo/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/FelixS90/libCZIrw_Demo/actions/workflows/codeql-analysis.yml/badge.svg?branch=main&event=push)](https://github.com/FelixS90/libCZIrw_Demo/actions/workflows/codeql-analysis.yml)
[![GitHub Pages](https://github.com/FelixS90/libCZIrw_Demo/actions/workflows/pages.yml/badge.svg?branch=main&event=push)](https://github.com/FelixS90/libCZIrw_Demo/actions/workflows/pages.yml)

## What
libCZI is an Open Source Cross-Platform C++ library to read and write [CZI](https://www.zeiss.com/microscopy/en/products/software/zeiss-zen/czi-image-file-format.html).

## Why 
libCZI is a library intended for providing read and write access to [CZI](https://www.zeiss.com/microscopy/en/products/software/zeiss-zen/czi-image-file-format.html) featuring:

* reading subblocks and get the content as a bitmap
* reading subblocks which are compressed with JPEG-XR
* works with tiled images and pyramid images
* composing multi-channel images with tinting and applying a gradation curve
* access metadata
* writing subblocks and metadata

In a nutshell, it offers (almost...) the same functionality as the 2D-Viewer in [ZEN](https://www.zeiss.com/microscopy/en/products/software/zeiss-zen.html) - in terms of composing the image (including display-settings) and managing the data found in a CZI-file.

## Related Software and Tooling
libCZI is already part of a larger ecosystem.

### OAD
The libCZI libary is part of the [Open Application Development Concept of Zeiss Microscopy](https://github.com/zeiss-microscopy/OAD).

### pylibCZIrw
[pylibCZIrw](https://pypi.org/project/pylibCZIrw/) is a python module for reading and writing CZI files by utilizing/wrapping libCZI.

## Contributing
[CONTRIBUTING.md](/CONTRIBUTING.md)

## Licensing
libCZI is a reader and writer for the CZI fileformat written in C++  
Copyright (C) 2022  Zeiss Microscopy GmbH

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

To obtain a commercial version please contact github.microscopy@zeiss.com.
