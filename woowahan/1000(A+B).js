const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", function (line) {
  console.log(line);
  // 기본적으로 매개변수 line에 할당되는 것이 입력값이며, 문자열로 할당된다.
  let num = line.split(" ");

  let answer = 0;
  for (const element of num) {
    answer += parseInt(element);
  }
  console.log(answer);

  // 방법 2.
  // const input = line.split(" ");
  // const answer = Number(input[0]) + Number(input[1]);

  rl.close();
}).on("close", function () {
  process.exit();
});
