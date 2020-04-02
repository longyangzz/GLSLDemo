#pragma once
#include <vector>

class Loader {
public:

	class RawModel* loadToVao(float positions[], int posSize, unsigned int indexData[], int indexSize);

	void cleanUp();

private:
	unsigned int createVao();

	void unbindVao();

	void bindIndexBuffer(unsigned int indexBuffer[], int size);

	void storeDatatoAttriList(int idx, float positions[], int size);

private:
	std::vector<class RawModel*> models;
	std::vector<unsigned int> vaos;
	std::vector<unsigned int> vbos;
};