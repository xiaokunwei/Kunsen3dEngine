

#include "..\Include\Math\Matrixd.h"
#include "..\Include\Math\Matrixf.h"

// specialise Matrix_implementaiton to be Matrixf
#define  Matrix_implementation Matrixf

KunSen::Matrixf::Matrixf(const KunSen::Matrixd& mat)
{
    set(mat.ptr());
}

KunSen::Matrixf& KunSen::Matrixf::operator = (const KunSen::Matrixd& rhs)
{
    set(rhs.ptr());
    return *this;
}

void KunSen::Matrixf::set(const KunSen::Matrixd& rhs)
{
    set(rhs.ptr());
}

// now compile up Matrix via Matrix_implementation
#include "Matrix_implementation.cpp"
