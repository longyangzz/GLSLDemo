#pragma once
#include "Vector.h"
#include "Matrices.h"

namespace GLMath {
    static Matrix4 createTransformMatrix(const Vector3& translateVector, float rx, float ry, float rz, float scale) {
        // translate rotate scale
        Matrix4 retMatrix;
        retMatrix.translate(translateVector);
        retMatrix.rotateX(rx);
        retMatrix.rotateY(ry);
        retMatrix.rotateZ(rz);
        retMatrix.scale(scale);
        return retMatrix;
    }
}