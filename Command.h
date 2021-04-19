/*==============================================*/
/* Code is written by: Prawida Yumia 4210191005 */
/*==============================================*/
#pragma once
class Command
{
private:
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};