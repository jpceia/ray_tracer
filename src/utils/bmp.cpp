/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:03:41 by jpceia            #+#    #+#             */
/*   Updated: 2022/02/12 11:55:03 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "miniRT.hpp"

// creates an BMP file with W x H dimensions, from a given array of pixels
void create_bmp(const std::string& fname, int width, int height, vec3f* pixels)
{
	// open file
	std::ofstream file;
	file.open(fname.c_str(), std::ios::out | std::ios::binary);
	if (!file.is_open())
		throw std::runtime_error("Could not open file: " + fname);
	// write header
	unsigned char header[54] = {
		'B', 'M', // magic
		0, 0, 0, 0, // size in bytes
		0, 0, // app data
		0, 0, // app data
		54, 0, 0, 0, // start of data - 54 bytes from start
		40, 0, 0, 0, // struct - 40 bytes
		0, 0, 0, 0, // width in pixels
		0, 0, 0, 0, // height in pixels
		1, 0, // number of planes
		24, 0, // bits per pixel
		0, 0, 0, 0, // compression is none
		0, 0, 0, 0, // image bits size
		0, 0, 0, 0, // horz resolution in pixels / m
		0, 0, 0, 0, // vert resolution in pixels / m
		0, 0, 0, 0, // #colors in palette
		0, 0, 0, 0 // #important colors
	};

	// fill in data
	int size = width * height * 3;
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[18] = (unsigned char)(width);
	header[19] = (unsigned char)(width >> 8);
	header[20] = (unsigned char)(width >> 16);
	header[21] = (unsigned char)(width >> 24);
	header[22] = (unsigned char)(height);
	header[23] = (unsigned char)(height >> 8);
	header[24] = (unsigned char)(height >> 16);
	header[25] = (unsigned char)(height >> 24);

	// write header
	file.write((char*)header, 54);

	// write pixels
	unsigned char data[3];
	for (int i = 0; i < width * height; i++)
	{
		vec3f pixel = pixels[i];
		data[0] = 255 * std::min(pixel[2], 1.0f);
		data[1] = 255 * std::min(pixel[1], 1.0f);
		data[2] = 255 * std::min(pixel[0], 1.0f);
		file.write((char*)data, 3);
	}

	// close file
	file.close();
}
