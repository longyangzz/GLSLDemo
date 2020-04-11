#include "DisplayManager.h"
#include "Loader.h"
#include "RawModel.h"
#include "Render.h"
#include "StaticShader.h"
#include "MathTools.h"
#include <GLFW\glfw3.h>

int main()
{
	DisplayManager mDisplayMgr;
	mDisplayMgr.createDisplay();

	Loader mLoader;

    // --------------�����嶥������--------------
    //   0/----------------/1
    //   /|               /|
    //  / |              / |
    //4/--|-------------/5 |
    // |  |             |  |
    // |  |             |  |
    // |  |             |  |
    // | 3/-------------|--/2
    // | /              | /
    // |/               |/
    //7/----------------/6

    // test
    float positions[]{
        -0.5f,      0.5f,       -0.5f,
        0.5f,       0.5f,       -0.5f,
        0.5f,       -0.5f,      -0.5f,
        -0.5f,      -0.5f,      -0.5f,
        -0.5f,      0.5f,       0.5f,
        0.5f,       0.5f,       0.5f,
        0.5f,       -0.5f,      0.5f,
        -0.5f,      -0.5f,      0.5f,
    };

    unsigned int indexData[]{
        1, 5, 0, 0, 5, 4,
        0, 4, 3, 3, 4, 7,
        3, 2, 6, 3, 6, 7,
        5, 2, 6, 5, 1, 2,
        4, 5, 6, 4, 6, 7,
        0, 1, 3, 1, 2, 3
    };

	RawModel* mModel = mLoader.loadToVao(positions, sizeof(positions), indexData,sizeof(indexData));

	Render mRender;
	StaticShader mShader;

	while (!mDisplayMgr.isRequestClosed())
	{
		mRender.prepare();

		mShader.start();
        mShader.loadTransformMatrix(GLMath::createTransformMatrix(GLMath::Vector3(), 0, 0, (float)glfwGetTime() * 50, 1));
		mRender.onReder(mModel);
		mShader.stop();

		mDisplayMgr.updateDisplay();
        if (mDisplayMgr.isKeyPressed(GLFW_KEY_R)) {
            mShader.reloadShader();
        }
	}

	mShader.cleanUp();
	mLoader.cleanUp();
	mDisplayMgr.closeDisplay();
	return 0;
}