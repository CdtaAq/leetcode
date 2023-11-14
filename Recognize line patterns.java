import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;

public class Point implements Comparable<Point> {
    private final int x;
    private final int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void draw() {
        // Implementation for drawing a point
    }

    public void drawTo(Point that) {
        // Implementation for drawing a line segment between this and that
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public int compareTo(Point that) {
        if (this.y != that.y) {
            return Integer.compare(this.y, that.y);
        } else {
            return Integer.compare(this.x, that.x);
        }
    }

    public double slopeTo(Point that) {
        if (this.x == that.x && this.y == that.y) {
            return Double.NEGATIVE_INFINITY; // Degenerate line segment
        } else if (this.y == that.y) {
            return 0.0; // Horizontal line segment
        } else if (this.x == that.x) {
            return Double.POSITIVE_INFINITY; // Vertical line segment
        } else {
            return (double) (that.y - this.y) / (that.x - this.x);
        }
    }

    public Comparator<Point> slopeOrder() {
        return Comparator.comparingDouble(this::slopeTo);
    }
}

public class LineSegment {
    private final Point p;
    private final Point q;

    public LineSegment(Point p, Point q) {
        this.p = p;
        this.q = q;
    }

    public void draw() {
        // Implementation for drawing a line segment
    }

    public String toString() {
        return p + " -> " + q;
    }
}

public class BruteCollinearPoints {
    private final ArrayList<LineSegment> segments;

    public BruteCollinearPoints(Point[] points) {
        // Implement your solution here
    }

    public int numberOfSegments() {
        return segments.size();
    }

    public LineSegment[] segments() {
        return segments.toArray(new LineSegment[0]);
    }
}

public class FastCollinearPoints {
    private final ArrayList<LineSegment> segments;

    public FastCollinearPoints(Point[] points) {
        // Implement your solution here
    }

    public int numberOfSegments() {
        return segments.size();
    }

    public LineSegment[] segments() {
        return segments.toArray(new LineSegment[0]);
    }
}

public class TestClient {
    public static void main(String[] args) {
        // Implement your sample client here
    }
}
