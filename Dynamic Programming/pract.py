import numpy as np
import matplotlib.pyplot as plt

# Generate the time array from 0 to 25 with small steps
time_values = np.arange(0, 25, 0.005)

# Define the quantization levels and codebook arrays
quantization_levels = np.arange(-1, 2.2, 0.2)
codebook = np.arange(-1, 2.2, 0.2)

# Generate an analog signal 'analog_signal' using the sine function
analog_signal = np.sin(time_values)

# Quantize the analog signal to obtain 'quantized_signal'
quantization_indices = np.digitize(analog_signal, quantization_levels) - 1
quantized_signal = codebook[quantization_indices]

# Plotting the original analog signal
plt.subplot(3, 1, 1)
plt.plot(time_values, analog_signal)
plt.title('Original Analog Signal')
plt.xlabel('Time (s) ---->')
plt.ylabel('Amplitude (V) ---->')
plt.xlim([0, 20])

# Plotting the quantized signal
plt.subplot(3, 1, 2)
plt.plot(time_values, quantized_signal)
plt.title('Quantized Signal')
plt.xlabel('Time (s) ---->')
plt.ylabel('Amplitude (V) ---->')
plt.xlim([0, 20])

# Convert the quantized signal to PCM signal
pcm_signal = np.uint8((quantized_signal - codebook[0]) / (codebook[1] - codebook[0]))

# Plotting the PCM signal
plt.subplot(3, 1, 3)
plt.plot(time_values, pcm_signal)
plt.title('PCM Signal')
plt.xlabel('Time (s) ---->')
plt.ylabel('Amplitude (V) ---->')
plt.xlim([0, 20])

# Display the plots
plt.tight_layout()
plt.show()
