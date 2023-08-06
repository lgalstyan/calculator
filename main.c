#include "calculator.h"

int main() {

    stack st;
    st.size = 0;
    Operator type;
    char operand[MAX_DOUBLE];

    while ((type = read_line(operand)) != END)
    {
        switch (type)
        {
        case NUMBER:
            push_back(&st, atof(operand));
            // print_stack(&st);
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
            // perror("Error: Unkonwn operand!");
            break;
        }
    }
        if (!isEmpty(&st))
        {
            printf(GREEN);
            printf("Resule is: %f\n", pop(&st));
            printf(RESET);
        }
        else
            // perror("Error: Invalid count of operand!");
    // printf("Enter a character: ");
    // while((ch = getchar()) != EOF)
    // {
    //     printf("You entered: %c\n", ch);
    // }

    return 0;
}




