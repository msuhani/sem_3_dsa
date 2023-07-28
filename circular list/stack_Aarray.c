#include <stdio.h>
#define MAXLEN 100
typedef struct{ 
    int element[MAXLEN];
    int top;} stack;
stack init (){
    stack S;
    S.top= -1;
    return S; 
}
int isEmpty( stack S )
{ 
    return (S.top== -1); 
    }

int isFull( stack S )
{ 
    return (S.top== MAXLEN -1); 
    }

int top ( stack S )
{ 
    if (isEmpty(S))
        printf("Empty stack\n");
    else
    return S.element[S.top]; 
}
stack push ( stack S , int x )
{ 
    if (isFull(S))
printf("OVERFLOW\n");
else
{ 
    ++S.top;
    S.element[S.top] = x;
}
return S; 
}

stack pop ( stack S )
{
     if (isEmpty(S))
        printf("UNDERFLOW\n");
    else
        { --S.top;}
        return S;
    }

void print ( stack S )
{ int i;
for (i= S.top; i>= 0; --i)
    printf("%d",S.element[i]);
     }

int main (){
    stack S;
    S = init();
    S = push(S,10);
    S = push(S,45);
    S = push(S,1);
    S = push(S,50);
    printf("Current stack : ");
    print(S);
    printf(" with top = %d.\n", top(S));
    S = pop(S);
    S = pop(S);
    printf("Current stack : ");
    print(S);
    printf(" with top = %d.\n", top(S));
    return 0;
}
