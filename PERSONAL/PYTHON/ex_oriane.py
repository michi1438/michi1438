import numpy 
import matplotlib.pyplot as plt

def logamme():
    y_axis = [] 
    x_axis = [] 
    x = 0
    while (x < 1000000000):
        x = x + 1 
        x_axis.append(x)
        y_axis.append(numpy.log(x))
    plt.plot(x_axis, y_axis)
    plt.show()
    plt.close()
    

logamme()
