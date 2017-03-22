## 局部路径规划
>自用项目，用于初步开发和测试

### 参数
+ in：
  * 中心线函数表达式(e:面前从x处开始，以(x0,y0)为圆心有一个半径为r的园，可视长度为__)；  
  * 车的当前速度及车向
+ out：转弯半径

### 思路
    由已知图像信息推算可能的路径信息（是否有障碍物需分开讨论）  
    无论曲直线，总体思路为取远处一点为目标，求一较好的半径
##### 直线  
  + 取中心线较远一点为参照，求半径
  + 直线应尽量少调整，取点可考虑有一定偏移
  + **是否需要尽快回中**

##### 曲线
  + 取中心线较远一点为参照，求半径，但需保证不出赛道
  + **综合速度选取路径**

###### 直曲混合
  + 尽量走“外-内-外”切的路线，进出弯道的线路较为关键

##### S弯
  + 检测曲线交点，在保证边界条件下以交点为目标

#### 若有障碍物
  1. 提取边角信息
  2. 计算路径
  3. 回中

### 说明
+ 初版以车身动态坐标为基础，
+ **需考虑速度对转弯半径的影响**
+ 二版实现得到速度和现转弯半径后，拟合合适的路径

###问题记录
1. bicycle.c 124 while内部执行顺序
2. S弯偏出赛道检测待检验
