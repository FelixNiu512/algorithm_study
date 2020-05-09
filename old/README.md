> 生命不息，学习不止

## 2020年

### 1月 

1. [模拟栈操作](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2020/01/StackSimulator.h)

2. [二分查找](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2020/01/BinarySearch.h)

3. [字符串反转](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2020/01/ReverseString.h)

4. [有序数组合并](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2020/01/ArrayMergeArray.h)

5. [两数相加(链表)](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2020/01/NumberCalculation.h)，来源：[leetcode题库第2题](https://leetcode-cn.com/problems/add-two-numbers/)

6. [两数之和](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2020/01/TwoSum.swift)，来源：[leetcode题库第1题](https://leetcode-cn.com/problems/two-sum/)

## 2019年

### 12月

1. [交换A和B的值](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2019.12/SwapNumber.h)
> 不借助中间变量：异或；加法。

2. [求最大公约数](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2019.12/GreaterCommonDivisor.h)
> 辗转相除法：循环；递归。    
> 更相减损法（等值算法）

3. [排序算法](https://github.com/ConstantCody/algorithm_study/blob/master/algorithms/2019.12/SortNumber.h)
* 冒泡排序：时间复杂度o(n²)
* 选择排序：时间复杂度o(n²)
* 直接插入排序：时间复杂度o(n²)
> 说明：将一个数据插入到一组已经排好序的序列当中，插入后该序列依旧是有序的。
* 快速排序：时间复杂度平均o(nlogn)，最差o(n²)
> 说明：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。    
> 步骤：1. 取一个数作为基准数 2. 分区：将比这个数大的放右边，小的放左边 3. 重复1、2，直到各区间只有一个数
* 希尔排序：时间复杂度：o(n^(1.3-2))
> 说明：是直接插入排序的升级版本，又称为“缩小增量排序”，其主要思想是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组
* **堆排序：时间复杂度o(nlogn)，未消化**