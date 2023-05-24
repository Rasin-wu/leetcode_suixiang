https://programmercarl.com/0047.%E5%85%A8%E6%8E%92%E5%88%97II.html#%E6%8B%93%E5%B1%95

### 在做全排列二时

如果要对树层中前一位去重，就用used[i - 1] == false，如果要对树枝前一位去重用used[i - 1] == true。

对于排列问题，树层上去重和树枝上去重，都是可以的，但是树层上去重效率更高！

组合用的时 used[i-1] == false 来去重
