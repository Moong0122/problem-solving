function solution(participant, completion) {
  participant.sort();
  completion.sort();

  let p_len = participant.length;
  for (let i = 0; i < p_len; i++) {
    if (participant[i] !== completion[i]) {
      return participant[i];
    }
  }
}
