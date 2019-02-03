import build.cmake_example as example
import numpy as np
from time import time



y = 480
x = 640

# y = 2
# x = 6
x = np.arange(y*x).reshape(y,x).astype(np.uint8)
start = time()
y = example.Pet(x)
end = time()
print(x)
print(y.get_elem(479,1))
print("duration = {}".format(end - start))