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

		// 퍼즐 아이디 시작 번호 초기화
		static void resetStartID(TileID startID = DEFAULT_START_ID);


		/* Accessors */

		// 퍼즐 블록 번호
		TileID getID();

		// 빈칸 여부 확인
		bool isBlank();


		/* Mutator */

		// 빈칸으로 설정
		void setBlank(bool b = true);


	private:
		/* Attribute */
		TileID m_ID;	// 퍼즐 블록 번호


		/* Supports */
		bool m_bBlank = false;
		static TileID m_NextID;	// 퍼즐 블록 번호를 부여하기 위한 인자
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
