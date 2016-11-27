#pragma once

#include "Direction.h"
#include "TileBlock.h"
#include "TileBlockRepo.h"
#include "State.h"

namespace SlidingPuzzleSpace
{
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

		// 퍼즐 초기화
		// 사전 조건: idArr는 블록 번호 배열이고 그 크기는 퍼즐 개수와 같으며, 블록 번호는 0 이상 퍼즐 개수 미만임. nullptr 가능.
		// 사후 조건: 퍼즐이, idArr이 nullptr이면 번호순으로 그렇지 않으면 사용자가 입력한 번호 순으로 초기화 됨.
		void initPuzzle(int* idArr = nullptr);

		// 완성 퍼즐 목표 설정
		// 사전 조건: idArr는 블록 번호 배열이고 그 크기는 퍼즐 개수와 같으며, 블록 번호는 0 이상 퍼즐 개수 미만임. nullptr 가능.
		// 사후 조건: 완성된 퍼즐의 모양이, idArr이 nullptr이면 번호순으로 그렇지 않으면 사용자가 입력한 번호 순으로 초기화 됨.
		void initGoal(int* idArr = nullptr);

		// 퍼즐 블록 이동
		// 사전 조건: movingTargetPos는 빈 블록 기준 이동할 인접 블록의 위치임.
		// 사후 조건: 블록이 설정한 방향으로 이동되며, 성공하면 true를 실패하면 false를 반환함.
		bool moveBlock(Direction movingTargetPos);

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
		/* Sub-Operations */

		// 모든 상태 삭제
		void deleteStates();

		// 목표 삭제
		void deleteGoal();


		/* Attributes */
		StatePtr m_CurrState = nullptr;	// 섞여 있는 블록
		StatePtr m_Goal = nullptr;		// 완성 목표

		/* Support */
		TileBlockRepo *m_BlockRepo = nullptr;	// 전체 블록들을 순서대로 가지고 있는 저장소
	};


	inline void SlidingPuzzle::initPuzzle(int* idArr/* = nullptr*/)
	{
		deleteStates();
		m_CurrState = new State(*m_BlockRepo, idArr);
	}

	inline void SlidingPuzzle::initGoal(int* idArr/* = nullptr*/)
	{
		deleteGoal();
		m_Goal = new State(*m_BlockRepo, idArr);
	}

	inline bool SlidingPuzzle::isSolved()
	{
		return m_CurrState->equals(*m_Goal);
	}

	inline int SlidingPuzzle::getSize()
	{
		return m_BlockRepo->getSize();
	}

	inline int SlidingPuzzle::getWidth()
	{
		return m_BlockRepo->getWidth();
	}

	inline int SlidingPuzzle::getHeight()
	{
		return m_BlockRepo->getHeight();
	}

	inline void SlidingPuzzle::deleteGoal()
	{
		if (m_Goal) {
			delete m_Goal;
		}
	}
}
