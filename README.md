# bubble_world
A 2D world with cute bubbles that has two **fundamental principles**:

- *Conservation of momentum*
- *Conservation of energy*

And some other features:
- *Uniform areal density*
- *No loss of mechanical energy*
- *bubbles and the edges of the world are absolute rigid*
- *Uniform force field supported*

Might be useful to demonstrate the laws of mechanical motion.

Load your own config file to create a bubble_world and watch the interesting interaction of the creatures!

The kinetic energy of single bubbles and the whole world is computed and shown real-time. The color of a bubble implies its kinetic energy(mv^2), for examlpe, a stationary bubble is totally black (RGB color #000000) because its kinetic energy is zero. 

Press the space key to pause the world and show velocity.

*Authored in 2019/4*

***
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-1.gif) 
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-8.gif) 
***

### 泡泡世界的特性
基本规则：动量守恒、能量守恒

其他特性：均匀的面密度、绝对刚体、绝对光滑无机械能损失、支持任意方向的匀强力场

### 使用说明
- 配置文件设置匀强力场大小方向、各个泡泡半径、初速度大小方向。
- 载入配置文件开始模拟，实时计算并显示每个泡泡的动能以及系统总动能。
- 泡泡颜色：动能值设置为泡泡的RGB颜色。故静止为纯黑。
- 空格键暂停/启动世界，暂停状态展示所有泡泡速度大小方向。

***

### 物理现象演示
#### 1. 同质量正碰的速度交换
两个泡泡的颜色在每次碰撞的瞬间恰好发生交换，而不是产生其他颜色。

![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-2.gif) 

#### 2. 不同质量正碰

![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-3.gif) 

#### 3. 自由落体

![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-4.gif) 

#### 3. 抛物运动
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-5.gif) 

#### 4. 牛顿摆
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-6.gif) 

#### 5. 牛顿摆-2

![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-7.gif) 

#### 6. 牛顿摆-3

![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-8.gif) 

#### 7. 随机运动

![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-1.gif) 

***

### 碰撞算法

多个物体的碰撞问题是程序的关键。采用回退的方法，一旦更新后的位置不合法（即发生了碰撞）， 就回退到上一个位置，并用碰撞对应的处理方法重新更新状态， 直到每个物体的位置都是合法的，就认为处理好了碰撞。

碰撞的处理方法分为两种：一种是撞到边缘，处理方法是把一个轴方向的分速度取负。 另一种是泡泡的互相碰撞。这时需要用动量守恒和能量守恒两个方程联立来解出两个球球之后的速度。 若两个球的速度矢量分别是v1，v2，质量分别是m1，m2，则有求解公式：

*newV1=((m1-m2)\*v1+2\*m2\*v2)/(m1+m2);*

*newV2=((m2-m1)\*v2+2\*m1\*v1)/(m1+m2);*

