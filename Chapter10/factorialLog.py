import logging
#Include the following line to remove all log messages within the script
#logging.disable(logging.CRITICAL)

#following are the logging levels following loggin.debug()
"""logging.info("")
logging.warning("")
logging.error("")
logging.critical("")
"""

logging.basicConfig(level=logging.DEBUG, format= " %(asctime)s - %(levelname)s - %(message)s")
logging.debug("Start of program")

def factorial(n):
    logging.debug("Start of Factorial function")
    total = 1

    for i in range(1, n + 1):
        total *= i
        logging.debug("The value of i is {}. Total is {}".format(i , total))

    logging.debug("End of factorial loop")
    return total

print(factorial(5))
logging.debug("end of the entire script")
