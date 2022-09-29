
#pragma once

#include "libCZI_Pixels.h"
#include "../JxrDecode/JxrDecode.h"
#include "libCZI_Site.h"

class CJxrLibDecoder : public libCZI::IDecoder
{
private:
		JxrDecode::codecHandle handle;
public:
		static std::shared_ptr<CJxrLibDecoder> Create();

		explicit CJxrLibDecoder(JxrDecode::codecHandle handle)
				: handle(handle)
		{}

public:
		std::shared_ptr<libCZI::IBitmapData> Decode(const void* ptrData, size_t size, libCZI::PixelType, std::uint32_t width, std::uint32_t height) override;
};
