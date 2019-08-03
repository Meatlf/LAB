/*
在Java和Native代码之间传递参数和返回值
功能：传递基本类型
说明：这个JNI程序加载了myjni.dll（windows）库
或者libmyjni.so（类UNIX）库。
并且声明了一个native方法，这个方法接受两个int类型的参数，
并且返回一个double类型的返回值，
这个值是两个int型数的平均值。
mian方法调用了average函数。 
 */
public class TestJNIPrimitive{

    // myjni.dll (Windows) or libmyjni.so (Unixes)
    static{
        System.loadLibrary("myjni");
    }

    // Declare a native method average() that receives two 
    // ints and return a double containing the average
    private native double average(int n1, int n2);

    // Test Driver
    public static  void main(String  args[]){
        System.out.println("In Java, the average is  " + new TestJNIPrimitive().average(3, 4));
    }
}