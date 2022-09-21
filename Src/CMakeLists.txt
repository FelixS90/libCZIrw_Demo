cmake_minimum_required(VERSION 3.1)

include(ExternalEIGEN3)

add_subdirectory(JxrDecode)
add_subdirectory(libCZI)

if (LIBCZI_BUILD_UNITTESTS)
 add_subdirectory(libCZI_UnitTests)
endif(LIBCZI_BUILD_UNITTESTS)