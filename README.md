### Overview
<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598659&page=4" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

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

### 泡泡世界的特性
基本规则：动量守恒、能量守恒

其他特性：均匀的面密度、绝对刚体、绝对光滑无机械能损失、支持任意方向的匀强力场

### 泡泡世界的起源
实习课看到前桌在玩老电脑的泡泡屏保，写了这个小玩意杀时间（我们确实很无聊...）

基于简洁的基本规则，泡泡世界自然地表现出了我们熟知的各种机械运动现象。

虽然代码很简单，效果却比较有趣，故记录于此。

### 使用说明
- 配置文件设置匀强力场大小方向、各个泡泡半径、初速度大小方向。
- 载入配置文件开始模拟，实时计算并显示每个泡泡的动能以及系统总动能。
- 泡泡颜色：动能值设置为泡泡的RGB颜色。故静止为纯黑。
- 空格键暂停/启动世界，暂停状态展示所有泡泡速度大小方向。

***

### 经典物理现象演示
#### 1. 同质量正碰的速度交换
两个泡泡的颜色在每次碰撞的瞬间恰好发生交换，而不是产生其他颜色。

<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598672&page=5" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 2. 不同质量正碰
小家伙很活泼，不断将动能传递给大家伙。大家伙的速度相对很难改变。（惯性现象）

<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598680&page=6" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 3. 自由落体
“石头和羽毛同时落地”

<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598698&page=7" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 3. 抛物运动
<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598704&page=8" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 4. 牛顿摆
<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598718&page=9" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 5. 牛顿摆-2
中间的泡泡真是不动如山啊

<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598725&page=10" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 6. 牛顿摆-3
<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598732&page=11" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 7. 躁动的随机世界
孤立系统的熵不会减少。即使泡泡世界不存在机械能-内能转化，也不会自发熵减。

那么问题来了，它有可能熵增吗？

<iframe src="//player.bilibili.com/player.html?aid=84543138&bvid=BV1b7411e7JA&cid=144598659&page=4" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

