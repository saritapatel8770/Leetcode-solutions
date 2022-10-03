const checkPermutations = (result, permutation, nums) => {
  if (permutation.length === nums.length) return result.push([...permutation]);
  for (let i = 0; i < nums.length; i++) {
    if (permutation.includes(nums[i])) continue;
    permutation.push(nums[i]);
    checkPermutations(result, permutation, nums);
    permutation.pop();
  }
};

const permute = (nums) => {
  const result = [];
  checkPermutations(result, [], nums);
  return result;
};

// console.log(permute([1, 2, 3]));
// console.log(permute([0, 1]));
// console.log(permute([1]));
