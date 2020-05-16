# 机器学习相关

## 极大似然估计
极大似然估计就是一种在样本已知、模型已知的情况下，反推模型参数的方法。

现有样本<a href="https://www.codecogs.com/eqnedit.php?latex=x_1,x_2,...,x_N" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x_1,x_2,...,x_N" title="x_1,x_2,...,x_N" /></a>

定义似然函数<a href="https://www.codecogs.com/eqnedit.php?latex=\widetilde{L}=P(x_1;\theta)P(x_2;\theta)...P(x_N;\theta)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\widetilde{L}=P(x_1;\theta)P(x_2;\theta)...P(x_N;\theta)" title="\widetilde{L}=P(x_1;\theta)P(x_2;\theta)...P(x_N;\theta)" /></a>

用我们聪明的脑子想一想，就知道似然函数的值必定是越大越有说服力，所以我们需要求使得出现该组样本的概率最大的<a href="https://www.codecogs.com/eqnedit.php?latex=\theta" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\theta" title="\theta" /></a>值。但是现在的似然函数难以求导计算，我们可以转为取其对数进行求导。

对数似然函数为<a href="https://www.codecogs.com/eqnedit.php?latex=L=\ln&space;\widetilde{L}=\ln&space;[P(x_1;\theta)P(x_2;\theta)...P(x_N;\theta)]" target="_blank"><img src="https://latex.codecogs.com/gif.latex?L=\ln&space;\widetilde{L}=\ln&space;[P(x_1;\theta)P(x_2;\theta)...P(x_N;\theta)]" title="L=\ln \widetilde{L}=\ln [P(x_1;\theta)P(x_2;\theta)...P(x_N;\theta)]" /></a>。

极大似然估计为<a href="https://www.codecogs.com/eqnedit.php?latex=\max&space;L" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\max&space;L" title="\max L" /></a>。求导计算即可。

## 线性回归
<a href="https://www.codecogs.com/eqnedit.php?latex=\theta^T(x)=\theta_1x_1&plus;\theta_2x_2&plus;...&plus;\theta_Nx_N" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\theta^T(x)=\theta_1x_1&plus;\theta_2x_2&plus;...&plus;\theta_Nx_N" title="\theta^T(x)=\theta_1x_1+\theta_2x_2+...+\theta_Nx_N" /></a>

一般用于解决预测问题。

## 逻辑回归 Logistic Regression
虽然带着回归两个字，但是LR是个彻头彻尾的分类算法。可以把“回归”二字理解为用回归的方法来做分类。

怎么用回归的方法来做分类呢？假定我们已经对线性回归<a href="https://www.codecogs.com/eqnedit.php?latex=\theta^T(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\theta^T(x)" title="\theta^T(x)" /></a>找到了最佳参数，即已经通过线性回归找到了多个变量之间的某个规律。我们可以通过设定阈值来进行分类。但缺点是显而易见的：离群值（异常值）对结果的影响往往是巨大的。

LR的做法是把直线掰弯：<a href="https://www.codecogs.com/eqnedit.php?latex=P(y(x;\theta))=\delta&space;(\theta^Tx)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?P(y(x;\theta))=\delta&space;(\theta^Tx)" title="P(y(x;\theta))=\delta (\theta^Tx)" /></a> 其中选用sigmoid来作为决策函数：<a href="https://www.codecogs.com/eqnedit.php?latex=\delta(z)=\frac{1}{1&plus;e^{-z}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\delta(z)=\frac{1}{1&plus;e^{-z}}" title="\delta(z)=\frac{1}{1+e^{-z}}" /></a>。sigmoid的取值范围为(0,1)，在中心位置值为0.5，所以可以选取0.5作为阈值，来完成二分类任务。

![](./imgs/1.png)

