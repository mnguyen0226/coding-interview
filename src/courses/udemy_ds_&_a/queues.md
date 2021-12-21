## Note on Queues data structure
- Queue is a first in first out data structure
- Queues ADT:
    - Enqueue(x)
    - Dequeue()
    - isEmpty()
    - isFull()
    - First()
    - Last()
- Queues implemented using array
    - Queue using single pointer
        - Insert costs O(1).
        - Delete costs O(n) since you have to shift element when delete at the front of queue.
    - Queue using front and rear: one pointer is used for insertion, one pointer is used for deletion.
        - Insert costs O(1).
        - Delete costs O(1).
    - Drawbacks of Queues using array: Can't reuse space of deleted element in queue.
        - Solution 1 - Reset pointers: move both front and rear to the front only when the queue is empty
        - Solution 2 - Circular queue:
            - Leave the front pointer empty, aka don't let front and rear equal to each other.
            - Use mode-operation for circulation operator.

- Queues implemented using linked list:
    - front and rear pointers
    - If heap is full then queue will be full. Node *t = new Node; if(t == NULL)
    - if(front == NULL) then the queue is empty

- DEQueue - Double Ended Queue
    - Use both the front and rear pointers for either insertion or deletion.
    - This means that you can delete and insert either front or rear
    - There are two types:
        - Input Restricted DEQueue: front pointer can delete but can't insert, rear pointer can do both.
        - Output Restricted DEQueue: rear pointer can delete but can't insert, front pointer can do both.

- Priority Queue: 
    - Limited set of priorities - Each elements has different priority belonging to different queue. For deletion, you have to delete from the highest queue.
    - Element Priority - Unlimited priority.
