#include "pch.h"
#include "PuzzleBlock.h"

namespace SlidingPuzzleSpace
{
	int PuzzleBlock::m_NextID = 0;

	PuzzleBlock::PuzzleBlock()
		: m_ID(m_NextID++)
	{
	}
}
