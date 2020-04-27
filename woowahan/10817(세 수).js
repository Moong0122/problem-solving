const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (line) {
  const arr = line.split(" ").map((n) => Number(n));
  console.log(arr.sort((a, b) => a - b)[1]);
  rl.close();
}).on("close", function () {
  process.exit();
});
