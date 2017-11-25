/**
 * initialize your data structure here.
 */
const MinStack = function () {
    this.stack = []
    this.min = []
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function (x) {
    const stack = this.stack
    const min = this.min
    const minLen = min.length
    stack.push(x)
    if (minLen === 0) this.min.push(x)
    else if (x <= min[minLen - 1]) min.push(x)
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
    const stack = this.stack
    const min = this.min
    const minLen = min.length
    const stackLen = stack.length
    if (stack[stackLen - 1] == min[minLen - 1]) min.pop()
    return stack.pop()
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
    const stack = this.stack
    return stack[stack.length - 1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
    const min = this.min
    return min[min.length - 1]
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = Object.create(MinStack).createNew()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */