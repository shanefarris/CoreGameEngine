#include "EigenSolver.h"

using namespace Ode;
using namespace Ogre;

void EigenSolver::DecrSortEigenStuff3 ()
{
	Tridiagonal3();
	QLAlgorithm();
	DecreasingSort();
	GuaranteeRotation();
}

void EigenSolver::Tridiagonal3 ()
{
	const float fM00 = m_kMat[0][0];
    float fM01 = m_kMat[0][1];
	Real fM02 = m_kMat[0][2];
	const float fM11 = m_kMat[1][1];
	const float fM12 = m_kMat[1][2];
	const float fM22 = m_kMat[2][2];

	m_afDiag[0] = fM00;
	m_afSubd[2] = (Real)0.0;
	if ( fM02 != (Real)0.0 )
	{
		const float fLength = sqrtf(fM01*fM01+fM02*fM02);
		const float fInvLength = ((Real)1.0)/fLength;
		fM01 *= fInvLength;
		fM02 *= fInvLength;
		const float fQ = ((Real)2.0)*fM01*fM12+fM02*(fM22-fM11);
		m_afDiag[1] = fM11+fM02*fQ;
		m_afDiag[2] = fM22-fM02*fQ;
		m_afSubd[0] = fLength;
		m_afSubd[1] = fM12-fM01*fQ;
		m_kMat[0][0] = (Real)1.0;
		m_kMat[0][1] = (Real)0.0;
		m_kMat[0][2] = (Real)0.0;
		m_kMat[1][0] = (Real)0.0;
		m_kMat[1][1] = fM01;
		m_kMat[1][2] = fM02;
		m_kMat[2][0] = (Real)0.0;
		m_kMat[2][1] = fM02;
		m_kMat[2][2] = -fM01;
	}
	else
	{
		m_afDiag[1] = fM11;
		m_afDiag[2] = fM22;
		m_afSubd[0] = fM01;
		m_afSubd[1] = fM12;
		m_kMat[0][0] = (Real)1.0;
		m_kMat[0][1] = (Real)0.0;
		m_kMat[0][2] = (Real)0.0;
		m_kMat[1][0] = (Real)0.0;
		m_kMat[1][1] = (Real)1.0;
		m_kMat[1][2] = (Real)0.0;
		m_kMat[2][0] = (Real)0.0;
		m_kMat[2][1] = (Real)0.0;
		m_kMat[2][2] = (Real)1.0;
	}
}

bool EigenSolver::QLAlgorithm ()
{
	const int iMaxIter = 32;

	for (int i0 = 0; i0 < m_iSize; i0++)
	{
		int i1;
		for (i1 = 0; i1 < iMaxIter; i1++)
		{
			int i2;
			for (i2 = i0; i2 <= m_iSize-2; i2++)
			{
				Real fTmp = fabs(m_afDiag[i2]) + fabs(m_afDiag[i2+1]);
				if ( fabs(m_afSubd[i2]) + fTmp == fTmp ) break;
			}
			if ( i2 == i0 ) break;

			Real fG = (m_afDiag[i0+1] - m_afDiag[i0])/(((Real)2.0) * m_afSubd[i0]);
			Real fR = sqrtf(fG*fG+(Real)1.0);
			if ( fG < (Real)0.0 ) fG = m_afDiag[i2]-m_afDiag[i0]+m_afSubd[i0]/(fG-fR);
			else fG = m_afDiag[i2]-m_afDiag[i0]+m_afSubd[i0]/(fG+fR);
			Real fSin = (Real)1.0, fCos = (Real)1.0, fP = (Real)0.0;
			for (int i3 = i2-1; i3 >= i0; i3--)
			{
				Real fF = fSin*m_afSubd[i3];
               float fB = fCos*m_afSubd[i3];
	            if ( fabs(fF) >= fabs(fG) )
		        {
			        fCos = fG/fF;
				    fR = sqrtf(fCos*fCos+(Real)1.0);
					m_afSubd[i3+1] = fF*fR;
                    fSin = ((Real)1.0)/fR;
	                fCos *= fSin;
		        }
			    else
				{
					fSin = fF/fG;
					fR = sqrtf(fSin*fSin+(Real)1.0);
					m_afSubd[i3+1] = fG*fR;
					fCos = ((Real)1.0)/fR;
					fSin *= fCos;
				}
				fG = m_afDiag[i3+1]-fP;
                fR = (m_afDiag[i3]-fG)*fSin+((Real)2.0)*fB*fCos;
	            fP = fSin*fR;
		        m_afDiag[i3+1] = fG+fP;
			    fG = fCos*fR-fB;

				for (int i4 = 0; i4 < m_iSize; i4++)
				{
					fF = m_kMat[i4][i3+1];
                    m_kMat[i4][i3+1] = fSin*m_kMat[i4][i3]+fCos*fF;
	                m_kMat[i4][i3] = fCos*m_kMat[i4][i3]-fSin*fF;
		        }
			}
			m_afDiag[i0] -= fP;
			m_afSubd[i0] = fG;
			m_afSubd[i2] = (Real)0.0;
		}
		if ( i1 == iMaxIter ) return false;
	}
	return true;
}

