# 图像分割中常用Loss

## Dice

目前医学图像分割中最常用（？）的评价指标，在V-net论文中被提出。

Dice可以理解为是两个轮廓区域的相似程度，用A、B表示两个轮廓区域所包含的点集，定义为：
$$DSC(A,B)=2 \frac{|A\cap B|}{|A|+|B|}$$
作为loss使用时，应取其负值进行优化。

以下代码中，`y_true`和`y_pred`均为0-1点集。故在使用之前要通过阈值将输出结果二值化。

```python

def dice_coef(y_true, y_pred, smooth=1):
    intersection = K.sum(y_true * y_pred, axis=[1,2,3])
    union = K.sum(y_true, axis=[1,2,3]) + K.sum(y_pred, axis=[1,2,3])
    return K.mean( (2. * intersection + smooth) / (union + smooth), axis=0)
def dice_coef_loss(y_true, y_pred):
    1 - dice_coef(y_true, y_pred, smooth=1)
```

## IoU

交并比，定义为：
$$IoU=\frac{I(X)}{U(X)}$$
其中，
$$I(X)=X*Y$$
$$U(X)=X+Y-X*Y$$
可见，IoU与dice较为类似，但IoU将X与Y区域的重复计算部分删去了。

```python
def IoU(y_true, y_pred, eps=1e-6):
    if np.max(y_true) == 0.0:
        return IoU(1-y_true, 1-y_pred) ## empty image; calc IoU of zeros
    intersection = K.sum(y_true * y_pred, axis=[1,2,3])
    union = K.sum(y_true, axis=[1,2,3]) + K.sum(y_pred, axis=[1,2,3]) - intersection
    return -K.mean( (intersection + eps) / (union + eps), axis=0)
```

真的会有人用IoU当作loss吗？至少我到现在还没见过

## Focal loss

暂时没用过，先不写

---

## [loss合集](https://github.com/JunMa11/SegLoss)
