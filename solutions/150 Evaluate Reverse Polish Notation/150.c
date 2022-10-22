typedef struct Stack
{
    int stack[5000];
    int head;
}Stack;

void push(Stack *myStack, int val)
{
    myStack->stack[myStack->head] = val;
    myStack->head += 1;
}

int pop(Stack *myStack)
{
    myStack->head -= 1;
    int popValue = myStack->stack[myStack->head];
    return popValue;
}

int operation(int left, int right, char operator)
{
    if (operator=='+')
        return left + right;
    else if (operator=='-')
        return left - right;
    else if (operator=='*')
        return left * right;
    else 
        return left / right;
    
}

int evalRPN(char ** tokens, int tokensSize){
    Stack *myStack = (Stack*)malloc(sizeof(Stack));
    myStack->head = 0;
    for(int i = 0; i < tokensSize; i++)
    {
        if(strlen(tokens[i]) == 1 && !isdigit(tokens[i][0]))
        {
            int right = pop(myStack);
            int left = pop(myStack);
            int ans = operation(left, right, tokens[i][0]);
            if(i==tokensSize-1)
                return ans;
            else
                push(myStack, ans);
        }
        else
        {
            push(myStack, atoi(tokens[i]));
        }
    }
    return atoi(tokens[tokensSize-1]);
}