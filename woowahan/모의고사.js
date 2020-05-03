function supo1Num(n) {
  const number = n % 5;
  if (number === 0) return 1;
  else if (number === 1) return 2;
  else if (number === 2) return 3;
  else if (number === 3) return 4;
  else return 5;
}
function supo2Num(n) {
  if (n % 2 === 0) return 2;
  const number = n % 8;
  if (number === 1) return 1;
  else if (number === 3) return 3;
  else if (number === 5) return 4;
  else if (number === 7) return 5;
}
function supo3Num(n) {
  const number = n % 10;
  if (number <= 1) return 3;
  else if (number <= 3) return 1;
  else if (number <= 5) return 2;
  else if (number <= 7) return 4;
  else if (number <= 9) return 5;
}
function solution(answers) {
  var answer = [];
  let supo1 = 0,
    supo2 = 0,
    supo3 = 0;
  const len = answers.length;
  for (let i = 0; i < len; i++) {
    if (supo1Num(i) === answers[i]) supo1++;
    if (supo2Num(i) === answers[i]) supo2++;
    if (supo3Num(i) === answers[i]) supo3++;
  }
  const supos = [supo1, supo2, supo3];
  let max = 0;
  for (let value of supos) {
    if (value > max) max = value;
  }
  for (let index in supos) {
    if (supos[index] === max) answer.push(Number(index) + 1);
  }
  return answer;
}


/*
function solution(answers) {
  var answer = [];
  let a1 = [1, 2, 3, 4, 5];
  let a2 = [2, 1, 2, 3, 2, 4, 2, 5];
  let a3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  let a1c = answers.filter((value, index) => value === a1[index % a1.length])
    .length;
  let a2c = answers.filter((value, index) => value === a2[index % a2.length])
    .length;
  let a3c = answers.filter((value, index) => value === a3[index % a3.length])
    .length;

  let max = Math.max(a1c, a2c, a3c);
  if (a1c === max) answer.push(1);
  if (a2c === max) answer.push(2);
  if (a3c === max) answer.push(3);
  return answer;
}

*/