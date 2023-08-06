#include "calculator.h"

// void print_stack(stack *st)
// {
//     for(int i = 0; i < st->size; ++i)
//         printf("%f ", st->data[i]);
// }

void push_back(stack* st,  double n)
{
    if (st->size == STACK_SIZE - 1)
        printf("Error: Stack already is full");
    else
    {
        st->data[st->size] = n;
        ++st->size;
    }
}

double pop(stack* st)
{
    if (st->size < 0)
        printf("Error: Stack is empty");
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
            return (INVALID);
        while (ch != EOF && isdigit(ch))
        {
            line[i] = ch;
            ++i;
            ch = getchar();
        }
        if(ch == '.')
        {
            line[i++] = ch;

            while (((ch = getchar()) != EOF || ch =='\n')&& isdigit(ch))
            {
                line[i] = ch;
                ++i;
            }
        if (ch == '\n' || ch == EOF)
            return END;
        }  
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
    }
    else
        return ;
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
        return ;
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
        return ;
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
        return ;
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
        return ;
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
        return ;
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
        return ;
    if (!isEmpty(st))
    {
        op2 = pop(st);
    }
    else
        return ;
    if (op1 == 0)
    {
        perror("Error: Cann't divide by zero!");
        return ;
    }
    push_back(st, op2 / op1);
}
