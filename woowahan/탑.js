function solution(heights) {
  var answer = [];
  let h_len = heights.length;
  for (let i = h_len - 1; i >= 0; i--) {
    let tmp = heights[i];
    let send = false;
    for (let j = i - 1; j >= 0; j--) {
      if (heights[j] > tmp) {
        answer[i] = j + 1;
        send = true;
        break;
      }
    }
    if (!send) answer[i] = 0;
  }
  return answer;
}

/*
function solution(heights) {
  return heights.map((value, index) => {
    while (index) {
    index--;
      if (heights[index] > value) return index+1;
    }
    return 0;
  });
}
*/