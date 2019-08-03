## 定点化
例如：有两个整数a,b，可以计算出：  
ans1 = (a+b)/(1<<q)   （1）  
ans2 = fa + fb = (a/(1<<q)) + (b/(1<<q)) （2）   
**说明**：ans1与ans2的计算结果近似相等，ans2的计算为浮点计算，先将fa左移q位并取整得到a，同理fb，利用式（1）进行计算，这个过程就叫做**定点化**运算。
## 参考资料
[1] Fixed_Point_Arithmetic_on_the_ARM.pdf