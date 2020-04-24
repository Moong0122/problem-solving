const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  let n = input[0].split(" ");
  let arr = input[1].split(" ");

  let answer = "";
  for (let i = 0; i < Number(n[0]); i++) {
    if (Number(arr[i]) < n[1]) answer += arr[i] + " ";
  }
  console.log(answer);
});
