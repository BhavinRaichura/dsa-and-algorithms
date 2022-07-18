## Properties: 
    1. The left subtree of a node contains only nodes with keys less than the node’s key.
    2. The right subtree of a node contains only nodes with keys greater than the node’s key.
    3. Both the left and right subtrees must also be binary search trees
    4. No two nodes data is same.
    5. Inorder traversal of BST is give output in assending order
    
 ## Inorder Traversal of BST
               6
             /   \
           3      8   
         /  \    /  \
        1    4  7    9
        
        inorder Traversal :  1, 3, 4, 6, 7, 8, 9 
        
## BTS to min-heap and max-heap
given BST se array me data collect in-order me data collect karenge and for
[1. BTS to max heap](https://github.com/BhavinRaichura/algo/blob/main/binary%20search%20tree/BST%20to%20max%20heap.cpp)
 ke liye data ko post-order traversal se put krte jayenge
[2. convert BST to min heap](https://www.geeksforgeeks.org/convert-bst-min-heap/)
 ke liye data ko pre-order traversal se put krte jayenge
