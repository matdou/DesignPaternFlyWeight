import matplotlib.pyplot as plt

# Read data from the text files
data = []
data_2 = []

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

# Plot both sets of data on the same graph
plt.plot(x_values, y_values, label='Flyweight')
plt.plot(x_values_2, y_values_2, label='Without Flyweight')

# Adding titles and labels
plt.title('Memory Allocated (bytes)')
plt.xlabel('Number of Trees Created')
plt.ylabel('Memory Allocated (bytes)')

# Show grid and legend
plt.grid(True)
plt.legend()

# Show the plot
plt.show()
