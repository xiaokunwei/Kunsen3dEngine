

#include "..\Include\Math\Matrixd.h"
#include "..\Include\Math\Matrixf.h"

// specialise Matrix_implementaiton to be Matrixd
#define  Matrix_implementation Matrixd

KunSen::Matrixd::Matrixd(const KunSen::Matrixf& mat)
{
    set(mat.ptr());
}

KunSen::Matrixd& KunSen::Matrixd::operator = (const KunSen::Matrixf& rhs)
{
    set(rhs.ptr());
    return *this;
}

void KunSen::Matrixd::set(const KunSen::Matrixf& rhs)
{
    set(rhs.ptr());
}

// now compile up Matrix via Matrix_implementation
#include "Matrix_implementation.cpp"

