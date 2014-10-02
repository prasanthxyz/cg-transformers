#include "loadBmpTexture.hpp"

GLuint loadBmpTexture(const char *fileName, GLuint texture)
{
	FILE *file;
	unsigned char header[54];
	unsigned int size;
	unsigned int width, height;
	unsigned char *data;

	file = fopen(fileName, "rb");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Invaild file path '%s'!", fileName);
		return false;
	}
	fread(header, 1, 54, file);
	if (header[0] != 'B' || header[1] != 'M')
	{
		fprintf(stderr, "Error: Invaild file '%s'!", fileName);
		return false;
	}

	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	size = width * height * 3;
	data = new unsigned char[size];

	fread(data, 1, size, file);
    fclose(file);

    glBindTexture(GL_TEXTURE_2D, texture);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    return texture;
}
