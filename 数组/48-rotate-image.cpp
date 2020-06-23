/* 48.旋转图像
题目描述：
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例1：
```
给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

示例2：
```
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```

思路：
采用分层来进行平移的方式，将矩阵的每一层都分开进行旋转，比如5*5的矩阵可以分为3层，旋转的时候，每四个矩阵块作为一组进行相应的旋转

可以看出，第二次旋转的时候比第一次旋转偏移了一格，这里我们使用add变量来记录矩阵块的偏移量，首先不考虑偏移量的时候写出左上角的坐标为(pos1,pos1),右上角的坐标为(pos1,pos2),左下角的坐标为(pos2,pos1),右下角的坐标为(pos2,pos2),则能够写出偏移之后对应的坐标


## 代码
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        if(matrix.size() == 0) return;
        int pos1 = 0, pos2 = matrix.size() - 1;
        int add;
        int temp1;
        int temp2;
        while(pos1 < pos2)
        {
            add = 0;
            while(add < (pos2 - pos1))
            {
                temp1 = matrix[pos1 + add][pos2];
                matrix[pos1 + add][pos2] = matrix[pos1][pos1 + add];

                temp2 = matrix[pos2][pos2 - add];
                matrix[pos2][pos2 - add] = temp1;

                temp1 = matrix[pos2 - add][pos1];
                matrix[pos2 - add][pos1] = temp2;

                matrix[pos1][pos1 + add] = temp1;

                add++;
            }
            pos1++;
            pos2--;
        }
    }
};
