#pragma once
/******************************************************
* File: dllmain.cpp
* Date: 2020/09/21
* Author: Zaijun Hao
* Purpose: Use in Matlab to parse binary data saved by VR application
* Reference: https://ww2.mathworks.cn/help/matlab/ref/loadlibrary.html
*******************************************************/

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#define DLLFUNEXP __cdecl
#else 
#define DLLEXPORT __attribute__((visibility("default")))
#define DLLFUNEXP 
#endif

#define MAX_LINE_LENGTH 1000
#ifdef __cplusplus
extern "C" {
#endif
DLLEXPORT int DLLFUNEXP vrEegToBrainVision(const char* inFile, const char* outFile);
DLLEXPORT int DLLFUNEXP vrMarkerToBrainVision(const char* inFile, const char* outFile);
DLLEXPORT int DLLFUNEXP vrEegWriteBrainVisionHeader(const char* outFile);
DLLEXPORT int DLLFUNEXP vrEegConvertAllInFolder(const char* inDir, const char* outDir);
DLLEXPORT int DLLFUNEXP vrReadAllEegData(const char* inFile, float** data, unsigned int* size);

DLLEXPORT float* DLLFUNEXP vrEmgReadToArray(const char* inFile, int* size);
#ifdef __cplusplus
}
#endif