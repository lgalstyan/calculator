#include "calculator.h"

void print_stack(stack *st)
{
    for(int i = 0; i < st->size; ++i)
        printf("%f ", st->data[i]);
}

void push_back(stack* st,  double n)
{
    printf("push-> %f\n", n);
    if (st->size == STACK_SIZE - 1)
        printf("Error: Stack already is full");
    else
    {
        st->data[st->size] = n;
        // printf("st->data[%zu] = %f\n", st->size, st->data[st->size]);
        ++st->size;
    }
    print_stack(st);
}

double pop(stack* st)
{
    if (st->size < 0)
        printf("Error: Stack is empty");
    printf("st->data[%zu] = %f\n", st->size - 1, st->data[st->size - 1]);
    // printf("size = %zu\n", st->size);
    --st->size;
    return (st->data[st->size]);
}

int isEmpty(stack *stack)
{
    if(stack->size == 0)
        return (1);
    return (0);
}

Operator read_line(char line[])
{
    char ch;
    size_t i;

    i = 0;
        ch = getchar();
        while(ch != EOF && ch != '\n' && (ch == ' ' || ch == '\t'))
        {
            ch = getchar();
        }
        if (ch == '\n' || ch == EOF)
            return END;
        if (ch == '+')
            return PLUS;
        if (ch == '-')
            return MINUS;
        if (ch == '/')
            return DIVIDE;
        if (ch == '*')
            return MULTIPL;
        if (!isdigit(ch) && ch != '.')
        {
            // perror("Error: input not a digit");
            return (INVALID);
        }
        while (ch != EOF && isdigit(ch))
        {
            line[i] = ch;
            ++i;
            ch = getchar();
        }
        // if (ch == '\n' || ch == EOF)
        //     return END;
        // if (ch == '.' && !strchr(line, (ch - '0')))
        // {
            // perror("Error: there are more points in the number");
        //     return (INVALID);
        // }
        if(ch == '.')
        {
            line[i++] = ch;

            while (((ch = getchar()) != EOF || ch =='\n')&& isdigit(ch))
            {
                line[i] = ch;
                ++i;
                // ch = getchar();
            }
        if (ch == '\n' || ch == EOF)
            return END;
        }  
    // }
    line[i] = '\0';
    return NUMBER;
}

void operator_plus(stack* st)
{
    double op1 = 1;
    double op2 = 1;
    if (!isEmpty(st))
    {

        op1 = pop(st);
        // printf("%f\n", op1);
    }
    else
    {
        // perror("Error: Invalid count of operand (plus)");
        return ;
    }
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
    {
        // perror("Error: Invalid count of operand (plus)");
        return ;
    }
    // printf("%f, %f\n", op1, op2);
    push_back(st, op1 + op2);
}


void operator_minus(stack* st)
{
    double op1 = 0;
    double op2 = 0;
    if (!isEmpty(st))
    {
        op1 = pop(st);
    }
    else
    {
        // perror("Error: Invalid count of operand (minus)");
        return ;
    }
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
    {
        // perror("Error: Invalid count of operand (minus)");
        return ;
    }
    push_back(st, op1 - op2);
}

void operator_multipl(stack* st)
{
    double op1 = 0;
    double op2 = 0;
    if (!isEmpty(st))
    {
        op1 = pop(st);
    }
    else
    {
        // perror("Error: Invalid count of operand (multiplication)");
        return ;
    }
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
    {
        // perror("Error: Invalid count of operand (multiplication)");
        return ;
    }
    push_back(st, op1 * op2);
}

void operator_divide(stack* st)
{
    double op1 = 0;
    double op2 = 0;
    if (!isEmpty(st))
    {
        op1 = pop(st);
    }
    else
    {
        // perror("Error: Invalid count of operand (division)");
        return ;
    }
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
    {
        // perror("Error: Invalid count of operand (division)");
        return ;
    }
    if (op1 == 0)
    {
        // perror("Error: Cann't divide by zero!");
        return ;
    }
    printf("op1 = %f op2 = %f\n", op1, op2);
    push_back(st, op2 / op1);
}
