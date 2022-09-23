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

#include "pch.h"
#include "inc_libCZI.h"

using namespace libCZI;

TEST(Splines, Splines1)
{
	static const double Points[] = { 0,0,0.362559241706161,0.876190476190476 ,0.554502369668246,0.561904761904762 ,1,1 };

	auto result = CSplines::GetSplineCoefficients(
		sizeof(Points) / sizeof(Points[0]) / 2,
		[](int idx, double* pX, double* pY)->void
	{
		idx *= 2;
		if (pX != nullptr) { *pX = Points[idx]; }
		if (pY != nullptr) { *pY = Points[idx + 1]; }
	});

	EXPECT_EQ(result.size(), (size_t)3) << "Incorrect result";

	EXPECT_NEAR(result[0].a, -11.360115103033465, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[0].b, 0, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[0].c, 3.9099603132098, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[0].d, 0, 1e-6) << "Incorrect result";

	EXPECT_NEAR(result[1].a, 35.39860240958761, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[1].b, -12.356144152351561, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[1].c, -0.5698739410787983, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[1].d, 0.876190476190476, 1e-6) << "Incorrect result";

	EXPECT_NEAR(result[2].a, -6.0063254490025031, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[2].b, 8.0274112635957717, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[2].c, -1.4007444718589364, 1e-6) << "Incorrect result";
	EXPECT_NEAR(result[2].d, 0.561904761904762, 1e-6) << "Incorrect result";
}
