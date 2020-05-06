function solution(n, lost, reserve) {
  const students = {};
  var answer = 0;
  for (let i = 1; i <= n; i++) {
    students[i] = 1;
  }
  lost.forEach((number) => students[number]--);
  reserve.forEach((number) => students[number]++);

  for (let i = 1; i <= n; i++) {
    if (students[i] === 2 && students[i - 1] === 0) {
      students[i - 1]++;
      students[i]--;
    } else if (students[i] === 2 && students[i + 1] === 0) {
      students[i + 1]++;
      students[i]--;
    }
  }
  for (let i = 1; i <= n; i++) {
    if (students[i] >= 1) answer++;
  }
  return answer;
}
