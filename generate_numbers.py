
# select a random sample without replacement
from random import seed
from random import sample
import random
# seed random number generator
seed(1)
# prepare a sequence
for i in range(20):
    print(random.randint(1, 25)),
# select a subset without replacement