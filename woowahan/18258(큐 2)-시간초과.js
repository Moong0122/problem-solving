const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
class Queue {
  constructor() {
    this._arr = [];
  }
  enqueue(item) {
    this._arr.push(item);
  }
  dequeue() {
    return this._arr.shift();
  }
  getQueue() {
    return this._arr;
  }
}

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  const instructionNum = Number(input[0]);

  const queue = new Queue();

  for (let i = 1; i <= instructionNum; i++) {
    const isa = input[i].split(" ");
    switch (isa[0]) {
      case "push":
        queue.enqueue(Number(isa[1]));
        break;
      case "pop":
        if (queue.getQueue().length === 0) console.log(-1);
        else console.log(queue.dequeue());
        break;
      case "size":
        console.log(queue.getQueue().length);
        break;
      case "empty":
        if (queue.getQueue().length === 0) console.log(1);
        else console.log(0);
        break;
      case "front":
        if (queue.getQueue().length === 0) console.log(-1);
        else console.log(queue.getQueue()[0]);
        break;
      case "back":
        if (queue.getQueue().length === 0) console.log(-1);
        else console.log(queue.getQueue()[queue.getQueue().length - 1]);
        break;
    }
  }
  process.exit();
});
