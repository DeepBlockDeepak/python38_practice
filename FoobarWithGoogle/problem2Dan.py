def getRadius(pegs):
    pegs.reverse() # easier for calculation
    n = len(pegs) # size of the list
    tot = 0 # total runing sum
    m = 2 # multiplication factor
    for p in pegs:
        tot = tot + (m*p)
        m = m * -1
    # we double counted the last element so remove
    # this is now -> 2Pn - 2Pn-1 + 2Pn-2 -2Pn-3 ... 2P1
    tot = tot - pegs[0]
    # check for even and odd
    a = 0
    b = 0
    result = 0
    # if it is even
    if n % 2 == 0:
        # this mean that we have -2P1 at the end of total. So we should add the P1 so total is -P1
        tot = tot + pegs[n-1] # formula for even
        a = (2 * tot)
        b = 3
    else:
        # this means that we have 2P1 at the end of total. So we should subtract P1 so total is +P1
        tot = tot - pegs[n-1]
        a = -2 * tot # formula for odds
        b = 1

    # if numenator is 0 or less than 1 since if it is less than one a is < b.
    result = a / b
    if a <= 0 or a < b:
        return [-1,-1]

    # checking and seeing if pegs and radius overlaps
    i = n - 1
    while i > 0:
        if(result + pegs[i]) >= pegs[i-1]:
            return [-1,-1]
        result = pegs[i-1] - ( result + pegs[i])
        i = i - 1

    # simplify if needed
    if a % b == 0:
        a = a / b
        b = b / b

    # return
    return [int(a),int(b)]



print(getRadius([4,32,49]))
print("==================================================")
print(getRadius([4,30,50]))
print("==================================================")
print(getRadius([6,32,56]))
print("==================================================")
print(getRadius([4,18,58,95]))
print("==================================================")
