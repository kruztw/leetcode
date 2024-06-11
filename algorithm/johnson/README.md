* 時機
    * 多點到多點最短距離
    * 邊不多的情況下, 速度會比 Floyd-Warshall 快
* 演算法
    * 新增一個超級點到各點距離為 0
        ![](https://i.imgur.com/WMJCJHl.png)
    * Bellman-Ford 找尋 h(x) // 超級點到 x 的距離, x = |V|
    * w'(i, j) = w(i, j) + h(i) - h(j)
        * 去除負數邊 !!
    * V 個點做 Dijkstra
* 複雜度
    * time: O(V^2^ + VElogV)

[code](https://github.com/kruztw/leetcode/blob/master/algorithm/johnson/simple.cpp)
[ref](https://web.ntnu.edu.tw/~algo/Path3.html)