设<a href="https://www.codecogs.com/eqnedit.php?latex=P(Y=1|x)=\frac{e^{wx&plus;b}}{1&plus;e^{wx&plus;b}}=\pi&space;(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?P(Y=1|x)=\frac{e^{wx&plus;b}}{1&plus;e^{wx&plus;b}}=\pi&space;(x)" title="P(Y=1|x)=\frac{e^{wx+b}}{1+e^{wx+b}}=\pi (x)" /></a>，由sigmoid的值域可知<a href="https://www.codecogs.com/eqnedit.php?latex=P(Y=0|x)=1-\pi&space;(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?P(Y=0|x)=1-\pi&space;(x)" title="P(Y=0|x)=1-\pi (x)" /></a>。推导过程如下：

<a href="https://www.codecogs.com/eqnedit.php?latex=\begin{equation}&space;\begin{aligned}&space;L(w)&=\sum_{i=1}^{N}[y_i\log&space;\pi&space;(x_i)&plus;(1-y_i&space;\log&space;(1-\pi&space;(x_i))]\\&space;&=&space;\sum_{i=1}^{N}[y_i\log&space;\frac{\pi&space;(x_i)}{(1-\pi&space;(x_i)}&plus;\log&space;(1-\pi&space;(x_i))]\\&space;&=&space;\sum_{i=1}^{N}[y_i(wx_i)-\log&space;(1-e^{wx_i})]&space;\end{aligned}&space;\end{equation}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{equation}&space;\begin{aligned}&space;L(w)&=\sum_{i=1}^{N}[y_i\log&space;\pi&space;(x_i)&plus;(1-y_i&space;\log&space;(1-\pi&space;(x_i))]\\&space;&=&space;\sum_{i=1}^{N}[y_i\log&space;\frac{\pi&space;(x_i)}{(1-\pi&space;(x_i)}&plus;\log&space;(1-\pi&space;(x_i))]\\&space;&=&space;\sum_{i=1}^{N}[y_i(wx_i)-\log&space;(1-e^{wx_i})]&space;\end{aligned}&space;\end{equation}" title="\begin{equation} \begin{aligned} L(w)&=\sum_{i=1}^{N}[y_i\log \pi (x_i)+(1-y_i \log (1-\pi (x_i))]\\ &= \sum_{i=1}^{N}[y_i\log \frac{\pi (x_i)}{(1-\pi (x_i)}+\log (1-\pi (x_i))]\\ &= \sum_{i=1}^{N}[y_i(wx_i)-\log (1-e^{wx_i})] \end{aligned} \end{equation}" /></a>

对其求偏导：
<a href="https://www.codecogs.com/eqnedit.php?latex=\frac{\partial&space;L(w)}{\partial&space;w}=\sum&space;_{i=1}^{N}[y_ix_i-\frac{e^{wx_i}}{1&plus;e^{wx_i}}x_i]=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\frac{\partial&space;L(w)}{\partial&space;w}=\sum&space;_{i=1}^{N}[y_ix_i-\frac{e^{wx_i}}{1&plus;e^{wx_i}}x_i]=0" title="\frac{\partial L(w)}{\partial w}=\sum _{i=1}^{N}[y_ix_i-\frac{e^{wx_i}}{1+e^{wx_i}}x_i]=0" /></a>

## 支持向量机 Support Vector Machine
![](./imgs/2.jpg)
支持向量机的核心思想就是在两类样本（两类的label分别为+1和-1）中寻找一个决策面，这个决策面一般表示就是<a href="https://www.codecogs.com/eqnedit.php?latex=W^TX&plus;b=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?W^TX&plus;b=0" title="W^TX+b=0" /></a>，我们需要找到一个最佳权值使得间隔最大。所以SVM的优化目标为：

<a href="https://www.codecogs.com/eqnedit.php?latex=\left\{\begin{matrix}&space;&\min&space;\frac{1}{2}||w||^2&space;&&space;\\&space;&(wx_i&plus;b)y\geq&space;1&space;&&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?\left\{\begin{matrix}&space;&\min&space;\frac{1}{2}||w||^2&space;&&space;\\&space;&(wx_i&plus;b)y\geq&space;1&space;&&space;\end{matrix}\right." title="\left\{\begin{matrix} &\min \frac{1}{2}||w||^2 & \\ &(wx_i+b)y\geq 1 & \end{matrix}\right." /></a>

再难一点的我也不会了……