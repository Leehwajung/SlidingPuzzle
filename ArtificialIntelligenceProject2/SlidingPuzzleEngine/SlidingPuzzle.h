#pragma once

#include "Direction.h"
#include "TileBlock.h"
#include "TileBlockRepo.h"
#include "Node.h"

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

		// ���� ��� �̵�
		// ���� ����: movedNode�� ����� �̵��� ���, movedNode�� pred�� ���� ���� ���ƾ� ��.
		// ���� ����: ����� �̵��ϴ� �� �����ϸ� true�� �����ϸ� false�� ��ȯ��.
		bool SlidingPuzzle::moveBlock(NodePtr movedNode);

		// ���� Ǯ�� ���� Ȯ��
		// ���� ����: ���� Ǯ�̸� ���������� true, ���������� false�� ��ȯ��.
		bool isSolved();

		// ���� ��� (Pred�� ���ư���)
		// ���� ����: CurrNode�� pred�� �ٲ��, ���������� true, ���������� false�� ��ȯ��.
		bool undo();

		// Ư�� ���� �̵�
		void displace(NodePtr node);


		/* Accessors */

		// ���� ���
		NodePtr getCurrNode();

		// ��ǥ ���
		StatePtr getGoal();

		// ���� ����� ����
		int getSize();

		// ������ �ʺ�
		int getWidth();

		// ������ ����
		int getHeight();


	private:
		/* Sub-Operations */

		// ��� ���� ����
		void deleteNodes();

		// ��ǥ ����
		void deleteGoal();


		/* Attributes */
		NodePtr m_CurrNode = nullptr;	// ���� �ִ� ���
		StatePtr m_Goal = nullptr;		// �ϼ� ��ǥ

		/* Support */
		TileBlockRepo *m_BlockRepo = nullptr;	// ��ü ��ϵ��� ������� ������ �ִ� �����
	};



	inline void SlidingPuzzle::initPuzzle(int* idArr/* = nullptr*/)
	{
		deleteNodes();
		m_CurrNode = new Node(*m_BlockRepo, *m_Goal, idArr);
	}

	inline void SlidingPuzzle::initGoal(int* idArr/* = nullptr*/)
	{
		deleteGoal();
		m_Goal = new State(*m_BlockRepo, idArr);
	}

	inline bool SlidingPuzzle::isSolved()
	{
		return m_CurrNode->equals(*m_Goal);
	}

	inline bool SlidingPuzzle::undo()
	{
		if (m_CurrNode->getPred()) {
			NodePtr pred = (NodePtr) m_CurrNode->getPred();
			delete m_CurrNode;
			m_CurrNode = pred;
			return true;
		}
		return false;
	}

	inline void SlidingPuzzle::displace(NodePtr node)
	{
		m_CurrNode = node;
	}

	inline NodePtr SlidingPuzzle::getCurrNode()
	{
		return m_CurrNode;
	}

	inline StatePtr SlidingPuzzle::getGoal()
	{
		return m_Goal;
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
