const longestValidParentheses = (str) => {
  let count = 0,
    left = 0,
    right = 0;

  for (let i = 0; i < str.length; i++) {
    let character = str[i];
    if (character === "(") left++;
    if (character === ")") right++;
    if (left === right) count = Math.max(count, left + right);
    if (right > left) left = right = 0;
  }

  left = right = 0;

  for (let i = str.length - 1; i >= 0; i--) {
    let character = str[i];
    if (character === "(") left++;
    if (character === ")") right++;
    if (left === right) count = Math.max(count, left + right);
    if (left > right) left = right = 0;
  }
  return count;
};

// console.log(longestValidParentheses("(()"))          // Output: 2
// console.log(longestValidParentheses(")()())"))       // Output: 4
// console.log(longestValidParentheses(""))             // Output: 0
