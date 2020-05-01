const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function checkHan(number) {
  if (number < 100) return true;
  else {
    const numberStr = String(number);
    const first = Number(numberStr[1]) - Number(numberStr[0]);
    for (let i = 2; i < numberStr.length; i++) {
      if (Number(numberStr[i]) - Number(numberStr[i - 1]) !== first)
        return false;
    }
  }
  return true;
}

rl.on("line", function (line) {
  const n = Number(line);
  let answer = n;

  for (let i = 1; i <= n; i++) {
    if (!checkHan(i)) answer--;
  }
  console.log(answer);
  rl.close();
}).on("close", function () {
  process.exit();
});
