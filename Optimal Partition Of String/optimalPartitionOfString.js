const partitionString = (str) => {
  if ([0, 1].includes(str.length)) return str.length;
  let count = 1;
  let obj = {};
  for (let character of str) {
    if (!Object.keys(obj).includes(character)) obj[character] = character;
    else {
      obj = {};
      obj[character] = character;
      count++;
    }
  }
  return count;
};

// console.log(partitionString("abacaba")) // Output: 4
