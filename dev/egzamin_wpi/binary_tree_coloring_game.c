/*
Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of nodes n in the tree. n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player. In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn. If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not possible, return false.




***

To minimize the nodes for x and to maximize the node for ourselves we try to block the paths of the
x (left,right,parent)
So, we calculate the size of subtree of left , right , parent as leftSz, rightSz, n-leftSz-rightSz-1
if the max of the three values is greater then n/2 nodes then we can always win.
Please upvote if you find it helpful

*/

// cpp
class Solution {
public:
    int leftSz , rightSz , val;
    int calSize(TreeNode* node) {
       if(!node)
           return 0;
        
        if(!node->left and !node->right)
            return 1;
        
        int l = calSize(node->left) , r = calSize(node->right);
        if(val == node->val)
            {leftSz = l ; rightSz = r; }
        
        return l + r + 1;
    }
    
    
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        int cnt = calSize(root);
        
        return max({leftSz,rightSz,n-leftSz-rightSz-1}) > n/2;
    }
};
