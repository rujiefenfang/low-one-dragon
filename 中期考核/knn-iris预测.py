import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt 
import seaborn as sns
data = sns.load_dataset("iris")
#查看数据前5行
#print(data.head())
#数据预处理
#将名称简化为01234
data.columns = [0,1,2,3,4]
#将species setosa versicolor virginca 转化为1，2，3
data.loc[data[4]=='setosa',4]=1
data.loc[data[4]=='versicolor',4]=2
data.loc[data[4]=='virginica',4]=3
#构造训练train和测试text数据集==8:2
train_index=[True if i%5 != 0 else False for i in range(data.shape[0])]
text_index=[True if i%5 == 0 else False for i in range(data.shape[0])]
train=data.values[train_index,:]
text=data.values[text_index,:]
print(data)
#预览
#print(train ,'\n\n' , text)
#计算欧式距离
def distance(n1,n2):
    dist=np.sqrt(np.sum(np.power((n1-n2),2)))
    return dist
#knn实现
def knn(train,text,k):
    num=0  #记录测试正确的值
    for i in range(text.shape[0]):
        a=np.zeros(shape=(train.shape[0],2))#创建一个存放标签的矩阵
        for j in range(train.shape[0]):
            dist=distance(train[j,:-1],text[i,:-1])
            a[j,:]=dist,train[j,-1]
        df=pd.DataFrame(data=a,columns=['dist','species']) 
        df=df.sort_values(['dist'])    #排序
        mode=df['species'].head(k).mode()[0]  #取众数，k为前k项
        if mode ==text[i,-1]:
            num+=1
    list1.append(num/text.shape[0])  #存储预测的准确率
list1=[]
for i in range(1,6): #k值为选取最短距离的前k项的众数
    knn(train,text,i)
print("k为1-5所对应的预测准确率为",list1)
def show():
    x=[1,2,3,4,5]
    y=list1
    plt.subplot()
    # 用来正常显示中文标签
    plt.rcParams['font.sans-serif']=['SimHei']
    plt.plot(x,y,marker='o')
    plt.xlabel('k的取值')
    plt.ylabel('正确率')
    plt.title('预测准确率随k值变化')
    for x,y in zip(x,y):
        plt.text(x,y,"(%d,%.3f)"%(x,y))
    plt.show()
show()


        







