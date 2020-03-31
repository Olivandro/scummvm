/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "sci/sci.h"
#include "sci/engine/state.h"
#include "sci/graphics/screen.h"
#include "sci/graphics/font.h"

namespace Sci {

#ifdef ENABLE_SCI32
static const byte sci32SystemFont[] = {
	0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x06, 0x01,
	0x09, 0x01, 0x0c, 0x01, 0x0f, 0x01, 0x12, 0x01,
	0x15, 0x01, 0x18, 0x01, 0x1b, 0x01, 0x1e, 0x01,
	0x21, 0x01, 0x26, 0x01, 0x29, 0x01, 0x2c, 0x01,
	0x2f, 0x01, 0x32, 0x01, 0x35, 0x01, 0x38, 0x01,
	0x3b, 0x01, 0x3e, 0x01, 0x41, 0x01, 0x44, 0x01,
	0x47, 0x01, 0x4a, 0x01, 0x4d, 0x01, 0x50, 0x01,
	0x53, 0x01, 0x56, 0x01, 0x59, 0x01, 0x5c, 0x01,
	0x5f, 0x01, 0x62, 0x01, 0x65, 0x01, 0x68, 0x01,
	0x71, 0x01, 0x7a, 0x01, 0x83, 0x01, 0x8c, 0x01,
	0x95, 0x01, 0x9e, 0x01, 0xa7, 0x01, 0xb0, 0x01,
	0xb9, 0x01, 0xc2, 0x01, 0xc9, 0x01, 0xd3, 0x01,
	0xdc, 0x01, 0xe5, 0x01, 0xee, 0x01, 0xf7, 0x01,
	0x00, 0x02, 0x09, 0x02, 0x12, 0x02, 0x1b, 0x02,
	0x24, 0x02, 0x2d, 0x02, 0x36, 0x02, 0x3f, 0x02,
	0x48, 0x02, 0x51, 0x02, 0x5a, 0x02, 0x63, 0x02,
	0x6c, 0x02, 0x75, 0x02, 0x7e, 0x02, 0x87, 0x02,
	0x90, 0x02, 0x99, 0x02, 0xa2, 0x02, 0xab, 0x02,
	0xb4, 0x02, 0xbd, 0x02, 0xc6, 0x02, 0xcf, 0x02,
	0xd8, 0x02, 0xe1, 0x02, 0xea, 0x02, 0xf3, 0x02,
	0xfc, 0x02, 0x05, 0x03, 0x0e, 0x03, 0x17, 0x03,
	0x20, 0x03, 0x29, 0x03, 0x32, 0x03, 0x3b, 0x03,
	0x44, 0x03, 0x4d, 0x03, 0x56, 0x03, 0x5f, 0x03,
	0x68, 0x03, 0x71, 0x03, 0x7a, 0x03, 0x83, 0x03,
	0x8c, 0x03, 0x95, 0x03, 0x9e, 0x03, 0xa7, 0x03,
	0xb0, 0x03, 0xb9, 0x03, 0xc2, 0x03, 0xcb, 0x03,
	0xd4, 0x03, 0xdd, 0x03, 0xe6, 0x03, 0xef, 0x03,
	0xf8, 0x03, 0x01, 0x04, 0x0a, 0x04, 0x13, 0x04,
	0x1c, 0x04, 0x25, 0x04, 0x2e, 0x04, 0x37, 0x04,
	0x40, 0x04, 0x49, 0x04, 0x52, 0x04, 0x5b, 0x04,
	0x64, 0x04, 0x6d, 0x04, 0x76, 0x04, 0x7f, 0x04,
	0x88, 0x04, 0x91, 0x04, 0x9b, 0x04, 0xa4, 0x04,
	0xad, 0x04, 0xb6, 0x04, 0xbf, 0x04, 0x02, 0x01,
	0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01,
	0x40, 0x13, 0x01, 0x00, 0x00, 0x00, 0x02, 0x01,
	0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01,
	0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01,
	0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x07, 0x40, 0x40, 0x40, 0x40, 0x00,
	0x40, 0x00, 0x05, 0x07, 0x50, 0x50, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x06, 0x07, 0x28, 0x7c, 0x28,
	0x28, 0x7c, 0x28, 0x00, 0x04, 0x07, 0x20, 0x30,
	0x40, 0x20, 0x10, 0x60, 0x20, 0x06, 0x07, 0x24,
	0x58, 0x34, 0x28, 0x40, 0x00, 0x00, 0x04, 0x07,
	0x20, 0x30, 0x40, 0x20, 0x40, 0x30, 0x20, 0x03,
	0x07, 0x20, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00,
	0x04, 0x07, 0x10, 0x20, 0x40, 0x40, 0x40, 0x20,
	0x10, 0x04, 0x07, 0x40, 0x20, 0x10, 0x10, 0x10,
	0x20, 0x40, 0x06, 0x05, 0x10, 0x54, 0x38, 0x54,
	0x10, 0x04, 0x08, 0x00, 0x20, 0x20, 0x70, 0x20,
	0x20, 0x00, 0x00, 0x03, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x40, 0x05, 0x07, 0x00, 0x00,
	0x00, 0x70, 0x00, 0x00, 0x00, 0x04, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x05, 0x07,
	0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x00, 0x05,
	0x07, 0x30, 0x48, 0x58, 0x68, 0x48, 0x30, 0x00,
	0x05, 0x07, 0x20, 0x60, 0x20, 0x20, 0x20, 0x70,
	0x00, 0x05, 0x07, 0x30, 0x48, 0x08, 0x30, 0x40,
	0x78, 0x00, 0x05, 0x07, 0x70, 0x08, 0x30, 0x08,
	0x08, 0x70, 0x00, 0x05, 0x07, 0x18, 0x28, 0x48,
	0x78, 0x08, 0x08, 0x00, 0x05, 0x07, 0x78, 0x40,
	0x70, 0x08, 0x08, 0x70, 0x00, 0x05, 0x07, 0x30,
	0x40, 0x70, 0x48, 0x48, 0x30, 0x00, 0x05, 0x07,
	0x78, 0x08, 0x10, 0x20, 0x20, 0x20, 0x00, 0x05,
	0x07, 0x30, 0x48, 0x30, 0x48, 0x48, 0x30, 0x00,
	0x05, 0x07, 0x30, 0x48, 0x48, 0x38, 0x08, 0x30,
	0x00, 0x02, 0x07, 0x00, 0x40, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x03, 0x07, 0x00, 0x20, 0x00, 0x00,
	0x20, 0x20, 0x40, 0x04, 0x07, 0x00, 0x10, 0x20,
	0x40, 0x20, 0x10, 0x00, 0x04, 0x07, 0x00, 0x00,
	0x70, 0x00, 0x70, 0x00, 0x00, 0x04, 0x07, 0x00,
	0x40, 0x20, 0x10, 0x20, 0x40, 0x00, 0x04, 0x07,
	0x20, 0x50, 0x10, 0x20, 0x20, 0x00, 0x20, 0x08,
	0x07, 0x1c, 0x2a, 0x55, 0x55, 0x2e, 0x18, 0x00,
	0x05, 0x07, 0x30, 0x48, 0x48, 0x78, 0x48, 0x48,
	0x00, 0x05, 0x07, 0x70, 0x48, 0x70, 0x48, 0x48,
	0x70, 0x00, 0x05, 0x07, 0x30, 0x48, 0x40, 0x40,
	0x48, 0x30, 0x00, 0x05, 0x07, 0x70, 0x48, 0x48,
	0x48, 0x48, 0x70, 0x00, 0x05, 0x07, 0x78, 0x40,
	0x70, 0x40, 0x40, 0x78, 0x00, 0x05, 0x07, 0x78,
	0x40, 0x70, 0x40, 0x40, 0x40, 0x00, 0x05, 0x07,
	0x30, 0x48, 0x40, 0x58, 0x48, 0x30, 0x00, 0x05,
	0x07, 0x48, 0x48, 0x78, 0x48, 0x48, 0x48, 0x00,
	0x04, 0x07, 0x70, 0x20, 0x20, 0x20, 0x20, 0x70,
	0x00, 0x05, 0x07, 0x08, 0x08, 0x08, 0x08, 0x48,
	0x30, 0x00, 0x05, 0x07, 0x48, 0x50, 0x60, 0x50,
	0x48, 0x48, 0x00, 0x05, 0x07, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x78, 0x00, 0x06, 0x07, 0x44, 0x6c,
	0x54, 0x44, 0x44, 0x44, 0x00, 0x06, 0x07, 0x44,
	0x64, 0x54, 0x4c, 0x44, 0x44, 0x00, 0x05, 0x07,
	0x30, 0x48, 0x48, 0x48, 0x48, 0x30, 0x00, 0x05,
	0x07, 0x70, 0x48, 0x48, 0x70, 0x40, 0x40, 0x00,
	0x06, 0x07, 0x30, 0x48, 0x48, 0x48, 0x48, 0x38,
	0x04, 0x05, 0x07, 0x70, 0x48, 0x48, 0x70, 0x48,
	0x48, 0x00, 0x05, 0x07, 0x30, 0x48, 0x20, 0x10,
	0x48, 0x30, 0x00, 0x06, 0x07, 0x7c, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x00, 0x05, 0x07, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x30, 0x00, 0x06, 0x07, 0x44,
	0x44, 0x44, 0x44, 0x28, 0x10, 0x00, 0x06, 0x07,
	0x44, 0x44, 0x44, 0x54, 0x54, 0x28, 0x00, 0x06,
	0x07, 0x44, 0x28, 0x10, 0x10, 0x28, 0x44, 0x00,
	0x06, 0x07, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10,
	0x00, 0x05, 0x07, 0x78, 0x08, 0x10, 0x20, 0x40,
	0x78, 0x00, 0x03, 0x07, 0x60, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x60, 0x05, 0x07, 0x40, 0x20, 0x20,
	0x10, 0x10, 0x08, 0x00, 0x03, 0x07, 0x60, 0x20,
	0x20, 0x20, 0x20, 0x20, 0x60, 0x04, 0x07, 0x20,
	0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x03,
	0x07, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x05, 0x07, 0x00, 0x30, 0x08, 0x38, 0x48, 0x38,
	0x00, 0x05, 0x07, 0x40, 0x40, 0x70, 0x48, 0x48,
	0x70, 0x00, 0x05, 0x07, 0x00, 0x30, 0x48, 0x40,
	0x48, 0x30, 0x00, 0x05, 0x07, 0x08, 0x08, 0x38,
	0x48, 0x48, 0x38, 0x00, 0x05, 0x07, 0x00, 0x30,
	0x48, 0x78, 0x40, 0x38, 0x00, 0x05, 0x07, 0x18,
	0x20, 0x70, 0x20, 0x20, 0x20, 0x00, 0x05, 0x07,
	0x00, 0x30, 0x48, 0x48, 0x38, 0x48, 0x30, 0x05,
	0x07, 0x40, 0x40, 0x50, 0x68, 0x48, 0x48, 0x00,
	0x02, 0x07, 0x40, 0x00, 0x40, 0x40, 0x40, 0x40,
	0x00, 0x04, 0x07, 0x10, 0x00, 0x10, 0x10, 0x10,
	0x10, 0x60, 0x04, 0x07, 0x40, 0x50, 0x50, 0x60,
	0x50, 0x50, 0x00, 0x02, 0x07, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x40, 0x00, 0x06, 0x07, 0x00, 0x68,
	0x54, 0x54, 0x54, 0x54, 0x00, 0x05, 0x07, 0x00,
	0x50, 0x68, 0x48, 0x48, 0x48, 0x00, 0x05, 0x07,
	0x00, 0x30, 0x48, 0x48, 0x48, 0x30, 0x00, 0x05,
	0x07, 0x00, 0x70, 0x48, 0x48, 0x70, 0x40, 0x40,
	0x05, 0x07, 0x00, 0x30, 0x48, 0x48, 0x38, 0x08,
	0x08, 0x05, 0x07, 0x00, 0x58, 0x60, 0x40, 0x40,
	0x40, 0x00, 0x05, 0x07, 0x00, 0x38, 0x40, 0x30,
	0x08, 0x70, 0x00, 0x04, 0x07, 0x20, 0x70, 0x20,
	0x20, 0x20, 0x20, 0x00, 0x05, 0x07, 0x00, 0x48,
	0x48, 0x48, 0x48, 0x38, 0x00, 0x06, 0x07, 0x00,
	0x44, 0x44, 0x44, 0x28, 0x10, 0x00, 0x06, 0x07,
	0x00, 0x54, 0x54, 0x54, 0x54, 0x28, 0x00, 0x05,
	0x07, 0x00, 0x48, 0x48, 0x30, 0x48, 0x48, 0x00,
	0x05, 0x07, 0x00, 0x48, 0x48, 0x48, 0x38, 0x08,
	0x70, 0x05, 0x08, 0x00, 0x78, 0x08, 0x30, 0x40,
	0x78, 0x00, 0x00, 0x04, 0x07, 0x10, 0x20, 0x20,
	0x40, 0x20, 0x20, 0x10, 0x03, 0x07, 0x40, 0x40,
	0x40, 0x00, 0x40, 0x40, 0x40, 0x04, 0x07, 0x40,
	0x20, 0x20, 0x10, 0x20, 0x20, 0x40, 0x05, 0x07,
	0x28, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
	0x01, 0x40
};
#endif

GfxFontFromResource::GfxFontFromResource(ResourceManager *resMan, GfxScreen *screen, GuiResourceId resourceId)
	: _resourceId(resourceId), _screen(screen), _resMan(resMan) {
	if (getSciVersion() < SCI_VERSION_2) {
		assert(resourceId != -1);
	}

#ifdef ENABLE_SCI32
	if (getSciVersion() >= SCI_VERSION_2 && resourceId == kSci32SystemFont) {
		_resource = nullptr;
		_resourceData = SciSpan<const byte>(sci32SystemFont, sizeof(sci32SystemFont), "system font");
	} else {
#endif
		// Workaround: lsl1sci mixes its own internal fonts with the global
		// SCI ones, so we translate them here, by removing their extra bits
		if (!resMan->testResource(ResourceId(kResourceTypeFont, resourceId)))
			resourceId = resourceId & 0x7ff;

		_resource = resMan->findResource(ResourceId(kResourceTypeFont, resourceId), true);
		if (!_resource) {
			error("font resource %d not found", resourceId);
		}
		_resourceData = *_resource;
#ifdef ENABLE_SCI32
	}
#endif

	if (_resource) {
		_numChars = _resourceData.getUint16SE32At(2);
		_fontHeight = _resourceData.getUint16SE32At(4);
	} else {
		_numChars = _resourceData.getUint16LEAt(2);
		_fontHeight = _resourceData.getUint16LEAt(4);
	}
	_chars = new Charinfo[_numChars];
	// filling info for every char
	for (int16 i = 0; i < _numChars; i++) {
		uint32 charOffsetIndex = 6 + i * 2;
		if (_resource) {
			_chars[i].offset = _resourceData.getUint16SE32At(charOffsetIndex);
		} else {
			_chars[i].offset = _resourceData.getUint16LEAt(charOffsetIndex);
		}
		_chars[i].width = _resourceData.getUint8At(_chars[i].offset);
		_chars[i].height = _resourceData.getUint8At(_chars[i].offset + 1);
	}
}

GfxFontFromResource::~GfxFontFromResource() {
	delete[] _chars;
	if (_resource) {
		_resMan->unlockResource(_resource);
	}
}

GuiResourceId GfxFontFromResource::getResourceId() {
	return _resourceId;
}

uint8 GfxFontFromResource::getHeight() {
	return _fontHeight;
}

uint8 GfxFontFromResource::getCharWidth(uint16 chr) {
	return chr < _numChars ? _chars[chr].width : 0;
}

uint8 GfxFontFromResource::getCharHeight(uint16 chr) {
	return chr < _numChars ? _chars[chr].height : 0;
}

SciSpan<const byte> GfxFontFromResource::getCharData(uint16 chr) {
	if (chr >= _numChars) {
		return SciSpan<const byte>();
	}

	const uint32 size = (chr + 1 >= _numChars ? _resourceData.size() : _chars[chr + 1].offset) - _chars[chr].offset - 2;
	return _resourceData.subspan(_chars[chr].offset + 2, size);
}

void GfxFontFromResource::draw(uint16 chr, int16 top, int16 left, byte color, bool greyedOutput) {
	if (chr >= _numChars) {
		// SSCI silently ignores attempts to draw characters that do not exist
		// in the font; for now, emit warnings if this happens, to learn if
		// it leads to any bugs
		warning("%s is missing glyph %d", _resource->name().c_str(), chr);
		return;
	}

	// Make sure we're comparing against the correct dimensions
	// If the font we're drawing is already upscaled, make sure we use the full screen width/height
	uint16 screenWidth = _screen->fontIsUpscaled() ? _screen->getDisplayWidth() : _screen->getWidth();
	uint16 screenHeight = _screen->fontIsUpscaled() ? _screen->getDisplayHeight() : _screen->getHeight();

	int charWidth = MIN<int>(getCharWidth(chr), screenWidth - left);
	int charHeight = MIN<int>(getCharHeight(chr), screenHeight - top);
	byte b = 0, mask = 0xFF;
	int y = 0;
	int16 greyedTop = top;

	SciSpan<const byte> charData = getCharData(chr);
	for (int i = 0; i < charHeight; i++, y++) {
		if (greyedOutput)
			mask = ((greyedTop++) % 2) ? 0xAA : 0x55;
		for (int done = 0; done < charWidth; done++) {
			if ((done & 7) == 0) // fetching next data byte
				b = *(charData++) & mask;
			if (b & 0x80) // if MSB is set - paint it
				_screen->putFontPixel(top, left + done, y, color);
			b = b << 1;
		}
	}
}

#ifdef ENABLE_SCI32
void GfxFontFromResource::drawToBuffer(uint16 chr, int16 top, int16 left, byte color, bool greyedOutput, byte *buffer, int16 bufWidth, int16 bufHeight) {
	if (chr >= _numChars) {
		// SSCI silently ignores attempts to draw characters that do not exist
		// in the font; for now, emit warnings if this happens, to learn if
		// it leads to any bugs
		warning("%s is missing glyph %d", _resource->name().c_str(), chr);
		return;
	}

	int charWidth = MIN<int>(getCharWidth(chr), bufWidth - left);
	int charHeight = MIN<int>(getCharHeight(chr), bufHeight - top);
	byte b = 0, mask = 0xFF;
	int y = 0;
	int16 greyedTop = top;

	SciSpan<const byte> charData = getCharData(chr);
	for (int i = 0; i < charHeight; i++, y++) {
		if (greyedOutput)
			mask = ((greyedTop++) % 2) ? 0xAA : 0x55;
		for (int done = 0; done < charWidth; done++) {
			if ((done & 7) == 0) // fetching next data byte
				b = *(charData++) & mask;
			if (b & 0x80) {	// if MSB is set - paint it
				int offset = (top + y) * bufWidth + (left + done);
				buffer[offset] = color;
			}
			b = b << 1;
		}
	}
}
#endif

} // End of namespace Sci