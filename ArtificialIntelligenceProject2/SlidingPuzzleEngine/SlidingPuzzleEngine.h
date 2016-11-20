// SlidingPuzzleEngine.h
//

#pragma once

#ifdef SLIDINGPUZZLEENGINE_EXPORTS
#define SLIDINGPUZZLE_API __declspec(dllexport)	// DLL로 함수를 내보냅니다.
#else
#define SLIDINGPUZZLE_API __declspec(dllimport)	// 응용 프로그램에서 함수의 가져오기를 최적화합니다.
#endif
