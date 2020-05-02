let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("");

class Stack {
  constructor() {
    this._arr = [];
  }
  push(item) {
    this._arr.push(item);
  }
  pop() {
    return this._arr.pop();
  }
  size() {
    return this._arr.length;
  }
  top() {
    return this._arr[this._arr.length - 1];
  }
}

const stack = new Stack();

const n = Number(input[0]);
for (let i = 1; i <= n; i++) {
  const isa = input[i].split(" ");
  switch (isa[0]) {
    case "push":
      stack.push(Number(isa[1]));
      break;
    case "pop":
      if (stack.size() === 0) console.log(-1);
      else console.log(stack.pop());
      break;
    case "size":
      console.log(stack.size());
      break;
    case "empty":
      if (stack.size() === 0) console.log(1);
      else console.log(0);
      break;
    case "top":
      if (stack.size() === 0) console.log(-1);
      else console.log(stack.top());
      break;
  }
}
