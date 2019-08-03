/*
功能：一个使用C实现函数的java类
编译方法：javac HelloJNI.java
参考资料：[Java Native Interface(JNI)从零开始详细教程]
(https://blog.csdn.net/createchance/article/details/53783490)
*/
public class HelloJNI{
    /* 静态代码块在这个类被类加载器加载的时候调用了
    System.loadLibrary()方法来加载一个native库“hello”
    （这个库中实现了sayHello函数）。
    这个库在windows品台上对应了“hello.dll”，
    而在类UNIX平台上对应了“libhello.so”。
    这个库应该包含在Java的库路径（使用java.library.path系统变量表示）上，
    否则这个上面的程序会抛出UnsatisfiedLinkError错误。
    你应该使用VM的参数-Djava.library.path=path_to_lib来指定包含native库的路径。
 */
    static{
        System.loadLibrary("hello");  // Load native library at runtime
                                        // hello.dll(Windows) or libhello.so(Unixes)
    }

    /* 
        使用native关键字将sayHello()方法声明为本地实例方法，
    这就很明显地告诉JVM：这个方法实现在另外一个语言中（C/C++），
    请去那里寻找他的实现。注意，一个native方法不包含方法体，只有声明。
    */
    // Declare a native method sayHello() that receives nothing and returns void
    private native void sayHello();

    // Test Driver
    /*
    main方法实例化了一个HelloJNI类的实例，
    然后调用了本地方法sayHello()。
    */ 
    public static void main(String[] args) {
        new HelloJNI().sayHello();  // invoke the native method
    }
}