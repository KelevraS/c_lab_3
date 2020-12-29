char* const message = "Select operation:";
char* const operations[] = {
						"Matrix addition",
						"Matrix multiplication",
						"Matrix determinant",
						"Matrix eigenvalue and eigenvector",
						"Matrix rank",
						"Matrix exponent",
						"Magic square"
};

void showWelcomeMessage()
{
	printf_s("%s\n", message);

	for (int i = 0; i < sizeof(operations) / sizeof(operations[0]); i++)
	{
		printf_s("%d: %s\n", i + 1, operations[i]);
	}
}