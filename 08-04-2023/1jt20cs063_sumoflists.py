class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    dummy_head = ListNode()
    current_node = dummy_head
    carry = 0
    
    while l1 or l2 or carry:
        sum_val = carry
        if l1:
            sum_val += l1.val
            l1 = l1.next
        if l2:
            sum_val += l2.val
            l2 = l2.next
        
        carry = sum_val // 10
        sum_val %= 10
        
        current_node.next = ListNode(sum_val)
        current_node = current_node.next
    
    return dummy_head.next
