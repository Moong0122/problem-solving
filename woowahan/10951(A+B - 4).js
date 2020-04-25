const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  let len = input.length;
  for (let i = 0; i < len; i++) {
    let n = input[i].split(" ");
    console.log(Number(n[0]) + Number(n[1]));
  }
  process.exit();
});
