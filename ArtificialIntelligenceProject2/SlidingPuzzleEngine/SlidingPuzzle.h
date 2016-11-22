#pragma once

#include "PuzzleBlock.h"
#include "Direction.h"

namespace SlidingPuzzleSpace
{
#define BLANK_BLOCK_ID	0

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

		// ���� �ʱ�ȭ (��ȣ ��)
		// ���� ����: ������ ���� ����� ��ȣ ������ �ʱ�ȭ��.
		void initPuzzle();

		// ���� �ʱ�ȭ (����� �Է� ��)
		// ���� ����: idArr�� ��� ��ȣ �迭�̰� �� ũ��� ���� ������ ������, ��� ��ȣ�� 0 �̻� ���� ���� �̸��� .
		// ���� ����: ������ ����ڰ� �Է��� ��ȣ ������ �ʱ�ȭ ��.
		void initPuzzle(int* idArr);

		// �ϼ� ���� ��ǥ ���� (��ȣ ��)
		// ���� ����: �ϼ��� ������ ����� ���� ����� ��ȣ ������ �ʱ�ȭ��.
		void initGoal();

		// �ϼ� ���� ��ǥ ���� (����� �Է� ��)
		// ���� ����: idArr�� ��� ��ȣ �迭�̰� �� ũ��� ���� ������ ������, ��� ��ȣ�� 0 �̻� ���� ���� �̸��� .
		// ���� ����: �ϼ��� ������ ����� ����ڰ� �Է��� ��ȣ ������ �ʱ�ȭ ��.
		void initGoal(int* idArr);

		// ���� ��� �̵�
		// ���� ����: x�� ����� 0 �̻� ���� ��ġ, y�� ����� 0 �̻� ���� ��ġ�̸�, �̵� ��� �Ǵ� ��ǥ�� �� ���(��� ��ȣ 0)��.
		// ���� ����: ����� ������ �������� �̵��Ǹ�, �����ϸ� true�� �����ϸ� false�� ��ȯ��.
		bool moveBlock(int x, int y, Direction dir);

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
		/* Attributes */
		PuzzleBlockPtr **m_Blocks = nullptr;	// ���� �ִ� ��� 2���� �迭
		PuzzleBlockPtr **m_Goal = nullptr;		// �ϼ� ��ǥ 2���� �迭
		int m_Width = 0;						// ������ �ʺ�
		int m_Height = 0;						// ������ ����


		/* Support */
		PuzzleBlockPtr *m_BlockArr = nullptr;	// ���� �ִ� ��� 1���� �迭
		PuzzleBlockPtr *m_GoalArr = nullptr;	// �ϼ� ��ǥ 1���� �迭
		PuzzleBlock *m_BlockRepo = nullptr;		// ��ü ��ϵ��� ������� ������ �ִ� ����� �迭
	};

	inline int SlidingPuzzle::getWidth()
	{
		return m_Width;
	}

	inline int SlidingPuzzle::getHeight()
	{
		return m_Height;
	}
}
