#ifndef CALCULATOR_H
#define CALCULATOR_H

//Colors Start
#define RESET	"\033[0m"
#define GREEN   "\x1B[32m"
#define RED		"\033[31m"
//Colors End

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_DOUBLE 100
#define STACK_SIZE 100

typedef enum {
    PLUS,
    MINUS,
    DIVIDE,
    MULTIPL,
    NUMBER,
    INVALID,
    END
} Operator;

typedef struct
{
	double data[STACK_SIZE];
    size_t size;
}		    stack;

Operator read_line(char *);
void push_back(stack*,  double );
double pop(stack*);
int isEmpty(stack*);

//operаtors
void operator_plus(stack*);
void operator_minus(stack*);
void operator_multipl(stack*);
void operator_divide(stack*);

// // not important
// void print_stack(stack *st);
#endif