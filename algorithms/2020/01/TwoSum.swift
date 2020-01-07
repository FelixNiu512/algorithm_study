//
//  TwoSum.swift
//  algorithms
//
//  Created by Constant Cody on 1/6/20.
//  Copyright © 2020 Constant Cody. All rights reserved.
//

import Foundation

class Solution {
    
    /**
     给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

     你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

     示例:

     给定 nums = [2, 7, 11, 15], target = 9

     因为 nums[0] + nums[1] = 2 + 7 = 9
     所以返回 [0, 1]
    
     链接：https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/
     题目来源：力扣（LeetCode）
     
     /**
     时间复杂度：O(n)，
     只遍历了包含有n 个元素的列表一次。在表中进行的每次查找只花费，O(1) 的时间。

     空间复杂度：O(n)，
     所需的额外空间取决于哈希表中存储的元素数量，该表最多需要存储n 个元素。
     */
     */
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict = [Int: Int]()
        var offset: Int
        for (index, item) in nums.enumerated() {
            offset = target - item;
            if dict.keys.contains(offset) {
                return [dict[offset]!, index]
            }
            dict[item] = index
        }
        return [0, 0]
    }
}


