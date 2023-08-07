#include "calculator.h"

int main()
{
	double result = 0; 
	stack st;
	st.size = 0;
	Operator type;
	char operand[MAX_DOUBLE];

	//printf(GREEN);
	//printf("-----------------------------\n");
	//printf("Enter the postfix expression\n");
	//printf(RESET);
	while ((type = read_line(operand)) != END)
	{
		switch (type)
		{
			case NUMBER:
				push_back(&st, atof(operand));
				break;
			case MINUS:
				operator_minus(&st);
				break;
			case PLUS:
				operator_plus(&st);
				break;
			case MULTIPL:
				operator_multipl(&st);
				break;
			case DIVIDE:
				operator_divide(&st);
				break;
			default:
				printf(RED);
				printf("Error: Unkonwn operand!\n");
				printf(RESET);
				return 1;
				break;
		}
	}
	//printf(GREEN);
	//printf("-----------------------------\n");
	//printf(RESET);
	result = pop(&st);
	if (isEmpty(&st))
	{
		printf(GREEN);
		printf("Result is: %f\n", result);
		printf(RESET);
	}
	else
	{
		printf(RED);
		printf("Error: Invalid count of operand!\n");
		printf(RESET);
		return 2;
	}
	return 0;
}




