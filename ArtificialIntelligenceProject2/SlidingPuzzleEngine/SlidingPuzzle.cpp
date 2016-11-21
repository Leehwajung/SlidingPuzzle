#include "pch.h"
#include "SlidingPuzzle.h"

namespace SlidingPuzzleSpace {
	SlidingPuzzle::SlidingPuzzle(int height, int width)
		:m_Height(height), m_Width(width)
	{
		int size = height * width;
		m_BlockRepo = new PuzzleBlock[size];
		m_Blocks = new PuzzleBlock*[size];
		m_Goal = new PuzzleBlock*[size];

		initPuzzle();
		initGoal();
	}

	SlidingPuzzle::~SlidingPuzzle()
	{
		if (m_Blocks) {
			delete[] m_Blocks;
		}
		if (m_Goal) {
			delete[] m_Blocks;
		}
		if (m_BlockRepo) {
			delete[] m_BlockRepo;
		}
	}

	void SlidingPuzzle::initPuzzle()
	{
		for (int i = 0; i < getSize(); i++) {
			m_Blocks[i] = &m_BlockRepo[i];
		}
	}

	void SlidingPuzzle::initPuzzle(int* idArr)
	{
		for (int i = 0; i < getSize(); i++) {
			m_Blocks[i] = &m_BlockRepo[idArr[i]];
		}
	}

	void SlidingPuzzle::initGoal()
	{
		for (int i = 0; i < getSize(); i++) {
			m_Goal[i] = &m_BlockRepo[i];
		}
	}

	void SlidingPuzzle::initGoal(int* idArr)
	{
		for (int i = 0; i < getSize(); i++) {
			m_Goal[i] = &m_BlockRepo[idArr[i]];
		}
	}

	void SlidingPuzzle::moveBlock(int x, int y, Direction dir)
	{
		int dx = x, dy = y;
		switch (dir) {
		case UP:
			if (y <= 0) {
				return;
			}
			dy--;
			break;
		case LEFT:
			if (x <= 0) {
				return;
			}
			dx--;
			break;
		case RIGHT:
			if (x >= m_Width - 1) {
				return;
			}
			dx++;
			break;
		case DOWN:
			if (y >= m_Height - 1) {
				return;
			}
			dy++;
			break;
		case NODIR:
			return;
		}

		int src = y * m_Width + x;
		int dst = dy * m_Width + dx;
		PuzzleBlock *tmp = m_Blocks[src];
		m_Blocks[src] = m_Blocks[dst];
		m_Blocks[dst] = tmp;
	}

	bool SlidingPuzzle::isSolved()
	{
		for (int i = 0; i < getSize(); i++) {
			if (m_Blocks[i] != m_Goal[i]) {
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
