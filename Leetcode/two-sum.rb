# https://leetcode.com/problems/two-sum/
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    indices = {}
    
    nums.each_with_index do |n1, i1|
        n2 = target-n1
        return [i1, indices[n2]] if indices.key?(n2)
        
        indices[n1] = i1
    end
end