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
		// 사전 조건: height과 width는 0 이상 정수
		SlidingPuzzle(int height, int width);

		// Destructor
		~SlidingPuzzle();


		/* Operations */

		// 퍼즐 초기화 (번호 순)
		// 사후 조건: 퍼즐이 퍼즐 블록의 번호 순으로 초기화됨.
		void initPuzzle();

		// 퍼즐 초기화 (사용자 입력 순)
		// 사전 조건: idArr는 블록 번호 배열이고 그 크기는 퍼즐 개수와 같으며, 블록 번호는 0 이상 퍼즐 개수 미만임 .
		// 사후 조건: 퍼즐이 사용자가 입력한 번호 순으로 초기화 됨.
		void initPuzzle(int* idArr);

		// 완성 퍼즐 목표 설정 (번호 순)
		// 사후 조건: 완성된 퍼즐의 모양이 퍼즐 블록의 번호 순으로 초기화됨.
		void initGoal();

		// 완성 퍼즐 목표 설정 (사용자 입력 순)
		// 사전 조건: idArr는 블록 번호 배열이고 그 크기는 퍼즐 개수와 같으며, 블록 번호는 0 이상 퍼즐 개수 미만임 .
		// 사후 조건: 완성된 퍼즐의 모양이 사용자가 입력한 번호 순으로 초기화 됨.
		void initGoal(int* idArr);

		// 퍼즐 블록 이동
		// 사전 조건: x는 블록의 0 이상 가로 위치, y는 블록의 0 이상 세로 위치이며, 이동 대상 또는 목표가 빈 블록(블록 번호 0)임.
		// 사후 조건: 블록이 설정한 방향으로 이동되며, 성공하면 true를 실패하면 false를 반환함.
		bool moveBlock(int x, int y, Direction dir);

		// 퍼즐 풀이 성공 확인
		// 사후 조건: 퍼즐 풀이를 성공했으면 true, 실패했으면 false를 반환함.
		bool isSolved();


		/* Accessors */

		// 퍼즐 블록의 개수
		int getSize();

		// 퍼즐의 너비
		int getWidth();

		// 퍼즐의 높이
		int getHeight();


	private:
		/* Attributes */
		PuzzleBlockPtr **m_Blocks = nullptr;	// 섞여 있는 블록 2차원 배열
		PuzzleBlockPtr **m_Goal = nullptr;		// 완성 목표 2차원 배열
		int m_Width = 0;						// 퍼즐의 너비
		int m_Height = 0;						// 퍼즐의 높이


		/* Support */
		PuzzleBlockPtr *m_BlockArr = nullptr;	// 섞여 있는 블록 1차원 배열
		PuzzleBlockPtr *m_GoalArr = nullptr;	// 완성 목표 1차원 배열
		PuzzleBlock *m_BlockRepo = nullptr;		// 전체 블록들을 순서대로 가지고 있는 저장소 배열
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
