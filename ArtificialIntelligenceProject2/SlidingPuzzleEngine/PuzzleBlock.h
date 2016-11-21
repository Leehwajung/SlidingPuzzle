#pragma once

class PuzzleBlock sealed
{
	/* Constructor */
public :
	PuzzleBlock();

	/* Accessor */
	int getID();

	/* Attribute */
private:
	int m_ID;

	/* Support */
	static int m_NextID;
};

inline int PuzzleBlock::getID()
{
	return m_ID;
}
