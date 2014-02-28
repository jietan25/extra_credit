#include<stdarg.h>
#include<stdio.h>

void sum(char *, int, ...);
int product(int a, int b, int c);

int main(void)
{
  sum("The sum is %d.\n",5,1,2,3,4,5);
  printf("%d\n", product(2,3,NULL));
  return 0;
}

void sum(char *string, int num_args, ...)
{
  int sum=0;
  va_list ap;
  int loop;

  va_start(ap,num_args);
  printf("%d\n", num_args);
  for(loop=0;loop<num_args;loop++)
    {sum+=va_arg(ap,int);
	printf("%d\t", loop);//va_arg(ap, int));
     }

  printf(string,sum);
  va_end(ap);
}

int product(int a, int b, int c)
{
	return c = a * b;
}