#include "calculator.h"

int main()
{

    stack st;
    st.size = 0;
    Operator type;
    char operand[MAX_DOUBLE];
    int flag_inval = 0;

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
            flag_inval = 1;
            perror("Error: Unkonwn operand!");
            break;
        }
    }
    if (!isEmpty(&st) && !flag_inval)
    {
        printf(GREEN);
        printf("Resule is: %f\n", pop(&st));
        printf(RESET);
    }
    return 0;
}




