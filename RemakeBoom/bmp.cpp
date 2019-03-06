#include <Windows.h>
#include "bmp.h"
#include "header.h"

void scanBmpPixelLine(FILE *f, Color *&line, uint32_t length)
{
	if (f == NULL)
	{
		return;
	}
	line = new Color[length];
	fread(line, sizeof(Color), length, f);
}

void readBmpHeader(FILE *f, BmpHeader &header)
{
	if (f == NULL)
	{
		return;
	}
	fseek(f, 0, 0L);
	fread(&header, sizeof(BmpHeader), 1, f);
}

void readBmpDib(FILE *f, BmpDib &dib)
{
	if (f == NULL)
	{
		return;
	}
	fseek(f, sizeof(BmpHeader), 0L);
	fread(&dib, sizeof(BmpDib), 1, f);
}

void readBmpPixelArray(FILE *f, BmpHeader header, BmpDib dib, PixelArray &data)
{
	if (f == NULL)
	{
		return;
	}

	data.rowCount = dib.imageHeight;
	data.columnCount = dib.imageWidth;
	data.pixels = new Color*[data.rowCount];

	char paddingCount = (4 - (dib.imageWidth * (dib.pixelSize / 8) % 4)) % 4;

	fseek(f, header.dataOffset, 0L);

	for (int i = 0; i < data.rowCount; i++)
	{
		scanBmpPixelLine(f, data.pixels[data.rowCount - 1 - i], dib.imageWidth);
		skipBmpPadding(f, paddingCount);
	}
}

void skipBmpPadding(FILE *f, char count)
{
	if (f == NULL)
	{
		return;
	}

	if (count == 0)
	{
		return;
	}

	char padding[3];
	fread(padding, count, 1, f);
}

void releaseBmpPixelArray(PixelArray data)
{
	for (uint32_t i = 0; i < data.rowCount; i++)
	{
		delete[]data.pixels[i];
	}

	delete[]data.pixels;
}

void drawBmp(int x, int y, Img img)
{
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);
	Color pixel;

	for (int i = 0; i < img.dib.imageHeight; i++)
	{
		for (int j = 0; j < img.dib.imageWidth; j++)
		{
			pixel = img.data.pixels[i][j];
			if (pixel.red != 195 || pixel.green != 195 || pixel.blue != 195)
			{
				SetPixel(hdc, x + j, y + i, RGB(pixel.red, pixel.green, pixel.blue));
			}
		}
	}

	ReleaseDC(console, hdc);
}

int loadBmp(Img &anh, const char link[])
{
	FILE *f;
	fopen_s(&f, link, "rb");
	readBmpHeader(f, anh.header);
	readBmpDib(f, anh.dib);
	readBmpPixelArray(f, anh.header, anh.dib, anh.data);

	return 1;
}

void drawNumber(int x, int y, int num)
{
	if (num == 0)
	{
		drawBmp(x, y, imgEmpty);
		drawBmp(x, y, imgNumber[0]);
		return;
	}
	while (1)
	{

		if (num % 10 == 0) break;
		drawBmp(x, y, imgEmpty);
		drawBmp(x, y, imgNumber[num % 10]);
		x -= 30;
		num /= 10;
	}
}