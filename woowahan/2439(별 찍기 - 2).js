const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
rl.on("line", (line) => {
  const n = line.split(" ");
  for (let i = 0; i < Number(n); i++) {
    let output = "";
    for (let j = 0; j < Number(n) - i - 1; j++) output += " ";
    for (let j = 0; j < i + 1; j++) output += "*";
    console.log(output);
  }
  rl.close();
});
