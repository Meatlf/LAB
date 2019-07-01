import numpy as np
import matplotlib.pyplot as plt
import h5py
import scipy
from PIL import Image
from scipy import ndimage

# （一）数据导入和预处理
# 导入数据，“_orig”代表这里是原始数据，我们还要进一步处理才能使用：
train_set_x_orig, train_set_y, test_set_x_orig, test_set_y, classes = load_dataset()
#由数据集获取一些基本参数，如训练样本数m，图片大小：
m_train = train_set_x_orig.shape[0]  #训练集大小209
m_test = test_set_x_orig.shape[0]    #测试集大小50
num_px = train_set_x_orig.shape[1]  #图片宽度64，大小是64×64
#将图片数据向量化（扁平化）：
train_set_x_flatten = train_set_x_orig.reshape(train_set_x_orig.shape[0],-1).T
test_set_x_flatten = test_set_x_orig.reshape(test_set_x_orig.shape[0],-1).T
#对数据进行标准化：
train_set_x = train_set_x_flatten/255.
test_set_x = test_set_x_flatten/255.

# calculate the sigmoid function
def sigmoid(inX):
    return 1.0/(1+np.exp(-inX))