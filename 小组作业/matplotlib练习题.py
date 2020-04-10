from matplotlib import pyplot as plt
import numpy as np
import seaborn as sns
data = sns.load_dataset("iris")

fig = plt.figure(figsize=(20,10),dpi=70)
plt.rcParams['font.sans-serif']=['SimHei']
#长乘以宽作为每种花瓣中每个数据的区分
data['sepal_size']=data['sepal_length']*data['sepal_width']
data['petal_size']=data['petal_length']*data['petal_width']
#分开不同种类的花瓣
data1=data[:50]
data2=data[50:100]
data3=data[100:150]
#1散点图
plt.subplot(221)
plt.scatter(data['sepal_size'],data['petal_size'])
plt.title('Size of Sepal vs Size of Petal')
plt.xlabel('size of sepal')
plt.ylabel('size of petal')

#2不同种类的散点图
plt.subplot(222)

plt.scatter(data1['sepal_size'],data1['petal_size'],color='b',label='setosa')
plt.scatter(data2['sepal_size'],data2['petal_size'],color='g',label='versicolor')
plt.scatter(data3['sepal_size'],data3['petal_size'],color='r',label='virginica')
plt.title('Size of Sepal vs Size of Petal')
plt.xlabel('size of sepal')
plt.ylabel('size of petal')
plt.legend(loc='upper left')
#3箱型图
plt.subplot(223)
sns.boxplot(y=data['sepal_size'],x=data['species'])
plt.title('Distribution of sepal_size')

plt.subplot(224)
sns.boxplot(y=data['petal_size'],x=data['species'])
plt.title('Distribution of petal_size')
plt.show()
