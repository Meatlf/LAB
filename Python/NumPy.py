"""
功能：
        对比用numpy或for循环实现矩阵乘法
说明：
        写代码时用尽量用numpy消灭for循环
函数：

作者：
        Meatlf
参考资料：
日期：
        2019-07-01
"""
import numpy as np
import time

a = np.array([1,2,3,4])
print(a)

a = np.random.rand(1000000)
b = np.random.rand(1000000)

tic = time.time()
c = np.dot(a,b)
toc = time.time()

print("Vectorized version:" + str(1000 * (toc - tic)) + "ms")

c = 0
tic = time.time()
for i in range(1000000):
    c+=a[i]*b[i]
toc = time.time()
print("For Loop version:" + str(1000 * (toc - tic)) + "ms")
