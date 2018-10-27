/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/20/2018
 * C2A4E3_pointerArray4D.cpp
 * Win 10
 * Visual C++ 2017
 *
 * Creates a 4d pointer array of size array[2][3][4][5]
 */

extern const int DIM0 = 2;
extern const int DIM1 = 3;
extern const int DIM2 = 4;
extern const int DIM3 = 5;
extern float ***pointerArray4D[];

// float lv 4 - 4 of 5 - [2][3][4][5] - [a,b][a,b,c][x] -> [a,b][a,b,c][a,b,c,d][x]
static float lv4aaa[DIM3], lv4aab[DIM3], lv4aac[DIM3], lv4aad[DIM3]; // lv 4 - Final [a][a][x]
static float lv4aba[DIM3], lv4abb[DIM3], lv4abc[DIM3], lv4abd[DIM3]; // lv 4 - Final [a][b][x]
static float lv4aca[DIM3], lv4acb[DIM3], lv4acc[DIM3], lv4acd[DIM3]; // lv 4 - Final [a][c][x]

static float lv4baa[DIM3], lv4bab[DIM3], lv4bac[DIM3], lv4bad[DIM3]; // lv 4 - Final [b][a][x]
static float lv4bba[DIM3], lv4bbb[DIM3], lv4bbc[DIM3], lv4bbd[DIM3]; // lv 4 - Final [b][b][x]
static float lv4bca[DIM3], lv4bcb[DIM3], lv4bcc[DIM3], lv4bcd[DIM3]; // lv 4 - Final [b][c][x]

// static float *lv 3 - 3 of 4 - [2][3][4] - [a,b][x] -> [a,b][a,b,c][x]
static float *lv3aa[DIM2] = {lv4aaa, lv4aab, lv4aac, lv4aad}; // lv 3 - Row [a][a][x]
static float *lv3ab[DIM2] = {lv4aba, lv4abb, lv4abc, lv4abd}; // lv 3 - Row [a][b][x]
static float *lv3ac[DIM2] = {lv4aca, lv4acb, lv4acc, lv4acd}; // lv 3 - Row [a][c][x]

static float *lv3ba[DIM2] = {lv4baa, lv4bab, lv4bac, lv4bad}; // lv 3 - Row [b][a][x]
static float *lv3bb[DIM2] = {lv4bba, lv4bbb, lv4bbc, lv4bbd}; // lv 3 - Row [b][b][x]
static float *lv3bc[DIM2] = {lv4bca, lv4bcb, lv4bcc, lv4bcd}; // lv 3 - Row [b][c][x]

// static float **lv 2 - 2 of 3 - [x] -> [a,b][x]
static float **lv2a[DIM1] = {lv3aa, lv3ab, lv3ac}; // lv 2 - Row a - [a][x]
static float **lv2b[DIM1] = {lv3ba, lv3bb, lv3bc}; // lv 2 - Row b - [b][x]

// Base layer
// float ***lv1 - 1 of 2 - x -> [x]
float ***pointerArray4D[DIM0] = {lv2a, lv2b};
