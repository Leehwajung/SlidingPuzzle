#include "pch.h"
#include "State.h"

namespace SlidingPuzzleSpace
{
	State::State(TileBlockRepo& repo, TileID* idArr/* = nullptr*/)
		: m_BlockRepo(repo), m_pPred(nullptr), m_bEqualsPred(false)
	{
		initializeBlocks();

		if (idArr) {
			int dx = 0, dy = 0;
			for (int i = 0; i < getSize(); i++) {
				m_BlockArr[i] = m_BlockRepo[idArr[i]];
				if (idArr[i] == 0) {
					m_nBlankX = dx;
					m_nBlankY = dy;
				}
				else {
					if (dx < getWidth() - 1) {
						dx++;
					}
					else {
						dx = 0;
						dy++;
					}
				}
			}
		}
		else {
			m_nBlankX = DEFAULT_BLANK_X;
			m_nBlankY = DEFAULT_BLANK_Y;
			for (int i = 0; i < getSize(); i++) {
				m_BlockArr[i] = m_BlockRepo[i];
			}
		}
	}

	State::State(State& pred, Direction& movingTargetPos)
		: State(pred)
	{
		m_pPred = &pred;

		switch (movingTargetPos) {
		case Direction::UP:
			if (m_nBlankY > 0) {
				m_nBlankY--;
			}
			else {
				m_bEqualsPred = true;
			}
			break;
		case Direction::LEFT:
			if (m_nBlankX > 0) {
				m_nBlankX--;
			}
			else {
				m_bEqualsPred = true;
			}
			break;
		case Direction::RIGHT:
			if (m_nBlankX < getWidth() - 1) {
				m_nBlankX++;
			}
			else {
				m_bEqualsPred = true;
			}
			break;
		case Direction::DOWN:
			if (m_nBlankY < getHeight() - 1) {
				m_nBlankY++;
			}
			else {
				m_bEqualsPred = true;
			}
			break;
		case Direction::NODIR:
			m_bEqualsPred = true;
			break;
		}

		if (!m_bEqualsPred) {
			TileBlockPtr &src = m_Blocks[m_nBlankY][m_nBlankX];
			TileBlockPtr &dst = m_Blocks[pred.m_nBlankY][pred.m_nBlankX];
			TileBlockPtr &tmp = src;
			src = dst;
			dst = tmp;
		}
	}

	State::State(State& other)
		: m_BlockRepo(other.m_BlockRepo), m_pPred(other.m_pPred),
		m_nBlankX(other.m_nBlankX), m_nBlankY(other.m_nBlankY),
		m_bEqualsPred(other.m_bEqualsPred)
	{
		initializeBlocks();
		for (int i = 0; i < getSize(); i++) {
			m_BlockArr[i] = other.m_BlockArr[i];
		}
	}

	State::~State()
	{
		if (m_Blocks) {
			delete[] m_Blocks;
		}
		if (m_BlockArr) {
			delete[] m_BlockArr;
		}
	}

	bool State::operator==(State& rightSide)
	{
		if (m_pPred != rightSide.m_pPred) {
			return false;
		}
		return equals(rightSide);
	}

	bool State::equals(State& other)
	{
		if (&m_BlockRepo != &other.m_BlockRepo) {
			return false;
		}
		for (int i = 0; i < getSize(); i++) {
			if (m_BlockArr[i] != other.m_BlockArr[i]) {
				return false;
			}
		}
		return true;
	}

	void State::initializeBlocks()
	{
		int size = getSize();
		m_BlockArr = new TileBlockPtr[size];
		m_Blocks = new TileBlockPtr*[size];

		for (int i = 0; i < getHeight(); i++) {
			m_Blocks[i] = &m_BlockArr[i * getWidth()];
		}
	}
}
