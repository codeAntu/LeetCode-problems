
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;

  
        Set<Integer> set = new HashSet<>();

        for (int num : nums) {
            set.add(num);
        }

        while (head != null) {
            if (set.contains(head.val)) {
                prev.next = head.next;
            } else {
                prev = head;
            }
            head = head.next;
        }


        
        return dummy.next;
    }
}