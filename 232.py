class MyQueue {
    constructor() {
        this.st1 = [];
        this.st2 = [];
    }

    push(x) {
        while (this.st1.length > 0) {
            this.st2.push(this.st1.pop());
        }
        this.st1.push(x);
        while (this.st2.length > 0) {
            this.st1.push(this.st2.pop());
        }
    }

    pop() {
        return this.st1.pop();
    }

    peek() {
        return this.st1[this.st1.length - 1];
    }

    empty() {
        return this.st1.length === 0;
    }
}
