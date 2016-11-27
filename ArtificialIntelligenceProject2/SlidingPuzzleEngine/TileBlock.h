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
		// 퍼즐 아이디 시작 번호 초기화
		static void resetStartID(TileID id /* = DEFAULTSTARTID */);

		/* Accessor */
		// 퍼즐 블록 번호
		TileID getID();

	private:
		/* Attribute */
		TileID m_ID;	// 퍼즐 블록 번호

		/* Support */
		static TileID m_NextID;	// 퍼즐 블록 번호를 부여하기 위한 인자
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
