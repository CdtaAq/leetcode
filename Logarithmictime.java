mport java.util.Collections;
import java.util.PriorityQueue;

public class DynamicMedian {
    private PriorityQueue<Integer> maxHeap; // for the lower half
    private PriorityQueue<Integer> minHeap; // for the upper half

    public DynamicMedian() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }

    public void insert(int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }

        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }

    public double findMedian() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("No elements");
        }

        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.peek() + minHeap.peek()) / 2.0;
        } else {
            return maxHeap.peek();
        }
    }

    public void removeMedian() {
        if (maxHeap.isEmpty()) {
            throw new IllegalStateException("No elements");
        }

        maxHeap.poll();

        // Rebalance heaps
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }
}
