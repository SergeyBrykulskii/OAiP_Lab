#pragma once

#ifdef DINAMICLIB_EXPORTS
#define DINAMICLIB_API __declspec(dllexport)
#else
#define DINAMICLIB_API __declspec(dllimport)
#endif

#include <iostream>
#include <vector>

extern "C" DINAMICLIB_API int FindMinimun(const std::vector<int>& v, const int& start_position, const int& size);

extern "C" DINAMICLIB_API int GetIntegerNumber();

extern "C" DINAMICLIB_API int GetNaturalNumber();

extern "C" DINAMICLIB_API double GetRealNumber();