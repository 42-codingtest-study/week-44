//문제: Doit031
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const N = +input[0]; // 배열의 크기
    const K = +input[1]; // 찾고자 하는 수

    //
    //  mid보다 작거나 같은 수의 개수를 반환하는 함수
    //  count 값이 K보다 크거나 같으면, 우리가 찾는 값은 mid보다 작거나 같은 수 중에 있음
    //  따라서 end = mid - 1을 해주고 탐색 범위를 줄여줌
    //   count 값이 K보다 작으면, 우리가 찾는 값은 mid보다 큰 수 중에 있음
    //  따라서 start = mid + 1을 해주고 탐색 범위를 줄여줌
    //

    let start = 1; // 1부터 시작 (원소의 값은 1 이상)
    let end = N * N; // N * n까지 (원소의 값은 N * N 이하)
    let answer = 0; // k번째 수

    while (start <= end) {
        let mid = Math.floor((start + end) / 2);
        let count = 0;
        for (let i = 1; i <= N; i++) {
            count += Math.min(Math.floor(mid / i), N);
        }
        // mid보다 작거나 같은 수의 개수가 k보다 크거나 같으면
        if (count >= K) {
            answer = mid;
            end = mid - 1;
        }
        // mid보다 작거나 같은 수의 개수가 k보다 작으면
        else {
            start = mid + 1;
        }
    }
    console.log(answer);
}
