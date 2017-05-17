### 伪代码

#### 选择
```c
if(单元素) {
  if (circle) path_c;
  else path_l;
}

// 直线起始
if (第一元素为直线) {
  i=直线元素数;
  if (i==length) {
    path_l(最后一段直线);     /*warning!!*/   
  }
  else if (直线组终点过近) {
    if (接两个圆) {
      path_s();
    }
    else{
      path_c();
    }
  }
  else if (直线组终点足够远) {
    path_l()
    path_block();
  }
  else {
    if(接两圆){
      path_ls();
    }
    else{
      path_lc();
    }
  }
}
// 弯道起始
else{
  if (下一元素为直线){
    if (直线切点过远) {
      path_c();
    }
    else if (直线切点一般) {
      path_cl();
    }
    else {  /*直线切点过近*/
      path_l();             /*是否应整理直线组?*/
    }
  }
  else{   /*下一元素为圆*/
    if (当前圆足够长) {
      path_s();
    }
    else if (仅有两圆) {
      path_c(第二个圆);
    }
    else if (第三元素为圆){
      path_s();
    }
    else{
      path_cl();
    }
  }
}
```


#### √ 直线( y = kx + b )
```c
    b > or < 0(左/右);  //以下默认为右
    if (b>off) {       //位置靠外
      if (k<10°) {       //方向偏右
        同侧逼近;
        while (出界)          //k<0时有几率
          r*=0.9;
      }
      else if (k<30°){   //方向中等
        中线逼近;
        while (出界)          //几率不大
          r*=0.9;
      }
      else{              //方向偏左
        对侧逼近;
        while (出界)          //几率不大？
          r*=0.9;
      }
    }
    else {             //位置靠内
      if (k<0°) {        //方向偏右
        同侧逼近;
        while (出界)           //几率极小
          r*=0.9;
      }
      else if (k<25°) {  //方向中等
        直行;
      }
      else {             //方向偏左
        对侧逼近;
        while (出界)           //几率不大
          r*=0.9;
      }
    }
```

#### √ 曲线( x, y, r)
    y > 0 or < 0(左/右转); //以下默认右转
    赛道 (内 or 外) 侧;
    if (内道及中线){
      if (k<10°){           //方向偏右
        内切;
        while (出界){           //几率大
          if (反转向) r*=0.9;
          else{
            if (r<L) r*=1.1;
            else r*=-1;         //反打方向
          }
        }
      }
      else if (k<20°){      //方向中等
        切中线;
        while (出界){            //几率小
          if (r>L) r=L;
          else r*=1.1；
        }
      }
      else{                 //方向偏左
        外切;
        while (出界)            //几率小
          r*=0.9；
      }                  
    }
    else {
      if (k<0)              //方向偏右
        内切；
      else if (k<10°){      //方向中等
        切中线;
        while (出界)           //几率不大
          r*=0.9;
      }
      else {                //方向偏左
        外切;
        while (出界)           //有几率
          r*=0.9;
      }
    }

#### √ 入单弯(l1, c1)
至直曲交点

    求交点;
    if (内道+off){
      if (x交点>500) 走外道;
      else 走交点;
    }
    else {
      if (x交点>200) 走外道;
      else 保证直道方向入弯;
    }

#### √ 出单弯(c1, l1)
至曲直交点

    求交点;
    if (x交点>200) 走外道;
    else 保证直道方向出弯;

#### √ S弯(c1, c2)  
    求两圆交点，即S弯中点;
    走交点;
    while (出界){           
      if (反转向) r*=0.9;
      else{
        if (r<L) r*=1.1;
        else r*=-1;         //反打方向
      }
    }

#### √ 入S弯(l1, c1)
    求直曲交点;
    走交点，保证直线方向;

#### √ 障碍(l1, p1, p2)
    if (p1.x>200) 垂直p1安全点逼近，出界检测点p1
    else if (p2.x>100) 垂直p2安全点逼近，出界检测线p1p2;
    else 中线逼近，出界检测点p2;
