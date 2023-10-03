//문제: Doit023
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
    const ARR = Array.from({ length: N + 1 }, () => []);
    // 연결 노드 상황 담기 index 0은 비워두자!
    const VISITED = Array.from({ length: N + 1 }, () => false);
    // 방문 배열 index 0은 안쓴다.
    let answer = 0; // 연결 요소 (뭉탱이)의 개수

    const DFS = (ARR, start) => {
        //DFS 구현
        const STACK = []; //stack활용한 DFS구현
        if (!VISITED[start])
            STACK.push(start); //방문 안한 start면 배열에 넣고 시작
        else return false; // 방문 한 적 있다면 바로 false로 끝내기 true면 연결 요소에 +1 할거임
        while (STACK.length) {
            let now = STACK.pop(); //pop으로 빼고 연결 노드 넣기
            ARR[now].forEach((e) => {
                if (!VISITED[e]) {
                    //방문안한것만 넣을거임
                    STACK.push(e);
                    VISITED[e] = true; //방문처리
                }
            });
        }
        return true; //연결 요소가 있다는 뜻
    };

    for (let i = 0; i < M; i++) {
        const [a, b] = input[i].split(" ").map(Number);
        ARR[a].push(b);
        ARR[b].push(a); //무방향이기에 둘다 추가해줌
    }
    for (let i = 1; i <= N; i++) {
        if (DFS(ARR, i)) answer++; //true면 연결요소가 있다는 뜻이니까 +1
    }

    console.log(answer);
}
