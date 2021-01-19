#include "customop.h"
#include "determinant.h"
#include "rancounter.h"
#include "eigensolver.h"
#include "magicsquare.h" 

enum OperationType
{
	Addition = 1,
	Multiplication = 2,
	Determinant = 3,
	Eigen = 4,
	Rank = 5,
	Exponent = 6,
	Magic = 7
};

int getOperationNumber()
{
	int selectedOperation;

	if (scanf_s("%d", &selectedOperation) < 1)
		perror("Invalid character!");

	return selectedOperation;
}

void selectOperation(int operation)
{
	switch (operation)
	{
	case Addition:
		addition();
		break;

	case Multiplication:
		multiplication();
		break;

	case Determinant:
		determinant();
		break;

	case Eigen:
		eigen();
		break;

	case Rank:
		rank();
		break;

	case Exponent:
		break;

	case Magic:
		magicSquare();
		break;

	default:
		printf_s("We haven't got this command type\n");
		break;
	}
}