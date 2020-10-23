#This program is solved in the hackerrank website !!works only for the specified input

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equalStacks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY h1
#  2. INTEGER_ARRAY h2
#  3. INTEGER_ARRAY h3
#


def equalStacks(h1, h2, h3):
    #reversing the given input list to represent it as a stack
    h1 = h1[::-1]
    h2 = h2[::-1]
    h3 = h3[::-1]
    
    #calculating the total sum of all individual stacks
    #(i.e, sum is equal height of the stack)
    sum1 = sum(h1)
    sum2 = sum(h2)
    sum3 = sum(h3)
    

    while(True):
        #finding the least height of the stack
        minheight = min(sum1,sum2,sum3)

        #loop terminating base case
        if minheight == 0:
            return 0
        
        #Reduce the height of the higher stacks 
        #till all of them reach to a similar height

        if minheight < sum1 :
            #subtract the height with the top element in the stack
            sum1 -= h1.pop()
        elif minheight < sum2 :
            sum2 -= h2.pop()
        elif minheight < sum3 :
            sum3 -= h3.pop()

        #if all the heights are the same then return the value
        if (sum1==sum2==sum3):
            return sum1



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n1 = int(first_multiple_input[0])

    n2 = int(first_multiple_input[1])

    n3 = int(first_multiple_input[2])

    h1 = list(map(int, input().rstrip().split()))

    h2 = list(map(int, input().rstrip().split()))

    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)

    fptr.write(str(result) + '\n')

    fptr.close()
