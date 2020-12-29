#include "customIO.h"
#include "customop.h"
#include "menuswitch.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "arrayUtil.h"

void getString(char str[256], int bufSize)
{
	scanf_s("%255s", str, bufSize);
}

int main(void)
{
	showWelcomeMessage();
	selectOperation(getOperationNumber());

	return 0;
}