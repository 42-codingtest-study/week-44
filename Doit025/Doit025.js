//문제: Doit025
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [N, M] = input.shift().split(" ").map(Number);
    const ARR = Array.from({ length: N }, () => []);
    const VISITED = Array.from({ length: N }, () => false);
    for (let i = 0; i < M; i++) {
        const [a, b] = input[i].split(" ").map(Number);
        ARR[a].push(b);
        ARR[b].push(a); //양방향
    }
    let answer;
    const DFS = (index, depth) => {
        //DFS 재귀로 구현
        if (depth === 5) {
            // 뎁스가 5번째까지 들어가면 ABCDE 달성
            answer = true; // flag
            return;
        }
        VISITED[index] = true;
        ARR[index].forEach((e) => {
            if (!VISITED[e]) {
                DFS(e, depth + 1);
            }
        });
        VISITED[index] = false;
    };
    for (let i = 0; i < N; i++) {
        DFS(i, 1);
        if (answer) break;
    }
    if (answer) console.log(1);
    else console.log(0);
}
