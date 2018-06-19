#pragma once

#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include "lodepng.h"

class	Texture
{
private:

	struct TextureInfo
	{
		std::vector<unsigned char> *data;
		unsigned width;
		unsigned height;
	};

	static std::map<std::string, TextureInfo> _cache;
	std::vector<unsigned char> *_imageData;
	unsigned _width;
	unsigned _height;
	
public:

	//! Only supports png currently
	Texture(std::string filepath);

	unsigned	Width(void);
	unsigned	Height(void);
	unsigned char	*Data(void);
};
