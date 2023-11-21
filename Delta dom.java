mport java.util.NoSuchElementException;
import java.util.Random;

public class RandomizedPriorityQueue<Item extends Comparable<Item>> {
    private Item[] heap;
    private int size;
    private Random random;

    public RandomizedPriorityQueue() {
        heap = (Item[]) new Comparable[1];
        size = 0;
        random = new Random();
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void insert(Item item) {
        if (size == heap.length - 1) {
            resize(2 * heap.length);
        }

        heap[++size] = item;
        swim(size);
    }

    public Item sample() {
        if (isEmpty()) {
            throw new NoSuchElementException("Priority queue underflow");
        }

        int randomIndex = random.nextInt(size) + 1;
        return heap[randomIndex];
    }

    public Item delRandom() {
        if (isEmpty()) {
            throw new NoSuchElementException("Priority queue underflow");
        }

        int randomIndex = random.nextInt(size) + 1;
        Item item = heap[randomIndex];
        swap(randomIndex, size--);
        sink(randomIndex);

        heap[size + 1] = null; // Avoid loitering

        if (size > 0 && size == (heap.length - 1) / 4) {
            resize(heap.length / 2);
        }

        return item;
    }

    // Other methods (insert, delete, swim, sink) go here...

    private void resize(int capacity) {
        Item[] temp = (Item[]) new Comparable[capacity];
        System.arraycopy(heap, 1, temp, 1, size);
        heap = temp;
    }

    private void swim(int k) {
        // Implementation of swim goes here...
    }

    private void sink(int k) {
        // Implementation of sink goes here...
    }

    private void swap(int i, int j) {
        Item temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}
