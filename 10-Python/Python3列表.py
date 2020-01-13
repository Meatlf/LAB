"""
功能：

说明：


函数：

作者：

参考资料：
[Python中数组，列表：冒号的灵活用法（np数组，列表倒序）](https://blog.csdn.net/qq1483661204/article/details/78149262)
日期：
        2019-06-10
"""
import numpy as np

# 二维数组
x = np.array([[1,2,3],[5,6,7],[7,8,9]])
print(x)
print('-------')
print(x[:,::-1])
print('-------')
print(x[:,::1])
print('-------')
print(x[:,::2])
print('-------')
print(x[:,::6666])

# 三维数组
y = np.array([[[1,2,3],[5,6,7],[7,8,9]],[[1,2,3],[5,6,7],[7,8,9]]])
print(y)
print('-------')
print(y[:,:,::-1])
