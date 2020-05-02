class Queue {
  constructor() {
    this._arr = [];
  }
  enqueue(item) {
    this._arr.push(item);
  }
  pop() {
    return this._arr.pop();
  }
  isEmpty() {
    if (this._arr.length === 0) return true;
    else return false;
  }
}

function isOkay(al1, al2) {
  // 모든 단어의 길이 동일, 한 글자 차이가 나면 true
  let alLen = al1.length;
  let different = 0;
  for (let i = 0; i < alLen; i++) {
    if (al1[i] !== al2[i]) different++;
  }
  if (different === 1) return true;
  else false;
}
function solution(begin, target, words) {
  var answer = 0;
  var targetMatchWords = false;

  for (let it of words) {
    if (it === target) targetMatchWords = true;
  }
  if (!targetMatchWords) return answer;

  const queue = new Queue();
  const wordLen = words.length;

  let check = {};
  for (let i = 0; i < wordLen; i++) {
    check[words[i]] = 0;
  }

  queue.enqueue(begin);
  check[begin] = 1;
  while (!queue.isEmpty()) {
    let cur = queue.pop();
    let curNum = check[cur];

    if (cur === target) break;
    for (let i = 0; i < wordLen; i++) {
      if (check[words[i]] === 0 && isOkay(words[i], cur)) {
        check[words[i]] = curNum + 1;
        queue.enqueue(words[i]);
      }
    }
  }
  answer = check[target] - 1;
  return answer;
}
