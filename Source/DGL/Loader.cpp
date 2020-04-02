#include "Loader.h"
#include "RawModel.h"
#include "glad/glad.h"

RawModel* Loader::loadToVao(float positions[], int posSize, unsigned int indexData[], int indexSize)
{
	unsigned int vaoID = createVao();
	bindIndexBuffer(indexData, indexSize);
	storeDatatoAttriList(0, positions, posSize);
	unbindVao();
	RawModel* tmpModel = new RawModel(vaoID, indexSize / sizeof(int));
	models.push_back(tmpModel);
	return tmpModel;
}

void Loader::cleanUp()
{
	if (models.size() > 0) {
		for (RawModel* item : models) {
			delete item;
		}
	}

	if (vaos.size() > 0) {
		glDeleteVertexArrays(vaos.size(), vaos.data());
	}

	if (vbos.size() > 0) {
		glDeleteBuffers(vbos.size(), vbos.data());
	}
}

unsigned int Loader::createVao()
{
	unsigned int vaoID;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	vaos.push_back(vaoID);
	return vaoID;
}

void Loader::unbindVao()
{
	glBindVertexArray(0);
}

void Loader::bindIndexBuffer(unsigned int indexBuffer[], int size)
{
	unsigned int iboID;
	glGenBuffers(1, &iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indexBuffer, GL_STATIC_DRAW);
	// 不要调用glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0)
}

void Loader::storeDatatoAttriList(int idx, float positions[], int size)
{
	unsigned int vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);
	glVertexAttribPointer(idx, 3, GL_FLOAT, false, 3 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	vbos.push_back(vboID);
}
