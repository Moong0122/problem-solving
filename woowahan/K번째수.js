function solution(array, commands) {
  var answer = [];
  let c_len = commands.length;
  for (let i = 0; i < c_len; i++) {
    let tmp = JSON.parse(JSON.stringify(array));
    let subPart = tmp.splice(
      commands[i][0] - 1,
      commands[i][1] - commands[i][0] + 1
    );
    subPart.sort((a, b) => a - b);
    answer.push(subPart[commands[i][2] - 1]);
  }
  return answer;
}

solution();

/*
splice는 deep copy가 발생하므로 slice를 사용하면 tmp를 따로 안 적어도 된다
*/
/*
function solution(array, commands) {
  return commands.map((v) => {
    return array
      .slice(v[0] - 1, v[1])
      .sort((a, b) => a - b)
      .slice(v[2] - 1, v[2])[0];
  });
}
*/