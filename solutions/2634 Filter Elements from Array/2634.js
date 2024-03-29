/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
  return arr.filter((val, i) => fn(val, i));
};
