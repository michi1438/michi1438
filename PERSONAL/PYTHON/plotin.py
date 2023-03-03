import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 100)
y = np.exp(x)

plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('y=e^x')
plt.title('Exponential Func: y = e^x')
plt.show()

