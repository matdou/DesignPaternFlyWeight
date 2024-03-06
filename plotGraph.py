import matplotlib.pyplot as plt

# Read data from the text file
data = []
data_2 = []
#file in data folder
with open('data/flyweight.txt', 'r') as file:
    for line in file:
        data.append([int(x) for x in line.strip().split()])

with open('data/simpleForest.txt', 'r') as file:
    for line in file:
        data_2.append([int(x) for x in line.strip().split()])

# Separate x and y values
x_values = [item[0] for item in data]
y_values = [item[1] for item in data]

x_values_2 = [item[0] for item in data_2]
y_values_2 = [item[1] for item in data_2]

# Plot the graph
plt.plot(x_values, y_values)

plt.title('Memory Allocated (bytes) - Flyweight')
plt.xlabel('number of trees created')
plt.ylabel('Memory Allocated (bytes) - Flyweight')
plt.grid(True)
plt.show()

plt.plot(x_values_2, y_values_2)
plt.title('Memory Allocated (bytes) - Without Flyweight')
plt.xlabel('number of trees created')
plt.ylabel('Memory Allocated (bytes)')
plt.grid(True)
plt.show()

