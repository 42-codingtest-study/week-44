//문제: Doit26
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [N, M, V] = input.shift().split(" ").map(Number); //[4,5,1]
    const arr = Array.from({ length: N + 1 }, (_, idx) => []);
    input.forEach((e) => {
        const [start, end] = e.split(" ").map(Number);
        arr[start].push(end);
    });
    const BFS = (arr, start) => {
        const check = Array.from({ length: N + 1 }, () => false);
        const queue = [start];
        check[start] = true;
        while (queue.length) {
            let now = queue.shift();
            console.log(now);
            arr[now].forEach((e) => {
                if (!check[e]) {
                    queue.push(e);
                    check[e] = true;
                }
            });
        }
    };
    BFS(arr, V);
    const DFS = (arr, start) => {
        const check = Array.from({ length: N + 1 }, () => false);
        const stack = [start];
        check[start] = true;
        while (stack.length) {
            let now = stack.pop();
            arr[now]
                .sort((a, b) => b - a)
                .forEach((e) => {
                    if (!check[e] && !check[e]) {
                        stack.push(e);
                        check[e] = true;
                    }
                });
        }
    };
    DFS(arr, V);
}
