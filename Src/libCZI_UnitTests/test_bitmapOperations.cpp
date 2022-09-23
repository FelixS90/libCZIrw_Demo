//******************************************************************************
// 
// libCZI is a reader and writer for the CZI fileformat written in C++
// Copyright (C) 2017-2021  Zeiss Microscopy GmbH
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

#include "pch.h"
#include "testImage.h"
#include "inc_libCZI.h"
#include "utils.h"

using namespace libCZI;

static std::shared_ptr<IBitmapData> CreateTestImage()
{
    auto bm = CBitmapData<CHeapAllocator>::Create(PixelType::Bgr24, CTestImage::BGR24TESTIMAGE_WIDTH, CTestImage::BGR24TESTIMAGE_HEIGHT);
    ScopedBitmapLockerSP lck{ bm };
    CTestImage::CopyBgr24Image(lck.ptrDataRoi, bm->GetWidth(), bm->GetHeight(), lck.stride);
    return bm;
}

TEST(BitmapOperations, NNResize1)
{
    static const std::uint8_t expectedResult[16] = { 0xfc,0xfc,0x14,0x65,0xb0,0xc7,0xe0,0x42,0x4e,0x5e,0x12,0xcb,0x30,0x64,0x30,0x1e };

    auto srcBm = CreateTestImage();
    auto bm = CBitmapData<CHeapAllocator>::Create(srcBm->GetPixelType(), 100, 100);
    CBitmapOperations::NNResize(srcBm.get(), bm.get());
    std::uint8_t hash[16];
    CBitmapOperations::CalcMd5Sum(bm.get(), hash, sizeof(hash));
    int c = memcmp(expectedResult, hash, sizeof(hash));
    EXPECT_EQ(c, 0);
}

TEST(BitmapOperations, NNResizeWithScale1CheckResult)
{
    // check that for "minification factor of 1" we get a 1:1 copy of the source bitmap
    auto sourcebitmap = CreateTestBitmap(PixelType::Bgr24, 163, 128);
    auto destBitmap = CBitmapData<CHeapAllocator>::Create(PixelType::Bgr24, 163, 128);
    CBitmapOperations::NNResize(sourcebitmap.get(), destBitmap.get());
    EXPECT_TRUE(AreBitmapDataEqual(sourcebitmap, destBitmap)) << "Bitmaps are expected to be equal.";
}