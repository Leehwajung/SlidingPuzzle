#pragma once

#include "Direction.h"
#include "TileBlockRepo.h"

namespace SlidingPuzzleSpace
{
#define DEFAULT_BLANK_X	0
#define DEFAULT_BLANK_Y	0

	typedef class State* StatePtr;

	/* 상태
	 * n×m 타일블록을 하나의 클래스로 나타냄.
	 * 이는 2차원 배열을 필드로 가지는 클래스를 정의하여 이용함.
	 */
	class State
	{
	public:
		/* Constructors / Destructor */

		// Constructor of First State
		State(TileBlockRepo& repo, TileID* idArr = nullptr);

		// Constructor of Later States
		State(State& pred, Direction& movingTargetPos);

		// Copy Constructor
		State(State& other);

		// Destructor
		~State();


		/* Operator */
		
		// 동일 비교 연산자
		bool operator==(State& rightSide);


		/* Operation */

		// 동일 비교
		bool equals(State& other);

		// 잘못 놓여진 타일의 개수 (h^)
		int getDiffSize(State& other);


		/* Accessors */

		// 이전 상태
		StatePtr getPred();

		// 퍼즐 블록의 개수
		int getSize();

		// 퍼즐의 너비
		int getWidth();

		// 퍼즐의 높이
		int getHeight();

		// 라운드(턴) 번호 (현재까지 이동 횟수) (g^)
		int getRound();

		// 이전 상태와 같은가
		bool equalsPred();


	private:
		/* Sub-Operation */

		// 생성자에서 사용할 블록 초기화 연산
		void generateBlocks();


	protected:
		/* Attributes */
		TileBlockPtr **m_Blocks = nullptr;	// 섞여 있는 블록 2차원 배열
		StatePtr m_pPred = nullptr;			// 부모에 대한 포인터 (탐색트리 (TR) 은 구현할 필요가 없다. 각 노드의 pred 포인터로 해결된다.)
		int m_nBlankX = DEFAULT_BLANK_X;	// 비어있는 블록의 x 좌표
		int m_nBlankY = DEFAULT_BLANK_Y;	// 비어있는 블록의 y 좌표
		int m_nRound = 0;					// 라운드(턴) 번호 (현재까지 이동 횟수) (g^)
		bool m_bEqualsPred = false;			// 이전 상태와 같은지 여부


		/* Supports */
		TileBlockPtr *m_BlockArr = nullptr;	// 섞여 있는 블록 1차원 배열
		TileBlockRepo &m_BlockRepo;			// 전체 블록들을 순서대로 가지고 있는 저장소
	};


	inline StatePtr State::getPred()
	{
		return m_pPred;
	}

	inline int State::getSize()
	{
		return m_BlockRepo.getSize();
	}

	inline int State::getWidth()
	{
		return m_BlockRepo.getWidth();
	}

	inline int State::getHeight()
	{
		return m_BlockRepo.getHeight();
	}

	inline int State::getRound()
	{
		return m_nRound;
	}

	inline bool State::equalsPred()
	{
		return m_bEqualsPred;
	}
}


