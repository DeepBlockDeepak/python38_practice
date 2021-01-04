#the parameter pegs, is a list of integers, which describe\n
# _ the location of pegs along a linear axis. (4 means 4 from zero)
# _ the function should return a two element list [a,b] where \n
# _ a/b is the ratio of the first gear, located at the first parameter location
# _ and the first gear should be twice the radius of the last 


def solution(pegs):
    #systems of equations for r_1 (the first radius) based on n (the length of [pegs])
    #show that every P_n (last peg) is positive. 
    #so reverse the order of pegs, and deal with the sign change in every following peg that occurs in the sytems of equations
    pegs.reverse()
    n = len(pegs)#size of the input list of pegs
    tot = 0 #total running sum
    m =2 #every Peg in the SoE (systems of equations) except, the last and first, are multiplied by a +-2
    
    for p in pegs:
        tot+= m*p
        m*=-1# every other Peg in the SoE changes sign, regardless of n
    #we now have tot = 2Pn-2P_(n-1) + 2P_(n-2)...2P_1
    #we double counted P_n, so remove it here. P_1 will be dealt with depending on signedness of n
    tot -= pegs[0]
    #check for even or odd sign of len(pegs)
    a,b= 0,0

    if n% 2 == 0:
        tot += pegs[n-1]#adding P_1 because we substracted an extra P_1 in the for loop
        a = 2* tot #the common fraction if n= even is 2/3
        b =3
    else:
        tot -= pegs[n-1]
        a = -2* tot#the common fraction if n= odd is -2 
        b =1

    result = a/b #equal to the value of the first radius
    '''
    if a<=0 or a < b : #OR might need to be an AND
        return [-1,-1]
    '''
    
    #check to see if each peg and its associated gear, overlaps the next gear
    i = n-1
    while i > 0:
        if(result + pegs[i]) >= pegs[i-1]:
            return [-1, -1]
        result = pegs[i-1] - (result + pegs[i])
        i -= 1
    #at this point 'result' will have passed the problem constraints
    if a % b == 0:
        a = a/b
        b = b/b
    
    #float values will exist at this point,, making into int()
    return [int(a),int(b)]

print(solution([4,32,49]))
print("==================================================")
print(solution([4,30,50]))
print("==================================================")
print(solution([6,32,56]))
print("==================================================")
print(solution([4,18,58,95]))
print("==================================================")
