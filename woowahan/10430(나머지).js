const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (line) {
  // 기본적으로 매개변수 line에 할당되는 것이 입력값이며, 문자열로 할당된다.
  const input = line.split(" ");
  const A = Number(input[0]);
  const B = Number(input[1]);
  const C = Number(input[2]);

  console.log((A + B) % C);
  console.log(((A % C) + (B % C)) % C);
  console.log((A * B) % C);
  console.log(((A % C) * (B % C)) % C);

  rl.close();
}).on("close", function () {
  process.exit();
});
