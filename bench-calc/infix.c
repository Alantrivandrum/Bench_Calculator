#include "infix.h"



// Functions
           _Bool check_stack_empty(struct double_stack * this)
	   {
		if(this->top == 0)
		{
			return 1;
		}
		else  return 0;
	   }


/*
	   _Bool check_top_for_operator(struct double_stack * this)
	   {
		if(this->items[this->top] == 'X'||'^'||'+'||'-'||'/')
		{
			return 1;
		}
		return 0;
	   }
*/

	   _Bool prec(struct double_stack * this, char c) 
	    { 
                    if(this->items[this->top-1] == '^' && c != '^')
		    {
			return 1;
		    }
		    else if((((this->items[this->top-1] == 'X')|| (this->items[this->top-1] =='/'))) && ((c == '+'|| (c == '-'))))
		    {
				return 1;
	            }
		    else if(this->items[this->top-1] == '+' || this->items[this->top-1] == '-' && (c == 'X'|| (c == '/'))) 
                    {
			return 0;
		    } 
		    else 
		    {
				return 0;
		    }			
             }
		    




		    /*
		    if(c == '^') return 3; 
		    else if(c == 'X' || c == '/') return 2; 
		    else if(c == '+' || c == '-') return 1; 
		    else return -1; 
		    */


   double evaluate_infix_expression(char ** expr, int nterms )
   {
          char ** output = malloc(sizeof(char *) * nterms);
	  
	  int k = 0;
	  
	  

	  struct double_stack * stack = double_stack_new(nterms);
	  
	  for(int i =0; i < nterms; i++) 
	   {
		
	
		if(*expr[i] == '(')
		{	
			double_stack_push(stack, *expr[i]);
		}
		else if((strlen(expr[i]) == 1) && (*expr[i] == '+' || *expr[i] == '-' || *expr[i] == 'X' || *expr[i] == '/' || *expr[i] == '^'))

		{
	
		
			        
				while(!check_stack_empty(stack) && prec(stack, *expr[i]))
				{
					printf(" %s Operator added\n", expr[i]);
					char character = (char) double_stack_pop(stack);
					//append popped operator to output string
		                        output[k] = malloc(sizeof(character));
					*output[k] = character;
					k++;
				}	
			if(expr[i+1] != NULL)
			{
			double_stack_push(stack,*expr[i]);	
			}
			
		}
	
		else if(*expr[i] == ')')
		{

			while(stack->items[stack->top-1] != '(')   //top of stack != '('
			{
				char character = (char) double_stack_pop(stack);
				//append popped operator to output string
                                output[k] = malloc(sizeof(character));
				*output[k] = character;
				k++;
			}
			double_stack_pop(stack);     //pop left bracket

		} else {

			printf(" %s Number added\n", expr[i]);
			output[k] = expr[i];
			k++;
			}
		
	   }

	   //Finally, pop any remaining stack items and append each of them to the
	   while(!check_stack_empty(stack))
	   {
		      char character = (char) double_stack_pop(stack);
		      //append popped operator to output string
                      output[k] = malloc(sizeof(character));
		      *output[k] = character;
		      k++;
	   }
	   //end of your reverse Polish notation expression.





	  return evaluate_postfix_expression (output,k);
   }


