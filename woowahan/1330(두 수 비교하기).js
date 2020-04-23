const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (line) {
  const input = line.split(" ");
  if (Number(input[0]) > Number(input[1])) console.log(">");
  else if (Number(input[0]) < Number(input[1])) console.log("<");
  else console.log("==");

  rl.close();
}).on("close", function () {
  process.exit();
});
