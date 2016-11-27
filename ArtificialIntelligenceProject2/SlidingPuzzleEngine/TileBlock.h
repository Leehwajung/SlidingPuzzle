#pragma once

#define DEFAULTSTARTID	((TileID) 0)

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
		static void resetStartID(TileID id /* = DEFAULTSTARTID */);

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

	inline void TileBlock::resetStartID(TileID id = DEFAULTSTARTID)
	{
		m_NextID = id;
	}

	inline TileID TileBlock::getID()
	{
		return m_ID;
	}

	typedef TileBlock* TileBlockPtr;
}
