#include "postfix.h"


double evaluate_postfix_expression (char ** expr , int nterms)
{
	
	struct double_stack * stack = double_stack_new(nterms);
	double value = 0;
	double value1;
	double value2;
	double result;


	for(int i=0; i < nterms ; i++)
	{
           	
		if(*expr[i] <= '9' && *expr[i] >= '0')
		{
			value = atof(expr[i]);
			double_stack_push(stack,value);
		}
		else
		{
			if(strlen(expr[i]) == 1) 
 			{

				// if (expr[i][0] == '^' || '/' || 'x' || '+' || '-')
				int operator = -1;
				if	(*expr[i] == '+') 	operator = 0;
				else if	(*expr[i] == '-') 	operator = 1;
				else if	(*expr[i] == 'X')	operator = 2;
				else if	(*expr[i] == '/')	operator = 3;
				else if	(*expr[i] == '^')	operator = 4;
				

				//may be an operator
				switch(operator)
				{

					case 0:
						value1 = double_stack_pop(stack);
						value2 = double_stack_pop(stack);
						result = value1 + value2;
						double_stack_push(stack,result);
						break;

					case 1:
						value1 = double_stack_pop(stack);
						value2 = double_stack_pop(stack);
						result = value2 - value1;
						double_stack_push(stack,result);
						break;

					case 2:
						value1 = double_stack_pop(stack);
						value2 = double_stack_pop(stack);
						result = value1 * value2;
						double_stack_push(stack,result);
						break;

					case 3:
						value1 = double_stack_pop(stack);
						value2 = double_stack_pop(stack);
						result = value2/value1;
						double_stack_push(stack,result);
						break;

					case 4:
						value1 = double_stack_pop(stack);
						value2 = double_stack_pop(stack);
						result = pow(value2,value1);
						double_stack_push(stack,result);
						break;

					default:
						//printf("code exited \n");
						//exit(1);
						break;
			       }
			} 
			else 
			{
				double_stack_push(stack, atof(expr[i]));
			}
		}

	}
	value = double_stack_pop(stack);
	return value;
}





