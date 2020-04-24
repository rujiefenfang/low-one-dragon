import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt 
import seaborn as sns
import random
data = sns.load_dataset("iris")
#数据预处理
#将名称简化为01234
data.columns = ['0','1','2','3','4']
#将species setosa versicolor virginca 转化为1，2，3
data.loc[data['4']=='setosa','4']=1
data.loc[data['4']=='versicolor','4']=2
data.loc[data['4']=='virginica','4']=3
data=np.array(data)
#计算欧式距离
def distance(n1,n2):
    dist=np.sqrt(np.sum(np.power((n1-n2),2)))
    return dist
def choice(data):
    a=np.zeros(shape=(150,2))
    for i in range(150):
        dist=distance(data[i,:-1],[0,0,0,0])#计算与0向量的距离
        a[i,:]=i,dist
    df=pd.DataFrame(data=a,columns=['lable','dist']) 
    df=df.sort_values(['dist'])
    a=np.array(df)
    index=[(int)(a[24,:][0]),(int)(a[74,:][0]),(int)(a[124,:][0])] #返回三个
    return index
choice(data)
def k_means(data,k,times):
    #初始化中心簇
    #index=random.sample(list(range(150)),k)
    index=choice(data)
    k_arr=np.zeros(shape=(3,4))
    num=0
    for i in index:
        k_arr[num,:]=data[i,:-1]
        num+=1
    a=np.zeros(shape=(150,2))
    #迭代
    while(times>0):
        for j in range(150):
            min=1000
            num=0
            for i in range(3):
                dist=distance(k_arr[i,:],data[j,:-1])
                if(dist<min):
                    min=dist
                    label=i+1
            a[j,:]=j,label 
        k_arr=np.zeros(shape=(3,4))
        n1,n2,n3=0,0,0
        #重新选取中心簇，均值
        for i in range(150):
            if(a[i,:][1]==1.0):
                k_arr[0,:]=k_arr[0,:]+data[i,:-1]
                n1+=1
            if(a[i,:][1]==2.0):
                k_arr[1,:]=k_arr[0,:]+data[i,:-1]
                n2+=1
            if(a[i,:][1]==3.0):
                k_arr[2,:]=k_arr[0,:]+data[i,:-1]
                n3+=1
        k_arr[0,:]/=n1
        k_arr[1,:]/=n2
        k_arr[2,:]/=n3       
        times-=1
        return a
a=k_means(data,3,20)
def show():
    fig = plt.figure(figsize=(20,10),dpi=70)
    plt.rcParams['font.sans-serif']=['SimHei']
    x1,x2,x3=[],[],[]
    y1,y2,y3=[],[],[]
    for i in range(150):
        if(a[i,:][1]==1.0):
            x1.append(data[i,:][0]*data[i,:][1])
            y1.append(data[i,:][2]*data[i,:][3])
        if(a[i,:][1]==2.0):
            x2.append(data[i,:][0]*data[i,:][1])
            y2.append(data[i,:][2]*data[i,:][3])
        if(a[i,:][1]==3.0):
            x3.append(data[i,:][0]*data[i,:][1])
            y3.append(data[i,:][2]*data[i,:][3])
    plt.subplot(121)  
    plt.scatter(x1,y1,color='b')
    plt.scatter(x2,y2,color='g')
    plt.scatter(x3,y3,color='r')
    plt.title('聚合预估')
    plt.subplot(122)
    data1=data[:50]
    data2=data[50:100]
    data3=data[100:150]
    plt.scatter(data1[:,0]*data1[:,1],data1[:,2]*data1[:,3],color='g',label='setosa')
    plt.scatter(data2[:,0]*data2[:,1],data2[:,2]*data2[:,3],color='r',label='versicolor')
    plt.scatter(data3[:,0]*data3[:,1],data3[:,2]*data3[:,3],color='b',label='virginica')  
    plt.title('实际情况')
    plt.show()
show()





    





