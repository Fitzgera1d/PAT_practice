**1021 Deepest Root**

分数 25

作者 CHEN, Yue

单位 浙江大学

A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called **the deepest root**.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer *N* (≤104) which is the number of nodes, and hence the nodes are numbered from 1 to *N*. Then *N*−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

### Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print `Error: K components` where `K` is the number of connected components in the graph.

### Sample Input 1:

```in
5
1 2
1 3
1 4
2 5
```

### Sample Output 1:

```out
3
4
5
```

### Sample Input 2:

```in
5
1 3
1 4
2 5
3 4
```

### Sample Output 2:

```out
Error: 2 components
```