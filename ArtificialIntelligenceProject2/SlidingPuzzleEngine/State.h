#pragma once

#include "Direction.h"
#include "TileBlockRepo.h"

namespace SlidingPuzzleSpace
{
#define DEFAULT_BLANK_X	0
#define DEFAULT_BLANK_Y	0

	typedef class State* StatePtr;

	class State
	{
	public:
		/* Constructors / Destructor */

		// Constructor of First State
		State(TileBlockRepo& repo, TileID* idArr = nullptr);

		// Constructor of Later States
		State(State& pred, Direction& movingTargetPos);

		// Copy Constructor
		State(State& other);

		// Destructor
		~State();


		/* Operator */
		
		// ���� �� ������
		bool operator==(State& rightSide);


		/* Operation */

		// ���� ��
		bool equals(State& other);


		/* Accessors */

		// ���� ����
		StatePtr getPred();

		// ���� ����� ����
		int getSize();

		// ������ �ʺ�
		int getWidth();

		// ������ ����
		int getHeight();

		// ���� ���¿� ������
		bool equalsPred();


	private:
		/* Sub-Operation */

		// �����ڿ��� ����� ��� �ʱ�ȭ ����
		void initializeBlocks();


		/* Attributes */
		TileBlockPtr **m_Blocks = nullptr;	// ���� �ִ� ��� 2���� �迭
		StatePtr m_pPred = nullptr;			// �θ� ���� ������
		int m_nBlankX = DEFAULT_BLANK_X;	// ����ִ� ����� x ��ǥ
		int m_nBlankY = DEFAULT_BLANK_Y;	// ����ִ� ����� y ��ǥ
		bool m_bEqualsPred = false;			// ���� ���¿� ������ ����


		/* Supports */
		TileBlockPtr *m_BlockArr = nullptr;	// ���� �ִ� ��� 1���� �迭
		TileBlockRepo &m_BlockRepo;			// ��ü ��ϵ��� ������� ������ �ִ� �����
	};


	inline StatePtr State::getPred()
	{
		return m_pPred;
	}

	inline int State::getSize()
	{
		return m_BlockRepo.getSize();
	}

	inline int State::getWidth()
	{
		return m_BlockRepo.getWidth();
	}

	inline int State::getHeight()
	{
		return m_BlockRepo.getHeight();
	}

	inline bool State::equalsPred()
	{
		return m_bEqualsPred;
	}
}


