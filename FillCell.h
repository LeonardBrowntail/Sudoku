/*==============================================*/
/* Code is written by: Prawida Yumia 4210191005 */
/*==============================================*/
#pragma once
#include "Command.h"
#include "Board.h"
class FillCell : public Command
{
private:
	int x;
	int y;
	int val;
	Board *board;
public:
	/* Constructor*/
	FillCell(int, int, int, Board&);

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

FillCell::FillCell(int inx, int iny, int inval, Board& b)
{
	x = inx;
	y = iny;
	val = inval;
	board = &b;
}

void FillCell::setX(int in)
{
	x = in;
}

void FillCell::setY(int in)
{
	y = in;
}

void FillCell::setVal(int in)
{
	val = in;
}

int FillCell::getX()
{
	return x;
}

int FillCell::getY()
{
	return y;
}

int FillCell::getVal()
{
	return val;
}

void FillCell::Execute()
{
	board->SetCell(x, y, val);
}

void FillCell::Undo()
{
	board->DelCell(x, y);
}