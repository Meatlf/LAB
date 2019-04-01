CUDA     := /usr/local/cuda


SM50     := -gencode=arch=compute_50,code=\"sm_50,compute_50\"
TARGET   := $(SM50)

CC       := $(CUDA)/bin/nvcc
NVCC     := $(CUDA)/bin/nvcc
LINK     := g++ -m64 -fPIC 
CXX      := g++ -c -m64
CCFLAGS  := -g
NVFLAGS  := -m64 --ptxas-options -v
INCLUDES := -I. -I$(CUDA)/include -I/usr/local/cuda/include
LIB      := -L$(CUDA)/lib64 -L/usr/local/cuda/lib -L/usr/local/cuda/lib64 -lcuda -lcudart -lntl -lgmp -lm

test-all: main.o 
	$(LINK)  -o test-all $^ $(LIB)
	
main.o: main.cu
	$(NVCC) -c $(NVFLAGS) $(TARGET) $(INCLUDES) $(LIB) main.cu
clean:
	rm -f test-all *.o
