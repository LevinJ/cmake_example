import build.cmake_example as example
import numpy as np

x = np.arange(10).reshape(2,5)

y = example(x)
print(y.get(2,0))