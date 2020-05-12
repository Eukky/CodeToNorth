# 最优化


## 无约束最优化

### 梯度下降法

梯度下降法是最朴实最简单而又很有效的方法，它建立在：函数<a href="https://www.codecogs.com/eqnedit.php?latex=f(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x)" title="f(x)" /></a>在<a href="https://www.codecogs.com/eqnedit.php?latex=a" target="_blank"><img src="https://latex.codecogs.com/gif.latex?a" title="a" /></a>点沿着梯度相反的方向<a href="https://www.codecogs.com/eqnedit.php?latex=-\nabla&space;f(a)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?-\nabla&space;f(a)" title="-\nabla f(a)" /></a>下降最快。（具体证明过程太长了，而且我自己没推过，暂时先不写）

<a href="https://www.codecogs.com/eqnedit.php?latex=x_n^{(i&plus;1)}=x_n^{(i)}-\eta\frac{\partial&space;f}{\partial&space;x_n}(x^{(i)})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_n^{(i&plus;1)}=x_n^{(i)}-\eta\frac{\partial&space;f}{\partial&space;x_n}(x^{(i)})" title="x_n^{(i+1)}=x_n^{(i)}-\eta\frac{\partial f}{\partial x_n}(x^{(i)})" /></a>

其中<a href="https://www.codecogs.com/eqnedit.php?latex=\eta" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\eta" title="\eta" /></a>为学习率。没啥好写的了

### 牛顿法
![](./imgs/1.jpg)

可以从两个角度来解释牛顿法：

- 代数的方法（？？）
    
    通过高中数学可知，若求函数的极小/极大值，可寻找其导数为0的点。所以，求极值问题即为求导数的零点问题~

    所以，牛顿法可以用于 1.解方程 2.最优化
    

    设<a href="https://www.codecogs.com/eqnedit.php?latex=f(x)=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x)=0" title="f(x)=0" /></a>的根为r。给出初始点<a href="https://www.codecogs.com/eqnedit.php?latex=x_0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_0" title="x_0" /></a>，过点<a href="https://www.codecogs.com/eqnedit.php?latex=(x_0,f(x_0))" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(x_0,f(x_0))" title="(x_0,f(x_0))" /></a>作与<a href="https://www.codecogs.com/eqnedit.php?latex=f(x)=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x)=0" title="f(x)=0" /></a>相交的切线，切线方程为<a href="https://www.codecogs.com/eqnedit.php?latex=y=f(x_0)&plus;f'(x_0)(x-x_0)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?y=f(x_0)&plus;f'(x_0)(x-x_0)" title="y=f(x_0)+f'(x_0)(x-x_0)" /></a>。取其与<a href="https://www.codecogs.com/eqnedit.php?latex=x" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x" title="x" /></a>轴相交的点为<a href="https://www.codecogs.com/eqnedit.php?latex=x_1" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_1" title="x_1" /></a>，则<a href="https://www.codecogs.com/eqnedit.php?latex=x_1=x_0-\frac{f(x_0)}{f'(x_1)}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_1=x_0-\frac{f(x_0)}{f'(x_1)}" title="x_1=x_0-\frac{f(x_0)}{f'(x_1)}" /></a>。虽然求得的<a href="https://www.codecogs.com/eqnedit.php?latex=x_1" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_1" title="x_1" /></a>并不能让<a href="https://www.codecogs.com/eqnedit.php?latex=f(x)=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x)=0" title="f(x)=0" /></a>，但是<a href="https://www.codecogs.com/eqnedit.php?latex=f(x_1)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x_1)" title="f(x_1)" /></a>的值比<a href="https://www.codecogs.com/eqnedit.php?latex=f(x_0)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x_0)" title="f(x_0)" /></a>更接近<a href="https://www.codecogs.com/eqnedit.php?latex=f(x)=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x)=0" title="f(x)=0" /></a>。于是就可以迭代求解了

    ！注意，此处的<a href="https://www.codecogs.com/eqnedit.php?latex=f(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x)" title="f(x)" /></a>本身即为导数（单纯是为了配合这张图）

    所以其实公式是这样的：

    <a href="https://www.codecogs.com/eqnedit.php?latex=x_{n&plus;1}=x_{n}-\frac{f'(x_n)}{f''(x_n)}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_{n&plus;1}=x_{n}-\frac{f'(x_n)}{f''(x_n)}" title="x_{n+1}=x_{n}-\frac{f'(x_n)}{f''(x_n)}" /></a>

