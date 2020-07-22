## leetcode、lintcode笔记

### Typical Questions：
1. 链表反转
    - [整个反转](https://github.com/LeeeLiu/Leetcode_notes/blob/master/list/206%EF%BC%8C234.md)
    - [指定区域反转](https://github.com/LeeeLiu/Leetcode_notes/blob/master/list/92.%20Reverse%20Linked%20List%20II.md)
2. 分治：
    - [最大子列和](https://github.com/LeeeLiu/Leetcode_notes/blob/master/array/53.%20Maximum%20Subarray.md)
3. 动态规划
    - [戳气球](./DP/312.burst-balloons.md)
    - [三角形最小路径和](./DP/120.triangle.md)
    - [从左上角到右下角]
        * [最小路径和](64.minimum-path-sum.cpp)
        * [救公主-最低初始血量(需二刷)](./DP/174.dungeon-game.md)
        * [无障碍物-有多少种走法](./DP/62.Unique-Paths.md)
        * [有障碍物-有多少种走法](./DP/63.uniquePathsWithObstacles.cpp)
    - [44.通配符匹配(需二刷)](https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/)
    - [最长有效括号](./DP/32.longest-valid-parentheses.md)
    - [子序列/子串：公共长度问题]
        * [两数组公共、最长的`子序列`长度](./DP/1143.LongestCommonSubsequence.md)
        * [两数组公共、最长的`子/串数组`长度](./DP/718.maximum-length-of-repeated-subarray.md)

    - [背包系列](./backpack/背包系列.md)
    - [最值型、计数型、存在型](./summary/动态规划.md)
    - [单词拆分](./DP/139.word-break.md)
4. 排序
    - [冒泡](./sort/463.整数排序.md)
    - [快排、归并](./sort/464.整数排序II.md)
        - [利用快排，找K大/小元素](./summary/ChallengeCAT/215.KthLargestElementinanArray.md)
    - [桶/多关键字排序](./sort/multi-keyword-sort.md)
    - [最高频的前K元素](./sort/top-k-frequent-elements.md)
5. 树
    - 字典树
        * [17.13.恢复空格(需二刷)](./tree/re-space-lcci.md)：`单词拆分`DP思路会超时👉字典树+DP
        
    - [路径总和](./tree/112.path-sum.md)
    - [二叉树遍历](./tree/BinaryTreeTraversal.md)
    - [BST(binary-search-tree,二叉搜索树)]
        * [由1-n生成所有BST](./tree/95.unique-binary-search-trees-ii.md)
        * [AVL](./tree/balance-a-binary-search-tree.md)

6. 图的最短路
    - [单源-无权图](./graph/120.word-ladder.md)
    - [单源+多源有权图：Dijstra+Floyd](./graph/743.network-delay-time.md)
7. 输出所有路径
    - [单源-无权图](./graph/121.word-ladderII.md)
8. 并查集
    - [情侣牵手](./unionFind/765.couples_holding_hands.md)
9. 比特位
    - [落单数字](./bitmanipulation/136.SingleNumber.md)
10. 二分查找
    - [两数之和II：有序数组](./binarySearch/167.two-sum-ii-input-array-is-sorted.md)
        * 也可以双指针
    - [在排序数组里找插入位置](./binarySearch/search-insert-position.md)
    - [第一个错误的代码版本](./binarySearch/74.first-bad-version.cpp)
    - 旋转-排序数组类
        * [无重复元素-搜索target](./binarySearch/33.SearchinRotatedSortedArray.md)
        * [有重复元素-搜索target](./summary/ChallengeCAT/63.SearchinRotatedSortedArrayII.md)
        * [有重复元素-搜索最小数](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)
            + 遍历数组，返回第一个比首位元素小的值，就是最小值。

    - [有序矩阵中第K小的元素](./binarySearch/378.kth-smallest-element-in-a-sorted-matrix.md)
11. 买卖股票类
    - [不能同时多笔交易（交易1次→次数不限→最多2次→最多k次）👉可以同时多笔交易](./array/123.BestTimetoBuyandSellStockIII.md)
    - [含冷冻期：不能同时多笔交易-次数不限(需二刷)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/)
12. 堆
    - [215.找K大元素](./summary/ChallengeCAT/215.KthLargestElementinanArray.md)
13. 滑动窗口
    - [3.没有重复字母的最长Substring](./array/3.longest-substring-without-repeating-characters.md)
    - [209.长度最小的子数组](./array/209.minimum-size-subarray-sum.md)
14. BFS
    - [785.判断二分图](./graph/785.is-graph-bipartite.md)
    - [能否到达终点](./summary/ChallengeCAT/1479-can-reach-the-endpoint.cpp)

###  持续整理中
