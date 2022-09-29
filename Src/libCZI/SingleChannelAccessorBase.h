
#pragma once

#include "libCZI.h"

class CSingleChannelAccessorBase
{
protected:
	std::shared_ptr<libCZI::ISubBlockRepository> sbBlkRepository;

	explicit CSingleChannelAccessorBase(std::shared_ptr<libCZI::ISubBlockRepository> sbBlkRepository)
		: sbBlkRepository(sbBlkRepository)
	{}

	bool TryGetPixelType(const libCZI::IDimCoordinate* planeCoordinate, libCZI::PixelType& pixeltype);

	static void Clear(libCZI::IBitmapData* bm, const libCZI::RgbFloatColor& floatColor);

	void CheckPlaneCoordinates(const libCZI::IDimCoordinate* planeCoordinate) const;
};