- 泰勒公式展开

    <a href="https://www.codecogs.com/eqnedit.php?latex=f(x)=\frac{f(x_0)}{0!}&plus;\frac{f'(x_0)}{1!}(x-x_0)&plus;\frac{f''(x_0)}{2!}(x-x_0)^2&plus;...&plus;\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n&plus;R_n(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x)=\frac{f(x_0)}{0!}&plus;\frac{f'(x_0)}{1!}(x-x_0)&plus;\frac{f''(x_0)}{2!}(x-x_0)^2&plus;...&plus;\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n&plus;R_n(x)" title="f(x)=\frac{f(x_0)}{0!}+\frac{f'(x_0)}{1!}(x-x_0)+\frac{f''(x_0)}{2!}(x-x_0)^2+...+\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n+R_n(x)" /></a>

    取前两项，后面的解释同上

## 有约束最优化

### 拉格朗日乘子法
将有等式约束优化问题转为无约束优化问题。

设给定目标函数为<a href="https://www.codecogs.com/eqnedit.php?latex=f(x,y)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x,y)" title="f(x,y)" /></a>，约束条件为<a href="https://www.codecogs.com/eqnedit.php?latex=g(x,y)=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?g(x,y)=0" title="g(x,y)=0" /></a>。


看起来就像下面这个图：

![](./imgs/2.jpg)

由图可以看出，等高线与约束线相切的时候取得极值。（数学证明我也不会……待填坑）

所以就可以得到：

<a href="https://www.codecogs.com/eqnedit.php?latex=\left\{\begin{matrix}&space;&\nabla&space;f(x)=\lambda&space;\nabla&space;g(x)&space;&&space;\\&space;&g(x)=0&space;&&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?\left\{\begin{matrix}&space;&\nabla&space;f(x)=\lambda&space;\nabla&space;g(x)&space;&&space;\\&space;&g(x)=0&space;&&space;\end{matrix}\right." title="\left\{\begin{matrix} &\nabla f(x)=\lambda \nabla g(x) & \\ &g(x)=0 & \end{matrix}\right." /></a>

所以拉格朗日乘子法就是

<a href="https://www.codecogs.com/eqnedit.php?latex=L(x,\lambda)=f(x)&plus;\lambda&space;g(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?L(x,\lambda)=f(x)&plus;\lambda&space;g(x)" title="L(x,\lambda)=f(x)+\lambda g(x)" /></a>

目的就是求解上面的那个方程组。计算的时候把约束条件要改写成标准形式。

### KKT条件
当约束为不等式的时候该怎么办呢？

设给定目标函数为<a href="https://www.codecogs.com/eqnedit.php?latex=f(x,y)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x,y)" title="f(x,y)" /></a>，约束条件为<a href="https://www.codecogs.com/eqnedit.php?latex=g(x,y)=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?g(x,y)=0" title="g(x,y)=0" /></a>，<a href="https://www.codecogs.com/eqnedit.php?latex=h(x,y)\leq&space;0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?h(x,y)\leq&space;0" title="h(x,y)\leq 0" /></a>。

那么，只会有两种情况出现：极值在<a href="https://www.codecogs.com/eqnedit.php?latex=h(x,y)=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?h(x,y)=0" title="h(x,y)=0" /></a>上（黑色线上），即该约束起作用；或极值在<a href="https://www.codecogs.com/eqnedit.php?latex=h(x,y)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?h(x,y)" title="h(x,y)" /></a>的范围内（斜线范围内），约束不起作用。

![](./imgs/3.jpg)

为包含所有可能的情况，则通过解下面这个方程组来得到答案：
<a href="https://www.codecogs.com/eqnedit.php?latex=\left\{\begin{matrix}&space;&\nabla&space;f&plus;\sum_{i}^{n}\lambda&space;_i\nabla&space;g_i&plus;\sum_{j}^{m}\mu&space;_j\nabla&space;h_j=0&space;&&space;\\&space;&g_i=0,i=1,2,...,n&space;&&space;\\&space;&h_j\leq&space;0,j=1,2,...,n&space;&&space;\\&space;&\mu&space;_j&space;\geq&space;0&space;&&space;\\&space;&\mu&space;_jh_j=0&space;&&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?\left\{\begin{matrix}&space;&\nabla&space;f&plus;\sum_{i}^{n}\lambda&space;_i\nabla&space;g_i&plus;\sum_{j}^{m}\mu&space;_j\nabla&space;h_j=0&space;&&space;\\&space;&g_i=0,i=1,2,...,n&space;&&space;\\&space;&h_j\leq&space;0,j=1,2,...,n&space;&&space;\\&space;&\mu&space;_j&space;\geq&space;0&space;&&space;\\&space;&\mu&space;_jh_j=0&space;&&space;\end{matrix}\right." title="\left\{\begin{matrix} &\nabla f+\sum_{i}^{n}\lambda _i\nabla g_i+\sum_{j}^{m}\mu _j\nabla h_j=0 & \\ &g_i=0,i=1,2,...,n & \\ &h_j\leq 0,j=1,2,...,n & \\ &\mu _j \geq 0 & \\ &\mu _jh_j=0 & \end{matrix}\right." /></a>

这就是KKT条件了。


---


[在线latex转html](https://www.codecogs.com/latex/eqneditor.php)