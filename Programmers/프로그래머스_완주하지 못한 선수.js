// https://school.programmers.co.kr/learn/courses/30/lessons/42576
function solution(participant, completion) {
    const hashmap = {};
    
    participant.forEach(m => {
        hashmap[m] = (hashmap[m] || 0) + 1;
    });
    
    completion.forEach(m => --hashmap[m]);
    
    return Object.keys(hashmap).find(key => hashmap[key] > 0);
}