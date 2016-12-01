#pragma once

#include "TileBlock.h"

namespace SlidingPuzzleSpace
{
#define DEFAULT_BLANK	0	// 타일이 없는 셀에는 0을 넣어 놓는다.

	class TileBlockRepo
	{
	public:
		TileBlockRepo(int height, int width, 
			TileID blankID = DEFAULT_BLANK, TileID startID = DEFAULT_START_ID);
		~TileBlockRepo();


		/* Operator */

		// 저장소 접근
		TileBlock* operator[](int index) const;


		/* Accessors */

		// 퍼즐 블록의 개수
		int getSize();

		// 퍼즐의 너비
		int getWidth();

		// 퍼즐의 높이
		int getHeight();


	private:
		/* Attributes */
		int m_Width = 0;	// 퍼즐의 너비
		int m_Height = 0;	// 퍼즐의 높이


		/* Support */
		TileBlock *m_BlockRepo = nullptr;	// 전체 블록들을 순서대로 가지고 있는 저장소 배열
	};



	inline TileBlockRepo::TileBlockRepo(int height, int width, 
		TileID blankID/* = DEFAULT_BLANK*/, TileID startID/* = DEFAULT_START_ID*/)
		:m_Height(height), m_Width(width)
	{
		TileBlock::resetStartID(startID);
		int size = height * width;
		m_BlockRepo = new TileBlock[size];
		for (int i = 0; i < size; i++) {
			if (m_BlockRepo[i].getID() == blankID) {
				m_BlockRepo[i].setBlank();
				break;
			}
		}
	}

	inline TileBlockRepo::~TileBlockRepo()
	{
		if (m_BlockRepo) {
			delete[] m_BlockRepo;
		}
	}

	inline TileBlock* TileBlockRepo::operator[](int index) const
	{
		return &m_BlockRepo[index];
	}

	inline int TileBlockRepo::getSize()
	{
		return m_Width * m_Height;
	}

	inline int TileBlockRepo::getWidth()
	{
		return m_Width;
	}

	inline int TileBlockRepo::getHeight()
	{
		return m_Height;
	}



	typedef TileBlockRepo* TileBlockRepoPtr;
}