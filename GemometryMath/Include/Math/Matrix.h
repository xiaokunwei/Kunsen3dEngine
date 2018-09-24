

#ifndef KUNSEN_MATRIX
#define KUNSEN_MATRIX 1


#include "Matrixd.h"
#include "Matrixf.h"


namespace KunSen {

#ifdef OSG_USE_FLOAT_MATRIX
    typedef Matrixf Matrix;
    typedef RefMatrixf RefMatrix;
#else
    typedef Matrixd Matrix;
#endif

} //namespace osg


#endif
