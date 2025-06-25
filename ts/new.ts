// const target: number = 9;

// // time complexity O(n ^ 2)
// function twoSum(nums: number[], target: number): number[] {
//   const ans: number[] = [];
//   const n = nums.length;

//   for (let i = 0; i < n; i++) {
//     let rem = target - nums[i];

//     let ans = find(rem);
//     if(ans != -1){
//       ans.push(i);
//       ans.push(ans);
//       return ans;
//     }

//   }

//   return ans;
// }


// //

// // o( n )

// // 1 time constant solution

// // O(5)

// const arr: number[] = [1, 2, 3, 4, 5];
// // n size array

// // 5 -> // O(5)= // O(1) constant time
// //  O(n)

// const n = 5;

// // o(n) + o(n) = o(n + 3) = o(n)

// function fun() {
//   for (let i = 0; i < 5; i++) {
//     console.log("              ");
//   }

//   for (let i = 0; i < 5; i++) {
//     console.log("                 ");
//   }
// }

// fun();

// // o (n)     o(n^2)
// // 1          1
// // 2         4
// // 3         9
// // 4         16
// // 5         25
// // 100   10000
// // 6465    41862225

// // 1
// // 2
// // 3

// // o(1)
// function fun2(nun: number) {
//   console.log("Hello World", nun);
// }
