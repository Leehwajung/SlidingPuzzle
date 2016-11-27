#pragma once

#include "Direction.h"
#include "TileBlock.h"
#include "TileBlockRepo.h"
#include "State.h"

namespace SlidingPuzzleSpace
{
	class SlidingPuzzle sealed
	{
	public:
		/* Constructor / Destructor */

		// Constructor
		// ���� ����: height�� width�� 0 �̻� ����
		SlidingPuzzle(int height, int width);

		// Destructor
		~SlidingPuzzle();


		/* Operations */

		// ���� �ʱ�ȭ
		// ���� ����: idArr�� ��� ��ȣ �迭�̰� �� ũ��� ���� ������ ������, ��� ��ȣ�� 0 �̻� ���� ���� �̸���. nullptr ����.
		// ���� ����: ������, idArr�� nullptr�̸� ��ȣ������ �׷��� ������ ����ڰ� �Է��� ��ȣ ������ �ʱ�ȭ ��.
		void initPuzzle(int* idArr = nullptr);

		// �ϼ� ���� ��ǥ ����
		// ���� ����: idArr�� ��� ��ȣ �迭�̰� �� ũ��� ���� ������ ������, ��� ��ȣ�� 0 �̻� ���� ���� �̸���. nullptr ����.
		// ���� ����: �ϼ��� ������ �����, idArr�� nullptr�̸� ��ȣ������ �׷��� ������ ����ڰ� �Է��� ��ȣ ������ �ʱ�ȭ ��.
		void initGoal(int* idArr = nullptr);

		// ���� ��� �̵�
		// ���� ����: movingTargetPos�� �� ��� ���� �̵��� ���� ����� ��ġ��.
		// ���� ����: ����� ������ �������� �̵��Ǹ�, �����ϸ� true�� �����ϸ� false�� ��ȯ��.
		bool moveBlock(Direction movingTargetPos);

		// ���� Ǯ�� ���� Ȯ��
		// ���� ����: ���� Ǯ�̸� ���������� true, ���������� false�� ��ȯ��.
		bool isSolved();


		/* Accessors */

		// ���� ����� ����
		int getSize();

		// ������ �ʺ�
		int getWidth();

		// ������ ����
		int getHeight();


	private:
		/* Sub-Operations */

		// ��� ���� ����
		void deleteStates();

		// ��ǥ ����
		void deleteGoal();


		/* Attributes */
		StatePtr m_CurrState = nullptr;	// ���� �ִ� ���
		StatePtr m_Goal = nullptr;		// �ϼ� ��ǥ

		/* Support */
		TileBlockRepo *m_BlockRepo = nullptr;	// ��ü ��ϵ��� ������� ������ �ִ� �����
	};


	inline void SlidingPuzzle::initPuzzle(int* idArr/* = nullptr*/)
	{
		deleteStates();
		m_CurrState = new State(*m_BlockRepo, idArr);
	}

	inline void SlidingPuzzle::initGoal(int* idArr/* = nullptr*/)
	{
		deleteGoal();
		m_Goal = new State(*m_BlockRepo, idArr);
	}

	inline bool SlidingPuzzle::isSolved()
	{
		return m_CurrState->equals(*m_Goal);
	}

	inline int SlidingPuzzle::getSize()
	{
		return m_BlockRepo->getSize();
	}

	inline int SlidingPuzzle::getWidth()
	{
		return m_BlockRepo->getWidth();
	}

	inline int SlidingPuzzle::getHeight()
	{
		return m_BlockRepo->getHeight();
	}

	inline void SlidingPuzzle::deleteGoal()
	{
		if (m_Goal) {
			delete m_Goal;
		}
	}
}
