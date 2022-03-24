# 3-ways-to-calculate-Fibonacci
3种不同的方法实现对于斐波那契的计算，包括定义递归、分治、动态规划
# 1.定义的递归方法

递归可以由定义得出

$f(n) = \{0$   $n=0$

		  $1$   $n=1$

		  $f(n-1) + f(n-2)$  $n\geq2$ 

```c++
int fib(int n){
    if(n<2) return n;
    else 
        return fib(n-1)+fib(n-2);
}
```

根据斐波那契数列的通项公式计算可以得到$T(n) = \theta(1.618^n)$



# 2.动态规划的迭代算法

```c++
int fib(int n){
    f2 = 0,f1=0,f;
    if(n<2) return n;
    else{
        for(k=2;k<=n;k++){
            f = f1+f2;
            f2 = f1;
            f1 = f;
        }
    }
    return f;
}
```

复杂度为$O(n)$

# 3.迭代的分治算法

```c++
int fib(n){
    S = [1,0;0,1];
    T = [1,1;1,0];
    
    q = n+1;
    while(b>0){
        if mod(q,2){
            S = S*T;
        }
        T = T*T;
        q = q/2;
    }
    return S[1][1];
}
```

复杂度为$
