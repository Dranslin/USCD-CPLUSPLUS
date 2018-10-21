/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/20/2018
 * C2A4E2_StorageMap5D.h
 * Win 10
 * Visual C++ 2017
 *
 * Provides storage map equation for any 5D array that is type independent.
 */

#ifndef C2A4E2_STORAGEMAP5D_H
#define C2A4E2_STORAGEMAP5D_H

//#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4) (*((ptr) + (idx0) * (dim1) * (dim2) * (dim3) * (dim4) + (idx1) * (dim2) * (dim3) * (dim4) + (idx2) * (dim3) * (dim4) + (idx3) * (dim4) + (idx4)))

#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4) (\
*((ptr) + (idx0) * (dim1) * (dim2) * (dim3) * (dim4) +\
(idx1) * (dim2) * (dim3) * (dim4) +\
(idx2) * (dim3) * (dim4) + (idx3) * (dim4) +\
(idx4))

#endif // !C2A4E2_STORAGEMAP5D_H
