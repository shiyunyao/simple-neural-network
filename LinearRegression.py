import numpy as np
import matplotlib.pyplot as plt
import csv

data = []
with open("housing_price_dataset.csv",mode="r",encoding="utf-8-sig") as f:
	reader = csv.reader(f)
	header = next(f)
	for row in reader:
		row[0] = int(row[0])
		row[1] = int(row[1])
		row[2] = int(row[2])
		if row[3] == "Rural":
			row[3] = 0
		elif row[3] == "Suburb":
			row[3] = 1
		else:
			row[3] = 2
		row[4] = int(row[4])
		row[5] = float(row[5])

		data.append(row)
array = np.array(data)

#Feature Scaling
means = np.mean(array,axis = 0)
std = np.std(array,axis = 0)
array = (array-means)/std

def gradient_descent(learning_rate):
	arr = np.delete(array,[5],axis = 1)
	values = np.delete(array,[0,1,2,3,4],axis = 1)
	arr = np.c_[arr,np.ones(50000)]
	variable = np.random.rand(1,6)
	J_theta = []
	for i in range(1,100):
		error = np.dot(arr,variable.T) - values
		variable = variable - learning_rate*np.sum(
			np.multiply(np.c_[error,error,error,error,error,error],arr),axis = 0)/50000
		J_theta.append(np.sum(np.multiply(error,error),axis = 0)/50000)
	return J_theta

#figure
fig = plt.figure()
ax = fig.add_subplot(111)
ax.set(xlabel='iteration',ylabel='Error')
ax.plot(range(1,100),gradient_descent(0.1),label="0.1")
ax.legend()
ax.plot(range(1,100),gradient_descent(0.2),label="0.2")
ax.legend()
ax.plot(range(1,100),gradient_descent(0.01),label="0.01")
ax.legend()
ax.plot(range(1,100),gradient_descent(0.5),label="0.5")
ax.legend()
plt.show()


