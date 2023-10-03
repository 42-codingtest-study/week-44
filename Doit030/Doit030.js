//문제: Doit030
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [N, M] = input[0].split(" ").map(Number);
    const ARR = input[1].split(" ").map(Number);

    let left = Math.max(...ARR);
    let right = ARR.reduce((acc, cur) => acc + cur);
    let mid = Math.floor((left + right) / 2); //중간값
    while (left < right) {
        let blueray = 1;
        let sum = 0;
        for (let i = 0; i < N; i++) {
            sum += ARR[i];
            if (sum > mid) {
                blueray += 1;
                sum = ARR[i];
            }
        }

        if (blueray <= M) {
            right = mid;
        } else {
            left = mid + 1;
        }
        mid = Math.floor((left + right) / 2);
    }

    console.log(mid);
}
