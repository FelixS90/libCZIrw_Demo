"""
This is a utility for preparing files in a folder for usage with CMake's ExternalData-mechanism
(c.f. https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html#managing-test-data).

The synopsis is: prepare_sample_data.py -s <source_directory> -d <destination_directory> -p <pointer_destination_directory>

'source_directory' is the folder where the files to be processed are found in. Only files directly in this folder
are processed (i.e. no sub-folders).

For each file md5-checksum is calculated. Then, the file is copied to a file which gets the filename of the hash-code
in the destination_directory. If the argument destination_directory is not given, this step is not done.
Next, the hash-code is written into a file with the same name as the original file with ".md5" appended, in the
directory pointer_destination_directory. Again, if the argument pointer_destination_directory is not given, this
step is not done.

"""
import argparse
import hashlib
import os
import shutil
import sys


class Parameters:
    __sourceDirectory: str
    __destinationDirectory: str
    __pointersDestinationDirectory: str

    def parse_commandline(self):
        parser = argparse.ArgumentParser(
            description='Utility for preparing test-data to be stored for CMake-test-data')
        parser.add_argument('-s', '--source', dest='source_directory',
                            help='The source directory containing the files to be processed.')
        parser.add_argument('-d', '--destination', dest='destination_directory',
                            help='The folder where the renamed files will be copied to.')
        parser.add_argument('-p', '--pointer_destination', dest='pointer_destination_directory',
                            help='The folder where the pointer-files will be written to.')
        args = parser.parse_args()
        if args.source_directory:
            self.__sourceDirectory = args.source_directory
        else:
            print('Error, no source directory specified.')
            sys.exit(99)

        if args.source_directory:
            self.__destinationDirectory = args.destination_directory
        if args.pointer_destination_directory:
            self.__pointersDestinationDirectory = args.pointer_destination_directory

    def get_source_directory(self):
        return self.__sourceDirectory

    def get_destination_directory(self):
        return self.__destinationDirectory

    def get_pointer_destination_directory(self):
        return self.__pointersDestinationDirectory


def hashfile(file_name):
    block_size = 65536
    hasher = hashlib.md5()
    with open(file_name, 'rb') as filestream:
        buf = filestream.read(block_size)
        while len(buf) > 0:
            hasher.update(buf)
            buf = filestream.read(block_size)

    return hasher.hexdigest()


parameters = Parameters()
parameters.parse_commandline()
list_of_files = os.listdir(parameters.get_source_directory())

for file in list_of_files:
    sourceFileFullPath = os.path.join(parameters.get_source_directory(), file)
    if os.path.isfile(sourceFileFullPath):
        hash_code = hashfile(sourceFileFullPath)
        print(f"file: {file} hash: {hash_code}")
        if parameters.get_destination_directory():
            destFileFullPath = os.path.join(parameters.get_destination_directory(), hash_code)
            shutil.copy(sourceFileFullPath, destFileFullPath)
        if parameters.get_pointer_destination_directory():
            with open(os.path.join(parameters.get_pointer_destination_directory(), file) + ".md5", 'w') as pointer_file:
                pointer_file.write(hash_code)
