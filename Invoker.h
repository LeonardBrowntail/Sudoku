/*==================================================================*/
/* Header file is written by: Aydin Ihsan Ibrahim Nurdin 4210191004 */
/*==================================================================*/
#pragma once
#include "FillCell.h"
#include "DeleteCell.h"
#include <stack>
#include <iostream>

class Invoker
{
private:
	std::stack<Command*> undoStack;
	std::stack<Command*> redoStack;
public:
	Invoker();
	void PushCommand(Command& command);
	void PopCommand();

	bool UndoAction();
	bool RedoAction();
};

Invoker::Invoker()
{
	std::cout << "Stack successfully allocated!" << std::endl;
}

void Invoker::PushCommand(Command& in)
{
	undoStack.push(&in);
	std::cout << "Command successfully pushed" << std::endl;
}

void Invoker::PopCommand()
{
	if (!undoStack.empty())
	{
		redoStack.push(undoStack.top());
		undoStack.pop();
	}
	else
	{
		std::cout << "nothing...\n";
	}
}

bool Invoker::UndoAction()
{
	if (!undoStack.empty())
	{
		undoStack.top()->Undo();
		redoStack.push(undoStack.top());
		undoStack.pop();
		return true;
	}
	return false;
}

bool Invoker::RedoAction()
{
	if (!redoStack.empty())
	{
		redoStack.top()->Undo();
		undoStack.push(redoStack.top());
		redoStack.pop();
		return true;
	}
	return false;
}