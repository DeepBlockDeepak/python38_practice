#!python3

import random, sys
from transposition_cipher import transposition_encrypt, transposition_decrypt

"""
#alternative method of importing methods in the transposition_cipher.py script
#chose not to use this because it's even uglier than what happens in C scripts, which are quite nice on this front actually

import transposition_cipher as tc
print(tc.transposition_encrypt(3, doggo))
"""

def main():

    random.seed(42) 

    for i in range(20): #run 20 tests
        message = "ABCDEFGHIJKLMNOQRSTUVWXYZ" * random.randint(4, 40)
        message = list(message)

        random.shuffle(message)

        message = "".join(message)    #now message is a larger, scrambled version of its original self

        print("Test #{}: '{}...'\n".format(i + 1, message[:50]))


        for key in range(1, int(len(message)/2)):
            encrypted = transposition_encrypt(key, message)
            decrypted = transposition_decrypt(key, encrypted)

            if message != decrypted:
                print("Mismatch with key = {} and message {}".format(key, message))

                print("Decrypted as: " + decrypted)

                sys.exit()
    print("Transposition cipher test passed.")
    
if __name__ == "__main__":
    main()

