"""
Given a positive integer n, find the smallest number
of squared integers which sum to n.

Ex: given n = 13, return 2, since 13 = 2^2 + 3^2 = 9 + 4
given n = 27, return 3, since 27 = 3^2 + 3^2 + 3^2 = 9 + 9 + 9

"""

def finding_squares(limit):
    for x in range(1, limit):
        y = x + 1
        z = y + 1

        while z <= limit:

            while z**2 < x**2 + y **2:
                z += 1
            
            if z**2 == x**2 + y**2 and z <= limit:
                pass
                #print("{} = {}^2 + {}^2".format(z,x,y))
                #print("-"*50)
            y = y + 1
