#pragma once

namespace SlidingPuzzleSpace
{
	class PuzzleBlock sealed
	{
	public :
		/* Constructor */
		// Constructor
		PuzzleBlock();

		/* Accessor */
		// ���� ��� ��ȣ
		int getID();

	private:
		/* Attribute */
		int m_ID;	// ���� ��� ��ȣ

		/* Support */
		static int m_NextID;	// ���� ��� ��ȣ�� �ο��ϱ� ���� ����
	};

	inline int PuzzleBlock::getID()
	{
		return m_ID;
	}

	typedef PuzzleBlock* PuzzleBlockPtr;
}
