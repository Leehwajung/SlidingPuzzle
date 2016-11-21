#pragma once
namespace {
#include "SlidingPuzzleEngine.h"
}

class PuzzleBlock sealed
{
	/* Constructor */
public :
	SLIDINGPUZZLE_API PuzzleBlock();

	/* Accessor */
	SLIDINGPUZZLE_API int getID();

	/* Attribute */
private:
	int m_ID;

	/* Support */
	static int m_NextID;
};

inline int PuzzleBlock::getID()
{
	return m_ID;
}
