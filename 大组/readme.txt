小数据多次排序,归并算法崩溃了,看样子是malloc崩溃的,但是我明明有free.
采用的办法是无脑的重新制造一些数据,因为制造数据是在计时点中间进行的,因此测试时间不太准确.
尝试了在函数里复制原来的数据,也不是很好的办法.
现在能想到的最后一个办法是先制造100*10k个数据,然后每次排100个数据,但是还不知道怎么实现.

计数排序有bug找了很久没找出来.bug是排完最大或最小的没了.
