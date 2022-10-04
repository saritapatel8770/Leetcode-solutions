/**
 * @param {string} s
 * @return {number}
 */
 function removePalindromeSub(str) {
    if (!str) return 0
    for (let i = 0, j = str.length - 1; i < j; i++, j--)
        if (str.charAt(i) !== str.charAt(j)) return 2
    return 1
};

/* 
  console.log(removePalindromeSub("ababa")) // 1
  console.log(removePalindromeSub("abb")) // 2
  */
