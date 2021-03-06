#include "pch.h"
#include "State.h"

namespace SlidingPuzzleSpace
{
	State::State(TileBlockRepo& repo, TileID* idArr/* = nullptr*/)
		: m_BlockRepo(repo), m_pPred(nullptr), m_nRound(0),
		m_bEqualsPred(false), m_MovedDir(Direction::NODIR)
	{
		generateBlocks();

		int dx = 0, dy = 0;
		for (int i = 0; i < getSize(); i++) {
			m_BlockArr[i] = idArr ? m_BlockRepo[idArr[i]] : m_BlockRepo[i];

			if (m_BlockArr[i]->isBlank()) {
				m_nBlankX = dx;
				m_nBlankY = dy;
			}

			if (dx < getWidth() - 1) {
				dx++;
			}
			else {
				dx = 0;
				dy++;
			}
		}
	}

	State::State(State& pred, Direction& movingTargetPos)
		: State(pred)
	{
		m_pPred = &pred;
		m_nRound++;
		m_MovedDir = movingTargetPos;

		m_bEqualsPred = true;
		switch (movingTargetPos) {
		case Direction::UP:
			if (m_nBlankY > 0) {
				m_nBlankY--;
				m_bEqualsPred = false;
			}
			break;
		case Direction::LEFT:
			if (m_nBlankX > 0) {
				m_nBlankX--;
				m_bEqualsPred = false;
			}
			break;
		case Direction::RIGHT:
			if (m_nBlankX < getWidth() - 1) {
				m_nBlankX++;
				m_bEqualsPred = false;
			}
			break;
		case Direction::DOWN:
			if (m_nBlankY < getHeight() - 1) {
				m_nBlankY++;
				m_bEqualsPred = false;
			}
			break;
		case Direction::NODIR:
			break;
		}

		if (!m_bEqualsPred) {
			TileBlockPtr &src = m_Blocks[m_nBlankY][m_nBlankX];
			TileBlockPtr &dst = m_Blocks[pred.m_nBlankY][pred.m_nBlankX];
			TileBlockPtr tmp = src;
			src = dst;
			dst = tmp;
		}
	}

	State::State(State& other)
		: m_BlockRepo(other.m_BlockRepo), m_pPred(other.m_pPred),
		m_nBlankX(other.m_nBlankX), m_nBlankY(other.m_nBlankY),
		m_nRound(other.m_nRound), m_bEqualsPred(other.m_bEqualsPred),
		m_MovedDir(other.m_MovedDir)
	{
		generateBlocks();
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

	int State::getDiffSize(State& other)
	{
		int num = 0;
		for (int i = 0; i < getSize(); i++) {
			if (m_Blocks[i] != other.m_Blocks[i]) {
				num++;
			}
		}
		return num;
	}

	void State::generateBlocks()
	{
		int size = getSize();
		m_BlockArr = new TileBlockPtr[size];
		m_Blocks = new TileBlockPtr*[size];

		for (int i = 0; i < getHeight(); i++) {
			m_Blocks[i] = &m_BlockArr[i * getWidth()];
		}
	}
}
