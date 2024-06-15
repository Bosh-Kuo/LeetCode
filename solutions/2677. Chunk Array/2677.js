/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
  let chunkSize = 0;
  let newArr = [];
  let chunkArr = [];
  for (let i = 0; i < arr.length; i++) {
    chunkSize++;
    chunkArr.push(arr[i]);
    if (chunkSize === size || i === arr.length - 1) {
      chunkSize = 0;
      newArr.push(chunkArr);
      chunkArr = [];
    }
  }
  return newArr;
};
