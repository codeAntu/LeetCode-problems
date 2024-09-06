
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
}



class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList();
        dfs(root, result);
        return result;
    }

    void dfs(Node root, List<Integer> result){
        if(root==null){
            return ;
        }

       for(Node child : root.children){
        dfs(child, result);
       }
       result.add(root.val);
    }
}
