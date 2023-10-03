//문제: Doit029
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const CHECK_ARR = input[1]
        .split(" ")
        .map(Number)
        .sort((a, b) => a - b);
    const INCLUDE_ARR = input[3].split(" ").map((n) => Number(n));

    let result = [];
    INCLUDE_ARR.forEach((e) => {
        let start = 0;
        let end = CHECK_ARR.length - 1;
        let exist = false;
        while (start <= end) {
            let mid = Math.floor((start + end) / 2);
            if (e < CHECK_ARR[mid]) {
                end = mid - 1;
            } else if (e > CHECK_ARR[mid]) {
                start = mid + 1;
            } else {
                exist = true;
                break;
            }
        }
        if (exist === true) {
            result.push(1);
        } else {
            result.push(0);
        }
    });

    console.log(result.join("\n"));
}
