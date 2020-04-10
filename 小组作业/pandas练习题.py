import pandas as pd 
import numpy as np 
data = {'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
        'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
        'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
        'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']}

labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
#1
df = pd.DataFrame(data,index=labels)
print(df)
print('\n动物年龄')
df0 = df[['animal','age']]
print(df0)
print('\n数据为空的行')
df1=df[df.isnull().T.any()]
print(df1)
print('\n年龄升序')
df2=df.sort_values('age',ascending=True)
print(df2)
print('\n查探降序')
df3=df.sort_values('visits',ascending=False)
print(df3)
print('\nPython交换snake')
df4=df.replace('snake','Python')
print(df4)
print('\n')

