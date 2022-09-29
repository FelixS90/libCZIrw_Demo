
#pragma once

#include "libCZI_Pixels.h"

class CSingleChannelTileCompositor
{
public:
	static void Compose(libCZI::IBitmapData* dest, libCZI::IBitmapData* source, int x, int y, bool drawTileBorder);
};
