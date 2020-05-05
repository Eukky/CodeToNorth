# 变换

OpenGL中图形的变换通过矩阵的运算来完成。此处不再赘述向量与矩阵的运算规则。

## 缩放

对一个向量进行缩放就是对向量的长度进行缩放，而保持它的方向不变。由于我们进行的是2维或3维操作，我们可以分别定义一个有2或3个缩放变量的向量，每个变量缩放一个轴(x、y或z)。

如果我们把缩放变量表示为`(S1,S2,S3)`，我们可以为任意向量`(x,y,z)`，定义一个缩放矩阵：

$$ \left[ \begin{matrix}
    S_1 & 0 & 0 & 0 \\
    0 & S_2 & 0 & 0 \\
    0 & 0 & S_3 & 0 \\
    0 & 0 & 0 & 1
\end{matrix} \right] \cdot \left( \begin{matrix}
    x \\ y \\ z \\ 1
\end{matrix}\right) = \left( \begin{matrix}
    S_1 \cdot x \\ S_2 \cdot y \\ S_3 \cdot z \\ 1
\end{matrix}\right) $$

## 位移

位移是在原始向量的基础上加上另一个向量从而获得一个在不同位置的新向量的过程，从而在位移向量基础上移动了原始向量。

如果我们把位移向量表示为`(Tx,Ty,Tz)`，我们就能把位移矩阵定义为：

$$ \left[ \begin{matrix}
    1 & 0 & 0 & T_1 \\
    0 & 1 & 0 & T_2 \\
    0 & 0 & 1 & T_3 \\
    0 & 0 & 0 & 1
\end{matrix} \right] \cdot \left( \begin{matrix}
    x \\ y \\ z \\ 1
\end{matrix}\right) = \left( \begin{matrix}
    x + T_1 \\ y + T_2 \\ z + T_3 \\ 1
\end{matrix}\right) $$

## 旋转

旋转矩阵在3D空间中每个单位轴都有不同定义，旋转角度用$\theta$表示：

- 沿X轴旋转

$$ \left[ \begin{matrix}
    1 & 0 & 0 & 0 \\
    0 & \cos\theta & -\sin\theta & 0 \\
    0 & \sin\theta & \cos\theta & 0 \\
    0 & 0 & 0 & 1
\end{matrix} \right] \cdot \left( \begin{matrix}
    x \\ y \\ z \\ 1
\end{matrix}\right) = \left( \begin{matrix}
    x \\ \cos\theta \cdot y - \sin\theta \cdot z \\ \sin\theta \cdot y + \cos\theta \cdot z \\ 1
\end{matrix}\right) $$

- 沿Y轴旋转

$$ \left[ \begin{matrix}
    \cos\theta & 0 & \sin\theta & 0 \\
    0 & 1 & 0 & 0 \\
    -\sin\theta & 0 & \cos\theta & 0 \\
    0 & 0 & 0 & 1
\end{matrix} \right] \cdot \left( \begin{matrix}
    x \\ y \\ z \\ 1
\end{matrix}\right) = \left( \begin{matrix}
    \cos\theta \cdot x + \sin\theta \cdot z \\ y \\ -\sin\theta \cdot x + \cos\theta \cdot z \\ 1
\end{matrix}\right) $$

- 沿Z轴旋转

$$ \left[ \begin{matrix}
    \cos\theta & -\sin\theta & 0 & 0 \\
    \sin\theta & \cos\theta & 0 & 0 \\
    0 & 0 & 1 & 0 \\
    0 & 0 & 0 & 1
\end{matrix} \right] \cdot \left( \begin{matrix}
    x \\ y \\ z \\ 1
\end{matrix}\right) = \left( \begin{matrix}
    \cos\theta \cdot x - \sin\theta \cdot y \\ \sin\theta \cdot x + \cos\theta \cdot y \\ z \\ 1
\end{matrix}\right) $$

经过将多个矩阵复合，可以把任意向量沿着一个单位旋转轴进行旋转，但这个将会导致一个问题：万向节死锁。
万向节死锁的真正解决方法是使用四元数来进行3D旋转。

## 矩阵的组合

由于矩阵乘法不遵循交换律的规则，在进行矩阵组合时，需要注意他们的顺序。矩阵的乘法从右往左进行，在组合矩阵时建议先进行缩放，再进行旋转，最后进行位移，否则每一个变换之间都会互相影响。
