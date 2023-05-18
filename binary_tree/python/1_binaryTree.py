class TreeNode(object):
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

def constructBinaryTree(nums):
    Treelist = [None for _ in range(len(nums))]

    for i in range(len(nums)):
        if nums[i] != None:
            node = TreeNode(nums[i])
            Treelist[i] = node
        if i == 0: root = node

    i = 0
    #注意结束的规则如下
    while i * 2 + 2 < len(nums):
        if Treelist[i] != None:
            # 和c++ 构建一样，这个是关键逻辑
            Treelist[i].left = Treelist[2 * i + 1]
            Treelist[i].right = Treelist[2 * i + 2]
            i += 1
    #返回根节点
    return root

if __name__ == '__main__':

    nums = [4,1,6,0,2,5,7,None,None,None,3,None,None,None,8]
    root = constructBinaryTree(nums)
    print(root)
