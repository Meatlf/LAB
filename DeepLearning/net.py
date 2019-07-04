import numpy as np

# 列表 sizes 包含各层神经元的数量
class Network(object):
    def __init__(self, sizes):
        self.num_layers = len(sizes)
        self.sizes = sizes
        # 生成均值为0，标准差为1的高斯分布
        self.biases = [np.random.randn(y,1) for y in sizes[1:]]
        self.weights = [np.random.randn(y, x)
            for x, y in zip(sizes[:-1], sizes[1:])]

def sigmoid(z):
    return 1.0/(1.0+np.exp(-z))

def feedforward(self, a):
    """Return the output of the network if "a" is input."""
    for b,w in zip(self.biases,self.weights):
        a=sigmoid(np.dot(w,a)+b)

net = Network([2, 3, 1])