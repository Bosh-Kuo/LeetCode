typedef struct stack
{
    int val[10000];
    int top;
}stack;

bool isValid(char * s){
    stack* myStack = (stack*)malloc(sizeof(stack));
    myStack->top = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            myStack->val[myStack->top] = s[i];
            myStack->top += 1;
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            // pop
            if (myStack->top <= 0)
                return false;
            int pop = myStack->val[myStack->top-1];
            myStack->top -= 1;
            
            if (s[i] == ')' && pop != '(')
                return false;
            else if (s[i] == ']' && pop != '[')
                return false;
            else if (s[i] == '}' && pop != '{')
                return false;
        }
    }
    if (myStack->top != 0)
        return false;
    else
        return true;
}