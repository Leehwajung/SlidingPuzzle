#pragma once

#include "Direction.h"
#include "TileBlockRepo.h"

namespace SlidingPuzzleSpace
{
#define DEFAULT_BLANK_X	0
#define DEFAULT_BLANK_Y	0

	typedef class State* StatePtr;

	/* ����
	* n��m Ÿ�Ϻ���� �ϳ��� Ŭ������ ��Ÿ��.
	* �̴� 2���� �迭�� �ʵ�� ������ Ŭ������ �����Ͽ� �̿���.
	*/
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

		// �߸� ������ Ÿ���� ���� (h^)
		int getDiffSize(State& other);


		/* Accessors */

		// ��� �迭
		TileBlockPtr** getBlocks();

		// ���� ����
		StatePtr getPred();

		// ���� ����� ����
		int getSize();

		// ������ �ʺ�
		int getWidth();

		// ������ ����
		int getHeight();

		// ����(��) ��ȣ (������� �̵� Ƚ��) (g^)
		int getRound();

		// ���� ���¿� ������
		bool equalsPred();

		// ���� ���¿� ���Ͽ�, ��ĭ�� �̵��� ����
		Direction getMovedDir();


	private:
		/* Sub-Operation */

		// �����ڿ��� ����� ��� �ʱ�ȭ ����
		void generateBlocks();


	protected:
		/* Attributes */
		TileBlockPtr **m_Blocks = nullptr;			// ���� �ִ� ��� 2���� �迭
		StatePtr m_pPred = nullptr;					// �θ� ���� ������ (Ž��Ʈ�� (TR) �� ������ �ʿ䰡 ����. �� ����� pred �����ͷ� �ذ�ȴ�.)
		int m_nBlankX = DEFAULT_BLANK_X;			// ����ִ� ����� x ��ǥ
		int m_nBlankY = DEFAULT_BLANK_Y;			// ����ִ� ����� y ��ǥ
		int m_nRound = 0;							// ����(��) ��ȣ (������� �̵� Ƚ��) (g^)
		bool m_bEqualsPred = false;					// ���� ���¿� ������ ����
		Direction m_MovedDir = Direction::NODIR;	// ���� ���¿� ���Ͽ�, ��ĭ�� �̵��� ����


													/* Supports */
		TileBlockPtr *m_BlockArr = nullptr;	// ���� �ִ� ��� 1���� �迭
		TileBlockRepo &m_BlockRepo;			// ��ü ��ϵ��� ������� ������ �ִ� �����
	};


	inline TileBlockPtr** State::getBlocks()
	{
		return m_Blocks;
	}

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

	inline int State::getRound()
	{
		return m_nRound;
	}

	inline bool State::equalsPred()
	{
		return m_bEqualsPred;
	}

	inline Direction State::getMovedDir()
	{
		return m_MovedDir;
	}
}


