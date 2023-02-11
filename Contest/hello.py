import matplotlib.pyplot as plt  
import numpy as np

t1 = np.arange(0, 20, 0.1)
y1 = np.sin(t1)
plt.figure(figsize=(8,8))
plt.subplot(211)
plt.plot(t1, y1)

t2 = np.arange(0, 20, 0.45)
y2 = np.sin(t2)
plt.subplot(212)
plt.stem(t2, y2)