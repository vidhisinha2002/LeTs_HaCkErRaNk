#!/bin/python

import math
import os
import random
import re
import sys

#
# Complete the 'extraLongFactorials' function below.
#
# The function accepts INTEGER n as parameter.
#

def extraLongFactorials(n):
    # Write your code here
    res=1
    for i in range(1,n+1):
        res=res*i
    
    print(res)

if __name__ == '__main__':
    n = int(raw_input().strip())

    extraLongFactorials(n)
