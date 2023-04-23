When we are dequeuing, we have to dequeue the element with highest priority. 
We shouln't voilate the basic rule that, deletions occur at front. So with this
the element with highest priority must be at front position.

In order to satisfy the above said point, after inserting we have to reaarange the 
queue. We shouldn't insert at the correct position [according to priority] at the time
of inserting itself. This is so because insertions must always happens at rear.


