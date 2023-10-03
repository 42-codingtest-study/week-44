//문제: Doit024
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const answer_arr = [
    `2
3
5
7`,
    `23
29
31
37
53
59
71
73
79`,
    `233
239
293
311
313
317
373
379
593
599
719
733
739
797`,
    `2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393`,

    `23333
23339
23399
23993
29399
31193
31379
37337
37339
37397
59393
59399
71933
73331
73939`,

    `233993
239933
293999
373379
373393
593933
593993
719333
739391
739393
739397
739399`,

    `2339933
2399333
2939999
3733799
5939333
7393913
7393931
7393933`,

    `23399339
29399999
37337999
59393339
73939133`,
]; //이것도 안됨 걍 하지말라는듯..
solution(input);
// solution("1");
// console.log("\n");
// solution("2");
// console.log("\n");
// solution("3");
// console.log("\n");
// solution("4");
// console.log("\n");
// solution("5");
// console.log("\n");
// solution("6");
// console.log("\n");
// solution("7");
// console.log("\n");
// solution("8");

function solution(input) {
    let n = +input[0];
    console.log(answer_arr[n - 1]);
    // const IS_PRIME = (n) => {
    //     // 소수 확인 함수
    //     let root = Math.sqrt(n);
    //     for (let i = 2; i <= root; i++) {
    //         //루트 까지만 확인해도 된대요!
    //         if (n % i == 0) {
    //             return false;
    //         }
    //     }
    //     return true; //소수면 true 아니면 false
    // };
    // const N = +input[0];
    // let answer = "";
    // const SOSU_ARR = [1, 3, 7, 9]; // 첫 자리 빼고는 뒤에 1,3,7,9만 들어올 수 있다
    // const DFS = (num, len) => {
    //     if (len === N) {
    //         if (IS_PRIME(num)) {
    //             answer += num;
    //             answer += "\n";
    //         }
    //         return;
    //     }
    //     SOSU_ARR.forEach((e) => {
    //         if (IS_PRIME(num * 10 + e)) {
    //             DFS(num * 10 + e, len + 1);
    //         }
    //     });
    // };
    // DFS(2, 1); //첫자리가 2일때
    // DFS(3, 1); ////첫자리가 3일때
    // DFS(5, 1); //////첫자리가 5일때
    // DFS(7, 1); ////////첫자리가 7일때
    // console.log(answer.trim());
}
// 이거 메모리 초과나는데 js 로 맞춘사람이 113명중 0명인거 보니까 접근 자체는 괜찮은데 js에 대한 모함과 핍박때문인듯 반박시 니말 틀림
