#include "pch.h"
#include "SlidingPuzzle.h"

namespace SlidingPuzzleSpace
{
	SlidingPuzzle::SlidingPuzzle(int height, int width)
		:m_Height(height), m_Width(width)
	{
		int size = height * width;
		m_BlockRepo = new PuzzleBlock[size];
		m_BlockArr = new PuzzleBlockPtr[size];
		m_Blocks = new PuzzleBlockPtr*[size];
		m_GoalArr = new PuzzleBlockPtr[size];
		m_Goal = new PuzzleBlockPtr*[size];

		for (int i = 0; i < height; i++) {
			m_Blocks[i] = &m_BlockArr[i * width];
			m_Goal[i] = &m_GoalArr[i * width];
		}

		initPuzzle();
		initGoal();
	}

	SlidingPuzzle::~SlidingPuzzle()
	{
		if (m_Blocks) {
			delete[] m_Blocks;
		}
		if (m_BlockArr) {
			delete[] m_BlockArr;
		}
		if (m_Goal) {
			delete[] m_Goal;
		}
		if (m_GoalArr) {
			delete[] m_GoalArr;
		}
		if (m_BlockRepo) {
			delete[] m_BlockRepo;
		}
	}

	void SlidingPuzzle::initPuzzle()
	{
		for (int i = 0; i < getSize(); i++) {
			m_BlockArr[i] = &m_BlockRepo[i];
		}
	}

	void SlidingPuzzle::initPuzzle(int* idArr)
	{
		for (int i = 0; i < getSize(); i++) {
			m_BlockArr[i] = &m_BlockRepo[idArr[i]];
		}
	}

	void SlidingPuzzle::initGoal()
	{
		for (int i = 0; i < getSize(); i++) {
			m_GoalArr[i] = &m_BlockRepo[i];
		}
	}

	void SlidingPuzzle::initGoal(int* idArr)
	{
		for (int i = 0; i < getSize(); i++) {
			m_GoalArr[i] = &m_BlockRepo[idArr[i]];
		}
	}

	bool SlidingPuzzle::moveBlock(int x, int y, Direction dir)
	{
		int dx = x, dy = y;
		switch (dir) {
		case Direction::UP:
			if (y <= 0) {
				return false;
			}
			dy--;
			break;
		case Direction::LEFT:
			if (x <= 0) {
				return false;
			}
			dx--;
			break;
		case Direction::RIGHT:
			if (x >= m_Width - 1) {
				return false;
			}
			dx++;
			break;
		case Direction::DOWN:
			if (y >= m_Height - 1) {
				return false;
			}
			dy++;
			break;
		case Direction::NODIR:
			return false;
		}

		PuzzleBlockPtr src = m_Blocks[y][x];
		PuzzleBlockPtr dst = m_Blocks[dy][dx];

		if (src->getID() == BLANK_BLOCK_ID
				|| dst->getID() == BLANK_BLOCK_ID) {
			PuzzleBlockPtr tmp = src;
			src = dst;
			dst = tmp;
			return true;
		}
		return false;
	}

	bool SlidingPuzzle::isSolved()
	{
		for (int i = 0; i < getSize(); i++) {
			if (m_BlockArr[i] != m_GoalArr[i]) {
				return false;
			}
		}
		return true;
	}

	int SlidingPuzzle::getSize()
	{
		return m_Width * m_Height;
	}
}
