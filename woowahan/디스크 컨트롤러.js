function solution(jobs) {
  let total = jobs.length;
  let answer = 0; // 총 기다린 시간을 저장
  let now = 0; // 현재 시간
  let queue = []; // 작업 진행 예정

  while (true) {
    let index = 0;
    while (true) {
      if (index >= jobs.length) break; // 배열 범위 넘었으므로 break
      if (jobs[index][0] <= now) {
        // 현재 시간보다 시작 시간이 작은 값들을 큐에 저장
        queue.push(jobs.splice(index, 1)[0]);
      } else {
        // 아니라면 index+=1을 해서 다음으로 넘어가기
        index += 1;
      }
    }
    if (queue.length === 0) {
      // 큐에 아무것도 없고
      if (jobs.length === 0) {
        // jobs에도 아무것도 없다면 반복문을 끝낸다
        break;
      } else {
        // jobs에 남아 있을 경우 현재 시간이 1 지났다고 하고 넘어간다
        now += 1;
      }
    } else {
      let minIndex = 0;
      for (let i = 1; i < queue.length; i++) {
        if (queue[minIndex][1] > queue[i][1]) {
          minIndex = i; // 큐 중에서 소요 시간이 가장 작은 값을 선택
        }
      }
      now += queue[minIndex][1]; // 현재 시간이 소요 시간만큼 지났다고 해주고
      answer += now - queue[minIndex][0]; // 현재 시간에서 - 요청된 시간을 빼주면

      queue.splice(minIndex, 1);
    }
  }
  return Math.floor(answer / total);
}
