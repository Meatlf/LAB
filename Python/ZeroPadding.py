# References [numpy.pad](https://docs.scipy.org/doc/numpy/reference/generated/numpy.pad.html)
import numpy as np

def zero_pad(a):
    X_pad = np.pad(a,(4,4),'constant',constant_values=(4,6))
    return X_pad

def main():
    a=[1,2,3,4,5]
    print(zero_pad(a))
    print("Hello World!")

if __name__ == '__main__':
    main()