void EigenSolver::DecreasingSort ()
{
	// sort eigenvalues in decreasing order, e[0] >= ... >= e[iSize-1]
	for (int i0 = 0, i1; i0 <= m_iSize-2; i0++)
	{
		// locate maximum eigenvalue
		i1 = i0;
		Real fMax = m_afDiag[i1];
		int i2;
		for (i2 = i0+1; i2 < m_iSize; i2++)
		{
			if ( m_afDiag[i2] > fMax )
			{
				i1 = i2;
				fMax = m_afDiag[i1];
			}
		}

		if ( i1 != i0 )
		{
			// swap eigenvalues
			m_afDiag[i1] = m_afDiag[i0];
			m_afDiag[i0] = fMax;

			// swap eigenvectors
			for (i2 = 0; i2 < m_iSize; i2++)
			{
				Real fTmp = m_kMat[i2][i0];
				m_kMat[i2][i0] = m_kMat[i2][i1];
				m_kMat[i2][i1] = fTmp;
				m_bIsRotation = !m_bIsRotation;
			}
		}
	}
}

void EigenSolver::GuaranteeRotation ()
{
	if ( !m_bIsRotation )
	{
		// change sign on the first column
		for (int iRow = 0; iRow < m_iSize; iRow++) 
            m_kMat[iRow][0] = -m_kMat[iRow][0];
	}
}

void EigenSolver::orthogonalLineFit(unsigned int vertex_count, const Vector3* vertices,Vector3& origin,Vector3& direction)
{
	unsigned int i;

    // compute average of points
	origin = vertices[0];
    for(i = 1; i < vertex_count; ++i) 
        origin += vertices[i];

	const float fInvQuantity = 1.0f / vertex_count;
	origin *= fInvQuantity;

	// compute sums of products
	Real fSumXX = 0.0, fSumXY = 0.0, fSumXZ = 0.0;
   float fSumYY = 0.0, fSumYZ = 0.0, fSumZZ = 0.0;
	for (i = 0; i < vertex_count; i++) 
	{
		const Vector3 kDiff (vertices[i] - origin);
	    fSumXX += kDiff.x*kDiff.x;
        fSumXY += kDiff.x*kDiff.y;
		fSumXZ += kDiff.x*kDiff.z;
	    fSumYY += kDiff.y*kDiff.y;
        fSumYZ += kDiff.y*kDiff.z;
		fSumZZ += kDiff.z*kDiff.z;
	}
	fSumXX *= fInvQuantity;
	fSumXY *= fInvQuantity;
	fSumXZ *= fInvQuantity;
	fSumYY *= fInvQuantity;
	fSumYZ *= fInvQuantity;
	fSumZZ *= fInvQuantity;

	// setup the eigensolver
	EigenSolver kES(3);
	kES(0,0) = fSumYY+fSumZZ;
	kES(0,1) = -fSumXY;
	kES(0,2) = -fSumXZ;
	kES(1,0) = kES(0,1);
	kES(1,1) = fSumXX+fSumZZ;
	kES(1,2) = -fSumYZ;
	kES(2,0) = kES(0,2);
	kES(2,1) = kES(1,2);
    kES(2,2) = fSumXX+fSumYY;

	// compute eigenstuff, smallest eigenvalue is in last position
	kES.DecrSortEigenStuff3();

    // unit-length direction for best-fit line
	kES.GetEigenvector(2,direction);
}

Real EigenSolver::SqrDistance(const Vector3& rkPoint,const Vector3& origin,const Vector3& direction)
{
	Vector3 kDiff(rkPoint - origin);
    const float fSqrLen = direction.squaredLength();
	const float fT = kDiff.dotProduct(direction) / fSqrLen;

    kDiff -= fT*direction;

	return kDiff.squaredLength();
}

void EigenSolver::GenerateOrthonormalBasis (Vector3& rkU, Vector3& rkV, Vector3& rkW, bool bUnitLengthW)
{
	if ( !bUnitLengthW ) rkW.normalise();

	Real fInvLength;

	if ( fabs(rkW[0]) >= fabs(rkW[1]) )
	{
		// W.x or W.z is the largest magnitude component, swap them
		fInvLength = 1.0f / sqrtf(rkW[0]*rkW[0] + rkW[2]*rkW[2]);

	    rkU[0] = -rkW[2]*fInvLength;
        rkU[1] = (Real)0.0;
		rkU[2] = +rkW[0]*fInvLength;
	}
    else
	{
        // W.y or W.z is the largest magnitude component, swap them
		fInvLength = 1.0f / sqrtf(rkW[1]*rkW[1] + rkW[2]*rkW[2]);

	    rkU[0] = (Real)0.0;
        rkU[1] = +rkW[2]*fInvLength;
		rkU[2] = -rkW[1]*fInvLength;
	}

	rkV = rkW.crossProduct(rkU);
}

