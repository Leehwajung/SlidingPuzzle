#pragma once

#define DEFAULT_START_ID	((TileID) 0)

namespace SlidingPuzzleSpace
{
	typedef int TileID;

	class TileBlock sealed
	{
	public :
		/* Constructor */
		// Constructor
		TileBlock();

		/* Operation */
		// ���� ���̵� ���� ��ȣ �ʱ�ȭ
		static void resetStartID(TileID id = DEFAULT_START_ID);

		/* Accessor */
		// ���� ��� ��ȣ
		TileID getID();

	private:
		/* Attribute */
		TileID m_ID;	// ���� ��� ��ȣ

		/* Support */
		static TileID m_NextID;	// ���� ��� ��ȣ�� �ο��ϱ� ���� ����
	};


	inline TileBlock::TileBlock()
		: m_ID(m_NextID++)
	{
	}

	inline void TileBlock::resetStartID(TileID id/* = DEFAULT_START_ID*/)
	{
		m_NextID = id;
	}

	inline TileID TileBlock::getID()
	{
		return m_ID;
	}

	typedef TileBlock* TileBlockPtr;
}
