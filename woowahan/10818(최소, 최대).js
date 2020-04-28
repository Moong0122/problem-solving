const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  const n = Number(input[0]);
  const arr = input[1].split(" ").map((n) => Number(n));
  arr.sort((a, b) => a - b);
  console.log(arr[0] + " " + arr[n - 1]);
  process.exit();
});