EigenSolver::EigenSolver(int iSize)
{
	assert( iSize >= 2 );
    m_iSize = iSize;
	m_afDiag = new float[m_iSize];
    m_afSubd = new float[m_iSize];

	// set according to the parity of the number of Householder reflections
	m_bIsRotation = ((iSize % 2) == 0);
}

float& EigenSolver::operator() (int iRow, int iCol)
{
	return m_kMat[iRow][iCol];
}

EigenSolver::~EigenSolver()
{
    delete[] m_afSubd;
	delete[] m_afDiag;
}

void EigenSolver::GetEigenvector (int i, Vector3& rkV) const
{
	assert( m_iSize == 3 );
	if ( m_iSize == 3 )
	{
		for (int iRow = 0; iRow < m_iSize; iRow++) 
            rkV[iRow] = m_kMat[iRow][i];
	}
	else
	{
	    rkV = Vector3::ZERO;
    }
}

void EigenSolver::GaussPointsFit(unsigned int iQuantity,const Vector3* akPoint,Vector3 &rkCenter,Vector3 akAxis[3],Real afExtent[3])
{
    // compute mean of points
    rkCenter = akPoint[0];
    unsigned int i;
    for (i = 1; i < iQuantity; i++)
        rkCenter += akPoint[i];
    const float fInvQuantity = ((Real)1.0)/iQuantity;
    rkCenter *= fInvQuantity;

    // compute covariances of points
   float fSumXX = (Real)0.0, fSumXY = (Real)0.0, fSumXZ = (Real)0.0;
   float fSumYY = (Real)0.0, fSumYZ = (Real)0.0, fSumZZ = (Real)0.0;
    for (i = 0; i < iQuantity; i++)
    {
        const Vector3 kDiff (akPoint[i] - rkCenter);
        fSumXX += kDiff.x*kDiff.x;
        fSumXY += kDiff.x*kDiff.y;
        fSumXZ += kDiff.x*kDiff.z;
        fSumYY += kDiff.y*kDiff.y;
        fSumYZ += kDiff.y*kDiff.z;
        fSumZZ += kDiff.z*kDiff.z;
    }
    fSumXX *= fInvQuantity;
    fSumXY *= fInvQuantity;
    fSumXZ *= fInvQuantity;
    fSumYY *= fInvQuantity;
    fSumYZ *= fInvQuantity;
    fSumZZ *= fInvQuantity;

    // compute eigenvectors for covariance matrix
    EigenSolver kES(3);
    kES(0,0) = fSumXX;
    kES(0,1) = fSumXY;
    kES(0,2) = fSumXZ;
    kES(1,0) = fSumXY;
    kES(1,1) = fSumYY;
    kES(1,2) = fSumYZ;
    kES(2,0) = fSumXZ;
    kES(2,1) = fSumYZ;
    kES(2,2) = fSumZZ;
    kES.IncrSortEigenStuff3();

    for (i = 0; i < 3; i++)
    {
        afExtent[i] = kES.GetEigenvalue(i);
        kES.GetEigenvector(i,akAxis[i]);
    }
}

Real EigenSolver::GetEigenvalue (int i) const
{
    return m_afDiag[i];
}

void EigenSolver::IncrSortEigenStuff3 ()
{
    Tridiagonal3();
    QLAlgorithm();
    IncreasingSort();
    GuaranteeRotation();
}

void EigenSolver::IncreasingSort ()
{
    // sort eigenvalues in increasing order, e[0] <= ... <= e[iSize-1]
    for (int i0 = 0, i1; i0 <= m_iSize-2; i0++)
    {
        // locate minimum eigenvalue
        i1 = i0;
       float fMin = m_afDiag[i1];
        int i2;
        for (i2 = i0+1; i2 < m_iSize; i2++)
        {
            if ( m_afDiag[i2] < fMin )
            {
                i1 = i2;
                fMin = m_afDiag[i1];
            }
        }

        if ( i1 != i0 )
        {
            // swap eigenvalues
            m_afDiag[i1] = m_afDiag[i0];
            m_afDiag[i0] = fMin;

            // swap eigenvectors
            for (i2 = 0; i2 < m_iSize; i2++)
            {
               float fTmp = m_kMat[i2][i0];
                m_kMat[i2][i0] = m_kMat[i2][i1];
                m_kMat[i2][i1] = fTmp;
                m_bIsRotation = !m_bIsRotation;
            }
        }
    }
}
