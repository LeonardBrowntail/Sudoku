/*==============================================*/
/* Code is written by: Prawida Yumia 4210191005 */
/*==============================================*/
#pragma once
#include "Command.h"
#include "Board.h"
class DeleteCell : public Command
{
private:
	int x;
	int y;
	int val;
	Board* board;
public:
	/* Constructor*/
	DeleteCell(int, int, Board&);

	/* Setter */
	void setX(int);
	void setY(int);
	void setVal(int);

	/* Getter */
	int getX();
	int getY();
	int getVal();

	/* Functions */
	void Execute();
	void Undo();
};

DeleteCell::DeleteCell(int inx, int iny, Board& b)
{
	x = inx;
	y = iny;
	board = &b;
	val = board->GetCell(x, y);
}

void DeleteCell::setX(int in)
{
	x = in;
}

void DeleteCell::setY(int in)
{
	y = in;
}

void DeleteCell::setVal(int in)
{
	val = in;
}

int DeleteCell::getX()
{
	return x;
}

int DeleteCell::getY()
{
	return y;
}

int DeleteCell::getVal()
{
	return val;
}

void DeleteCell::Execute()
{
	board->DelCell(x, y);
}

void DeleteCell::Undo()
{
	board->SetCell(x, y, val);
}