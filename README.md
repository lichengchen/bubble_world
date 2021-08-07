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

### 泡泡世界的起源
实习课见前桌玩起老电脑的泡泡屏保，写了这个小玩意杀时间（我们确实要被无聊的实习逼疯了...）

虽然代码很简单，效果却比较有趣。简洁的基本规则基础上，可以模拟出我们熟知的各种机械运动现象。

### 使用说明
- 配置文件设置匀强力场大小方向、各个泡泡半径、初速度大小方向。
- 载入配置文件开始模拟，实时计算并显示每个泡泡的动能以及系统总动能。
- 泡泡颜色：动能值设置为泡泡的RGB颜色。故静止为纯黑。
- 空格键暂停/启动世界，暂停状态展示所有泡泡速度大小方向。

***
### 经典物理现象演示
#### 1. 同质量正碰的速度交换
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-2.gif) 

#### 2. 不同质量正碰
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-3.gif) 

#### 3. 自由落体；伽利略斜塔实验
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-4.gif) 

#### 3. 平抛运动
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-5.gif) 

#### 4. 牛顿摆
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-6.gif) 

#### 4. 牛顿摆-2
中间的泡泡真是不动如山啊

![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-7.gif) 

#### 4. 牛顿摆-3
![img](https://github.com/lichengchen/bubble_world/blob/main/gifs/6-8.gif) 

