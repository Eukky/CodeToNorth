# 面经

## Google 
### 软件工程师实习 一面
"Invert a function"

You are given a function F, which maps non-negative integers to non-negative integers. You know that F is **strongly** monotonically increasing: is x1 > x2, then F(x1) > F(x2).

Write code which given such a function F, and an integer y, quickly finds the clostest inverse x mapping from y - so that | F(x) - y | is minimized.

- 暴力解法的代码？时间复杂度？
- 二分解法的代码？时间复杂度？
- follow-up:
    - 如何防止溢出？
    - 二分法的右边界怎么找？

## 阿里达摩院
### 计算机视觉算法工程师实习 一面
- pooling层是如何反向传播的？
- BN层是怎么训练的？在inference阶段如何取值？
- 1x1卷积的作用？
- svm和lr的区别？
- GAN的原理？cycleGAN的原理？
- 什么是感受野？
- 分割的流程，loss的公式？
- 线程和进程的区别？

## 医准智能
### 医学图像算法工程师实习 一面
- 在项目中用到了哪些框架？
- cyclegan、pix2pix、MUNIT？优点在哪里？
- 使用cyclegan进行style transfer与（高维和低维的分别重构？）的方法的区别？
- Adam，SGD，Momentum等优化方法的优缺点？
- 正则化项L1、L2的作用？
- BN层的作用？
- GAN的论文是否熟悉？wGAN？

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
