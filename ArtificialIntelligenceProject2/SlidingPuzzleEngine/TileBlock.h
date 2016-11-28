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
		static void resetStartID(TileID startID = DEFAULT_START_ID);


		/* Accessors */

		// ���� ��� ��ȣ
		TileID getID();

		// ��ĭ ���� Ȯ��
		bool isBlank();


		/* Mutator */

		// ��ĭ���� ����
		void setBlank(bool b = true);


	private:
		/* Attribute */
		TileID m_ID;	// ���� ��� ��ȣ


		/* Supports */
		bool m_bBlank = false;
		static TileID m_NextID;	// ���� ��� ��ȣ�� �ο��ϱ� ���� ����
	};



	inline TileBlock::TileBlock()
		: m_ID(m_NextID++)
	{
	}

	inline void TileBlock::resetStartID(TileID startID/* = DEFAULT_START_ID*/)
	{
		m_NextID = startID;
	}

	inline TileID TileBlock::getID()
	{
		return m_ID;
	}

	inline bool TileBlock::isBlank()
	{
		return m_bBlank;
	}

	inline void TileBlock::setBlank(bool b/* = true*/)
	{
		m_bBlank = b;
	}



	typedef TileBlock* TileBlockPtr;
}
