#pragma once

#include "TileBlock.h"

namespace SlidingPuzzleSpace
{
	class TileBlockRepo
	{
	public:
		TileBlockRepo(int height, int width);
		~TileBlockRepo();


		/* Operator */
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



	inline TileBlockRepo::TileBlockRepo(int height, int width)
		:m_Height(height), m_Width(width)
	{
		TileBlock::resetStartID();
		m_BlockRepo = new TileBlock[height * width];
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