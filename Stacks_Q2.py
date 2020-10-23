#python program to check for balanced paranthesis


def check_balanced_paranthesis(expr):
    stack=[]
    top= -1

    for char in expr:
        if char in ["(","{","["]:
            #pushing into the stack
            #the append function in python is the push() function in stack
            #it adds an element to the top of the stack and top is incremented
            stack.append(char)
            top+=1
        else :
            top_stack = stack[top]
            if char == ")" and top_stack == "(" :
                #the pop function in python is the pop() function in stack
                #it removes an element from the top of the stack & top is decremented
                stack.pop()
                top-=1
            if char == "}" and top_stack == "{" :
                stack.pop()
                top-=1
            if char == "]" and top_stack == "[" :
                stack.pop()
                top-=1
                 
    if not stack and top == -1:
        return True
    else :
        return False


expr = input("Enter the paranthesis expression")
if check_balanced_paranthesis(expr):
    print("Yes, The Given Expression is Balanced")
else :
    print("No, The Given Expression is Not Balanced")

    
