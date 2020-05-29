import numpy as np
import pylab
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

data1 = np.loadtxt("u.txt")
data2 = np.loadtxt("U_.txt")

fig = plt.figure('Practical')
ax = fig.add_subplot(111, projection='3d')
ax.scatter(data1[:,0],data1[:,1],data1[:,2], s = 2)


u, v = np.mgrid[0:1:0.02, 0:1:0.02]
x = u
y = v
z = np.exp(-4.0 * np.pi * np.pi * y) * np.sin(2.0*np.pi * x)
fig = plt.figure('Analitic')
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x, y, z, cmap='inferno')
ax.legend()

fig3 = plt.figure('Difference')
ax3 = fig3.add_subplot()
ax3.plot(data1[:,0], data1[:,2]-data2[:,2], 'r')
ax3.legend(loc='best')
ax3.grid()


plt.show()





