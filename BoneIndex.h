Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id)
{
    uintptr_t ABoneArray = Driver::read<uintptr_t>(processID, mesh + 0x5f0);
    if (!ABoneArray) ABoneArray = Driver::read<uintptr_t>(processID, mesh + 0x5f0 + 0x10);

    FTransform ComponentToWorld = Driver::read<FTransform>(processID, mesh + 0x240);

    FTransform bone = Driver::read<FTransform>(processID, ABoneArray + (id * 0x60));

    D3DMATRIX Matrix;
    Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

    return Vector3(Matrix._41, Matrix._42, Matrix._43);
}
