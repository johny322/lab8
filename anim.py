import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.animation as animation
import numpy as np
import pylab

#data1 = np.loadtxt("u.txt")

fig1, ax1 = plt.subplots()
fig2, ax2 = plt.subplots()
#plt.close()

ax1.set_xlim((0,1))
ax1.set_ylim((-2,2))

ax2.set_xlim((0,1))
ax2.set_ylim((-2,2))

line1, = ax1.plot([],[], lw=2, label='U(x)')
line2, = ax2.plot([],[], lw=2, label='U(t)')

ax1.grid()
ax1.legend(loc=1)
ax2.grid()
ax2.legend(loc=1)

def init1():
    line1.set_data([],[])
    return line1,

def animate1(i):
    x = np.linspace(0,1,50)
    y = np.linspace(0,1,50)
    z = np.exp(-4.0 * np.pi * np.pi * y[i]) * np.sin(2.0*np.pi * x)
    line1.set_data(x, z)
    ax1.set_title(str(i))
    return line1,

def init2():
    line2.set_data([],[])
    return line2,

def animate2(i):
    x = np.linspace(0,1,50)
    y = np.linspace(0,1,50)
    z = np.exp(-4.0 * np.pi * np.pi * y) * np.sin(2.0*np.pi * x[i])
    line2.set_data(x, z)
    ax2.set_title(str(i))
    return line2,

anim = animation.FuncAnimation(fig1, animate1, init_func=init1, frames=50, interval=100,
blit=True)

anim = animation.FuncAnimation(fig2, animate2, init_func=init2, frames=50, interval=100,
blit=True)

plt.show()

